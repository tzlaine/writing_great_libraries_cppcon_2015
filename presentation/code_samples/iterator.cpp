// sample(iterator_facade)
#include <boost/iterator/iterator_facade.hpp>

struct node_base { /*...*/ };

struct node_iter :
    public boost::iterator_facade<
        node_iter,
        node_base,
        boost::forward_traversal_tag
    >
{
    node_iter();
    explicit node_iter(node_base * p);

 private:
    friend
        class boost::iterator_core_access;

    void increment();
    bool equal(node_iter const & it) const;
    node_base & dereference() const;

    node_base * m_node;
};
// end-sample

int main()
{
    return 0;
}

node_iter::node_iter() : m_node(0) {}
node_iter::node_iter(node_base * p) : m_node(p) {}
void node_iter::increment() {}
bool node_iter::equal(node_iter const & it) const { return false; }
node_base & node_iter::dereference() const { return *m_node; }
