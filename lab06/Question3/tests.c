#include <stdio.h>
#include "graph.h"

static void add_edge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void test_has_triangle_empty() {
    Graph g = {0};

    int ans = has_triangle(&g);

    if (ans == 0) {
        printf("PASS: has_triangle empty graph\n");
    } else {
        printf("FAIL: has_triangle empty graph, expected 0, got %d\n", ans);
    }
}

void test_has_triangle_simple_yes() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 0, 2);

    int ans = has_triangle(&g);

    if (ans == 1) {
        printf("PASS: has_triangle simple yes\n");
    } else {
        printf("FAIL: has_triangle simple yes, expected 1, got %d\n", ans);
    }
}

void test_has_triangle_path_only() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);

    int ans = has_triangle(&g);

    if (ans == 0) {
        printf("PASS: has_triangle path only\n");
    } else {
        printf("FAIL: has_triangle path only, expected 0, got %d\n", ans);
    }
}

void test_has_triangle_cycle_of_four() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 0);

    int ans = has_triangle(&g);

    if (ans == 0) {
        printf("PASS: has_triangle cycle of four\n");
    } else {
        printf("FAIL: has_triangle cycle of four, expected 0, got %d\n", ans);
    }
}

void test_has_triangle_in_one_component() {
    Graph g = {0};

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 0, 2);  // triangle
    add_edge(&g, 3, 4);  // separate component

    int ans = has_triangle(&g);

    if (ans == 1) {
        printf("PASS: has_triangle one component only\n");
    } else {
        printf("FAIL: has_triangle one component only, expected 1, got %d\n", ans);
    }
}

void test_has_triangle_bipartite_style_no() {
    Graph g = {0};

    add_edge(&g, 0, 2);
    add_edge(&g, 0, 3);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);

    int ans = has_triangle(&g);

    if (ans == 0) {
        printf("PASS: has_triangle bipartite-style no triangle\n");
    } else {
        printf("FAIL: has_triangle bipartite-style no triangle, expected 0, got %d\n", ans);
    }
}

void test_has_triangle_triangle_on_larger_nodes() {
    Graph g = {0};

    add_edge(&g, 1, 3);
    add_edge(&g, 3, 4);
    add_edge(&g, 1, 4);

    int ans = has_triangle(&g);

    if (ans == 1) {
        printf("PASS: has_triangle triangle on larger nodes\n");
    } else {
        printf("FAIL: has_triangle triangle on larger nodes, expected 1, got %d\n", ans);
    }
}

void test_has_triangle_complete_graph() {
    Graph g = {0};

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            add_edge(&g, i, j);
        }
    }

    int ans = has_triangle(&g);

    if (ans == 1) {
        printf("PASS: has_triangle complete graph\n");
    } else {
        printf("FAIL: has_triangle complete graph, expected 1, got %d\n", ans);
    }
}

int main() {
    test_has_triangle_empty();
    test_has_triangle_simple_yes();
    test_has_triangle_path_only();
    test_has_triangle_cycle_of_four();
    test_has_triangle_in_one_component();
    test_has_triangle_bipartite_style_no();
    test_has_triangle_triangle_on_larger_nodes();
    test_has_triangle_complete_graph();
    return 0;
}