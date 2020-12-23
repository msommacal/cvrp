#if ! defined (GRAPH_AL_H)
#define GRAPH_AL_H 1

// Data structure
struct graph_al {
    int n;          // number of nodes
    int* h;         // head of list
    int* s;         // successors
    float* w;       // weights of edges
};

// Constructor
extern void init_graph_al(struct graph_al*, int n);

// Export the graph as a DOT file
extern void print_graph_al(struct graph_al*);

// Add an edge between i and j
extern void add_edge_al(struct graph_al*, int i, int j, float w);

// Destructor
extern void clear_graph_al(struct graph_al*);

#endif
