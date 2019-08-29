#include <stdio.h>
#define MAX 5

typedef struct stack
{
  int s[MAX];
  int tos;
}stack;

void push(stack *t, int ele)
{
  if(t -> tos == MAX - 1)
  {
    printf("Stack Overflow\n");
  }
  t -> tos++;
  t -> s[t -> tos] = ele;
}

int isempty(stack *t)
{
  if(t -> tos == -1)
    return 1;
  else
    return 0;
}

int pop(stack *t)
{
  int z;
  if(isempty(t))
  {
    printf("Stack Underflow\n");
    return -1;
  }
  z = t -> s[t -> tos];
  t -> tos--;
  return z;
}

int stacktop(stack *t)
{
  if(isempty(t))
  {
    printf("Stack Empty\n");
    return -1;
  }
  return(t -> s[t -> tos]);
}

void display(stack *t)
{
  int i;
  if(isempty(t))
  {
    printf("Stack Empty\n");
    return;
  }
  for(i = t -> tos; i >= 0; i--)
    printf("%d ", t -> s[i]);
  printf("\n");
  return;
}

void main()
{
  stack x;
  int ch, ele;
  x.tos = -1;

  while(1)
  {
    printf("\nMenu: 1. Push   2. Pop   3. Stacktop   ");
    printf("4. Display   5. Exit\n");
    printf("Enter Choice: ");
    scanf("%d", &ch);

    if(ch == 5)
      break;

    switch(ch)
    {
      case 1: printf("Enter Element to be Pushed: ");
              scanf("%d", &ele);
              push(&x, ele);
              display(&x);
              break;
      case 2: if(isempty(&x))
                printf("Underflow\n");
              else
              {
                ele = pop(&x);
                printf("Popped Element: %d\n", ele);
                display(&x);
              }
              break;
      case 3: if(isempty(&x))
                printf("Stack Empty\n");
              else
              {
                ele = stacktop(&x);
                printf("Stacktop: %d\n", ele);
                display(&x);
              }
              break;
      case 4: printf("Stack: ");
              display(&x);
              break;
      default: printf("Invalid Choice\n");
    }
  }
}
