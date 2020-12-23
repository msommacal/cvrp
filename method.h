#if ! defined (METHOD_H)
#define METHOD_H 1

#include "graph_am.h"
#include "graph_al.h"

// Giant Tour
extern void giant_tour(struct graph_am*, int, int*);

// Split
extern void split(struct graph_am*, int, int*, int*, struct graph_al*);

// Bellman-Ford
extern void bellman_ford(struct graph_al*, float*, int*);

#endif
