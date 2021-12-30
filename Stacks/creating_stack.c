// function for stack

#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    struct node **s;
};

void stackcreate(struct stack *st,int size)
{
   st->size=size;
   st->top=-1;
   st->s=(struct node **)malloc(st->size*sizeof(struct node *));
}

void push(struct stack *st,struct node *x)
{
    if(st->top==st->size-1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

struct node *pop(struct stack *st)
{
    struct node *x=NULL;
    if(st->top==-1)
    printf("Stack Underflow\n");
    else
    {
        x=st->s[st->top--];
    }
    return x;
}

int isemptystack(struct stack st)
{
    if(st.top==-1)
    return 1;
    return 0;
}

int isfullstack(struct stack st)
{
    return st.top==st.size-1;
}

int main()
{

    return 0;
}
