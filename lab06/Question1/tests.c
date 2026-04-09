#include <stdio.h>
#include "graph.h"

static void add_edge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void test_count_edges_empty() {
    Graph g = {0};

    int ans = count_edges(&g);

    if (ans == 0) {
        printf("PASS: count_edges empty graph\n");
    } else {
        printf("FAIL: count_edges empty graph, expected 0, got %d\n", ans);
    }
}

void test_count_edges_one_edge() {
    Graph g = {0};

    add_edge(&g, 1, 4);

    int ans = count_edges(&g);

    if (ans == 1) {
        printf("PASS: count_edges one edge\n");
    } else {
        printf("FAIL: count_edges one edge, expected 1, got %d\n", ans);
    }
}

void test_count_edges_basic() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 2, 3);

    int ans = count_edges(&g);

    if (ans == 3) {
        printf("PASS: count_edges basic graph\n");
    } else {
        printf("FAIL: count_edges basic graph, expected 3, got %d\n", ans);
    }
}

void test_count_edges_disconnected_parts() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 3, 4);

    int ans = count_edges(&g);

    if (ans == 2) {
        printf("PASS: count_edges disconnected parts\n");
    } else {
        printf("FAIL: count_edges disconnected parts, expected 2, got %d\n", ans);
    }
}

void test_count_edges_star_graph() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 0, 3);
    add_edge(&g, 0, 4);

    int ans = count_edges(&g);

    if (ans == 4) {
        printf("PASS: count_edges star graph\n");
    } else {
        printf("FAIL: count_edges star graph, expected 4, got %d\n", ans);
    }
}

void test_count_edges_path_graph() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);

    int ans = count_edges(&g);

    if (ans == 4) {
        printf("PASS: count_edges path graph\n");
    } else {
        printf("FAIL: count_edges path graph, expected 4, got %d\n", ans);
    }
}

void test_count_edges_complete_graph() {
    Graph g = {0};

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            add_edge(&g, i, j);
        }
    }

    int ans = count_edges(&g);

    if (ans == 10) {
        printf("PASS: count_edges complete graph\n");
    } else {
        printf("FAIL: count_edges complete graph, expected 10, got %d\n", ans);
    }
}

int main() {
    test_count_edges_empty();
    test_count_edges_one_edge();
    test_count_edges_basic();
    test_count_edges_disconnected_parts();
    test_count_edges_star_graph();
    test_count_edges_path_graph();
    test_count_edges_complete_graph();
    return 0;
}