#ifndef STACKNODE_Hp
#define STACKNODE_H
#include "interfaces/interfaceNode.h"
template <typename K>
class StackNode : public interfaceNode<K>{
public:
    StackNode();
    StackNode<K>* getUnder();
    void setUnder(StackNode<K>* pElement);
    bool operator == (StackNode<K>* pStackNodeToCompare);
private:
    StackNode<K>* _underMe;


};
template <typename K>
StackNode<K>::StackNode(){
    this->_underMe = 0;
}

template <typename K>
StackNode<K>* StackNode<K>::getUnder(){
    return this->_underMe;
}
template <typename K>
void StackNode<K>::setUnder(StackNode<K>* pElement){
    this->_underMe = pElement;
}

template<typename K>
bool StackNode<K>::operator ==(StackNode<K>* pStackNodeToCompare){
    if(*this->getElement() == *pStackNodeToCompare->getElement()){
        return true;
    }else{
        return false;
    }
}

#endif // STACKNODE_H
