#ifndef STACK_H
#define STACK_H

#include "stackNode.h"
const int EMPTY = 0;
const int FIRST_POSITION = 0;
template <typename K>
class Stack{
public:
    Stack();
    bool push(K pNewTop);
    StackNode<K>* top();
    StackNode<K>* pop();
    bool isEmpty();
    bool ifExists(K pElement);
    unsigned int getLenght();
    bool operator == (Stack<K>* pStackToCompare);
private:
    int _lenght;
    StackNode<K>* _top;
};
template<typename K>
Stack<K>::Stack(){
    this->_lenght = EMPTY;
    this->_top= NULL;
}

template <typename K>
bool Stack<K>::isEmpty(){ return this->_lenght == EMPTY;}

template <typename K>
unsigned int Stack<K>::getLenght(){return this->_lenght;}

template <typename K>
StackNode<K>* Stack<K>::top(){return this->_top;}

template <typename K>

StackNode<K>* Stack<K>::pop(){
     StackNode<K>* tmp = this->_top;
     this->_top = this->_top->getUnder();
     this->_lenght-=1;
     return tmp;
}

template <typename K>
bool Stack<K>::ifExists(K pElement){
    if (this->_lenght == EMPTY){
        return false;
    }
    StackNode<K>* current = this->_top;
    for ( int i = EMPTY ; i < this->_lenght ; i++){
        if (*(current->getElement()) == pElement){
            return true;
        }else{
            if ( current->getUnder() == NULL){
                return false;
            }
            current = current->getUnder();
        }
    }
    return false;
}

template <typename K>
bool Stack<K>::push(K pElement){
    if (this->_lenght == EMPTY){
        StackNode<K>* tmp = new StackNode<K>();
        tmp->setElement(pElement);
        this->_top = tmp;
        this->_lenght += 1;
        return true;
    }else{
        StackNode<K>* tmp = new StackNode<K>();
        tmp->setElement(pElement);
        tmp->setUnder(this->_top);
        this->_top = tmp;
        this->_lenght += 1;
        return true;
    }
    return false;
}

template <typename K>
bool Stack<K>::operator ==(Stack<K>* pStackToCompare){
    if (this->_lenght == pStackToCompare->getLenght()){
        StackNode<K>* tempTop = this->_top;
        StackNode<K>* tempTopToCompare = pStackToCompare->top();
        for (int counter = FIRST_POSITION ;counter <= this->getLenght();counter++){
            if(*tempTop==*tempTopToCompare){
                tempTop= tempTop->getUnder();
                tempTopToCompare = tempTopToCompare->getUnder();
            }else{
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

#endif // STACK_H
