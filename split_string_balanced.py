# Balanced strings are those who have equal quantity of 'L' and 'R' characters.
# Given a balanced string s split it in the maximum amount of balanced strings.
# Return the maximum amount of splitted balanced string

# Input: s = "RLRRLLRLRL"
# Output: 4
# s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

def balancedStringSplit(s):
  counter = 0
  ans=0
  for index,character in enumerate(s):
    if character =='R':
      counter=counter+1
    else:
      counter=counter-1
  
    if counter==0:
      ans=ans+1
 
  return ans
    

ans = balancedStringSplit("RLRL")
print(ans)