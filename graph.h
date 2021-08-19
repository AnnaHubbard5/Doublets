// FILE: graph.h (part of the namespace main_savitch_15)
// TEMPLATE CLASS PROVIDED: graph<Item> (a class for labeled graphs)
//   The vertices of an n-vertex graph are numbered from zero to n-1. Each vertex
//   has a label of type Item. It may be any of the C++ built-in types (int,
//   char, etc.), or any class with a default constructor and an assignment
//   operator. The graph may not have multiple edges.
//
// VALUE SEMANTICS for the graph<Item> template class:
//    Assignments and the copy constructor may be used with graph<Item> objects.

#ifndef GRAPH_H
#define GRAPH_H
#include <cstdlib>  // Provides size_t
#include <set>      // Provides set
#include <vector>

namespace main_savitch_15
{
    template <class Item>
    class graph{
    public:
        // MEMBER CONSTANTS
        static const std::size_t MAXIMUM = 20;
        // CONSTRUCTOR
        graph() { many_vertices = 0; }
        // MODIFICATION MEMBER FUNCTIONS
        void add_vertex(const Item& label);
        void add_edge(std::size_t source, std::size_t target);
        void remove_edge(std::size_t source, std::size_t target);
        Item& operator [ ] (std::size_t vertex);
        // CONSTANT MEMBER FUNCTIONS
        std::size_t size( ) const { return many_vertices; }
        bool is_edge(std::size_t source, std::size_t target) const;
        std::set<std::size_t> neighbors(std::size_t vertex) const;
        Item operator[ ] (std::size_t vertex) const;
        void bfs(std::size_t start, std::vector<std::size_t> &parent);
        std::vector<std::size_t> shortest_path(std::size_t source, std::size_t dest);
    private:
        bool edges[MAXIMUM][MAXIMUM];
        Item labels[MAXIMUM];
        std::size_t many_vertices;
    };
}

#include "graph.template" // Include the implementation.
#endif
