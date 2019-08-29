#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct queue
{
	int q[MAX];
	int f, r, cnt;
}queue;

void insert(queue *t, int ele)
{
	if(t -> cnt == MAX)
	{
		printf("Queue Overflow\n");
		return;
	}
	t -> cnt++;
	t -> r = (t -> r + 1) % MAX;
	t -> q[t -> r] = ele;
}

int isempty(queue *t)
{
	if(t -> cnt == 0)
		return 1;
	else
		return 0;
}

int delete1(queue *t)
{
	int z;
	if(isempty(t))
	{
		printf("Queue Underflow\n");
		return -1;
	}
	t -> cnt--;
	z = t -> q[t -> f];
	t -> f = (t -> f + 1) % MAX;
	return z;
}

int queuefront(queue *t)
{
	int z;
	if(isempty(t))
	{
		printf("Queue Empty\n");
		return -1;
	}
	t -> f = (t -> f + 1) % MAX;
	return z;
}

void display(queue *t)
{
	int i;
	if(isempty(t))
	{
		printf("Queue Empty\n");
		return;
	}
	for(i = t -> f; i <= t -> r; i = (i + 1) % MAX)
		printf("%d ", t -> q[i]);
	printf("\n");
	return;
}

void main()
{
	queue x;
	int ele, ch;
	x.f = 0;
	x.r = MAX - 1;
	x.cnt = 0;

	while(1)
	{
		printf("\nMenu: 1. Insert  2. Delete  3. Queue Front  ");
		printf("4. Display  5. Exit\n");
		printf("Choice: ");
		scanf("%d", &ch);

		if(ch == 5)
			break;
		switch(ch)
		{
			case 1: printf("Enter Element to be Inserted: ");
							scanf("%d", &ele);
							insert(&x, ele);
							display(&x);
							break;
			case 2: if(isempty(&x))
								printf("Queue Underflow\n");
							else
							{
								ele = delete1(&x);
								printf("Deleted Element: %d\n", ele);
								display(&x);
							}
							break;
			case 3: if(isempty(&x))
								printf("Queue Empty\n");
							else
							{
								ele = queuefront(&x);
								printf("Queue Front: %d\n", ele);
								display(&x);
							}
							break;
			case 4: printf("Queue: ");
							display(&x);
							break;
			default: printf("Invalid Choice\n");
		}
	}
}
