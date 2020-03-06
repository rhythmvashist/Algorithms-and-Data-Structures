// Given a mapping of digits to letters (as in a phone number), and a digit string, return all possible letters the number could represent. You can assume each valid number in the mapping is a single digit.

// For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then “23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].
# include <iostream>
# include <vector>
using namespace std;

void getLetterCombiantion(){

}

vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(!digits.empty()){
            getLetterCombiantion();
            return result;
        }

}

/*
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList();
        if(digits!=null && digits.length()>0)
        getLetterComb(digits.toCharArray(), 0, "", result);
        return result;
    }
    
    private void getLetterComb(char[] chars, int i, String curr, List<String> result){
        char[] next = new char[]{};
        switch(chars[i]){
            case '2':
                next = new char[]{'a','b','c'};
                break;
            case '3':
                next = new char[]{'d','e','f'};
                break;
            case '4':
                next = new char[]{'g','h','i'};
                break;
            case '5':
                next = new char[]{'j','k','l'};
                break;
            case '6':
                next = new char[]{'m','n','o'};
                break;
            case '7':
                next = new char[]{'p','q','r','s'};
                break;
            case '8':
                next = new char[]{'t','u','v'};
                break;
            case '9':
                next = new char[]{'w','x','y','z'};
                break;
        }
        for(char c : next){
            String temp = curr+c;
            if(i==chars.length-1){
                result.add(temp);
            } else {
                getLetterComb(chars, i+1, temp, result);
            }
        }
    }
}

*/