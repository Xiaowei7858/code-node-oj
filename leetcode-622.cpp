#include<stdlib.h>
typedef struct {
    int* data;
    int head;
    int rear;
    int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->data = (int*)malloc(sizeof(int) * (k + 1));
    cq->head = 0;
    cq->rear = 0;
    cq->size = k + 1;
    return cq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->head == obj->rear)
        return true;
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if ((obj->rear + 1) % obj->size == obj->head)
        return true;
    return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->size;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->head = (obj->head + 1) % obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    //·ÀÖ¹Ô½½ç·ÃÎÊ
    int temp = obj->rear - 1;
    if (temp == -1)
        temp = obj->size - 1;
    return obj->data[temp];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/