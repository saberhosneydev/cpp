#include <iostream>

using namespace std;

class Queue
{
public:
    int front,rear,capacity,size;
    int* array;
};

Queue* createQueue(int capactiy){
    Queue* obj = new Queue();
    obj->capacity = capactiy;
    obj->front = obj->size = 0;
    obj->rear =capactiy - 1;
    obj->array = new int[(obj->capacity * sizeof(int))];
    return obj;
}

int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}
int isEmpty(Queue* queue)
{ return (queue->size == 0); }

void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}
int dequeue(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
int front(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
int main(int argc, char const *argv[])
{
    Queue* sex = createQueue(10);
    enqueue(sex, 10);
    enqueue(sex, 5);
    enqueue(sex, 4);
    enqueue(sex, 25);

    cout<<dequeue(sex)<<" dequeued from queue\n";

    cout << "Front item is " << front(sex) << endl;
    cout << "Rear item is " << rear(sex) << endl;
    return 0;
}