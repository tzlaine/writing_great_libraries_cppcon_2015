// sample(right_generic_start)
int foo (int a, int b)
// end-sample
{ return 42; }

void foo_void (int a, int b)
// sample(right_generic_start)
{ return /*...*/; }
// end-sample

// sample(right_generic_start)

double foo (double a, double b)
// end-sample
{ return 42; }

void foo_void (double a, double b)
// sample(right_generic_start)
{ return /*...*/; }
// end-sample

// sample(wrong_generic_start)
template <typename T>
T foo (T a, T b)
// end-sample
{ return T(42); }

template <typename T>
void foo_void (T a, T b)
// sample(wrong_generic_start)
{ return /*...*/; }
// end-sample

int main ()
{
    return 0;
}
