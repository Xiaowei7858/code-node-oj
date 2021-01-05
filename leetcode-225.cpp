#define LEN 20
//设置队列操作
//设置队列表示栈操作
typedef struct {
    int* data;
    int head;
    int rear;
    int size;
}Queue;

//初始化队列
Queue* initQueue(int k) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * k);
    queue->head = -1;
    queue->rear = -1;
    queue->size = k;
    return queue;
}
//入队列
void enQueue(Queue* queue, int value) {
    if (queue->head == -1) {
        queue->head = 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->data[queue->rear] = value;
}
//出队列
int deQueue(Queue* queue) {
    int temp = queue->data[queue->head];
    if (queue->head == queue->rear) {
        queue->head = -1;
        queue->rear = -1;
        return temp;
    }
    queue->head = (queue->head + 1) % queue->size;
    return temp;
}
//判空
bool isEmpty(Queue* queue) {
    return queue->head == -1;
}

typedef struct {
    Queue* queue1, * queue2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* mystack = (MyStack*)malloc(sizeof(MyStack));
    mystack->queue1 = initQueue(LEN);
    mystack->queue2 = initQueue(LEN);
    return mystack;
}
//queue1 为存储队列，queue2 为辅助队列
/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (isEmpty(obj->queue1)) {
        enQueue(obj->queue2, x);
    }
    else {
        enQueue(obj->queue1, x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (isEmpty(obj->queue1)) {
        while (obj->queue2->head != obj->queue2->rear) {
            enQueue(obj->queue1, deQueue(obj->queue2));
        }
        return deQueue(obj->queue2);
    }
    while (obj->queue1->head != obj->queue1->rear) {
        enQueue(obj->queue2, deQueue(obj->queue1));
    }
    return deQueue(obj->queue1);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (isEmpty(obj->queue1)) {
        return obj->queue2->data[obj->queue2->rear];
    }
    return obj->queue1->data[obj->queue1->rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (isEmpty(obj->queue1) && isEmpty(obj->queue2))
        return true;
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1->data);
    obj->queue1->data = NULL;
    free(obj->queue2->data);
    obj->queue2->data = NULL;
    free(obj->queue1);
    obj->queue1 = NULL;
    free(obj->queue2);
    obj->queue2 = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/