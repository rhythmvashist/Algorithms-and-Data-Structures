/*
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
*/

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

bool pair_exist(vector<int> A ,int sum){
    
    int l, r; 
    /* Sort the elements */
    sort(A.begin(),A.end());
    /* Now look for the two candidates in  
       the sorted array*/
    l = 0; 
    r = A.size()-1; 
    while (l < r) {   
        if (A[l] + A[r] == sum) 
            return true; 
        else if (A[l] + A[r] < sum) 
            l++; 
        else // A[i] + A[j] > sum 
            r--; 
    } 
    return false; 
}

int main(){
  vector <int> list {10,15,3,55};
  int k = 17;
  if(pair_exist(list,k)){
    cout<<"yes"<<endl;
  }
  else{
    cout<<"no"<<endl;
  }
  return 0;
}