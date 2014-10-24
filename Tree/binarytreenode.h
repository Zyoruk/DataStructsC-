#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include "interfaces/interfaceNode.h"
#include "cstddef"
template <typename K>
class BinaryTreeNode :public interfaceNode<K>
{
public:
    BinaryTreeNode();
    K* getElement();
    void setElement(K pElement);
    void setRight(BinaryTreeNode* pRight);
    void setLeft(BinaryTreeNode* pLeft);
    BinaryTreeNode* getLeft();
    BinaryTreeNode* getRight();
private:
    interfaceNode<K>* _right;
    interfaceNode<K>* _left;
};
template <typename K>
BinaryTreeNode<K>::BinaryTreeNode()
{
    this->_element = 0;
    this->_left = 0;
    this->_right = 0;
}

template <typename K>
K* BinaryTreeNode<K>::getElement(){
    return &this->_element;
}

template <typename K>
void BinaryTreeNode<K>::setElement(K pElement){
    this->_element = pElement;
}

template <typename K>
BinaryTreeNode<K>* BinaryTreeNode<K>::getLeft(){
    return (BinaryTreeNode*)this->_left;
}

template <typename K>
BinaryTreeNode<K>* BinaryTreeNode<K>::getRight(){
    return (BinaryTreeNode*)this->_right;
}

template <typename K>
void BinaryTreeNode<K>::setLeft(BinaryTreeNode<K> *pLeft){
    this->_left = pLeft;
}

template <typename K>
void BinaryTreeNode<K>::setRight(BinaryTreeNode<K> *pRight){
    this->_right = pRight;
}


#endif // BINARYTREENODE_H
