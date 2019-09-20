
//This program takes two string and using recurrsion tries to find the the subsequnce of second string inside the first sequence 

 #include <iostream>

using namespace std;

//THIS METHOD IS USED TO FIND THE NUMBER OF PATH FROM THE GIVEN CO-ORDINATE TO THE THR HOME THAT IS SITUATEED AT THE ORIGIN
int numPathFromHome(int street,int avenue){
  if(street==0||avenue==0){
    return 1;
  }
  return numPathFromHome(street-1,avenue)+numPathFromHome(street,avenue-1);
}

// THIS Method is used to find if the given string s is a subsequnece of the string t
bool hasSubSequence(const string& t,const string& s){
  int tLen=t.length();
  int sLen=s.length();

  // if we reach the end of first string without returing false that concludes that all characters of a are in t
  if(sLen==0){
    return true;
  }
  // if any character doesnt matches it stops the whole function and return false
  if(tLen==0){
    return false;
  }
  //if first characters of both the string matches then check for further characters
  if(t[0]==s[0]){
    return hasSubSequence(t.substr(1,tLen),s.substr(1,sLen));
  }
  //if the first character of both string are not same then check for the second character of the first string and the first character of second string
  else{
    return hasSubSequence(t.substr(1,tLen),s);
  }
}

int main(){
  cout<<"The total number of path for Eric to reach home from 3,4 are " <<numPathFromHome(3,4)<<endl;
  cout<<"The total number of path for Eric to reach home from 6,5 are " <<numPathFromHome(6,5)<<endl;
  cout<<"The total number of path for Eric to reach home from 1,2 are " <<numPathFromHome(1,2)<<endl;

  string str="goldenstatewarriors";
  string sub="state";
  if(hasSubSequence(str,sub)){
    cout<<"There is a subsequence present in the string "<<str<< "with the subequnece of " <<sub<<endl;
  }
  else{
    cout<<"No Subsequence exists"<<endl;
  }

  str="torontoraptors";
  sub="kni";
  if(hasSubSequence(str,sub)){
    cout<<"There is a subsequence present in the string "<<str<<" with the subequnece of " <<sub<<endl;
  }
  else{
    cout<<"No Subsequence exists"<<endl;
  }
  return 0;
}
