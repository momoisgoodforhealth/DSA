#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <iostream>

using namespace std;



struct BstNode
{
  int data;
  BstNode* left;
  BstNode* right;
};


BstNode* rootPtr;

BstNode * GetNewNode (int data)
{
  BstNode* newNode = new BstNode();
 newNode->data = data;
 newNode -> left = newNode -> right = NULL;
 return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
  if (root == NULL)
  {
    root = GetNewNode(data);
  }
  else if (data <= root->data)
  {
     root->left = Insert(root->left, data);
  }
  else
  {
    root->right = Insert(root->right, data);
  }

  return root;
};

bool Search(BstNode *root, int data)
{
  if (root == NULL) return false;

  if (root->data == data) return true;
  else if (data < root->data)
  {
    return Search(root->left, data);
  }
  else if (data > root->data)
  {
    return Search(root->right, data);
  }
}

    int main()
{
  BstNode* root = NULL; // pointer to root node
  root = Insert(root,15);
  root = Insert(root,10);
  root = Insert(root,20);
  int number;
  cout<<"Enter Number to be Searched\n";
  cin>>number;
  if (Search(root, number)) cout<<"Found\n";
  else cout << "Not Found\n";
}
