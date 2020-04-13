// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

// Example: 

// Input: 19
// Output: true
// Explanation: 
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

#include <iostream>
#include <set>
using namespace std;

class Solution {
    
public:
    int getsq(int n){
        int sq=0;
        while(n){
            int digit = n%10;
            sq+= digit*digit;
            n= n/10;
        }
     return sq;   
    }
    
    bool isHappy(int n) {        
       set<int> visited;
        while(n!=1){
            int x = getsq(n);
            if(visited.count(x)){
                return false;
            }
            n=x;
            visited.insert(x);
        }
        return true; 
    }
};