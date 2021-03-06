#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>  
#include <dirent.h>  
#include <sys/stat.h>  
#include "gk_logger.h"
#include "api.h"

#ifndef strlwr
char *strlwr(char *s)
{
    char *str;
    if( s == NULL){
        return NULL;
    }
    str = s;
    while(*str != '\0')
    {
        if(*str > 'A' && *str < 'Z'){
            *str += 'a'-'A';
        }
        str++;
    }
    return s;
}
#endif 

VM g_vm;
void load_shared(char* file)
{
    void *handle;   
    int (*add)(VM* vm,int,int);
    char *error;  
  
    handle = dlopen (file, RTLD_LAZY);  
    if (!handle) {  
        fprintf (stderr, "%s\n", dlerror());  
        return ;
    }  
  
    add = dlsym(handle, "add");  
    if ((error = dlerror()) != NULL)  {  
        fprintf (stderr, "%s\n", error);  
        return ;
    }  
  
    printf ("[%s]:%d\n", file,(*add)(&g_vm,2,10));  
    dlclose(handle);  
    gklog_debug("%s",file);
}
/* 
struct dirent 
{ 
   
   long d_ino; // inode number 索引节点号  
   off_t d_off; // offset to this dirent 在目录文件中的偏移  
   unsigned short d_reclen; // length of this d_name 文件名长  
   unsigned char d_type; // the type of d_name 文件类型  
   char d_name [NAME_MAX+1]; // file name (null-terminated) 文件名，最长255字符  
}; 
 */ 
void ListFile(char *path)  
{  
    struct dirent* ent = NULL;  
    DIR *pDir;  
    pDir=opendir(path);  
    while (NULL != (ent=readdir(pDir)))  
    {  
        gklog_trace("type=%d\t,%s", ent->d_type,strlwr(ent->d_name));  
        char* lwr = (char*)strlwr(ent->d_name);
        if(strstr(lwr,".so"))
        {
            char file[256];
            strcpy(file,path);
            strcat(file,"/");
            strcat(file,lwr);
            //printf("file,%s\n", file);
            load_shared(file);
        }
    }  
}    
  
void loade_modules() 
{
    ListFile("./modules");

    char* substr=  strstr("123456a7890", "A789"); 
    printf("substr:%s\n",substr);
}  
int main(int argc, char **argv) {  
    g_vm.x = 100;
    g_vm.y = 1000;
    void *handle;   
    int (*add)(VM* vm,int,int);
    char *error;  
    int num;
  
    handle = dlopen ("./modules/libmy.so", RTLD_LAZY);  
    if (!handle) {  
        fprintf (stderr, "%s\n", dlerror());  
        exit(1);  
    }  
  
    add = dlsym(handle, "add");  
    if ((error = dlerror()) != NULL)  {  
        fprintf (stderr, "%s\n", error);  
        exit(1);  
    }  
  
    printf ("%d\n", (*add)(&g_vm,2,10));  
    dlclose(handle);  
    loade_modules();
    scanf("%d",&num);
    return 0;  
}  
