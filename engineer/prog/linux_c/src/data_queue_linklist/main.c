#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAXSTR 50

typedef struct _node * pnode;

struct _node{
	char name[MAXSTR];
	char phone[MAXSTR];
	pnode next;
}node;

pnode head, tail;

void init();
void enqueue();
void dequeue();
void display();
void release();

int main()
{
	int choice;

	printf("鍊結串列佇列測試程式\n");

	while(1)
	{
		printf("1) 新增\t2) 刪除\t3) 顯示\t0) 結束 : ");
		scanf("%d",&choice);

		if(!choice)
			break;

		switch(choice)
		{
			case 1:		enqueue();	break;
			case 2:		dequeue();	break;
			case 3:		display();	break;
			default:	display();	break;
		}
	}
	printf("清空串列\n");
	release();

	return 0;
}

void init()
{
	head = tail = NULL;
}

void enqueue()
{
	pnode p = (pnode)malloc(sizeof(node));

	if(p)
	{
		printf("請輸入姓名 ");
		scanf("%s", p->name);
		printf("請輸入電話 ");
		scanf("%s", p->phone);
		p->next = NULL;
		if(head)
		{
			tail->next = p;
			tail = p;
		}
		else
		{
			head = tail = p;
		}
	}
	else
	{
		printf("無法取得記憶體空間新增資料\n");
	}
}


void dequeue()
{
	pnode p;

	if(head)
	{
		p = head;
		if(head->next)
			head = head->next;
		else
			head = tail = NULL;
		printf("刪除資料姓名 %s 電話 %s\n", p->name, p->phone);
		free(p);
	}
	else
	{
		printf("串列已空\n");
	}
}

void display()
{
	pnode p;
	p = head;

	while(p)
	{
		printf("姓名 %s 電話 %s\n", p->name, p->phone);
		p = p->next;
	}
}

void release()
{
	pnode p;

	tail = NULL;
	while(head)
	{
		p = head;
		head = head->next;
		free(p);
	}
}