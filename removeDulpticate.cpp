// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Given nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

// It doesn't matter what you leave beyond the returned length.

#include <iostream>
#include <vector> 
#include <set>

using namespace std;

int removeDuplicates(vector<int>& nums) {
            set<int> result;
            for(int i=0;i<nums.size();i++){
                int x=nums[i];
                // that means element is not present 
                if(result.find(x)==result.end() ){
                    result.insert(x);
                }   
            }

            for(int yresult) cout <<y<<endl;
            return result.size();
        
}

int main(){
    vector<int> input ;
    input.push_back(1);
    input.push_back(1);
    input.push_back(2);
    int result = removeDuplicates(input);
    cout<<result<<endl;
    return 0;
}