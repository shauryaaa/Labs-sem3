 #include<stdio.h>
 #include<stdlib.h>
 #define SIZE 10
 struct stack{
 	int a[SIZE];
 	int top;
 };
 int push(struct stack*s,int x)
 {
     int a;
 	if(s->top==(SIZE-1))
	 {
	 
 	printf("overflow\n");
 	return 0;
	 }
 	
 	else
 	{s->top++;
 	    s->a[s->top]=x;
 	return s->a[s->top];
 	}
 }
 int pop(struct stack*s)
 {
 	if(s->top==-1)
 	{
 		printf("underflow\n");
 		return 0;
	 }
	 else
	 return s->a[s->top--];
 }
 void display(struct stack*s)
 {
 
 int i;
 if(s->top==-1)
 {
 	printf("empty\n");
 	return;
 }
 else{
 for(i=0;i<=(s->top );i++)
 {
 	printf("%d\n",s->a[i]);
 }
 }
 return;
}
 
 int main()
 {struct stack s,s1;
 int a,b,x,x1,i,x2,x3;
 s.top=-1;
 s1.top=-1;
 printf("press 1-push\n2-pop\n3-3rd element from top\n4-3rd element from bottom\n5-pop n elements\n");
  while(1)
 {
 scanf("%d",&a);
 
 switch(a)
 {
 	case 1:
 		printf("enter elemets to push\n");
 		scanf("%d",&x);
 		b=push(&s,x);
		 printf("pushed element is %d\n",b);
		 break;
		 case 2:
		 	a=pop(&s);
		 	printf("poped element is %d\n",a);
		 	break;
		 	case 3:
		 		if(s.top<=1)
		 		{printf("command cannot be executed\n");
		 		break;
				 }
				 else
				 {
				 	x1=pop(&s);
				 	x2=pop(&s);
				 	x3=pop(&s);
				 	printf("3rd element from top is %d\n",x3);
				    push(&s,x3);
				 	push(&s,x2);
				 	push(&s,x1);
				 	display(&s);
				 	break;
				 }
				 case 4:
				 	if(s.top<=1)
				 	{printf("command cannot be executed\n");
				 	break;
					 }
					 else
					 {
					 	while(s.top!=2)
					 	{
					 		a=pop(&s);
					 		b=push(&s1,a);
						 }
						 b=pop(&s);
						 printf("3rd element from bottom %d",b);
						 a=push(&s1,b);
						 while(s1.top!=-1)
						 {
						 	a=pop(&s1);
						 	b=push(&s,a);
						 }
						 display(&s);
						 break;
					 }
					 case 5:
					 	printf("enter no. of elements to popped\n");
					 	scanf("%d",&a);
					 	if(s.top<(a-1))
					 	{
					 		printf("false input\n");
					 		break;
						 }
						 else
						 {
						 	for(i=0;i<a;i++)
						 	{
						 		b=pop(&s);
						 		printf("elements popped is %d",b);
						 		i++;
						 		break;
						 	 
							 }
						 }
						 case 6:
						 display(&s);
						 break;
} }
 	return 0;
 }
