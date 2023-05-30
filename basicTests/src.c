#include <src.h>

#include <string.h>
#include <stdio.h>

size_t strlen_basic(const char* const str)
{
    if (str == NULL)
        return 0;

    return strlen(str);
}

size_t strlen_better(const char* const str)
{
    if (str == NULL)
    {
        fprintf(stderr, "[ERROR] str == NULL\n"); // use logger
        return 0;
    }

    return strlen(str);
}
