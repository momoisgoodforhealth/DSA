#include <stdlib.h>
#include <stdio.h>
struct Node
{
  int data;
  struct Node * next;
};

struct Node* head;
struct Node* Reverse(struct Node* head)
{
  struct Node *current, *prev, *next;
  current = head;
  prev = nullptr;
  while (current != nullptr)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  return head;
}

void Insert(int x)
{
  Node *temp = (Node *)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = head;
  head = temp;
}

void Print()
{
  Node *temp = head;
  printf("List is: ");
  while (temp != NULL)
  {
    printf(" %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  head = NULL;
  printf("How many numbers?\r\n");
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    printf("Enter value\r\n");
    scanf("%d", &x);
    Insert(x);
    Print();
  }
  head = Reverse(head);
  Print();

}
