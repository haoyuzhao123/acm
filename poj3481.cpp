//poj 3481
//Double Queue

#include <cstdio>
#include <vector>

using namespace std;

struct STreeNode {
  int K;
  int P;
  STreeNode * par;
  STreeNode * left;
  STreeNode * right;
};

STreeNode * root = NULL;

//the function to determine whether p is the left
//or the right child. p is root then return -1;
//p is left child then return 1;
//p is right child then return 0;
int whichChild(STreeNode * p) {
  if (p == root) {
    return 0;
  }
  else {
    if (p->par->left == p) {
      return 1;
    }
    else {
      return 0;
    }
  }
}

void rotateL(STreeNode * p) {
  if (p == root) {
    return;
  }
  else if (p->par == root) {
    STreeNode * pPar = p->par;
    //set the parents of the nodes after rotateL
    p->par = NULL;
    pPar->par = p;
    if (p->left != NULL) {
      p->left->par = pPar;
    }

    //set the children after rotateL
    root = p;
    pPar->right = p->left;
    p->left = pPar;
  }
  else {
    STreeNode * pPar = p->par;
    int k = whichChild(pPar);
    //set the parents of the nodes after rotateL
    p->par = pPar->par;
    pPar->par = p;
    if (p->left != NULL) {
      p->left->par = pPar;
    }

    //set the children after rotateL
    if (k) {
      p->par->left = p;
    }
    else {
      p->par->right = p;
    }
    pPar->right = p->left;
    p->left = pPar;
  }
}

void rotateR(STreeNode * p) {
  if (p == root) {
    return;
  }
  else if (p->par == root) {
    STreeNode * pPar = p->par;
    //set the parents of the nodes after rotateR
    if (p->right != NULL) {
      p->right->par = pPar;
    }
    p->par =NULL;
    pPar->par = p;

    //set the children of each node
    pPar->left = p->right;
    root = p;
    p->right = pPar;
    
  }
  else {
    STreeNode * pPar = p->par;
    int k = whichChild(pPar);
    //set the parents of the nodes after rotateR
    if (p->right != NULL) {
      p->right->par = pPar;
    }
    p->par = pPar->par;
    pPar->par = p;

    //set the children of each node
    pPar->left = p->right;
    if (k) {
      p->par->left = p;
    }
    else {
      p->par->right = p;
    }
    p->right = pPar;
  }
}

void splay(STreeNode * p) {
  if (p == root) {}
  else if (p == NULL) {}
  else if (p->par == root) {
    if (whichChild(p)) {
      rotateR(p);
    }
    else {
      rotateL(p);
    }
  }
  else {
    STreeNode * pPar = p->par;
    if (whichChild(p)) {
      if (whichChild(pPar)) {
	rotateR(pPar);
	rotateR(p);
      }
      else {
	rotateR(p);
	rotateL(p);
      }
    }
    else {
      if (whichChild(pPar)) {
	rotateL(p);
	rotateR(p);
      }
      else {
	rotateL(pPar);
	rotateL(p);
      }
    }
    splay(p);
  }
}

void addClient(STreeNode * ptr, int k, int p) {
  if (ptr == NULL) {
    STreeNode * newPtr = new STreeNode;
    newPtr->K = k;
    newPtr->P = p;
    newPtr->par = NULL;
    newPtr->left = NULL;
    newPtr->right = NULL;
    

    root = newPtr;
  }
  else if (p < ptr->P) {
    if (ptr->left == NULL) {
      STreeNode * newPtr = new STreeNode;
      newPtr->K = k;
      newPtr->P = p;
      newPtr->par = ptr;
      newPtr->left = NULL;
      newPtr->right = NULL;
      ptr->left = newPtr;

      splay(newPtr);
    }
    else {
      addClient(ptr->left, k, p);
    }
  }
  else {
    if (ptr->right == NULL) {
      STreeNode * newPtr = new STreeNode;
      newPtr->K = k;
      newPtr->P = p;
      newPtr->par = ptr;
      newPtr->left = NULL;
      newPtr->right = NULL;
      ptr->right = newPtr;

      splay(newPtr);
    }
    else {
      addClient(ptr->right, k, p);
    }    
  }
}

void serveMax(STreeNode * ptr) {
  if (ptr == NULL) {
    printf("%d\n", 0);
  }
  else if (ptr->right == NULL) {
    printf("%d\n", ptr->K);
    if (ptr != root) {
      ptr->par->right = ptr->left;
    }
    else {
      root = ptr->left;
    }

    if (ptr->left != NULL) {
      ptr->left->par = ptr->par;
    }
    
    STreeNode * newPtr = ptr->par;
    splay(newPtr);
    delete ptr;
  }
  else {
    serveMax(ptr->right);
  }
}

void serveMin(STreeNode * ptr) {
  if (ptr == NULL) {
    printf("%d\n", 0);
  }
  else if (ptr->left == NULL) {
    printf("%d\n", ptr->K);
    if (ptr != root) {
      ptr->par->left = ptr->right;
    }
    else {
      root = ptr->right;
    }

    if (ptr->right != NULL) {
      ptr->right->par = ptr->par;
    }

    STreeNode * newPtr = ptr->par;
    delete ptr;
    splay(newPtr);
  }
  else {
    serveMin(ptr->left); 
  }
}


void removeTree(STreeNode * p) {
  if (p == NULL) {}
  else {
    removeTree(p->left);
    removeTree(p->right);
    delete p;
  }
}

void solve() {
  while (true) {
    int instr;
    scanf("%d", &instr);
    if (instr == 0) {
      break;
    }
    else if (instr == 1) {
      int K, P;
      scanf("%d%d", &K, &P);
      addClient(root, K, P);
    }
    else if (instr == 2) {
      serveMax(root);
    }
    else if (instr == 3) {
      serveMin(root);
    }
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif

  solve();
  removeTree(root);

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif

  return 0;
}
