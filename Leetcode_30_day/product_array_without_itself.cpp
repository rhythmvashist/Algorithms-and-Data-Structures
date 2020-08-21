/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> ans(size) ;
    int product =1 ;
    int product_with_zero=1;
    int zeroc=0;

    for(int t:nums){
        product*=t;
        if(t==0){
            zeroc++;
        }
        else{
            product_with_zero*=t;
            
        }
    }

    if(product!=0){
        for(int i=0;i<size;i++){
            ans[i]=product/nums[i];
        }
    }
    
    else if(zeroc==1){
        for(int i=0;i<size;i++){
            if(nums[i]==0){
                ans[i]= product_with_zero;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> input={1,2,3,4};
    vector<int> result= productExceptSelf(input);
}
