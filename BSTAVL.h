#ifndef BSTAVL_H
#define BSTAVL_H

using namespace std;

template<class T>
struct Node{
  T Data;
  Node* left;
  Node* right;
}

template<class T>
class BSTAVL {
  Node* root;
public:
  void addNode(T& data);
  void deleteNode(T& data);
  
};

#endif
