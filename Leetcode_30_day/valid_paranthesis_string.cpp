#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int leftcount=0;
        int rightcount=0;
        int asterick=0;
        for(char c:s){
            if(c=='('){
                leftcount++;
            }
            else if(c==')'){
                rightcount++;
            }
            else if(c=='*'){
                asterick++;
            }
        }
        if(leftcount==rightcount){
            return true;
        }
        if(leftcount>rightcount){
            if(leftcount==(rightcount+asterick)){
                return true;
            }
        }
        if(leftcount<rightcount){
            if((leftcount+asterick)==(rightcount)){
                return true;
            }
        }
        return false;
    }

    bool checkValidString(string str){
        stack<char> holder;
            int ast=0;
            for(char c: s){
                if(!holder.empty()){
                    if(c=='*'){
                        ast++;
                    }
                    else if(c=='('){
                        holder.push(c);
                    }
                    else{
                        char temp = holder.top();
                        if(temp=='('){
                            holder.pop();
                        }
                        else{
                            holder.push(c);
                        }
                    }
                }
                else if (c=='*'){
                    ast++;
                }
                else{
                    holder.push(c);
                }
            }
            
            while(ast>0){
                if(!holder.empty()){
                    holder.pop();
                }
                ast--;
            }

            if(holder.empty()){
                return true;
            }

            return false;
        }
};