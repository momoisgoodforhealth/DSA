#include <stdbool.h>
#include <stdlib.h>
#include  <stdio.h>

typedef struct {
    int size;
    int front;
    int rear;
    int * data;
    int count;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k)
{
  MyCircularQueue * queue = malloc(sizeof(MyCircularQueue));
  queue->size = k;
  queue->front = 0;
  queue->rear = 0;
  queue->data = malloc(sizeof(int)*k);
  queue->count = 0;
  return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
if (obj->count == obj->size) return -1;
obj->data[obj->rear] = value;
obj->rear =  ((obj->rear + 1) % obj->size);
obj->count++;
return true;
}



bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
  if (obj->count == 0) return false;
  obj->front  = obj->front +1 %obj->size;
  obj->count--;
  return true;
}



int myCircularQueueFront(MyCircularQueue* obj)
{
  return obj->data[obj->front];
}



int myCircularQueueRear(MyCircularQueue* obj)
{
  return obj->data[obj->rear];
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
  if (obj->count == 0) return true;
  else return false;
}


bool myCircularQueueIsFull(MyCircularQueue* obj)
{
  if (obj->count == obj->size) return true;
  else return false;
}


void myCircularQueueFree(MyCircularQueue* obj)
{
if (obj != NULL)
{
  free(obj->data);
free(obj);
}

}
