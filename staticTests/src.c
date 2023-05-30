#include <src.h>

#include <string.h>
#include <stdio.h>

static size_t mystrlen_static(const char* const str)
{
    return strlen(str);
}

size_t strlen_non_static(const char* const str)
{
    if (str == NULL)
    {
        fprintf(stderr, "[ERROR] str == NULL\n");
        return 0;
    }

    return mystrlen_static(str);
}
