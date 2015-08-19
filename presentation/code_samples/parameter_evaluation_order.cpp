int foo(int i)
{ return i; }
int bar(int a, int b)
{ return a + b; }

int main()
{
// sample(parameter_evaluation_order)
int i = 2;
auto result = bar(foo(i), foo(i));
// end-sample

    return 0;
}
