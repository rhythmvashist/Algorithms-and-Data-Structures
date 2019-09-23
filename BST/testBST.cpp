/* This file is used to  test the BST  class */
#include <iostream>
#include <vector>
#include "BST.h"
#include <ctime>
#include <stack>

using namespace std;


template <typename T>
void printlist(vector<T> list){
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
void printBT(BST<T> bt){
    bt.inorder(bt.getRoot());
}

// this method get a numbre a generates a list of numbers ranging from [-n,n]

vector<int> genData(int n){
    vector<int> list;
    srand(time(0));
    for(int i=0;i<n;i++){
        list.push_back(rand()%(2*n+1)-n);
    }
    return list;
}

template <typename T>
BST<T> makeBST(vector<T> list){
    BST<T> btree;
    Node<T>* root=btree.getRoot();
    for(int i=0;i<list.size();i++){
        btree.insert(list[i],root);
    }
    return btree;
}


template <typename T>
int depth(Node<T>* node){
    if (node == nullptr)
        return 0;
    else{
        int left = depth(node->getLeft());
        int right = depth(node->getRight());
        if (left > right){
            return(left + 1);
        }
        else {
            return(right + 1);
        }
    }
}

template <typename T>
int height(BST<T> tree){
    Node<T>* root=tree.getRoot();
    return depth(root);
}


BST<char> infixExpTree(string str){
    stack<Node<char>*> holder;
    Node<char>* root;
    Node<char>* right;
    Node<char>* left;
    for(int i=0;i<str.length();i++){
        char temp=str[i];
        if(temp!='(' && temp !=')'){
            root=new Node<char>(temp,nullptr,nullptr);
            holder.push(root);
        }
        else if(temp==')'){
            right=holder.top();
            holder.pop();
            root=holder.top();
            holder.pop();
            left=holder.top();
            holder.pop();

            root->setLeft(left);
            root->setRight(right);
            holder.push(root);
        }
    }
    root=holder.top();
    holder.pop();
    BST<char> tree(root);
    return tree;
}


void InfixPostfixExpr(Node<char>* root){
    if(root!=nullptr){
        InfixPostfixExpr(root->getLeft());
        InfixPostfixExpr(root->getRight());
        cout<<root->getData()<< " " ;
    }
}

int getInput(){
    int x=0;
    cout<<"please enter any integer number : ";
    cin>>x;
    return x;
}

string getExpression(){
    string str="";
    cout<<"please enter any string : ";
    cin>>str;
    return str;
}

int main(){
     int n=getInput();
     vector<int>list=genData(n);
    cout<<"list 1 :";
    printlist(list);

    int n2=getInput();
    vector<int> list2=genData(n);
    cout<<"list 2 :";
    printlist(list2);

    BST<int> bst1=makeBST(list);
    cout<<"IN-order traversal of bst1 is : ";
    printBT(bst1);

    BST<int> bst2=makeBST(list2);
    cout<<"IN-order traversal of bst2 is : ";
    printBT(bst2);

    cout << "The height of bst1 is " << height(bst1) << endl;
    cout << "The height of bst2 is " << height(bst2) << endl;

    string infix = getExpression(); // read infix expression from input

    BST<char> bt4 = infixExpTree(infix);
    cout << "In-order traversal of bt4 is: ";
    printBT(bt4);

    Node<char>* temp=bt4.getRoot();

    InfixPostfixExpr(temp) ;
    


    return 0;
}
