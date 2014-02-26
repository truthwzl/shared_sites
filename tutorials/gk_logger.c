/*
 * gk_logger.c
 *
 *  Created on: Feb 28, 2011
 *      Author: root
 */

#include "gk_logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
int isDebug = 1;
void EXPORT_API gklog_trace(const char* format,...)
{
	if(!isDebug)return;
	printf("\033[33m"); // 开始以黄色打印 \033[1m 加粗
	printf("[TRACE]:");
	printf("\033[0m");
	va_list arg_ptr;
	va_start(arg_ptr,format);  //以固定参数的地址为起点确定变参的内存起始地址。
	vprintf(format,arg_ptr); //输出各参数的值
	printf("\n");
}
void EXPORT_API gklog_debug(const char* format,...)
{
	if(!isDebug)return;
	printf("\033[32m\033[1m"); // 开始以绿色打印
	printf("[DEBUG]:");
	printf("\033[0m");
	va_list arg_ptr;
	va_start(arg_ptr,format);  //以固定参数的地址为起点确定变参的内存起始地址。
	vprintf(format,arg_ptr); //输出各参数的值
	printf("\n");
}
void EXPORT_API gklog_error(const char* format,...)
{
	if(!isDebug)return;
	printf("\033[31m\033[1m"); // 开始以红色打印
	printf("[ERROR]:");
	printf("\033[0m");
	va_list arg_ptr;
	va_start(arg_ptr,format);  //以固定参数的地址为起点确定变参的内存起始地址。
	vprintf(format,arg_ptr); //输出各参数的值
	printf("\n");
}
void EXPORT_API gklog_warn(const char* format,...)
{
	if(!isDebug)return;
	printf("[WARN]:");
	va_list arg_ptr;
	va_start(arg_ptr,format);  //以固定参数的地址为起点确定变参的内存起始地址。
	vprintf(format,arg_ptr); //输出各参数的值
	printf("\n");
}
void EXPORT_API gklog_infor(const char* format,...)
{
	if(!isDebug)return;
	printf("\033[34m"); // 开始以蓝色打印 \033[1m 加粗
	printf("[INFOR]:");
	printf("\033[0m");

	va_list arg_ptr;
	va_start(arg_ptr,format);  //以固定参数的地址为起点确定变参的内存起始地址。
	vprintf(format,arg_ptr); //输出各参数的值
	printf("\n");
}
static char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void EXPORT_API gklog_hex(unsigned char* data,int len)
{
	if(!isDebug)return;
	char* tmp = (char*)malloc(len*2+1);
	int count =0;
	int i = 0;
	for(i=0;i<len;i++)
	{
		tmp[count++] = hex[(data[i]>>4)];
		tmp[count++] = hex[(data[i]& 0x0f)];
	}
	tmp[count]='\0';
	printf("[HEX]: %s\n",tmp);
	free(tmp);
}