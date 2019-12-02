
# input
# WUBWUBABCWUB
# output
# ABC 
# input
# WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB
# output
# WE ARE THE CHAMPIONS MY FRIEND 

#one linear solution 
# def dub_step(str):
#   out = str.replace('WUB'," ")
#   print(out)

def dub_step(str):
  out=''
  j=0
  for i in range(0,len(str)):
    if str[j]=='W' and str[j+1]=='U' and str[j+2]=='B':
      j=j+2
      out+=' '
    else:
      j=j+1

      out+=str[j]

  print(out)

     

        


  







dub_step('WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB')