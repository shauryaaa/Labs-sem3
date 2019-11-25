#include<stdio.h> 
#include<stdlib.h>
#define MAXSIZE 10 
struct stack 
{ 
    int st[MAXSIZE];
    int top 
    
}; 

 void push (struct stack *s, int x)
{
  if (s->top == (MAXSIZE - 1))
    printf ("stack overflow");
  else
    {
      s->top++;
      s->st[s->top] = x;
    }
}


 
int pop (struct stack *s)
{
  int temp;
  if (s->top == -1)
    printf ("stack underflow");
  else
    {
      temp = s->st[s->top];
      s->top--;
    }
  return temp;
}


 
void poptopthird (struct stack *s)
{
  struct stack temp;
  int i, t;
  temp.top = -1;
  if (s->top < 2)
    {
      printf ("No sufficient elements");
      return;
    }
  for (i = 0; i < 2; i++)
    {
      t = pop (s);
      push (&temp, t);
    }
  t = pop (s);
  printf ("the third element from top is %d", t);
  push (s, t);
  if (temp.top != -1)
    {
      for (i = 0; i < 2; i++)
	{
	  t = pop (&temp);
	  push (s, t);
	}
    }
}


 
void popbottomthird (struct stack *s)
{
  struct stack temp;
  int k, t, i;
  temp.top = -1;
  k = s->top;
  if (s->top < 2)
    {
      printf ("No sufficient elements");
      return;
    }
  for (i = k; i > 2; i--)
    {
      t = pop (s);
      push (&temp, t);
    }
  t = pop (s);
  printf ("the third from bottom is %d", t);
  push (s, t);
  if (temp.top != -1)
    {
      
 
for (i = temp.top; i >= 0; i--)
	{
	  t = pop (&temp);
	  push (s, t);
	}
    }
}


 
void
display (struct stack s)
{
  int i;
  for (i = 0; i <= s.top; i++)
    printf ("%d\n", s.st[i]);
}


 
void
main ()
{
  int ch, x, k, i;
  struct stack s;
  s.top = -1;
  while (1)
    {
      printf ("Enter choice");
      printf
	("1:push, 2: pop, 3: thirdfromtop, 4:thirdfrombottom, 5: display 6:popnelements 7:exit\n");
      scanf ("%d", &ch);
    switch (ch)
	{
	case 1:
	  printf ("Enter the element to be inserted\n");
	  scanf ("%d", &x);
	  push (&s, x);
	  break;
	case 2:
	  x = pop (&s);
	  printf ("poped element is %d\n", x);
	  break;
	case 3:
	  poptopthird (&s);
	  break;
	case 4:
	  popbottomthird (&s);
	  break;
	case 6:
	  printf ("Enter number of elements to be poped\n");
	  scanf ("%d", &k);
	  for (i = 0; i < k; i++)
	    {
	      x = pop (&s);
	      if (s.top != -1)
		printf ("poped element is %d\n", x);
	    }
	  break;
	case 5:
	  display (s);
	  break;
	case 7:
	  exit (0);
	  break;
	}
    }
}
