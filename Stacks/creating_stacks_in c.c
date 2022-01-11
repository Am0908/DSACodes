#include <stdlib.h>
#include <stdio.h>

struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *st)
{
    printf("Enter size of stack:");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int*)malloc(st->size*sizeof(int));
}

void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
    printf("stack overflow!");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct stack *st)
{
    int x=-1;
    if(st->top!=-1)
    {
        x=st->s[st->top];
        st->top--;
    }
    else
    printf("stack underflow");
    return x;
}

void display(struct stack st)
{
    while(st.top>=0)
    {
        printf("%d ",st.s[st.top]);
        st.top--;
    }
    printf("\n");
}

int isempty(struct stack st)
{
    if(st.top==-1)
    return 1;
    return 0;
}

int isfull(struct stack st)
{
    return (st.top==st.size-1);
}

void stacktop(struct stack st)
{
    if(st.top!=-1)
    printf("%d\n",st.s[st.top]);
}
int main()
{
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    display(st);
    printf("%d\n",isfull(st));
    stacktop(st);
    return 0;
}
