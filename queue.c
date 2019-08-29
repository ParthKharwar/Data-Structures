#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct queue
{
	int q[MAX];
	int f, r;
}queue;

void insert(queue *t, int ele)
{
	if(t -> r == MAX - 1)
	{
		printf("Queue Overflow\n");
		return;
	}
	t -> r++;
	t -> q[t -> r] = ele;
}

int isempty(queue *t)
{
	if(t -> f == t -> r + 1)
		return 1;
	else
		return 0;
}

int delete1(queue *t)
{
	int max, pos, i;
	if(isempty(t))
	{
		printf("Queue Underflow\n");
		return -1;
	}
	max = t -> q[t -> f];
	pos = t -> f;
	for(i = t -> f + 1; i <= t -> r; i++)
	{
		if(t -> q[i] > max)
		{
			max = t -> q[i];
			pos = i;
		}
	}
	for(i = pos; i <= t -> r; i++)
		t -> q[i] = t -> q[i + 1];
	t -> r--;
	return max;
}

int queuefront(queue *t)
{
	int z;
	if(isempty(t))
	{
		printf("Queue Empty\n");
		return -1;
	}
	return (t -> q[t -> f]);
}

void display(queue *t)
{
	int i;
	if(isempty(t))
	{
		printf("Queue Empty\n");
		return;
	}
	for(i = t -> f; i <= t -> r; i++)
		printf("%d ", t -> q[i]);
	printf("\n");
}

void main()
{
	queue x;
	int ele, ch;
	x.f = 0;
	x.r = -1;

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
