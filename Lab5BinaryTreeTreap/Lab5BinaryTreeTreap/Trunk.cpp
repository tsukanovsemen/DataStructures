#include "Trunk.h"
#include "BinaryTree.h"

void showTrunks(Trunk* p)
{
      if (p == nullptr) 
      {
          return;
      }

      showTrunks(p->prev);
      cout << p->str;
}

//template<class T>
//void printTree(T* root, Trunk* prev, bool isLeft)
//{
//    
//}
