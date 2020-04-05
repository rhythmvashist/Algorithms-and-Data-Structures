// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Example 1:
// Input: [2,2,1]
// Output: 1

// Example 2:
// Input: [4,1,2,1,2]
// Output: 4



# include <bits/stdc++.h> 
using namespace std;


int singleNumber(int nums[],int n) 
{ 
    map<int,int> m; 
    long sum1 = 0,sum2 = 0; 
  
    for(int i = 0; i < n; i++) { 
        if(m[nums[i]] == 0) { 
            sum1 += nums[i]; 
            m[nums[i]]++; 
        } 
        sum2 += nums[i]; 
    } 
      
    // applying the formula. 
    return 2 * (sum1) - sum2; 
} 

//check if the elem count is one then return the numbr else return -99
int getSingleNumber(int nums[],int n){
  map<int,int> m;

  for(int i=0;i<n;i++){
    m[nums[i]]++;
  }
  for(int i=0;i<n;++i){
    if(m[nums[i]]==1){
      return nums[i];
    }
  }
  return -99;
}


// using XOR to solve this situation (1 ^ 1 = 0)
int singleNumber(int nums[],int size) {
        int res = nums[0];
        for(int i=1;i < nums.size();i++){
            res = res ^ nums[i];
        }
        return res;
       
    }  


// Driver code 
int main() 
{ 
    int a[] = {2, 3, 5, 4, 5, 3, 4}; 
    int n = 7; 
    cout << singleNumber(a,n) << "\n"; 
  
    int b[] = {15, 18, 16, 18, 16, 15, 89}; 
  
    cout << getSingleNumber(b,n)<<"\n"; 
    return 0; 
} 