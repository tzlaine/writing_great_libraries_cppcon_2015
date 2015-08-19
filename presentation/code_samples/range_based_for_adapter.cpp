#include <array>

// sample(range_based_for_adapter)
struct custom_array
{
    std::array<int, 5> m_storage;
};

auto begin (custom_array const & a) -> decltype(a.m_storage.begin())
{ return a.m_storage.begin(); }

auto end (custom_array const & a) -> decltype(a.m_storage.end())
{ return a.m_storage.end(); }


// end-sample

int main()
{
// sample(range_based_for_adapter)
custom_array array;
for (auto value : array) {
    // whatever
}
// end-sample

    return 0;
}
