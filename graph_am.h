#if ! defined (GRAPH_AM_H)
#define GRAPH_AM_H 1

// Data structure
struct graph_am {
    int n;      // number of nodes
    float* M;   // matrix of size n*n
};

// Constructor
extern void init_graph_am(struct graph_am*, int n);

// Add an edge between i and j
extern void add_edge_am(struct graph_am*, int i, int j, int w);

// Printer
extern void print_graph_am(struct graph_am*);

// Destructor
extern void clear_graph_am(struct graph_am*);

#endif
