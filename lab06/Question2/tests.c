#include <stdio.h>
#include "graph.h"

static void add_edge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void test_count_isolated_all_isolated() {
    Graph g = {0};

    int ans = count_isolated(&g);

    if (ans == 5) {
        printf("PASS: count_isolated all isolated\n");
    } else {
        printf("FAIL: count_isolated all isolated, expected 5, got %d\n", ans);
    }
}

void test_count_isolated_one_edge() {
    Graph g = {0};

    add_edge(&g, 0, 4);

    int ans = count_isolated(&g);

    if (ans == 3) {
        printf("PASS: count_isolated one edge\n");
    } else {
        printf("FAIL: count_isolated one edge, expected 3, got %d\n", ans);
    }
}

void test_count_isolated_basic() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);

    int ans = count_isolated(&g);

    if (ans == 2) {
        printf("PASS: count_isolated basic graph\n");
    } else {
        printf("FAIL: count_isolated basic graph, expected 2, got %d\n", ans);
    }
}

void test_count_isolated_one_isolated() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);

    int ans = count_isolated(&g);

    if (ans == 1) {
        printf("PASS: count_isolated one isolated\n");
    } else {
        printf("FAIL: count_isolated one isolated, expected 1, got %d\n", ans);
    }
}

void test_count_isolated_two_components_one_isolated() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 2, 3);

    int ans = count_isolated(&g);

    if (ans == 1) {
        printf("PASS: count_isolated two components one isolated\n");
    } else {
        printf("FAIL: count_isolated two components one isolated, expected 1, got %d\n", ans);
    }
}

void test_count_isolated_no_isolated() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);

    int ans = count_isolated(&g);

    if (ans == 0) {
        printf("PASS: count_isolated no isolated\n");
    } else {
        printf("FAIL: count_isolated no isolated, expected 0, got %d\n", ans);
    }
}

void test_count_isolated_complete_graph() {
    Graph g = {0};

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            add_edge(&g, i, j);
        }
    }

    int ans = count_isolated(&g);

    if (ans == 0) {
        printf("PASS: count_isolated complete graph\n");
    } else {
        printf("FAIL: count_isolated complete graph, expected 0, got %d\n", ans);
    }
}

int main() {
    test_count_isolated_all_isolated();
    test_count_isolated_one_edge();
    test_count_isolated_basic();
    test_count_isolated_one_isolated();
    test_count_isolated_two_components_one_isolated();
    test_count_isolated_no_isolated();
    test_count_isolated_complete_graph();
    return 0;
}