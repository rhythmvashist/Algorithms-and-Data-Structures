#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = 0;
        map<string,vector<string>> result;
        for(string s :strs){
            string s2 = s;
            sort(s2.begin(),s2.end());
            result[s2].push_back(s);
        }
        vector<vector<string>> out;
        for (auto pp:result){
            out.push_back(pp.second);
        }
        return out;
    }
};