#include <stdlib.h>
#include <stdio.h>

struct Node
{
  int data;
  struct Node* next;
};

struct Node* head;

void Insert(int x)
{
  Node* temp = (Node*)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = head;
  head = temp;
}

void Print()
{
  Node* temp = head;
  printf("List is: ");
  while(temp!=NULL)
  {
    printf(" %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}


void Delete(int n)
{
  Node* temp1 = head;

  if (n == 1)
  {
    head = temp1->next;
    free(temp1);
    return;
  }

  for(int i = 0 ; i < n - 2 ; i++) temp1 =  temp1->next; // point (n-1) node
  Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  free(temp2);

}


int main()
{
  head = NULL;
  printf("How many numbers?\r\n");
  int n,x;
  scanf("%d", &n);
  for (int i = 0; i<n; i++)
  {
    printf("Enter value\r\n");
    scanf("%d", &x);
    Insert(x);
    Print();
  }
}
