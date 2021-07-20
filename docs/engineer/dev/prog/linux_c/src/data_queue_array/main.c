#include <stdio.h>

#define QSIZE 5

int queue[QSIZE];
int head, tail;

void init();
int isFull();
int isEmpty();
void enqueue();
void dequeue();
void display();
void release();

int main()
{
	int choice;

	printf("陣列佇列測試程式(可儲存資料筆數%d)\n", QSIZE+1);

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
	head = tail = 0;
}

int isFull()
{
	if((tail+1)%QSIZE == head)
	{
		printf("佇列已滿\n");
		return 1;
	}
	return 0;
}

int isEmpty()
{
	if(head%QSIZE == tail%QSIZE)
	{
		printf("佇列已空\n");
		return 1;
	}
	return 0;
}

void enqueue()
{
	int d;

	if(!isFull())
	{
		printf("請輸入資料 ");
		scanf("%d",&d);
		tail++;
		tail%=QSIZE;
		queue[tail] = d;
	}
}


void dequeue()
{
	if(!isEmpty())
	{
		head++;
		head%=QSIZE;
		printf("刪除資料 %d\n",queue[head]);
	}
}

void display()
{
	for(int i = (head+1)%QSIZE; i != (tail+1)%QSIZE;)
	{
		printf("%d ",queue[i]);
		i++;
		i%=QSIZE;
	}
	printf("\n");
}

void release()
{
	for(int i = (head+1)%QSIZE; i != (tail+1)%QSIZE;)
	{
		queue[i]=-1;
		i++;
		i%=QSIZE;
	}
}

