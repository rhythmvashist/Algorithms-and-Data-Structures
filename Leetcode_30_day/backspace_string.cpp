//
//  main.cpp
//  Debug_project
//
//  Created by Rhythm Vashist on 2020-04-11.
//  Copyright © 2020 Rhythm Vashist. All rights reserved.
//

// Backspace String Compare
// Solution
// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

// Example 1:

// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:

// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:

// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".


#include <iostream>
//#include<bits/stdc++.h>
#include <queue>
using namespace std;

string getstring(queue<char> &q, string str){
        int count =0;
        for(char c:str){
          q.push(c);
        }
        string temp="";
        string per="";
        while(!q.empty()){
            char c = q.front();
            q.pop();
            if(c=='#'){
                temp=per;
                count++;
                if(count>0){
                  if (temp.length()>0){
                    temp.erase(temp.begin()+temp.length()-1);
                  }
                }
            }
            else{
                per=temp;
                temp+=c;
                count=0;
            }
        }
        return temp;
    }
    
int main() {
  std::cout << "Hello World!\n";
  queue<char> s1;
  queue<char> s2;
  string S= "abc##de";
  string T="abc###de";
  string ss= getstring(s1,S);
  string st = getstring(s2,T);
 cout<<ss<<"\n"<<st<<'\n';
     if(ss==st) cout<<"yes";
cout<<"no";
  return 0;
}
