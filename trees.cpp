#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;

struct node{
  int val;
  struct node* right;
  struct node* left;

  node(int t)
  {
    val=t;
    right =NULL;
    left = NULL;
  }
};
void postorder(struct node* nd)
{
  if (nd == NULL)
  {
    return;
  }

  

  postorder(nd->left);
  
  postorder(nd->right);
  cout<<nd->val<<endl;
  
}
int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);

  struct node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  postorder(root);

    return 0;
}