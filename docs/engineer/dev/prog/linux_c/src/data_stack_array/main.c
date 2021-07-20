#define ASIZE 5

int stack[ASIZE]={0};
int top=-1;

void push();
void pop();
void display();
void release();

int main()
{
	int choice;

	printf("陣列堆疊測試程式(可儲存資料筆數%d)\n", ASIZE+1);

	while(1)
	{
		printf("1) 新增\t2) 刪除\t3) 顯示\t0) 結束 : ");
		scanf("%d",&choice);

		if(!choice)
			break;

		switch(choice)
		{
			case 1:		push();		break;
			case 2:		pop();		break;
			case 3:		display();	break;
			default:	display();	break;
		}
	}
	printf("清空堆疊\n");
	release();

	return 0;
}

void push()
{
	int d;

	if(top < ASIZE)
	{
		printf("請輸入資料(整數) : ");
		scanf("%d",&d);
		top++;
		stack[top] = d;
	}
	else
	{
		printf("堆疊滿了\n");
	}
}


void pop()
{
	if(top >= 0)
	{
		printf("%3d\n",stack[top]);
		top--;
	}
	else
	{
		printf("堆疊是空的\n");
	}
}

void display()
{
	int pos = top;
	while(pos >= 0)
	{
		printf("%3d ",stack[pos]);
		pos--;
	}
	printf("\n");
}

void release()
{
	while(top >= 0)
		pop();
}
