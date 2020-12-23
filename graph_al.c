#include <stdlib.h>
#include <stdio.h>
#include "graph_al.h"

void init_graph_al(struct graph_al* G, int n) {
    G->n = n;
    G->h = (int*) malloc((n+1)*sizeof(int));
    G->s = (int*) malloc(1*sizeof(int));
    G->w = (float*) malloc(1*sizeof(float));

    int i;
    for (i=0;i<n;i++) {
        G->h[i] = -1;   
    }

    G->h[n] = 0;
}

void add_edge_al(struct graph_al* G, int i, int j, float w) {
    int m = G->h[G->n];
    
    // head of list array
    if (G->h[i] == -1) {
        G->h[i] = m;
    }
    
    // successors
    G->s = realloc(G->s, (m+1)*sizeof(int));
    G->s[m] = j;

    // weight array
    G->w = realloc(G->w, (m+1)*sizeof(float));
    G->w[m] = w;

    G->h[G->n] += 1;
}

void print_graph_al(struct graph_al* G) {   
    printf("digraph G {\n\trankdir=LR;\n\n");

    int i;
    for (i=0;i<G->n;i++) {
    	printf("\t%d [shape=circle];\n", i);
    }

    printf("\n");
    
    int j;
    for (i=0;i<G->n;i++) {
        if (G->h[i] != -1) {
          	printf("\t%d -> %d [label=\"%2.1f\"];\n", i, G->s[G->h[i]], G->w[G->h[i]]);
            for (j=G->h[i]+1;j<G->h[i+1];j++) {
                printf("\t%d -> %d [label=\"%2.1f\"];\n", i, G->s[j], G->w[j]);
            }
        }
    }

    printf("}\n");
}

void clear_graph_al(struct graph_al* G) {
    free(G->h);
    free(G->s);
    free(G->w);
}
