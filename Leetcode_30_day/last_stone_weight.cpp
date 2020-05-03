/*
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    int diff = 0;
    if(stones.size()==0){
        return 0;
    }
    if (stones.size()==1){
        return stones[0];
    }
    sort(stones.begin(),stones.end());
    for(int i = stones.size()-1;i>0;i--){
        int first = stones[i];
        int sec = stones[i-1];
        stones.pop_back();

        if(first == sec){
            stones.pop_back();
            i--;
        }
        if(first<sec || sec<first){
            diff = abs(first-sec);
            stones[stones.size()-1]=diff;
        }
        if (stones.size()==1){
            return stones[0];
        }
        sort(stones.begin(),stones.end());
    }
}

int main() {
    vector<int> list = {10,4,2,10};
    int ans = lastStoneWeight(list);
    cout<<ans;
}