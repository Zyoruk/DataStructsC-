#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "binarytreenode.h"
template <typename K>
class BinaryTree
{
public:
    BinaryTree();
    unsigned int getLenght();
    bool add(K pElement);
    bool remove(K pElement);
    bool ifExists(K pElement);
    BinaryTreeNode<K>* search(K pElement);

private:
    unsigned int lenght;
    BinaryTreeNode<K>* _root;

    bool addAux(K pElement , BinaryTreeNode<K>* pLeaf);
    bool removeAux ( K pElement , BinaryTreeNode<K>* pLeaf);
    BinaryTreeNode<K>* searchAux(K pElement, BinaryTreeNode<K>* pLeaf);
    BinaryTreeNode<K>* lowestHighest (BinaryTreeNode<K>* pNode);
    BinaryTreeNode<K>* highestLowest (BinaryTreeNode<K>* pNode);
};
template <typename K>
BinaryTree<K>::BinaryTree()
{
    this->_root = new BinaryTreeNode<K>();
    this->lenght = 0;
}
template <typename K>
unsigned int BinaryTree<K>::getLenght(){
    return this->lenght;
}
template <typename K>
bool BinaryTree <K>::add(K pElement)
{
    if(*this->_root->getElement() == 0){
        this->_root->setElement(pElement);
        this->lenght += 1;
        return true;
    }else{
        return addAux(pElement , this->_root);
    }
}
template <typename K>
bool BinaryTree<K>::addAux(K pElement , BinaryTreeNode<K>* pNode){
    if ( pElement < (*pNode->getElement())){
        if (pNode->getLeft() == NULL){
            BinaryTreeNode<K>* leftToAdd = new BinaryTreeNode<K>();
            leftToAdd->setElement(pElement);
            pNode->setLeft(leftToAdd);
            leftToAdd->setFather(pNode);
        this->lenght += 1;
            return true;
        }else{
            return addAux(pElement , pNode->getLeft());
        }
    }else if (pElement > (*pNode->getElement())){
        if (pNode->getRight() == NULL){
            BinaryTreeNode<K>* rightToAdd = new BinaryTreeNode<K>();
            rightToAdd->setElement(pElement);
            pNode->setRight(rightToAdd);
            rightToAdd->setFather(pNode);
        this->lenght += 1;
            return true;
        }else{
            return addAux(pElement , pNode->getRight());
        }
    }else{
        return false;
    }
}
template <typename K>
bool BinaryTree<K>::remove(K pElement){
    if ( this->lenght == 0){
        std::cout << "Empty Tree";
        return false;
    }else{
        return removeAux(pElement , this->_root);
    }
}
template <typename K>
bool BinaryTree<K>::removeAux (K pElement , BinaryTreeNode<K>* pCurrentNode){
    BinaryTreeNode<K>* tmp = this->searchAux(pElement , pCurrentNode);
    if (tmp == 0){
        return false;
    }else{
        if ((tmp->getLeft() == 0 ) && (tmp->getRight() == 0)){
            if (*(tmp->getElement()) == pElement){
                tmp->setElement(0);
                tmp = 0 ;
                this->lenght-= 1;
                return true;
            }else{
                return false;
            }
        }else if ((tmp->getRight() == 0 ) && (tmp->getLeft() != 0)){
            tmp->setElement(*(this->highestLowest(tmp)->getElement()));
            this->lenght-= 1;
            return this->removeAux(pElement , tmp->getLeft());
        }else if ((tmp->getRight() != 0 ) && (tmp->getLeft() == 0)){
            tmp->setElement(*(this->lowestHighest(tmp)->getElement()));
            this->lenght-= 1;
            return this->removeAux(pElement , tmp->getRight());
        }else{
            tmp->setElement(*(this->lowestHighest(tmp)->getElement()));
            this->lenght-= 1;
            return this->removeAux(pElement, tmp->getRight());
        }
    }
}
template <typename K>
BinaryTreeNode<K>* BinaryTree<K>::search(K pElement){
    if (this->lenght == 0){
        return 0;
    }else{
        return searchAux(pElement , this->_root);
    }
}
template <typename K>
BinaryTreeNode<K>* BinaryTree<K>::searchAux(K pElement, BinaryTreeNode<K>* pNode){
    if (*pNode->getElement() == pElement){
        return pNode;
    }else if (*pNode->getElement() < pElement){
        if (pNode->getRight()== 0){
            return 0;
        }
        return searchAux(pElement , pNode->getRight());
    }else{
        if(pNode->getLeft() == 0){
            return 0;
        }
        return searchAux(pElement, pNode->getLeft());
    }
}
template <typename K>
bool BinaryTree<K>::ifExists(K pElement){
    if (this->search(pElement) == 0){
        return false;
    }

   return pElement == *(this->search(pElement)->getElement());
}

template <typename K>
BinaryTreeNode<K>* BinaryTree<K>::highestLowest(BinaryTreeNode<K> *pNode){
    if (pNode->getLeft() == 0){
        return pNode;
    }else{
        return lowestHighest(pNode->getLeft());
    }
}
template <typename K>
BinaryTreeNode<K>* BinaryTree<K>::lowestHighest(BinaryTreeNode<K>* pNode){
    if (pNode->getRight() == NULL){
        return pNode;
    }else{
        return highestLowest(pNode->getRight());
    }
}


#endif // BINARYTREE_H
