#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "graph_am.h"
#include "graph_al.h"
#include "method.h"

int main(int argc, char *argv[]) {
    // number of clients
    int n;
    scanf("%d", &n);

    // capacity of the vehicles
    int Q;
    scanf("%d", &Q);

    // quantities required by clients
    int *q;
    q = (int *) malloc(n*sizeof(int));

    int i;
    for (i=0;i<n;i++) {
        scanf("%d", &q[i]);
    }

    // init the graph
    struct graph_am G;
    init_graph_am(&G, n+1);

    // cost of each edge
    float w;
    int j;
    for (i=0;i<n+1;i++) {
        for (j=0;j<n+1;j++) {
            scanf("%f", &w);
            add_edge_am(&G, i, j, w);
        }
    }

    // make the giant tour
    int *T;
    T = (int*) malloc(n*n*sizeof(int));

    time_t t;
    srand((unsigned) time(&t));
    giant_tour(&G, (rand() % n)+1, T);

    // init the graph
    struct graph_al H;
    init_graph_al(&H, n+1);

    // apply the split operation
    split(&G, Q, q, T, &H);

    // apply the bellman-ford algorithm
    float *p;
    p = (float*) malloc((n+1)*sizeof(float));

    int *F;
    F = (int*) malloc((n+1)*sizeof(int));

    bellman_ford(&H, p, F);

    // display results
    if ((argc > 1) && (strcmp(argv[1], "--graph") == 0)) {
        printf("digraph R {\n\trankdir=LR;\n\n");

        for (i=0;i<n+1;i++) {
            printf("\t%d [shape=circle];\n", i);
        }

        printf("\n\n");

        i = n;
        while (i != 0) {
            printf("\t0 -> ");
            for (j=F[i];j<i;j++) {
                printf("%d -> ", T[j]);
            }
            printf("0;\n");
            i = F[i];
        }

        printf("}\n");   
    } else {
        printf("Total cost:\n  %f\n\n", p[n]);

        printf("Round(s):\n");

        i = n;
        while (i != 0) {
            printf("  ");
            for (j=F[i];j<i-1;j++) {
                printf("%d, ", T[j]);
            }
            printf("%d", T[j]);
            printf("\n");
            i = F[i];
        }
    }

    // clear all data structures
    clear_graph_am(&G);
    clear_graph_al(&H);
    free(q);
    free(T);
    free(p);
    free(F);

    return (EXIT_SUCCESS);
}
