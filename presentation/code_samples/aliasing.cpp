#include <memory>

namespace wrong {
// sample(wrong_xor_swap)
void xor_swap (int & a, int & b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}
// end-sample
}

namespace bad {
// sample(bad_xor_swap)
void xor_swap (int & a, int & b)
{
    if (&a != &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}
// end-sample
}

namespace less_bad {
// sample(less_bad_xor_swap)
void xor_swap (int & a_, int & b_)
{
    int a = a_, b = b_;

    a ^= b;
    b ^= a;
    a ^= b;

    a_ = a; b_ = b;
}
// end-sample
}

namespace ok {
// sample(ok_xor_swap)
std::pair<int, int> xor_swap (int a, int b)
{
    a ^= b;
    b ^= a;
    a ^= b;
    return std::make_pair(a, b);
}
// end-sample
}

namespace unclear {
// sample(unclear_pointer_using_code)
struct Base { /*...*/ };

struct S : Base { /*...*/ };

unsigned int * get_index (const Base & b);

std::pair<S *, unsigned int *> make_s_with_index ();
// end-sample

unsigned int * get_index (const Base & b)
{ return nullptr; }

// sample(possible_unclear_make_s_with_index_impl)
std::pair<S *, unsigned int *> make_s_with_index ()
{
    std::pair<S *, unsigned int *> retval{new S, nullptr};
    retval.second = get_index(*retval.first);
    return retval;
}
// end-sample
}

namespace clearer {
// sample(clearer_pointer_using_code)
struct Base { /*...*/ };

struct S : Base { /*...*/ };

unsigned int * get_index (const Base & b);

// We could also use std::unique_ptr<S> here.
std::pair<S, unsigned int *> make_s_with_index ();
// end-sample

unsigned int * get_index (const Base & b)
{ return nullptr; }

// sample(possible_clearer_make_s_with_index_impl)
std::pair<S, unsigned int *> make_s_with_index ()
{
    std::pair<S, unsigned int *> retval{S(), nullptr};
    retval.second = get_index(retval.first);
    return retval;
}
// end-sample
}

int main ()
{
    return 0;
}
