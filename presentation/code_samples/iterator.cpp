// sample(iterator_facade)
#include <boost/iterator/iterator_facade.hpp>

struct node_base { /*...*/ };

struct node_iterator :
    public boost::iterator_facade<
        node_iterator,
        node_base,
        boost::forward_traversal_tag
    >
{
    node_iterator();
    explicit node_iterator(node_base * p);

 private:
    friend class boost::iterator_core_access;

    void increment();
    bool equal(node_iterator const & other) const;
    node_base & dereference() const;

    node_base * m_node;
};
// end-sample

int main()
{
    return 0;
}

node_iterator::node_iterator() : m_node(0) {}
node_iterator::node_iterator(node_base * p) : m_node(p) {}
void node_iterator::increment() {}
bool node_iterator::equal(node_iterator const & other) const { return false; }
node_base & node_iterator::dereference() const { return *m_node; }
