#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int size = nums.size();
      int count = 0;
      int maxcount = 0;
      int index =-1;
      for (int i=0;i<size;i++){ 
        for(int j=0;j<size;j++){   
         
          if (nums[i]==nums[j]){
            count++;
          }
        
        }
        if (count >maxcount){
          maxcount =count;
          index = i;
        }
      }

      if (maxcount > size/2){
        return nums[index];
      }

        
    }
}