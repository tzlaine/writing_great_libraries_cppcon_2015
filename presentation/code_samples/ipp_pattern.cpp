#define FOO_HEADER_ONLY 0

// sample(ipp_pattern_header)
// foo.h
namespace foo {
    int bar ();
}

#if FOO_HEADER_ONLY
#include "foo.ipp"
#endif
// end-sample

// sample(ipp_pattern_impl)
// foo.cpp
#if ! FOO_HEADER_ONLY
#include "foo.ipp"
#endif
// end-sample

int main ()
{
    int i = foo::bar();

    return 0;
}
