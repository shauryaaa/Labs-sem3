 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define SIZE 20
struct stack{
        char a[SIZE];
        int top;

};
void push(struct stack *s,char x)
{
        if(s->top==(SIZE-1))
        {
                printf("overflow\n");
                return;
        }
        else
        {
                s->a[++s->top]=x;
                return;
        }
}
char pop(struct stack *s)
{
        if(s->top==-1){
                printf("underflow");
                return 0;
        }
        else
        return s->a[s->top--];
}
int stackempty(struct stack *s)
{
        if(s->top==-1)
                return 1;
        return 0;
}
char stacktop(struct stack *s)
{if(s->top==-1)
        {printf("underflow");
                exit(0);
        }
        return s->a[s->top];
}
int precd(char symb)
{
         if(symb=='(')
         return 0;
        if(symb=='+'||symb=='-')
                return 1;
        if(symb=='*'||symb=='/')
                return 2;
        if(symb=='^')
                return 3;
}
void itp(char infix[20],char postfix[20])
{
        int i,w,j=0;
        int a;
                char symb,topsymb;
                struct stack s;
                s.top=-1;
        for(i=0;infix[i]!='\0';i++)
        {symb=infix[i];
                if(symb>='a'&& symb<='z')
                        postfix[j++]=symb;
                else if(symb=='(')
                        push(&s,symb);
                else if(symb==')')
                {
                        while((topsymb=pop(&s))!='(')
                        {postfix[j++]=topsymb;
                        }
                         
                }
                        else
                        {
                                while(!stackempty(&s) && (precd(symb)<=precd(stacktop(&s))))
                                                {
                                                postfix[j++]=pop(&s);
                                                }
                                                push(&s,symb);
                        }
                        }while(!stackempty(&s))
                        {postfix[j++]=pop(&s);
                        }
                        postfix[j]='\0';
                        printf("%s",postfix);
}
int main()
{
    char infix[20],postfix[20];
    printf("enter\n");
    scanf("%s",infix);
    printf("\n");
    itp(infix,postfix);
    return 0;
}
