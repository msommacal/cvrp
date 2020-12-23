#include <stdlib.h>
#include <stdio.h>
#include "graph_am.h"

// Constructor
void init_graph_am(struct graph_am* G, int n) {
   G->n = n;
   G->M = (float*) malloc(n*n*sizeof(float));
    
   int i;
   int j;
   for (i=0;i<G->n;i++) {
        for (j=0;j<G->n;j++) {
            G->M[i+i*(G->n-1)+j] = -1;
        }
    }
}

// Add an edge between i and j
void add_edge_am(struct graph_am* G, int i, int j, int w) {
    G->M[i+i*(G->n-1)+j] = w;
}

// Printer
void print_graph_am(struct graph_am* G) {  
    int i;
    int j;
    float w;

    printf("digraph G {\n\trankdir=LR;\n\n");

    for (i=0;i<G->n;i++) {
        printf("\t%d [shape=circle];\n", i);
    }

    printf("\n");

    for (i=0;i<G->n;i++) {
        for (j=0;j<G->n;j++) {
            w = G->M[i+i*(G->n-1)+j];
            if (w > 0) {
                printf("\t%d -> %d ", i, j);
                printf("[label=\"%2.1f\"];\n", w);
            }
        }
    }

    printf("}\n");
}

// Destructor
void clear_graph_am(struct graph_am* G) {
    free(G->M);
}
