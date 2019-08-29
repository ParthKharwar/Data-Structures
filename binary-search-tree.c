#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

typedef struct head
{
	node *root;
}head;

node *father(head *t, node *p)
{
	node *q;
	if(p==t->root)
		return NULL;
	q = t -> root;
	while(q != NULL)
	{
		if(q -> left == p || q -> right == p)
			return q;
		if(p -> data <= q -> data)
			q = q-> left;
		else
			q = q -> right;
	}
	return NULL;
}

void insert(head *t, int ele)
{
	node *p, *q;
	p = (node *)malloc(sizeof(node));
	p -> data = ele;
	p -> left = p -> right = NULL;
	if(t -> root == NULL)
	{
		t -> root = p;
		return;
	}
	q = t -> root;
	while(q != NULL)
	{
		if(ele <= q -> data)
			if(q -> left == NULL)
			{
				q -> left = p;
				return;
			}
			else
				q = q -> left;
		else if(q -> right == NULL)
		{
			q -> right = p;
			return;
		}
		else
			q = q -> right;
	}
}

int search(head *t, int ele)
{
	node *q = t -> root;
	while(q != NULL)
	{
		if(ele == q -> data)
			return 1;
		if(ele < q -> data)
			q = q -> left;
		else
			q = q -> right;
	}
	return 0;
}

node *findmax(node *r)
{
	if(r -> right == NULL)
		return r;
	else
		return findmax(r -> right);
}

void delete1(head *t, int ele)
{
	node *q, *f;
	if(t -> root == NULL)
	{
		printf("Binary Search Tree Empty\n");
		return;
	}
	q = t -> root;
	while(q != NULL)
	{
		if(ele == q -> data)
			break;
		if(ele < q -> data)
			q = q -> left;
		else
			q = q -> right;
	}
	if(q == NULL)
	{
		printf("%d Not Found\n",ele);
		return;
	}
	if(q -> left == NULL && q -> right == NULL)
	{
		if(q == t -> root)
		{
			t -> root == NULL;
			return;
		}
		f = father(t, q);
		if(f -> left == q)
			f -> left = NULL;
		else
			f -> right = NULL;
		return;
	}
	if(q -> left != NULL)
	{
		int val;
		node *max = findmax(q -> left);
		val = max -> data;
		delete1(t, max -> data);
		q -> data = val;
		return;
	}
	if(q == t -> root)
	{
		t -> root = t -> root -> right;
		return;
	}
	f = father(t, q);
	if(f -> left == q)
		f -> left = q -> right;
	else
		f -> right = q -> right;
}

void inorder(node *x)
{
	if(x != NULL)
	{
		inorder(x -> left);
		printf("%d ", x -> data);
		inorder(x -> right);
	}
}

void postorder(node *x)
{
	if(x != NULL)
	{
		postorder(x -> left);
		postorder(x -> right);
		printf("%d ", x -> data);
	}
}

void preorder(node *x)
{
	if(x != NULL)
	{
		printf("%d ", x -> data);
		preorder(x -> left);
		preorder(x -> right);
	}
}

void main()
{
	head x;
	int ch, ele;
	x.root = NULL;
	while(1)
	{
		printf("\nMenu:\n");
		printf("1. Insert  2. Delete  3. Search  4. Inorder\n5. Postorder  6. Preorder  7. Exit\n");
		printf("Enter Choice: ");
		scanf("%d", &ch);

		if(ch == 7)
			break;

		switch(ch)
		{
			case 1: printf("Enter Element to Insert: ");
							scanf("%d", &ele);
							insert(&x, ele);
							inorder(x.root);
							printf("\n");
							break;
			case 2: printf("Enter Element to Delete: ");
							scanf("%d", &ele);
							delete1(&x, ele);
							inorder(x.root);
							printf("\n");
							break;
			case 3:	printf("Enter Element to Search: ");
							scanf("%d", &ele);
							if(search(&x, ele))
								printf("Element Found\n");
							else
								printf("Element Not Found\n");
							break;
			case 4: inorder(x.root);
							printf("\n");
							break;
			case 5: postorder(x.root);
							printf("\n");
							break;
			case 6: preorder(x.root);
							printf("\n");
							break;
			default: ("Invalid Choice\n");
		}
	}
}
