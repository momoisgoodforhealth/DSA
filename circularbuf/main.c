#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  int front;
  int rear;
  int *data;
  int count;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k) {
  MyCircularQueue *queue = malloc(sizeof(MyCircularQueue));
  if (!queue)
    return NULL;
  queue->size = k;
  queue->front = 0;
  queue->rear = 0;
  queue->data = malloc(sizeof(int) * k);
  if (!queue->data) {
    free(queue);
    return NULL;
  }
  queue->count = 0;
  return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value) {
  if (obj->count == obj->size)
    return false;
  obj->data[obj->rear] = value;
  obj->rear = ((obj->rear + 1) % obj->size);
  obj->count = obj->count + 1;
  return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj) {
  if (obj->count == 0)
    return false;
  obj->front = (obj->front + 1) % obj->size;
  obj->count--;
  return true;
}

int myCircularQueueFront(MyCircularQueue *obj) {
  if (obj->count == 0)
    return -1;
  return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj) {
  int last = (obj->rear - 1 + obj->size) % obj->size;
  return obj->data[last];
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj) {
  if (obj->count == 0)
    return true;
  else
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue *obj) {
  if (obj->count == obj->size)
    return true;
  else
    return false;
}

void myCircularQueueFree(MyCircularQueue *obj) {
  if (obj != NULL) {
    free(obj->data);
    free(obj);
  }
}

int main() {
  int ret;

  MyCircularQueue *newqueue = myCircularQueueCreate(3);

  ret = newqueue->size;
  printf("queue size : %d\n", ret);

  ret = myCircularQueueEnQueue(newqueue, 1);
  printf("myCircularQueueEnQueue(newqueue, 1) %d\n", ret);
  ret = myCircularQueueEnQueue(newqueue, 2);
  printf("myCircularQueueEnQueue(newqueue, 2) %d\n", ret);
  ret = myCircularQueueEnQueue(newqueue, 3);
  printf("myCircularQueueEnQueue(newqueue, 3) %d\n", ret);
  ret = myCircularQueueEnQueue(newqueue, 4);
  printf("myCircularQueueEnQueue(newqueue, 4) %d\n", ret);
  ret = myCircularQueueEnQueue(newqueue, 5);
  printf("myCircularQueueEnQueue(newqueue, 5) %d\n", ret);
  ret = myCircularQueueFront(newqueue);
  printf("myCircularQueueFront(newqueue) %d\n", ret);
  ret = myCircularQueueRear(newqueue);
  printf("myCircularQueueRear(newqueue) %d\n", ret);

  myCircularQueueFree(newqueue);
}