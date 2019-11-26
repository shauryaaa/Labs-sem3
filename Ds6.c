#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 

 struct node
{
  int row, col, num;
  struct node *prev;
  struct node *next;
};

 
struct node *head = NULL;

struct node *getnode ()
{
  struct node *x;
  x = (struct node *) malloc (sizeof (struct node));
  if (x == NULL)
    {
      printf ("Out of RAnge\n");
      exit (0);
    }
  return x;
}
void insert (int row, int col, int num)
{
  struct node *newnode, *temp;
  newnode = getnode ();
  newnode->row = row;
  newnode->col = col;
  newnode->num = num;
  newnode->next = NULL;
  newnode->prev = NULL;

if (head == NULL)
    head = newnode;
  else
    {
      temp = head;
      while (temp->next != NULL)
	temp = temp->next;
      temp->next = newnode;
      newnode->prev = temp;
    }
}
void  display (int r, int c)
{
  struct node *temp;
  int i, j;
if (head == NULL)
    {
      printf ("List empty\n");
      return;
    }
  else
    {				/*If row and column matches with an entry in the LL, then print the value else print 0 */
      
 
for (i = 0; i < r; i++)
	{
	  for (j = 0; j < c; j++)
	    {
	      temp = head;
	      while (temp != NULL)
		{
		  if (temp->row == i && temp->col == j)
		    {
		      printf ("%d\t", temp->num);
		      break;
		    }
		  temp = temp->next;
		}
	      if (temp == NULL)
		printf ("0\t");
	    }
	  printf ("\n");
	}
    }
}


 
int  main ()
{
  int arr[80][80], i, j, m, n, row, col, num, ct = 0;
  struct node *temp;
 printf ("Enter row number & columns: ");
  scanf ("%d%d", &m, &n);
  /*Read non-zero values in matrix and insert into LL*/
printf ("Enter number of entries in matrix");
  scanf ("%d", &ct);
  for (i = 0; i < ct; i++)
    {
      printf ("Enter the row, col and num");
      scanf ("%d%d%d", &row, &col, &num);
      insert (row, col, num);
    }
/*Display complete matrix*/
printf ("sparse matrix is: \n");
  display (m, n);
}
