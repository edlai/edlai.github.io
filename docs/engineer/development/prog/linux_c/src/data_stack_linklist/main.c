typedef struct _node *pnode;

struct _node
{
  int data;
  pnode next;
} node;

pnode head;

void init();
void push();
void pop();
void display();
void release();

int main()
{
  int choice;

  init();

  printf("串列堆疊測試程式\n");

  while (1)
  {
    printf("1) 新增\t2) 刪除\t3) 顯示\t0) 結束 : ");
    scanf("%d", &choice);

    if (!choice)
      break;

    switch (choice)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    default:
      display();
      break;
    }
  }
  printf("清空堆疊\n");
  release();

  return 0;
}

void init()
{
  head = NULL;
}

void push()
{
  int d;
  pnode p = (pnode)malloc(sizeof(node));

  printf("請輸入資料(整數) ");
  scanf("%d", &d);

  p->data = d;
  p->next = head;
  head = p;
}

void pop()
{
  pnode p;

  if (head)
  {
    p = head;
    head = head->next;
    printf("刪除 %d \n", p->data);
    free(p);
  }
  else
  {
    printf("堆疊是空的\n");
  }
}

void display()
{
  pnode p = head;

  while (p)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void release()
{
  pnode p;
  while (head)
  {
    p = head;
    head = head->next;
    free(p);
  }
}
