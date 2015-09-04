template <typename T>
void print (T && t) {}

// sample(template_decl)
template <typename T>
void some_function (T a, T b);
// end-sample

// sample(template_def)
template <typename T>
void some_function (T a, T b)
{
    auto c = a + b;
    print(c);
}
// end-sample

#if 0
// sample(constrained_template_decl)
template <Arithmetic T>
void some_function (T a, T b);
// end-sample
#endif

int main ()
{
    int a = 1, b = 2;
    some_function(a, b);

    return 0;
}
