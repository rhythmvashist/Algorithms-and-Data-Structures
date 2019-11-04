# Balanced strings are those who have equal quantity of 'L' and 'R' characters.
# Given a balanced string s split it in the maximum amount of balanced strings.
# Return the maximum amount of splitted balanced string

# Input: s = "RLRRLLRLRL"
# Output: 4
# s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

def balancedStringSplit(s):
  print(s)
  for index,character in enumerate(s):
    counter = 0
    if(index+1)<len(s):
      print(s[index],s[index+1])
    #print(index,character)



balancedStringSplit("RLRLLLL")