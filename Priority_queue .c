#include <stdio.h>
#include <stdlib.h>
//typedef :- It is used to give type defination
#define SIZE 100
typedef struct PriorityQueue
{
    int element;
    int priority;
}PQueue;
PQueue pq[SIZE];
int front = -1,rear = -1;

int isEmpty()
{
    return (front == -1) ? 1 : 0;
}
int isFull()
{
    return (rear == SIZE-1) ? 1 : 0;
}
void enqueue(int data, int priority)
{
    int i;
    if(isEmpty())
    {
        rear = rear+1;
        pq[rear].element = data;
        pq[rear].priority = priority;
        front = rear;
    }
    else
    {
        for(i=front;i>=rear;i++)
        {
            if(pq[i].priority < priority)
            {
                for(int j=rear;j>=i;j--)
                {
                    pq[j+1].element = pq[j].element;
                    pq[j+1].priority = pq[j].priority;
                }
                pq[i].element = data;
                pq[i].priority = priority;
                rear++;
                break;
            }
        }
        if(i==(rear+1))
        {
            rear = rear+1;
            pq[rear].element = data;
            pq[rear].priority = priority;
        }
    }
    printf("Element Inserted !!!\n");
}

int dequeue(){
   int data =pq[front].element;
   if(front==rear){
    front = rear-1;
   }
   else{
   front = front+1;
   }
   return data;
}
int peek()
{
    return pq[front].element;
}
void display()
{
    printf("Elements of Priority Queue are :\n");
    for(int i=front;i<=rear;i++)
    {
        printf("Element :- %d => Priority :- %d\n",pq[i].element,pq[i].priority);
    }
}
int main()
{
    while (1)
    {
        printf("---------Priority Queue----------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        int choice, data, priority;
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if(isFull())
                {
                    printf("Queue Overflow !!!\n");
                }
                else
                {
                    printf("Enter Element : ");
                    scanf("%d",&data);
                    printf("Enter Priority : ");
                    scanf("%d",&priority);
                    enqueue(data, priority);
                }
                break;
            case 2:
                if(isEmpty())
                    printf("Queue Underflow !!!\n");
                else{
                    printf("%d is Dequeued from the Queue.\n",dequeue(data));
                break;}
            case 3:
                if(isEmpty())
                    printf("Queue is Empty!!!\n");
                else
                    printf("Element available in front of the Queue is %d.\n",peek());
                break;
            case 4:
                if(isEmpty())
                    printf("Queue is Empty!!!\n");
                else
                    display();
                break;
            case 5:
                exit(0);
            default:
            printf("Invalid Choice !!!\n");
        }
        printf("\n");
    }
}
