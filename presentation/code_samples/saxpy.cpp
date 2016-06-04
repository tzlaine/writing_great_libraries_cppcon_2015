struct matrix_t
{
    using value_type = double;
};

// sample(bad_matrix_interface)
matrix_t saxpy (float a, matrix_t const & x, matrix_t const & y);
// end-sample

matrix_t saxpy (float a, matrix_t const & x, matrix_t const & y)
{ return matrix_t{}; }

// sample(good_matrix_interface)
matrix_t operator* (float a, matrix_t const & x);
matrix_t operator+ (matrix_t const & x, matrix_t const & y);
// end-sample

matrix_t operator* (float a, matrix_t const & x)
{ return matrix_t{}; }
matrix_t operator+ (matrix_t const & x, matrix_t const & y)
{ return matrix_t{}; }

int main ()
{
float a;
matrix_t x, y;

{
// sample(bad_matrix_interface)
auto z = saxpy(a, x, y); // Wha?
// end-sample
}

{
// sample(good_matrix_interface)
auto z = a * x + y; // Now this I get.
// end-sample
}

    return 0;
}
