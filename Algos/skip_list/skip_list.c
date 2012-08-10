#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* data stucture for skip list */
/* node structure */
struct node {
  int data;
  int height;
  struct node *next;
  struct node *down;
};
typedef struct node sl_node;

/* header of list */
typedef struct {
  int height;
  sl_node *head;
  sl_node *bottom;
} sl_head;


/* search */
/* returns a pointer to the node containing the key */
sl_node *find(const sl_head *list, const int key) {

  sl_node *p = list->head;

  /* get down to the base list */
  while(p->down != NULL) {
    while(p->next != NULL && key > p->next->data)
      p = p->next;
    p = p->down;
  }
  /* search in the base list */
  while(p->next != NULL && key >= p->next->data)
    p = p->next;

  return key == p->data ? p : NULL;
}

/* flip a coin */
int getRand(int min, int max)
{
    static int Init = 0;
    int rc;

    if (Init == 0) {
	srand(time(NULL));
	Init = 1;
    }
    rc = (rand() % (max - min + 1) + min);

    return rc;
}

/* helper func for initialising a node */
void init_node(sl_node *p, int k, int h) {
  p->next = p->down = NULL;
  p->data = k;
  p->height = h;
}

/* insert into a skip list */
int insert(sl_head *list, int key) {

  if(find(list, key) != NULL) return 0;
  else {
    sl_node *path[list->height + 1];
    sl_node *p = list->head;
    sl_node *down = NULL;
    int i = 0;

    while(p->down != NULL) {
      while(p->next != NULL && key > p->next->data)
	p = p->next;
      path[p->height] = p;
      p = p->down;
    }
    while(p->next != NULL && key > p->next->data)
      p = p->next;

    do {
      if(i > list->height) {
	sl_node *sentinel = (sl_node*)malloc(sizeof(sl_node));
	init_node(sentinel, -1, i);
	sentinel->down = list->head;
	list->head = sentinel;
	p = sentinel;
      }
      sl_node *in = (sl_node*)malloc(sizeof(sl_node));
      init_node(in, key, i);
      i++;

      in->next = p->next;
      p->next = in;

      if(down != NULL)
	in->down = down;
      down = in;

      if(i <= list->height) p = path[i];
    } while(getRand(0, 2) > 1);
    list->height = list->head->height;

    return 1;
  }
}

void print_list(sl_head *list) {

  sl_node *p = list->head;
  do{
    sl_node *q = p;
    while(q != NULL) {
      if(q->data > -2) printf ("%2d ", q->data);
      q = q->next;
    }
    printf ("\n");
  } while((p = p->down) != NULL);
}

int main(int argc, char *argv[])
{
  sl_head *list = (sl_head*)malloc(sizeof(sl_head));
  sl_node *sentinel = (sl_node*)malloc(sizeof(sl_node));
  init_node(sentinel, -1, 0);
  list->head = sentinel;

  int cas = 2;

  /* test case 1 */
  /* hand made 2 levels skip list */
  if(cas == 1) {
    int i;
    for(i = 4; i > 0; i--) {
      sl_node *p = (sl_node*)malloc(sizeof(sl_node));
      init_node(p, i, 0);
      p->next = sentinel->next;
      sentinel->next = p;
    }

    sentinel = (sl_node*)malloc(sizeof(sl_node));
    init_node(sentinel, -1, 1);
    sentinel->down = list->head;
    list->head = sentinel;

    sl_node *p = (sl_node*)malloc(sizeof(sl_node));
    init_node(p, 1, 1);

    list->head->next = p;
    p->down = list->head->down->next;

    print_list(list);

    if((p = find(list, 1)) != NULL) printf("found\n");
    else printf("not found\n");
  }
  /* test case 2 */
  /* insertion test */
  if(cas == 2) {

    int i;
    for(i = 0; i < 20; i++)
      insert(list, getRand(0, 1000));

    if((find(list, 1)) != NULL) printf("found\n");
    else printf("not found\n");
    print_list(list);
  }

  return 0;
}
