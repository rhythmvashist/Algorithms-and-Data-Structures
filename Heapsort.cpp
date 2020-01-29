//@author:Rhythm Vashist
/*
this file implements a heap sort that sorts the array with nlogn complexity and constant space complexity
*/

#include <iostream>
using namespace std;

//this function is used to swap the elements passed at the index.
void swap(int arr[],int parent,int child){
	int temp=arr[child];
	arr[child]=arr[parent];
	arr[parent]=temp;
}

void printArray(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


// this method check if any node node satisfy the max heap condition
bool satisfyHeap(int arr[],int root){
	int rootelem=arr[root];
	int leftNode=arr[2*root+1];
	int rightNode=arr[2*root+2];
	if(rootelem>leftNode&&rootelem>rightNode){
		return true;
	}
	return false;
}


// this methods helps us to arrange in way to implement a max heap data structure.
void makeHeap(int arr[],int size,int rootIndex){
	int root=rootIndex;
	int left=2*root+1;
	int right=2*root+2;

	if(right<size){
	  if(arr[right]>arr[root]){
			root=right;
		}
	}

	if(left<size){
	  if(arr[left]>arr[root]){
			root=left;
		}
	}

	if(root!=rootIndex){
		swap(arr,root,rootIndex);
		makeHeap(arr,size,root);
	}
}


// this method takes the index and returns the root element of the element at that index
int getParent(int index){
	return (index/2)-1;
}

// this method uses makeHeap method to make max heap and then takes the root element and keep swaping it with the last elemtn in the array and at the end sort the whole array.
void heapSort(int arr[],int size){
	
  int root=getParent(size);
	for(;root>=0;root--){
		makeHeap(arr,size,root);
	}

	for(int i=size-1; i>=0; i--){
		swap(arr,0, i); 
		makeHeap(arr,i,0);
	}
}


int main(){
	int arr[5]={10,20,2,45,1};
	int size=5;

	cout<<"Initial Array :";
    printArray(arr,size);
	heapSort(arr,size);
	cout<<"Final Array :";
    printArray(arr,size);
	return 0;
}
