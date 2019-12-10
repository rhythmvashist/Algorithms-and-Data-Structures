#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int size = nums.size();
      int elem = nums[0];
      int count = 0;
      for (int i=0;i<size;i++){     
        if (nums[i]== elem){
          count++;
        }
        else{
          count--;
        }

      }
        
    }
}