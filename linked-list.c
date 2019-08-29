#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct head
{
	node *start;
}head;

void insertbeg(head *t, int ele)
{
	node *p;
	p = (node *)malloc(sizeof(node));
	p -> data = ele;
	p -> next = NULL;
	if(t -> start == NULL)
	{
		t -> start = p;
		return;
	}
	p -> next = t -> start;
	t -> start = p;
}

void insertend(head *t, int ele)
{
	node *p, *q;
	p = (node *)malloc(sizeof(node));
	p -> data = ele;
	p -> next = NULL;
	if(t -> start == NULL)
	{
		t -> start = p;
		return;
	}
	q = t -> start;
	while(q -> next != NULL)
		q = q -> next;
	q -> next = p;
}

void deleteele(head *t, int ele)
{
	node *q;
	if(t -> start == NULL)
	{
		printf("Linked List Empty\n");
		return;
	}
	if(t -> start -> data == ele)
	{
		t -> start = t -> start -> next;
		return;
	}
	q = t -> start;
	while(q -> next != NULL)
	{
		if(q -> next -> data == ele)
			break;
		else
			q = q -> next;
	}
	if(q -> next == NULL)
		printf("%d Not Found\n", ele);
	else
		q -> next = q -> next -> next;
}

void display(head *t)
{
	node *q = t -> start;
	if(t -> start == NULL)
	{
		printf("Linked List Empty\n");
	}
	while(q != NULL)
	{
		printf("%d ", q -> data);
		q = q -> next;
	}
	printf("\n");
}

void reverse(head *t)
{
	node *p, *q, *r;
	p = NULL;
	q = t -> start;
	while(q != NULL)
	{
		r = q -> next;
		q -> next = p;
		p = q;
		q = r;
	}
	t -> start = p;
}

int count(head *t)
{
	int c = 0;
	node *q = t -> start;
	while(q != NULL)
	{
		c++;
		q = q -> next;
	}
	return c;
}

int search(head *t, int ele)
{
	node *q = t -> start;
	while(q != NULL)
	{
		if(q -> data == ele)
			return 1;
		else
			q = q -> next;
	}
	return 0;
}

void main()
{
	head x;
	int ch, ele;
	x.start = NULL;
	while(1)
	{
		printf("\nMenu:\n1. Insert Beginning  2. Insert End  ");
		printf("3. Delete Element  4. Display\n");
		printf("5. Reverse List  6. Count  7. Search  8. Exit\n");
		printf("Choice: ");
		scanf("%d", &ch);
		if(ch == 8)
			break;
		switch(ch)
		{
			case 1: printf("Enter Element to be Inserted: ");
			        scanf("%d", &ele);
		 	        insertbeg(&x, ele);
		 	        display(&x);
			        break;
			case 2: printf("Enter Element to be Inserted: ");
        			        scanf("%d", &ele);
        		 	        insertend(&x, ele);
        		 	        display(&x);
        			        break;
			case 3: printf("Enter Element to be Deleted: ");
        			        scanf("%d", &ele);
        		 	        deleteele(&x, ele);
        		 	        display(&x);
        			        break;
			case 4: printf("Linked List: ");
                		        display(&x);
			        break;
			case 5: printf("Linked List: ");
        			        display(&x);
			        reverse(&x);
			        printf("Linked List: ");
			        display(&x);
		                   break;
			case 6: ele = count(&x);
			        printf("Number of Nodes: %d\n", ele);
			        break;
			case 7: printf("Enter Element to be Searched: ");
			        scanf("%d", &ele);
			        if(search(&x, ele))
			                printf("Element Found\n");
			        else
			        	     printf("Element Not Found\n");
			        break;
			default: printf("Invalid Choice\n");
		}
	}
}
