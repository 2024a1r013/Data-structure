#include <stdio.h>
#include <stdlib.h>
#define max 100 
int list[max],top=-1;
int isEmpty()
{
    return (top == -1) ? 1 : 0;
}
int isfull()
{
    return (top == max-1) ? 1 : 0 ;
}
int push()
{
    if(isfull())
    {
        printf("stack overflow !!");
    }
    else
    {
        int data ;
        scanf("%d",&data);
        top = top + 1 ;
        list[top]=data;
    }
    return 0;
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack is empty !!");
    }
    else
    {
        list[top];
        top = top - 1;
    }
    return 0;
}
int display ()
{
    for (int i=top ; i>=0 ; i--)
    {
        printf("%d ",list[i]);
    }
    return 0;
}
int main ()
{
    push();
    push();
    push();
    pop();
    push();
    push();
    pop();
    pop();
    pop();
    display();
    return 0;
}
