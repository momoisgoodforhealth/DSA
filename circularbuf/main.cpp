#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <iostream>

using namespace std;

class Queue
{
  private:
    int *arr;
    int front, size;
    int capacity;

  public:
    //constructor
    Queue(int c)
    {
      arr = new int[c];
      capacity = c;
      size = 0;
      front = 0;
    }

    //Get front element
    int getFront()
    {
      if (size == 0) return -1;
      return arr[front];
    }

    //Get rear element
    int getRear()
    {
      if (size == 0) return -1;
      int rear = (front + size - 1) % capacity;
      return arr[rear];
    }

    //insert element
    int enqueue(int x)
    {
      //queue is full
      if (size ==  capacity) return -1;
      int rear = (front + size) % capacity;
      arr[rear] = x;
      size++;
      return 0;
    }

    //remove rear element
    int dequeue()
    {
      if (size==0) return -1;
      int res = arr[front];
      front = (front + 1) % capacity;
      size--;
      return res;
    }
};

int main()
{
  Queue q(4);
  q.enqueue(10);
  cout << q.getFront() << " " << q.getRear() << endl;
  q.enqueue(20);
  cout << q.getFront() << " " << q.getRear() << endl;
  q.enqueue(30);
  cout << q.getFront() << " " << q.getRear() << endl;
  q.enqueue(40);
  cout << q.getFront() << " " << q.getRear() << endl;
  q.dequeue();
  cout << q.getFront() << " " << q.getRear() << endl;
  q.dequeue();
  cout << q.getFront() << " " << q.getRear() << endl;
  q.enqueue(50);
  cout << q.getFront() << " " << q.getRear() << endl;
  return 0;
}
