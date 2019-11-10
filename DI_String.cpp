// Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

// Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

// If S[i] == "I", then A[i] < A[i+1]
// If S[i] == "D", then A[i] > A[i+1]
 

// Example 1:

// Input: "IDID"
// Output: [0,4,1,3,2]
#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len=S.length();
        vector<int> cont;
        int low=0;
        int high=len;
        
        for(int i=0;i<len;i++){
            if(S[i]=='I'){
                cont.push_back(low++);
            }
            else{
                cont.push_back(high--);
            }
        }
        cont.push_back(low);
        return cont;
        
    }
};