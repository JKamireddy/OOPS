#0ifndef TREE_H
#define TREE_H
#include <iostream>
using std::cout;
template <class T> class BSTree;

template <class T>
class BSNode
{
   friend class BSTree<T>;
   T value;
   BSNode<T> * left;
   BSNode<T> * right;
   BSNode(const T & val);
};

template <class T>
class BSTree
{
   BSNode<T> * root;
   public:
      enum {BST_OK = 0, BST_DUPLICATE = -1, BST_NOT_FOUND = -2};
      BSTree();
      BSTree(const BSTree<T> &);
      void clear(void);
      int insert(const T & data);
      int height(void) const;
      int size(void) const;
      void print_pre(void) const;
      void zrint_pre(const BSNode<T>*) const;
      void print_in(void) const;
      void zrint_in(const BSNode<T>*) const;
      void print_post(void) const;
      void zrint_post(const BSNode<T>*) const;
      int find(T & val) const;
      BSTree<T> & operator = (const BSTree<T> &);
      BSTree<T> & operator = (BSTree<T> &&);
      ~BSTree<T>();
      //user  functions
   private:
      void zkill(BSNode<T>*);
      BSNode<T>* zcopy(const BSNode<T>*) const;
      int zclimb(const BSNode<T>*) const;
      int zsize(const BSNode<T>*) const;
};

/*BSNode() function using  constructor
 argument value with which to initialize 'value'*/

template <class T>
BSNode<T>::BSNode(const T & val)
{
   left=0;// setting to NULL 
   right=0;// setting to NULL
   value=val;
}

/* BSTree()- function using default constructor
 here initializing head pointer to NULL*/
template <class T>
BSTree<T> ::BSTree()
{
   root=0;// setting to NULL
}

template <class T>
int BSTree<T>::find(T & val) const
{

}

/*BSTree(BSTree)- function 
using copy constructor which copies BS from one BStree to make BS for
 nother BSTree, one BSNode at a BSTime*/

template <class T>
BSTree<T>::BSTree(const BSTree<T> &rhs)
{
   this->root=zcopy(rhs.root);
}

/* clear() - function which  Clears all of the nodes from the tree and resets them to be
    an empty tree.*/
template <class T>
void BSTree<T>::clear(void)
{
   if(this->root!=0)
   {
      zkill(this->root);
      this->root=0;
   }
}

/*insert(T)-function which taking  an integer data value and inserting  into the tree 
for the tree to remain as  a binary search tree.
 data to be inserted and 
returns "DUPLICATE" if match is found, otherwise OK */
template <class T>
int BSTree<T>::insert(const T & data)
{
   BSNode<T>* finger=this->root;
   if(finger==0)
   {
      finger=new BSNode<T>(data);
      this->root=finger;
      return BST_OK;
   }
   while(1)
   {
      if(finger->value==data)
         return BST_DUPLICATE;
      if(data<finger->value)
      {
         if(finger->left!=0)
            finger=finger->left;
         else
         {
            finger->left=new BSNode<T> (data);
            return BST_OK;
         }
      }
      else
      {
         if(finger->right!=0)
            finger=finger->right;
         else
         {
            finger->right=new BSNode<T> (data);
            return BST_OK;
         }
      }
   }
}

/* height() - function which calculates and then
   returns the height of the tree.
   returns the height of tree (longest branch)*/
template <class T>
int BSTree<T>::height(void) const
{
   return zclimb(this->root);
}


/*size()-function which calculates and 
returns the number of nodes in the tree.
returns the number of nodes in the tree which 
 calls @size  because no use of this*/
template <class T>
int BSTree<T>::size(void) const
{
   return zsize(this->root);
}

/*print_pre - function which prints tree to stdout in "preorder" format 
this function also calls another function because no use of this */
template <class T>
void BSTree<T>::print_pre(void) const
{
   zrint_pre(this->root);
}
//recursive fucntion  of print_pre 
template <class T>
void BSTree<T>::zrint_pre(const BSNode<T>* finger) const
{
   if(finger!=0)
   {
      cout<<finger->value<<" ";
      zrint_pre(finger->left);
      zrint_pre(finger->right);
   }
}

/*print_in-function
which prints tree the to stdout in "inorder" format
calling the  recursive function zrint_in*/
template <class T>
void BSTree<T>::print_in(void) const
{
   zrint_in(this->root);
}
// print_in - recursive function

template <class T>
void BSTree<T>::zrint_in(const BSNode<T>*finger) const
{
   if(finger!=0)
   {
      zrint_in(finger->left);
      cout<<finger->value<<" ";
      zrint_in(finger->right);
   }
mmmmmmmmmmmmmmmmmmmmmmm,,,,,,,,,,,,,,,,,}

/*print_post-function which 
prints the tree to stdout in "postorder" format
which calls the  recursive function zrint_post*/
template <class T>
void BSTree<T>::print_post(void) const
{
   zrint_post(this->root);
}
//print_post-recursive function
template <class T>
void BSTree<T>::zrint_post(const BSNode<T>*finger) const
{
   if(finger!=0)
   {
      zrint_post(finger->left);
      zrint_post(finger->right);
      cout<<finger->value<<" ";
   }
}

template <class T>
BSTree<T>& BSTree<T>::operator = (const BSTree<T> &rhs)
{
   this->root=zcopy(rhs.root);
   return *this;
}

template <class T>
BSTree<T>& BSTree<T>::operator = (BSTree<T> &&rhs)
{
   this->root=zcopy(rhs.root);
   return *this;
}

/*Function: ~BSTree using  destructor
 which calls @kill that recursively deletes all znodes*/
template <class T>
BSTree<T>::~BSTree<T>()
{
   if(this->root!=0)
   {
      zkill(this->root);
      this->root=0;
   }
}

//USER ADDED FUNCTIONS

/*@copy - function 
which  makes a clone of tree in memory
that returns the  pointer to head of tree */
template <class T>
BSNode<T>* BSTree<T>::zcopy(const BSNode<T>*head) const
{
   BSNode<T>* cacheP=new BSNode<T>(head->value);

   if(head->left!=0)
      cacheP->left=zcopy(head->left);
   if(head->right!=0)
      cacheP->right=zcopy(head->right);

   return cacheP;
}

//Function: @kill
//Use: deletes subtrees, followed by self
//Args: pointer to head of target tree
//Returns:
//Notes: called by destructor
template <class T>
void BSTree<T>::zkill(BSNode<T>* head)
{
   if(head->left!=0)
      zkill(head->left);
   if(head->right!=0)
      zkill(head->right);
   delete head;
}

/*@climb -function which  uses  the 
recursive function to count the height of tree
 and rerurns the height of longest branch*/
template <class T>
int BSTree<T>::zclimb(const BSNode<T>* limb) const
{
   if(limb==0)
      return 0;
   int leftside=1+zclimb(limb->left);
   int rightside=1+zclimb(limb->right);
   if(leftside>rightside)
      return leftside;
   return rightside;
}

/*@size - function which uses 
the recursive function to count the nodes in the tree and 
 returns the  total node count  */
template <class T>
int BSTree<T>::zsize(const BSNode<T>* finger) const
{
   if(finger==0)
      return 0;
   return(1+zsize(finger->left)+zsize(finger->right));
}

#endif
