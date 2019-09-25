//
// Created by Rhythm vashist on 2018-10-15.
//
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const int ROWS=6;
const int COLM=6;

/** This function takes two index of the array and swap the number on the corresponding indexes
 *
 * @param arr  : the array in which numbers are ti be swaped
 * @param initial : the index of the first number
 * @param fin : the index  of the second number
 */
void swap(int arr[],int initial,int fin){
    int temp=arr[initial];
    arr[initial]=arr[fin];
    arr[fin]=temp;
}

/** this array is used to print the array
 *
 * @param arr
 * @param n
 */
void printarry(int arr[],int n){
    for(int i=0;i<n;i++){
        std::cout << arr[i] <<" ";
    }
    std::cout  << '\n';
}
/** this function takes the array and set a random number to each index of the array
 *
 * @param arr  : the array that needs to be initialisd
 * @param size : the size of the array passed as the parameter
 */
void genrandarray(int arr[],int size){
    for(int i =0;i<size;i++){
        arr[i]=rand();
    }
}
/** this function set all the values of the 2d array to  0 so as to make sure no index has garbage value
 *
 * @param arr: the array that is to be initialised
 */
void initialise2d(double arr[][COLM]){
    for (int i = 0; i < ROWS; i++) {
        for(int j=0;j<COLM;j++){
            arr[i][j]=0;
        }
    }
}
/** this function is used to print the 2d array in this case the final tabke havung all the values
 *
 * @param arr : the 2d  array that has all the values inside it
 * @param a : the 1d array having the vaues of the size of the various array that are needed to be made
 */

void printarry(double arr[][COLM],int a[]){
    std::cout << "   N     S(n)       S(n)/n^2             Q(n)    Q(n)/nlogn           M(n)    M(n)/nlogn" << '\n';
    for(int i=0;i<ROWS;i++){
        if(i<=3){
            std::cout <<" "<< a[i]<<"      " ;
        }
        else{
            std::cout << a[i]<<"      " ;
        }
        for(int j=0;j<COLM;j++){
            std::cout<<arr[i][j]<< setw(15);
        }
        std::cout  << '\n';
    }
}
/** this function help us to sort the guven array with the help of swaping the lower number with a higher number
 *
 * @param arr : the array that needs to be sorted
 * @param n : the size of the array that is to be sorted
 */
void selectionSort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int temp=arr[i];
        for(j=i+1;j<n;j++){
            if(arr[j]<temp){
                swap(arr,i,j);
            }
        }
    }
}
/** this method helps us to find a partition in an array and arrange the number with the smaller number on the one side and the
 *greater number on the other side of the partition and placing the partiton at the right postiton.
 * @param arr : the array in which the partiton was to be founded
 * @param low: the index of the left most value
 * @param high : the index of the rightmost value of the array
 * @return: this function returns the index of the array where the partition number is placed
 */
 /*
 int partition(int arr[], int low, int high ){
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
 */
 int partition(int A[],int low,int high)
 {
     int pivot = A[high];
     int i = (low - 1);

     for (int j = low; j <= high- 1; j++)
     {
         if (A[j] <= pivot)
         {
             i++;
             swap(A,i,j);
         }
     }
     swap(A,i+1,high);
     return (i + 1);

 }

/** this ary helps us to sort the arry by determing the partiton and then sorting the array by sorting the left side
 * and the right side of the array
 * @param arr  : the array thats need to be sorted
 * @param start : the index of the lowest position in the array
 * @param end : the highest idex till which the insertion sort needs to work and sort the array
 */
void quicksort(int arr[],int start,int end){
    if(start<end){
        int part=partition(arr,start,end);
        quicksort(arr,start,part-1);
        quicksort(arr,part+1,end);
    }
    return;
}
/** this method calls the quicksort function that sorts the array
 *
 * @param arr : the array thats need to be sorted
 * @param size : the size of the array thats need to be sorted
 */
void quicksort(int arr[],int size){
    int low=0;
    int high=size-1;
    quicksort(arr,low,high);
}

/** this function takes the array and breaks it into 2 different parts  and then sorts the two differenet array
 *  amd then combine both the array to make the final sorted array
 *
 * @param arr : the array thats need to be sorted
 * @param low : the lowest index of the array in which the function need to be called
 * @param mid : the centre of the array
 * @param high : the highest index of the array
 */

void merge(int A[], int a_start, int a_end, int b_start, int b_end, int w[]){
    int i, j, k;
    i = a_start;
    j= b_start;
    k = a_start;
    while (i <= a_end && j <= b_end){
        if(A[i] < A[j])
          w[k+1] = A[i++];
        else if (A[i] > A[j])
          w[k++] = A[j++];
        else{
          w[k++] = A[i++];
          w[k+1] = A[j++];
        }
        while(i <= a_end){
          w[k++] = A[i++];
        }
        while(j<=b_end){
          w[k++] = A[j++];
        }
        for(int x = a_start; i <=b_end; i++){
          A[x] = w[x];
        }
    }
}

