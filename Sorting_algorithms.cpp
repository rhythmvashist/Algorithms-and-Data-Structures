#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void swap(int arr[],int initial,int fin){
     int temp=arr[initial];
     arr[initial]=arr[fin];
     arr[fin]=temp;
}

void printarry(int arr[],int n){
    for(int i=0;i<n;i++){
        std::cout << arr[i] <<" ";
    }
    std::cout  << '\n';
}

void selectionSort(int arr[],int n){
    int i,j,min,loc;
    for(i=0;i<n-1;i++){
        int temp=arr[i];
        loc=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<temp){
                loc=j;
            }
        }
        swap(arr,i,loc);

    }
}

//// this partition always take the the first index as the pivot
/// this oneis from ryan better avaible on geeksquad.

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int a = low+1;
    int b = high;
    while (b > a){
        if (arr[a] <= pivot && arr[b] > pivot){
            a++;
            b--;
        }
        else if (arr[a] > pivot && arr[b] > pivot){
            b--;
        }
        else if (arr[a] > pivot && arr[b] <= pivot){
            swap(arr, a , b);
            a++;
            b--;
        }
        else if (arr[a] <= pivot && arr[b] <= pivot){
            a++;
        }
    }
    if (arr[a] <= pivot){
        swap(arr, a, low);
        return a;
    }
    else{
        swap(arr, a-1, low);
    }
    return a-1;
}

void quicksort(int arr[],int start,int end){
    if(start<end){
        int part=partition(arr,start,end);
        quicksort(arr,start,part-1);
        quicksort(arr,part+1,end);
    }
    return;
}

int main() {
    /////////// RANDOM ARRY FOR TESTING ////////
    int arr[6]={18,3,10,7,8,1};
    ///////////////////////////////////////////
    int len= sizeof(arr)/sizeof(arr[0]);
    int part=partition(arr,0,len);
    std::cout << "the part is " <<part <<"and the arr value is " <<arr[part]<<'\n';
    printarry(arr,len);

    selectionSort(arr,len);
    printarry(arr,len);
    std::cout << "quck sort start" << '\n';

     int arry[6]={18,3,10,7,8,1};
     quicksort(arry,0,len-1);
     printarry(arry,len);

    return 0;
}
