#ifndef SRC_PRIV_H
#define SRC_PRIV_H

#include <stddef.h>

#ifndef SRC_H
#error "Please include src.h instead, do not include this file directly"
#endif

size_t get_sysfile_meminfo_size(const char* file_path);

#endif