/** this method calls the merge method that breaks the array in two differenet parts and the make it sorted
 *
 * @param arr : the array that needs ti be sorted
 * @param low: the lowest index of the array
 * @param high : the highest index of teh array till whc the array needs to be sorted
 * @param w :  this
 */

void mergesort(int A[], int low, int high, int w[]){
  if (low == high)
    return;
  int mid = (low + high) / 2 ;
  mergesort(A, low, mid, w);
  mergesort(A, mid+1, high, w);
  merge(A, low, mid, mid +1, high, w);
  return;
}

//this method callls the the main mergesort method that sorts the array

void mergesort(int arr[],int size){
    int low=0;
    int high=size;
    int w[32000];
    //mergesort(arr,low,high);
    mergesort(arr,low,high,w);
}

/** the function runs the selection sort method 100 times on each array of the length  from 1000 to 32000 as given and stores the averge
 * time taken to sort the array in the 2d array
 * *
 * @param arry :the 2d array tha stores the result of the sorting time
 * @param col1 : the column index of the 2d arary to store the value in the correct column
 * @param col2  : the column index of the 2d arary to store the value in the correct column
 * @param len  : the length of the arry having differnt length as its values
 * @param sizearray : it is a 1d array that has the size of the various array stored it it that are required to be checked
 */
void selectionsortcalculations(double arry[][COLM],int col1,int col2,int len,int sizearray[]){
    for(int index=0;index<len;index++) {
        int arr[sizearray[index]];
        int start = clock();
        for (int i = 0; i < 100; i++) {
            genrandarray(arr, sizearray[index]);
            selectionSort(arr, sizearray[index]);
        }
        double tot=(clock()-start)/100.0;
        double com=tot/(pow(sizearray[index],2)*1.0);
        arry[index][col1]=tot;
        arry[index][col2]=com;
        cerr<<" the s("<<sizearray[index]<<")  is  "<<tot<<endl;
        cerr<<" the s("<<sizearray[index]<<")/n^2  is  "<<tot/(pow(sizearray[index],2)*1.0)<<endl;
    }
}

/** the function runs the  quick sort method 100 times on each array of the length  from 1000 to 32000 as given and stores the averge
 * time taken to sort the array in the 2d array
 * *
 * @param arry :the 2d array tha stores the result of the sorting time
 * @param col1 : the column index of the 2d arary to store the value in the correct column
 * @param col2  : the column index of the 2d arary to store the value in the correct column
 * @param len  : the length of the arry having differnt length as its values
 * @param sizearray : it is a 1d array that has the size of the various array stored it it that are required to be checked
 */

void quicksortcalculations(double arry[][COLM],int col1,int col2,int len,int sizearray[]){
    for(int index=0;index<len;index++) {
        int n=sizearray[index];
        int arr[32000];
        double start = clock();
        for (int i = 0; i < 100; i++) {
            genrandarray(arr, sizearray[index]);
            quicksort(arr,sizearray[index]);
        }
        double tot=(clock()-start)/100.0;
        double com=tot/(n*(log (n)/log (2)));
        arry[index][col1]=tot;
        arry[index][col2]=com;
        cerr<<" the Q("<<sizearray[index]<<") is  "<<tot<<endl;
        cerr<<" the Q("<<sizearray[index]<<")/is "<<tot/(n*(log (n)/log (2)))<<endl;
    }
}
/** the function runs the merge sort method 100 times on each array of the length  from 1000 to 32000 as given and stores the averge
 * time taken to sort the array in the 2d array
 * *
 * @param arry :the 2d array tha stores the result of the sorting time
 * @param col1 : the column index of the 2d arary to store the value in the correct column
 * @param col2  : the column index of the 2d arary to store the value in the correct column
 * @param len  : the length of the arry having differnt length as its values
 * @param sizearray : it is a 1d array that has the size of the various array stored it it that are required to be checked
 */
void mergesortcalculations(double arry[][COLM],int col1,int col2,int len,int sizearray[]){
    for(int index=0;index<len;index++) {
        int n=sizearray[index];
        int arr[32000];
        int start = clock();
        for (int i = 0; i < 100; i++) {
            genrandarray(arr, sizearray[index]);
            mergesort(arr,sizearray[index]);
        }
        double tot=(clock()-start)/100.0;
        double com=tot/(n*(log (n)/log (2)));
        arry[index][col1]=tot;
        arry[index][col2]=com;
        cerr<<" the M("<<sizearray[index]<<") is  "<<tot<<endl;
        cerr<<" the M("<<sizearray[index]<<")/is "<<tot/(n*(log (n)/log (2)))<<endl;
    }
}


int main() {
    srand(time(0));
    double arry[ROWS][COLM];
    int sizearray[6]={1000,2000,4000,8000,16000,32000};
    int len= sizeof(sizearray)/sizeof(sizearray[0]);
    initialise2d(arry);
    quicksortcalculations(arry,2,3,len,sizearray);
    std::cout  << '\n';
    mergesortcalculations(arry,4,5,len,sizearray);
    std::cout  << '\n';
    std::cerr << "Processing is going on it may take some time to generate the table please wait " << '\n';
    selectionsortcalculations(arry,0,1,len,sizearray);
    printarry(arry,sizearray);
    return 0;
}
