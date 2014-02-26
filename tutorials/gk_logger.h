#ifndef GK_LOGGER_H
#define  GK_LOGGER_H

#define  LOG_DEBUG 0
#define  LOG_ERROR 1
#define  LOG_TRACE 2
#define  LOG_INFOR 4
#define  LOG_WARN  8
#define  LOG_HEX   16

#define  EXPORT_API //__declspec(dllexport)
#ifdef __cplusplus
extern "C"
{
#endif
#define LOGID 0

void EXPORT_API gklog_trace(const char* format,...);
void EXPORT_API gklog_debug(const char* format,...);
void EXPORT_API gklog_error(const char* format,...);
void EXPORT_API gklog_warn(const char* format,...);
void EXPORT_API gklog_infor(const char* format,...);
void EXPORT_API gklog_hex(unsigned char* data,int len);

#ifdef __cplusplus
};
#endif
#endif // GK_LOGGER_H
