#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

struct queue{
    int dynamic_array[MAX_SIZE];
    int front, rear;
};

struct queue* queue_initializer()
{
    struct queue* queue = (struct queue*) malloc(sizeof(struct queue));
    
    if (queue != NULL)
    {
        queue->front = -1;
        queue->rear = -1;

        printf("\n**Queue ready for use**\n");
        return queue;    
    }

    printf("\n**Memory allocation failure! Cannot initialize queue**\n");
    return NULL;
}

void enqueue(struct queue* queue, int new_node_data)
{
    if (queue->rear == MAX_SIZE-1)
    {
        printf("\n**queue is FULL. Element addition ABORTED!**\n");
        return;
    }
    
    if (queue->front == -1 && queue->rear == -1)
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear++;
    }

    queue->dynamic_array[queue->rear] = new_node_data;
    printf("\n**Element addition to the Queue Successful**\n");
}

void dequeue(struct queue* queue) {
    if (queue->front == -1) {
        printf("\n**Queue is EMPTY. Nothing to dequeue**\n");
        return;
    }

    if (queue->front > queue->rear) 
    {
        queue->front = -1;
        queue->rear = -1;
        printf("\n**queue front pointer exceeded beyond specified length. Pointers Reset to original values**\n");
    }
    else
    {
        queue->front++;
        printf("\n**Element Deletion from the Queue successful**\n");
    }
}

void display_queue(struct queue* queue)
{
    struct queue* ptr = queue;

    if (ptr->front == -1)
    {
        printf("\n**queue is empty**\n");
        return;
    }
    
    printf("\nfront-> ");
    for (int i = ptr->front ; i <= ptr->rear ; i++)
    {
        printf("%d -> ", ptr->dynamic_array[i]);
    }
    printf("rear\n");
}

void get_topmost_or_rearmost_element(struct queue* queue)
{
    int mode;
    printf("Please select which element you want to check:\n1.Front-most element \n2.Rear-most element\n");
    scanf("%d", &mode);

    if (mode > 2 || mode < 1)
    {
        printf("please enter a valid input. \'%d\' is not a valid input!\n", mode);
    }
    else if (mode == 1)
    {
        printf("front-most element = %d\n", queue->dynamic_array[queue->front]);
    }
    else {
        printf("rear-most element = %d\n", queue->dynamic_array[queue->rear]);
    }
}

int main()
{
    struct queue* queue;
    int mode, new_node_data;

    printf("This program depicts the implementation of queue using dynamic arrays\n");
    printf("the following options are avaliable for queue manipulation:\n1.Initialize queue\n2.Add element to the queue\n3.Delete element from the queue\n4.Get the topmost or rearmost element from the queue\n5.Re-print the operations list.\n6.EXIT\n");

    while(mode != 10)
    {
        printf("please enter the operation you want to perform\n");
        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            printf("\nInitializing Queue");

            queue = queue_initializer();
            break;
        case 2:
            printf("please enter the data of the element you would like to enqueue\n");
            scanf("%d", &new_node_data);

            enqueue(queue, new_node_data);
            break;
        case 3:
            printf("deleting front-most element from the queue\n");

            dequeue(queue);
            break;
        case 4:
            get_topmost_or_rearmost_element(queue);
            break;

        case 5:
            printf("the following options are avaliable for queue manipulation:\n1.Re-Initialize queue\n2.Add element to the queue\n3.Delete element from the queue\n4.Get the topmost or rearmost element from the queue\n5.Re-print the operations list.\n6.EXIT\n");
            break;
        case 6:
            goto EXIT;
            break;
        case 7:
            display_queue(queue);
            break;
        default:
            printf("operation not found!!! please check the operations list and try again.\n");
            break;
        }
    }    
    
    EXIT:
    return 0;
}

/*
FOR TESTING ONLY
queue = queue_initializer();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    get_topmost_or_rearmost_element(queue);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 50);
    display_queue(queue);
    dequeue(queue);
    dequeue(queue);
    get_topmost_or_rearmost_element(queue);
    dequeue(queue);
    dequeue(queue);
    display_queue(queue);
    dequeue(queue);
    display_queue(queue);
    dequeue(queue);
    

*/