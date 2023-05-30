#include <src.c> // copy paste CODE

#include <assert.h>

static void test_strlen_non_static(void);
static void test_strlen_static(void);

static void test_strlen_non_static(void)
{
    assert(strlen_non_static(NULL) == 0);
    assert(strlen_non_static("") == 0);
    assert(strlen_non_static("ala") == 3);
    assert(strlen_non_static("a\0la") == 1);
}

static void test_strlen_static(void)
{
    assert(mystrlen_static("") == 0);
    assert(mystrlen_static("ala") == 3);
    assert(mystrlen_static("a\0la") == 1);
}

int main(void)
{
    test_strlen_non_static();
    test_strlen_static();

    return 0;
}
