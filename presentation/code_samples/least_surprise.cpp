#include <algorithm>
#include <vector>

// sample(unexpected_delete)
struct X
{ /*...*/ };

void RegisterX(X const * x);
// end-sample

int main()
{

// sample(unexpected_delete)
X * x = new X{ /*...*/ };
RegisterX(x);
// end-sample

    return 0;
}

// sample(register_x_defn)
void RegisterX(X const * x)
{
    if (x) {
        // Some stuff that "registers" x...
    }
    delete x; // WTF
}
// end-sample
