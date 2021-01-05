#define DEEP 20
#include<assert.h>
typedef struct {
    int* data;
    int top;
    int capacity;
} stack;
//初始化栈
stack* initStack(int k) {
    stack* s = (stack*)malloc(sizeof(stack));
    s->data = (int*)malloc(sizeof(int) * k);
    s->top = -1;
    s->capacity = k;
    return s;
}
//检查容量
void checkStack(stack** ps) {
    if ((*ps)->top == (*ps)->capacity) {
        int* temp = (int*)realloc((*ps)->data, sizeof(int) * (*ps)->capacity * 2);
        (*ps)->data = temp;
        (*ps)->capacity *= 2;
    }
    return;
}
//判空
bool isEmpty(stack* s) {
    return s->top == -1;
}
//入栈
void pushStack(stack* s, int value) {
    assert(s);
    checkStack(&s);
    s->data[++s->top] = value;
}
//出栈
int popStack(stack* s) {
    assert(s);
    assert(!isEmpty(s));
    int temp = s->data[s->top];
    s->top--;
    return temp;
}
//取栈顶元素
int topStack(stack* s) {
    assert(s);
    assert(!isEmpty(s));
    return s->data[s->top];
}

//定义s1为push栈，s2为pop栈
typedef struct {
    stack* s1, * s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->s1 = initStack(DEEP);
    queue->s2 = initStack(DEEP);
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    checkStack(&(obj->s1));
    pushStack(obj->s1, x);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->s2)) {
        while (!isEmpty(obj->s1)) {
            pushStack(obj->s2, popStack(obj->s1));
        }
    }
    if (!isEmpty(obj->s2))
        return obj->s2->data[obj->s2->top];
    return -1;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int temp = myQueuePeek(obj);
    if (temp != -1) {
        popStack(obj->s2);
        return temp;
    }
    return -1;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if (isEmpty(obj->s1) && isEmpty(obj->s2))
        return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1->data);
    obj->s1->data = NULL;
    free(obj->s2->data);
    obj->s2->data = NULL;
    free(obj->s1);
    obj->s1 = NULL;
    free(obj->s2);
    obj->s2 = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/