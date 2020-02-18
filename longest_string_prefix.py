# Write a function to find the longest common prefix string amongst an array of strings.

# If there is no common prefix, return an empty string "".

# Example 1:

# Input: ["flower","flow","flight"]
# Output: "fl"
# Example 2:

# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.


# the cpp solution
# class Solution {
# public:
#     string longestCommonPrefix(vector<string>& strs) {
#         if (strs.size() == 0) return "" ;
#         string result = "";
#         for(int i=0;i<strs[0].length();i++){
#             for(int j=1;j<strs.size();j++){
#                 if(i>strs[j].length() || strs[0][i] != strs[j][i]){
#                     return result;
#                 }      
#             }
#             result+=strs[0][i];
#         }
#         return result;
#     }
# };

def longestCommonPrefix(strs) :
    result = ""
    if len(strs) == 0: return result

    for count,c in enumerate(strs[0]):
        for strings in strs:
            if count > len(strings) or c != strings[count]:
                return result
        
        result+=c
    return result

def main():
    string_list =["flower","flow","flight"]
    result = longestCommonPrefix(string_list)
    print(result)


if __name__ == "__main__":
    main()