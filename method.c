#include <stdlib.h>
#include "method.h"

#define TRUE 1
#define FALSE 0

// Giant Tour
void giant_tour(struct graph_am* G, int f, int* T) {
    int i;
    int j;

    float min;      // minimum of the column
    int ind_min;    // index of the minimum
    
    int* mark;
    mark = (int*) malloc((G->n-1)*sizeof(int));

    for (i=0;i<G->n-1;i++) {
        mark[i] = FALSE;
    }

    // init the current client
    int cur = f;

    for (i=0;i<G->n-1;i++) {
        // add the current client in the tour and mark it
        T[i] = cur;
        mark[cur-1] = TRUE;

        // look for the nearest unmarked neighbour
        ind_min = -1;
        min = -1;

        for (j=1;j<G->n;j++) {
            if ((mark[j-1] == FALSE) && (G->M[cur+cur*(G->n-1)+j] != 0)) {
                if ((G->M[cur+cur*(G->n-1)+j] < min) || (min == -1)) { 
                    min = G->M[cur+cur*(G->n-1)+j];
                    ind_min = j;
                }
            }
        }

        // change the current client
        cur = ind_min;
    }

    free(mark);
}

// Split
void split(struct graph_am* G, int Q, int* q, int* T, struct graph_al* H) {
    int i;
    int j;
    int load;
    float total_cost;

    for (i=0;i<G->n-1;i++) {
        j = i;
        load = 0;

        while ((j < G->n-1) && (load <= Q)) {
            load += q[T[j]-1];

            if (i == j) {
                total_cost = G->M[T[i]] + G->M[T[i]+T[i]*(G->n-1)];
            } else {
                total_cost = total_cost
                           - G->M[T[j-1]+T[j-1]*(G->n-1)]
                           + G->M[T[j-1]+T[j-1]*(G->n-1)+T[j]]
                           + G->M[T[j]+T[j]*(G->n-1)];
            }

            if (load <= Q) {
                add_edge_al(H, i, j+1, total_cost);
            }

            j += 1;
        }
    }
}

// Bellman-Ford
void bellman_ford(struct graph_al* H, float* p, int* F) {
    int i;
    int j;
    int x;
    int y;

    // init potentials and fathers
    p[0] = 0;
    F[0] = 0;

    for (i=1;i<H->n;i++) {
        p[i] = -1;
        F[i] = 0;
    }

    // for all successor of the root
    for (i=H->h[0];i<H->h[1];i++) {
        x = H->s[i];
        p[x] = H->w[i];
    }

    // for all successor of other nodes
    for (x=1;x<H->n-1;x++) {
        for (j=H->h[x];j<H->h[x+1];j++) {
            y = H->s[j];
            if (p[x] + H->w[j] < p[y] || p[y] == -1) {
                p[y] = p[x] + H->w[j];
                F[y] = x;
            }
        }
    }

    // the last node has no successor
    if (p[H->n-2] + H->w[H->h[H->n]-1] < p[H->n-1] || p[H->n-1] == -1) {
        p[H->n-1] = p[H->n-2] + H->w[H->h[H->n]-1];
        F[H->n-1] = H->n-2;
    }
}
