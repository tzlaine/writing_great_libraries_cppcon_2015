#include <algorithm>
#include <vector>

template <typename InIter, typename OutIter, typename Fn>
OutIter filter(InIter first, InIter last, OutIter out, Fn f)
{ return std::copy_if(first, last, out, f); }

// sample(filter)
struct X
{
    int value;
    /*...*/
};
// end-sample

int main()
{

// sample(filter)
std::vector<X> xs = {/*...*/};
std::vector<X> selected_xs;

filter(
    xs.begin(),
    xs.end(),
    std::back_inserter(selected_xs),
    [](X const & x) { return x.value == 42; }
);
// end-sample

// sample(copy_if)
std::copy_if(
    xs.begin(),
    xs.end(),
    std::back_inserter(selected_xs),
    [](X const & x) { return x.value == 42; }
);
// end-sample

    return 0;
}
