#include <stdio.h>
#include <stdlib.h>

struct data
{
  char key;
  struct data *next;
};

struct queue
{
  struct data *top;
  struct data *rear;
};

void print_queue_list(struct queue q);
void enqueue(struct queue *q, char key);
char dequeue(struct queue *q);

int main(void)
{
  struct queue q = {NULL, NULL};
  char n;  

  enqueue(&q, 'a');
  print_queue_list(q);
  enqueue(&q, 'b');
  print_queue_list(q);
  enqueue(&q, 'c');
  print_queue_list(q);

  n = dequeue(&q);
  if(n != '\0')
    {
      printf("dequeueされた文字：%c\n\n", n);
      printf("dequeue関数後\n");
      print_queue_list(q);
    }

  if(q.top != NULL)
    {
      while(q.top->next == q.top)
	{
	 free(q.top);
	 q.top = q.top->next;
	}
    }
  
  return 0;
}

void print_queue_list(struct queue q)
{
  int i = 0;
  struct queue cur;
  cur = q;

  printf("__________________\n");
  while(1){
    if(cur.top == NULL){
    printf("<---TOP<---REAR\n");
    break;
    }
    else{
      printf("%c", cur.top->key);
      if(i == 0){
	printf("<---TOP");
      }
      if(cur.top->next == NULL){
	printf("<---REAR\n");
	break;
      }
      printf("\n");
      cur.top = cur.top->next;
      i = 1;
    }
  }
  printf("__________________\n\n");
}

void enqueue(struct queue *q, char key){
  struct data *p = NULL;
  p = (struct data*)malloc(sizeof(struct data));
  p->key = key;
  p->next = NULL;

  if(q->top == NULL){
    q->top = p;
    q->rear = p;
  }
  else{
    q->rear->next = p;
    q->rear = p;
  }
}

char dequeue(struct queue *q)
{
  char x;
  struct data *d;

  if(q->top == NULL){
    printf("キューは空です。\n");
    x = '\0';
  }
  else{
    x = q->top->key;
    d = q->top;
    q->top = d->next;
    free(d);
  }
  return x;
}
