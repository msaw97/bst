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

  node* root;

  node* treeInsert(node* t, int z)//root, z
  {

        if(t ==NULL)     //jezeli nie ma BST korzenia to wezel staje sie korzeniem
      {
        t = new node;
        t -> key = z;
        t -> left = NULL;
        t -> right = NULL;
        t -> parent = NULL;
      }

      else if ( z < t->key)     //element od kluczu mniejszym od wezla dodawany jest do lewego poddrzewa
      {
        node* lchild = treeInsert(t->left, z);
        t-> left = lchild;
        lchild -> parent = t;
      }

      else  //element od kluczu wiekszym od wezla dodawany jest do prawego poddrzewa
      {
        node* rchild = treeInsert(t-> right, z);
        t-> right = rchild;
        rchild -> parent =t;
      }
      return t;
  }

  node * transplant (node*t, node* u, node* v){  //procedura wstawiania poddrzewa o korzeniu v w miejsce poddrzewa o korzeniu u
      if( u-> parent == NULL){
          t = v;
      }
      else if( u-> parent -> left == u){
          u-> left = v;
      }
      else {
          u -> right =v;
      }
      if (v != NULL){
        v->parent = u-> parent;
      }
  }

  node * treeDelete(node*t, node*z){
        if( z->left == NULL){
            transplant(t, z, z->right);
        }
        else if (z-> right == NULL){
            transplant(t, z, z-> left);
        }
        else {
            node*y = treeMinimum(z->right);
            if (y-> parent != z){
                  transplant(t, y, y-> right);
                  y-> right = z->right;
                  y-> right ->parent = y;
            }
            transplant(t, z, y);
            y-> left = z-> left;
            y-> left-> parent =y;
        }
        return t;


    }

  void inorderTreeWalk(node*t)    //przechodzenie drzewa metoda in order
    {
        if(t != NULL)
        {
            inorderTreeWalk(t-> left);
            cout<<t->key<<endl;//<<" "<< t-> parent <<endl;
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

      void tinsert(int z)
      {
        root = treeInsert(root, z);
      }


      void inorderTreeWalk()
        {
        inorderTreeWalk(root);
        }



      void tsearch(int k){
          root= treeSearch(root, k);
          cout<<root;
        }

    /*  void tdelete(int z){
        root =  treeDelete(root, z);
      }*/

  };


  int main()
  {
    BST t;
    t.tinsert(7);
    t.tinsert(4);
    t.tinsert(11);
    t.tinsert(-1);
    t.tinsert(5);
    t.inorderTreeWalk();
    t.tsearch(-1);
  //  t.tdelete(-1);
  //  t.inorderTreeWalk();
  }
