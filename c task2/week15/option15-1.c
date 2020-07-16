/* Breadth first search : queue */
#include<stdio.h>
#include<stdlib.h>

#define VMAX 100
#define EMAX 10000

struct adjlist{
    int e_num;
    struct adjlist *next;
}*adj[VMAX];

/* Global variable */
int n, m, visit[EMAX], bfnum[VMAX], out[EMAX], in[EMAX], parent[VMAX];
int c, d;

/* Queue's Data structure */
struct queue{
    int key;
    struct queue *before;
};

struct queuehead{
    struct queue *top, *rear;
}q;

/* Prototype declaration */
void enqueue(int k);
int dequeue();

/* Breadth first search*/
void bfs(int v){
    int w, e;
    struct adjlist *p;

    bfnum[v] = c; c = c + 1;
    enqueue(v);
    while(q.top != NULL){
        v = dequeue(); p = adj[v];
        while(p != NULL){
            e = p->e_num;
            if(visit[e] == 0){
	            visit[e] = d; d = d + 1;
	            if(out[e] == v) w = in[e];
	            else w = out[e];
	            if(bfnum[w] == 0){
	                bfnum[w] = c; c = c + 1;
	                enqueue(w);
	                parent[w] = e;
	            }
            }p = p->next;
        }
    }
}
/* initialize of queue */
void initqueue(){ q.top = NULL; q.rear = NULL; }

/* Insert a element to queue */
void enqueue(int k)
{
    struct queue *new, *w;
    new = (struct queue *)malloc(sizeof(struct queue));
    new->key = k;
    new->before = NULL;
    if((w = q.rear) != NULL){
        q.rear = new;
        w->before = new;
    }
    else{
        q.rear = new;
        q.top = new;
    }
}

/* Delete a element from queue */
int dequeue(){
    struct queue *w;
    int key;
    w = q.top;
    key = w->key;
    q.top = w->before;
    if(q.top == NULL) q.rear = NULL;
    free(w);
    return (key);
}


void print_bfn(){
    int i;
    printf("The bfn number bf_num[v] \n");
    for(i = 1; i <= n; i++) printf("bf_num[%d]: %d\n", i, bfnum[i]);
    printf("\n");
}

void print_tree_edge(){
    int i, e;
    printf("List of tree edge:\n");
    for(i = 1; i <= n; i++){
        e = parent[i];
        if(e != 0) printf("e%d = (%d, %d)\n", e, out[e], in[e]);
        /* when e's value equals 0,  U don't need print because having root */
     }
}

/* Input start point */
int  input_start(){
    int w;
    printf("Please input start point\n");
    printf("s: "); scanf("%d", &w);
    printf("\n");
    return (w);
}

/* Compose of adjacent list and edge's array (Prototype declaration)*/
void addlist(int v, int w, int e_num);
void input_graph(){
    int i, j, k, v, w;
    printf("Please inout a vertex nubmer: \n"); scanf("%d", &n);
    printf("Please input a edge number: \n"); scanf("%d", &m);
    printf("Please input each of %d sides's both ends points : \n", m);
    for(i = 1; i <= n; i++) adj[i] = NULL;
    for(i = 1; i <= m; i++){
        printf("edge%d: ", i); scanf("%d %d", &v, &w);
        out[i] = v; in[i] = w;
        addlist(v, w, i);
    }
}

/* Add data structure to list */
void addlist(int v, int w, int e_num){
    struct adjlist *new, *work;
    new = (struct adjlist *)malloc(sizeof(struct adjlist));
    new->e_num = e_num;
    work = adj[v];
    adj[v] = new;
    new->next = work;
    new = (struct adjlist *)malloc(sizeof(struct adjlist));
    new->e_num = e_num;
    work = adj[w];
    adj[w] = new;
    new->next = work;
}

void file_input_graph(){
    int v, w, e;
    FILE *fp;
    char file[256];
    /*option15-1.dat*/
    printf("Please input file name(option15.dat)\n"); scanf("%s", file);
    printf("\n");
    if((fp = fopen(file, "r")) == NULL){
        printf("\nERROR : Cannot open file %s\n", file); exit(1);
    }
    fscanf(fp, "%d", &n); fscanf(fp, "%d", &m);
    for(v = 1; v <= n; v ++) adj[v] = NULL;
    for(e = 1; e <= m; e++){
        fscanf(fp, "%d %d", &v, &w);
        out[e] = v; in[e] = w;
        addlist(v, w, e);
    }
    fclose(fp);
}

void print_graph(){
    int k, v, w;
    struct adjlist *new, *work;
    printf("print inputted graph \n");
    printf("n: %d m: %d \n", n, m);

    for(v = 1; v <= n; v++){
        printf("%d ", v);
        work = adj[v];
        while(work != NULL){
            w = work->e_num;
            if(out[w] == v) k = in[w];
            else k = out[w];
            printf("e %d(%d) ", work->e_num, k);
            work = work->next;
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){
    int s, v, e;
    /*input_graph();*/
    
    file_input_graph();
    print_graph();
  
   
    initqueue();
    c = 1; d = 1;
    for(v = 1; v <= n; v++) bfnum[v] = parent[v] = 0;
    for(e = 1; e <= m; e++) visit[e] = 0;
   
    s = input_start();
  
    bfs(s);
    for(v = 1; v <= n; v++){
        if(bfnum[v] == 0) bfs(v);
    }

    print_bfn();
    print_tree_edge();
  
    return 0;
}
