#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int size = nums.size();
      int count = 1;
      int index =0;
      for (int i=0;i<size;i++){ 
        if (nums[index] == nums[i]){
          count++;
        }
        else{
          count --;
        }
        if(count ==0){
          index = i;
          count =1;
        }
        

    }
    return nums[index];
}