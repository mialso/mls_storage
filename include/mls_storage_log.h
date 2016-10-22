#ifndef MLS_STORAGE_LOG_H
#define MLS_STORAGE_LOG_H

#include <stdint.h>

#define STR(x) #x
#define TO_STR(string) STR(string)
#define AT get_string(__FILE__":"TO_STR(__LINE__)":",__func__) 

void log_debug(const char *location, const char *message, int64_t data);
void log_debug_e(const char *location, const char *message, int64_t data, uint64_t err_num);
void log_error(const char *location, uint64_t err_num);

#endif
