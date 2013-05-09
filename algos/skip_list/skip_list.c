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

/* a better search func */
sl_node *find1(const sl_head *list, const int key) {

  sl_node *p = list->head;

  while(p != NULL) {
    while(p->next != NULL && key > p->next->data)
      p = p->next;

    /* if the node is found */
    if(p->next != NULL && key == p->next->data) {
      p = p->next;
      /* get down to base level */
      while(p->down != NULL)
	p = p->down;
      return p;
    }
    p = p->down;
  }
  return NULL;
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

/* constructor for sl_node */
sl_node *new_node(int k, int h, sl_node *n, sl_node *d) {

  sl_node *p = (sl_node*)malloc(sizeof(sl_node));
  p->data = k;
  p->height = h;
  p->next = n;
  p->down = d;

  return p;
}

/* insert into a skip list */
/* bottom up approach */
int insert(sl_head *list, int key) {

  sl_node *path[list->height + 1];
  sl_node *p = list->head;
  sl_node *down = NULL;
  int i = 0;

  while(p != NULL) {
    while(p->next != NULL && key > p->next->data)
      p = p->next;
    if(p->next != NULL && key == p->next->data)
      return 1;
    path[p->height] = p;
    p = p->down;
  }

  /* insert from the base level */
  p = path[0];
  do {
    /* if it's a new height, create a sentinel node */
    if(i > list->height)
      p = list->head = new_node(-1, i, NULL, list->head);

    /* insertion */
    p->next = new_node(key, i++, p->next, NULL);

    if(down != NULL)
      p->next->down = down;
    down = p->next;

    if(i <= list->height)
      p = path[i];
  } while(getRand(0, 2) > 1);

  /* update the list height */
  list->height = list->head->height;

  /* direct link to the base list */
  if(list->bottom == NULL) {
    list->bottom = list->head;
    while(list->bottom->down != NULL)
      list->bottom = list->bottom->down;
  }

  return 0;
}

/* delete the node containing key */
/* up down approach */
int delete(sl_head* list, int key) {

  sl_node *p = list->head;
  sl_node *to_delete = NULL;

  while(p != NULL) {
    /* go 'right' */
    while(p->next != NULL && key > p->next->data)
      p = p->next;

    /* if the next one is the node, delete it */
    if(p->next != NULL && p->next->data == key) {
      to_delete = p->next;
      p->next = p->next->next;
      free(to_delete);
    }

    /* continue to next level */
    p = p->down;
  }

  return 0;
}

/* print */
/* print a skip list with all its levels */
void print_list(const sl_head *list) {

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

    print_list(list);
  }

  return 0;
}
