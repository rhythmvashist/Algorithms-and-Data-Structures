#include "coffeeshop.h"
#include <iostream>
#include <cmath>
using namespace std;

// every function has been templated to accept any type of data

//default constructor to head and tail to null pointer
template<class T>
Queue<T>::Queue (){
    head =tail=nullptr;
}

//function to check if the queue is empty?
template<class T>
bool Queue<T>::isempty(){
    return(head==nullptr);
}

//function to enqueue in the queue
template<class T>
void Queue<T>::enqueue(T x){
    if(tail==nullptr){
        tail=new Node{x,nullptr};
        head=tail;
    }
    else{
        tail->next=new Node{x,nullptr};
        tail=tail->next;
    }
}

// function to dequeue from the queue
template<class T>
T Queue<T>::dequeue(){
    if(head==nullptr){ // display error if queue is empty
        cout<<"Queue is empty"<<endl;
        exit(1);
    }
    else{
        T retvalue=head->data;
        Node *temp=head;
        head=head->next;
        if(head==nullptr)
            tail=nullptr;
        delete temp;
        return retvalue;
    }
}

// function to print the queue
template<class T>
void Queue<T>::print(){
    Node*q =head;
    while(q!=nullptr){
        cout<<q->data<<"->";
        q=q->next;
    }
    cout<<"nullptr"<<endl;
}
