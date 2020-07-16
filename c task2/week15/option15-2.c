/* Depth first search : stack */
#include<stdio.h>
#include<stdlib.h>
#define VMAX 100
#define EMAX 10000

struct adjlist {
    int e_num;
    struct adjlist* next;
} *adj[VMAX];


int n, m, visit[EMAX], dfnum[VMAX], out[EMAX], in[EMAX], parent[VMAX];
int c, d;

/* DFS */
void dfs(int v) {
    int u, w, e;
    struct adjlist* p;

    dfnum[v] = c; c = c + 1;
    p = adj[v];
    while (p != NULL) {
        e = p->e_num;
        if (visit[e] == 0) {
            visit[e] = d; d = d + 1;
            if (out[e] == v) w = in[e];
            else w = out[e];
            if (dfnum[w] == 0) { parent[w] = e; dfs(w); }
        }p = p->next;
    }
}

void print_dfn() {
    int i;
    printf("The dfs number df_num[v] \n");
    for (i = 1; i <= n; i++)
        printf("dfnum[%d]: %d\n", i, dfnum[i]);
    printf("\n");
}

void print_tree_edge() {
    int i, e;
    printf("List of tree edge:\n");
    for (i = 1; i <= n; i++) {
        e = parent[i];
        if (e != 0) printf("e%d = (%d, %d)\n", e, out[e], in[e]);

    }
}

int  input_start() {
    int w;
    printf("Please input start point\n");
    printf("s: "); scanf("%d", &w);
    printf("\n");
    return (w);
}

void addlist(int v, int w, int e_num);
void input_graph() {
    int i, j, k, v, w;
    printf("Please input a vertex nubmer: \n"); scanf("%d", &n);
    printf("Please input a edge number: \n"); scanf("%d", &m);
    printf("Please input each of %d sides's both ends points: \n", m);
    for (i = 1; i <= n; i++) adj[i] = NULL;
    for (i = 1; i <= m; i++) {
        printf("edge%d: ", i); scanf("%d %d", &v, &w);
        out[i] = v; in[i] = w;
        addlist(v, w, i);
    }
}

void addlist(int v, int w, int e_num) {
    struct adjlist* new, * work;
    new = (struct adjlist*)malloc(sizeof(struct adjlist));
    new->e_num = e_num;
    work = adj[v];
    adj[v] = new;
    new->next = work;
    new = (struct adjlist*)malloc(sizeof(struct adjlist));
    new->e_num = e_num;
    work = adj[w];
    adj[w] = new;
    new->next = work;
}

void file_input_graph() {
    int v, w, e;
    FILE* fp;
    char file[256];
 
    printf("Plwase input file name(option15.dat)\n"); scanf("%s", file);
    printf("\n");
    if ((fp = fopen(file, "r")) == NULL) {
        printf("\nERROR : Cannot open file %s\n", file); exit(1);
    }
    fscanf(fp, "%d", &n); fscanf(fp, "%d", &m);
    for (v = 1; v <= n; v++) adj[v] = NULL;
    for (e = 1; e <= m; e++) {
        fscanf(fp, "%d %d", &v, &w);
        out[e] = v; in[e] = w;
        addlist(v, w, e);
    }
    fclose(fp);
}

void print_graph() {
    int k, v, w;
    struct adjlist* new, * work;
    printf("Outpue inputted graph\n");
    printf("n: %d m: %d \n", n, m);

    for (v = 1; v <= n; v++) {
        printf("%d ", v);
        work = adj[v];
        while (work != NULL) {
            w = work->e_num;
            if (out[w] == v) k = in[w];
            else k = out[w];
            printf("e %d(%d) ", work->e_num, k);
            work = work->next;
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int s, v, e;

    file_input_graph();

    print_graph();
    c = 1; d = 1;
    for (v = 1; v <= n; v++) dfnum[v] = parent[v] = 0;
    for (e = 1; e <= m; e++) visit[e] = 0;

    s = input_start(); dfs(s);

    for (v = 1; v <= n; v++) { if (dfnum[v] == 0) dfs(v); }

    print_dfn();
    print_tree_edge();

    return 0;
}