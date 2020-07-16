#include<stdio.h>/*Breadth first search(幅優先探索): キュー(queue)*/
#include<stdlib.h>

#define VMAX 100
#define EMAX 10000

struct adjlist{
  int e_num;
  struct adjlist *next;
}*adj[VMAX];

/*グローバル変数*/
int n, m, visit[EMAX], bfnum[VMAX], out[EMAX], in[EMAX], parent[VMAX];
int c, d;

/*キューのデータ構造*/
struct queue{
  int key;
  struct queue *before;
};
struct queuehead{
  struct queue *top, *rear;
}q;

/*bfs---(プロトタイプ宣言)*/
void enqueue(int k);
int dequeue();
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
/*キューの初期化*/
void initqueue(){ q.top = NULL; q.rear = NULL; }
/*キューへの要素の挿入*/
void enqueue(int k){
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

/*キューから要素の取り出し*/
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

/*幅優先順を出力*/
void print_bfn(){
  int i;
  printf("The bfn number bf_num[v] \n");
  for(i = 1; i <= n; i++) printf("bf_num[%d]: %d\n", i, bfnum[i]);
  printf("\n");
}
/*木辺を出力*/
void print_tree_edge(){
  int i, e;
  printf("List of tree edge:\n");
  for(i = 1; i <= n; i++){
    e = parent[i];
    if(e != 0) printf("e%d = (%d, %d)\n", e, out[e], in[e]);
    /*e == 0のときは, 根であるので出力しない*/
  }
}

/*開始点の入力*/
int  input_start(){
  int w;
  printf("出発点を入力してください\n");
  printf("s: "); scanf("%d", &w);
  printf("\n");
  return (w);
}
/*隣接リストと辺の配列を構成(プロトタイプ宣言)*/
void addlist(int v, int w, int e_num);
void input_graph(){
  int i, j, k, v, w;
  printf("頂点数を入力してください\n"); scanf("%d", &n);
  printf("辺数を入力してください\n"); scanf("%d", &m);
  printf("%d個の辺それぞれの両端点を入力してください\n", m);
  for(i = 1; i <= n; i++) adj[i] = NULL;
  for(i = 1; i <= m; i++){
    printf("辺%d: ", i); scanf("%d %d", &v, &w);
    out[i] = v; in[i] = w;
    addlist(v, w, i);
  }
}
/*リストへの構造体を追加*/
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
/*ファイルに既に蓄えられているデータからグラフの隣接リスト等を構成する*/
void file_input_graph(){
  int v, w, e;
  FILE *fp;
  char file[256];
  /*option15-1.dat*/
  printf("ファイル名を入力してください(option15.dat)\n"); scanf("%s", file);
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
/*隣接リストを出力*/
void print_graph(){
  int k, v, w;
  struct adjlist *new, *work;
  printf("入力したグラフの出力\n");
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
  /* -------------------ファイルがある場合----------------------- */
  /*ファイルに既に蓄えられているデータからグラフの隣接リスト等を作成*/
  file_input_graph();
  /*グラフデータ(隣接リスト)の出力*/
  print_graph();
  
  /*-------------------------------------------------------------*/
  
  /*キュー(q)の初期化*/
  initqueue();
  c = 1; d = 1;
  for(v = 1; v <= n; v++) bfnum[v] = parent[v] = 0;
  for(e = 1; e <= m; e++) visit[e] = 0;
  /*/開始点をsとする*/
  s = input_start();
  
  bfs(s);
  for(v = 1; v <= n; v++){
    //Gが連結ならばこの行とすぐ前の行は不用
    if(bfnum[v] == 0) bfs(v);
  }

  /*幅優先順の出力*/
  print_bfn();
  /*木辺の出力*/
  print_tree_edge();
  
  return 0;
}
