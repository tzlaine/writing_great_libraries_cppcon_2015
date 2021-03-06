#include <vector>

// sample(c_range_interface_1)
struct X { /*...*/ };

int num_xs ();

const X * get_x (int i);
// end-sample

// sample(c_range_interface_2)
int num_xs ();

void get_xs (X** xs);
// end-sample

int num_xs ()
{ return 0; }

const X * get_x (int i)
{ return nullptr; }

void get_xs (X** xs)
{}

void remove_x (int i)
{}

void use(const X *)
{
}
void use(const X &)
{
}

// sample(c++_lazy_range_interface)
struct x_range {
    // iterator into our internal storage
    using iterator =
        std::vector<X>::const_iterator;
    iterator first, last;
};

x_range::iterator begin (x_range r)
{ return r.first; }

x_range::iterator end (x_range r)
{ return r.last; }

// end-sample
std::size_t size (x_range r)
{ return end(r) - begin(r); }

// sample(c++_lazy_range_interface)
x_range get_xs ();
// end-sample

x_range get_xs ()
{
    static std::vector<X> v;
    return x_range{v.begin(), v.end()};
}

int some_index ()
{ return 0; }

int main()
{
{
// sample(c_range_usage_1)
const int num = num_xs();
for (int i = 0; i < num; ++i) {
    const X * x = get_x(i);
    use(x);
}
// end-sample
}

{
// sample(c_range_usage_2)
const int num = num_xs();
std::vector<X*> xs(num);
get_xs(&xs[0]);
for (auto x : xs) {
    use(x);
}
// end-sample
}

{
// sample(c_range_usage_3)
int num = num_xs();
// some code to here change num,
// in order to take a subset of num_xs() ...
for (int i = 0; i < num; ++i) {
    const X * x = get_x(i);
    use(x);
}
// end-sample
}

{
// sample(c_range_usage_4)
int num = num_xs();
// Fiery explosion when i == num - 1.
// If we're lucky.
for (int i = 0; i < num; ++i) {
    const X * x = get_x(i);
    if (i == some_index())
        remove_x(i);
    use(x);
}
}
// end-sample

{
// sample(c++_lazy_range_usage)
x_range range = get_xs();
for (auto const & x : range) {
    use(x);
}

// This will use memcpy for PODs, etc.
std::vector<X> copy_of_xs(size(range));
std::copy(begin(range),
          end(range),
          copy_of_xs.begin());
// end-sample
}
    return 0;
}
