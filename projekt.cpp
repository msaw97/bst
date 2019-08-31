//Binary Search tree
//Miłosz Sawicki

#include <iostream>
using namespace std;

class BST
{
  struct node   //wezel BST, zawiera klucz, wskaznik do lewego i prawego syna
  {
    node * left;
    node * right;
    node * parent;
    int key;
  };

  node* root;   //wskanik do glownego korzenia

  node* treeInsert(node* t, int z)//root, z
  {
      if(t == NULL)     //jezeli nie ma BST korzenia to wezel staje sie korzeniem
      {
        t = new node;
        t -> key = z;
        t -> left = NULL;
        t -> right = NULL;
        t -> parent = NULL;
      }

      else if ( z < t->key)     //element od kluczu mniejszym od wezla dodawany jest do lewego poddrzewa
      {
        t -> parent = t;
        t-> left = treeInsert(t->left, z);
      }

      else  //element od kluczu wiekszym od wezla dodawany jest do prawego poddrzewa
      {
        t -> parent = t;
        t-> right = treeInsert(t-> right, z);
      }

      return t;
  }

  node * transplant (node*t, int u, int v){   //procedura wstawiania poddrzewa o korzeniu v w miejsce poddrzewa o korzeniu u

  }



  void inorderTreeWalk(node*t)    //przechodzenie drzewa metoda in order
    {
        if(t != NULL)
        {
            inorderTreeWalk(t-> left);
            cout<<t->key<<endl;
            inorderTreeWalk(t->right);
        }
    }


    node* treeSearch(node*t, int k)
    {
        if(t == NULL)
            return NULL;

        while (t != NULL && k != t->key)
        {
              if(k < t->key) {
                  t = t-> left;
                  }

              else {
                  t= t-> right;
                  }
        }
        return t;
    }

  node* treeMinimum(node*t)
  {
    while (t-> left !=NULL)
    {
         t = t-> left;
    }
    return t;
  }

  node* treeMaximum(node*t)
  {
    while (t-> right !=NULL)
    {
        t = t-> right;
    }
    return t;
  }


  public:
      BST()
      {
        root = NULL;  //konstruktor upewnia sie, ze przy tworzeniu BST jest puste
      }

      void treeInsert(int z)
      {
        root = treeInsert(root, z);
      }


      void inorderTreeWalk()
        {
        inorderTreeWalk(root);
        }



      void treeSearch(int k){
        cout<< treeSearch(root, k);
        }


  };


  int main()
  {
    BST t;
    t.treeInsert(7);
    t.treeInsert(4);
    t.treeInsert(11);
    t.treeInsert(-1);
    t.treeInsert(5);
    t.inorderTreeWalk();
    t.treeSearch(33);
  }
