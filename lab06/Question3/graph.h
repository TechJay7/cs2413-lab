#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 5

typedef struct {
    int adj[MAX_NODES][MAX_NODES];
} Graph;

int count_edges(Graph* g);
int count_isolated(Graph* g);
int has_triangle(Graph* g);

#endif