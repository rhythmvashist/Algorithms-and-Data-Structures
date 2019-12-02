/*
@auhtor:rhythm vashist
this file is  semi hanoi that takes the number of no of disk from the user and moves them from
*/
#include <iostream>
using namespace std;


bool isEven(int n){
    if(n%2==0){
        return true;
    }
    return false;
}

// the hanoi function to move the disk from source to destination.

void Hanoi(int n,char sources,char destinations,char tmp){
    if(n==1){
        cout<<"moves from "<<sources<<" to "<<destinations<<endl;
    }
    else{
        Hanoi(n-1,sources,tmp,destinations);
        Hanoi(1,sources,destinations,tmp);
        Hanoi(n-1,tmp,destinations,sources);
    }
}

// this semi hanaoi methods helps to move the disk for even number of disks with the help of hanoi .
int semiHanoi(int nofdisks,char source,char destinations,char tmp){
    int moves=0;
    int n=nofdisks/2;
    moves++;
	 
	 // the base case if the n is equal to 2 as we are diving the n by 2 so we are taking the this case as n=1 
    if(n==1){
        cout<<"moves from "<<source<<" to "<<tmp<<endl;
        cout<<"moves from "<<destinations<<" to "<<tmp<<endl;
        return 2;
    }
    else{
       // here  i am using the hint given in the assignmnet , but for that we need to divide the n by 2 otherwise we would have to call thus function usung n-2 and the if condition would be 
       
        semiHanoi(2*(n-1),source,destinations,tmp);
		
		// printing the move
        cout<<"moves from "<<destinations<<" to "<<source<<endl;
   

        Hanoi(2*(n-1),tmp,source,destinations);
        Hanoi(2*n,source,tmp,destinations);
        return moves;
    }

}

int main(){
    int n;
    cout<<"enter the number of disks :";
    cin>>n;
    cout<<"the moves are :"<<endl;
    cout<<semiHanoi(n,'A','B','C')<<endl;
    return 0;
}
