// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]

#include <iostream>
#include <vector>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size =nums.size();
        int pointer  =0;
        for(int x:nums){
            if(x!=0){
                nums[pointer] = x;
                pointer++;
            }
        }
        
        for(int i=pointer;i<size;++i){
            nums[i]=0;
        }
        
    }
};