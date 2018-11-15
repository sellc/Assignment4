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
  void addNode(T& data){
    if(root == nullptr){
      root = new Node(data);
    } else {
      addNode(data, root);
    }
  }
  void addNode(T& data, Node* root){
    if(root == nullptr){
      root->data = new Node(data);
    } else if(root->data > data){
      addNode(data, root->left);
    } else {
      addNode(data, root->right);
    }
  }
  void deleteNode(T& data){
    deleteNode(data, root);
  }
  void deleteNode(T& data, Node* root){
    if(root->data == data){
      delete root;
    } else if(root->data > data){
      deleteNode(data, root->left);
    } else {
      deleteNode(data, root->right);
    }
  }
};

#endif
