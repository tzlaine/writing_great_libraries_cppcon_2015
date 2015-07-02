// sample(c_range_interface)
struct X { /*...*/ };

int num_xs ();

const X* get_x (int i);
// end-sample

int num_xs ()
{ return 0; }

const X* get_x (int i)
{ return nullptr; }

void use(const X*)
{
}

int main()
{
{
// sample(c_range_usage_1)
const int num = num_xs();
for (int i = 0; i < num; ++i) {
    const X* x = get_x(i);
    use(x);
}
// end-sample
}

{
// sample(c_range_usage_2)
int num = num_xs();
// some code to here change num,
// in order to take a subset of num_xs() ...
for (int i = 0; i < num; ++i) {
    const X* x = get_x(i);
    use(x);
}
}
// end-sample
    return 0;
}
