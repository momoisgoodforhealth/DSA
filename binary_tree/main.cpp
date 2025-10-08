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
  if (root = NULL)
  {
    root = GetNewNode(data);
    return root;
  }
};

int main()
{
  BstNode* root = NULL; // pointer to root node;
  Insert(root,15);
  Insert(root,10);
  Insert(root,20);
}
