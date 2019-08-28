//Binary Search tree
//Miłosz Sawicki

#include <iostream>
using namespace std;

class BST
{
  struct node
  {
    node * left, * right;
    int key;
  };

  node* root;

  node* insert(int z, node* t)
  {
      if(t == NULL)
      {
        t = new node;
        t -> key = z;
        t -> left = t -> right = NULL;
      }

      else if ( z < t->key)
      {
        t-> left = insert(z, t->left);
      }

      else
      {
        t-> right = insert(z, t-> right);
      }

      return t;
  }


  public:
      BST()
      {
          root = NULL;
      }

      void insert(int x)
      {
          root = insert(x, root);
      }


  };


  int main()
  {
    BST t;
    t.insert(2);
    t.insert(4);
    t.insert(11);
    t.insert(7);

  }
