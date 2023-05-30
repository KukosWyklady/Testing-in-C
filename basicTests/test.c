#include <src.h>

#include <assert.h>

static void test_strlen_basic(void);
static void test_strlen_better(void);

static void test_strlen_basic(void)
{
    assert(strlen_basic(NULL) == 0);
    assert(strlen_basic("") == 0);
    assert(strlen_basic("ala") == 3);
    assert(strlen_basic("a\0la") == 1);
}

static void test_strlen_better(void)
{
    assert(strlen_better(NULL) == 0);
    assert(strlen_better("") == 0);
    assert(strlen_better("ala") == 3);
    assert(strlen_better("a\0la") == 1);
}

int main(void)
{
    test_strlen_basic();
    test_strlen_better();

    return 0;
}
