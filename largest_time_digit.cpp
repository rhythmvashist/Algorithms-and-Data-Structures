// Largest Time for Given Digits
// Given an array of 4 digits, return the largest 24 hour time that can be made.

// The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

// Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

// Example 1:

// Input: [1,2,3,4]
// Output: "23:41"
// Example 2:

// Input: [5,5,5,5]
// Output: ""

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void getPermutation(string str, int low, int high, vector<string> &res)
{
    if (low == high)
    {
        res.push_back(str);
    }
    else
    {
        for (int i = low; i <= high; i++)
        {
            swap(str[low], str[i]);
            getPermutation(str, low + 1, high, res);
            swap(str[low], str[i]);
        }
    }
}

//checking if the given string is valid time
bool isValid(string str)
{
    if ((stoi(str.substr(0, 2))) <= 23 && 60 >= stoi(str.substr(2, str.length())))
    {
        return true;
    }
    return false;
}

string largestTimeFromDigits(vector<int> &A)
{
    string result = "";

    string str = "";
    for (int val : A)
    {
        str += to_string(val);
    }
    vector<string> res;
    getPermutation(str, 0, str.length() - 1, res);

    for (int i = 0; i < res.size(); i++)
    {
        if (isValid(res[i]))
        {
            if (result == "")
            {
                result = res[i];
            }
            else
            {
                if (stoi(res[i]) > stoi(result))
                {
                    result = res[i];
                }
            }
        }
    }

    string out = "";
    for (int i = 0; i < result.length(); i++){
        if (i == 2){
            out += ":";
        }
        out += result[i];
    }
    return out;
}

int main() {
  vector<int> a={2,2,2,2};
  cout<<largestTimeFromDigits(a);
}