#ifndef SRC_H
#define SRC_H

#include <stddef.h>
#include <src-priv.h>

size_t get_file_size(const char* file_path);

#define get_sysfile_meminfo_size() get_sysfile_meminfo_size("/proc/meminfo")


#endif
