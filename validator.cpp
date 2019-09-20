
/*
@auhtor:Rhyhtm Vashist
this file read a html file and with the hep of stack checks if the file is valid or not 
*/

#include <iostream>
#include <fstream>
#include <stack>
using namespace std;


/* This function convert  all the uppercase  characters in  a string to lowercase */
string toLowerCase(string in){
    string temp="";
    for(int i=0;i<in.length();i++){
        if(in[i] <= 'Z' && in[i] >= 'A')
            temp+=in[i] - ('Z' - 'z');
        else if(in[i] <= 'z' && in[i] >= 'a'){
            temp+=in[i];
        }
    }
    return temp;
}

/* this method returns  a bool value whenver a passed string is a HTML sematics tag*/
bool isTag(string str,bool arr[2]) {
	bool result = false;
    bool isOpen = false;
	bool isClose = false;
	bool isSlash = false;
	arr[0] = false;
	arr[1] = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '<'){
			isOpen = true;
		}
		else if (str[i] == '/') {
			isSlash = true;
		}
		else if (str[i] == '>') {
			isClose = true;
		}
	}
	if (isOpen && isClose) {
		result = true;
		arr[0] = true;
	}
	if (isOpen && isClose && isSlash) {
		arr[1] = true;
	}
	return result;
}


/*  this method returns the html tag by returning the characte that is enclosed inside the the brackets*/
string gettagName(string str){
    string input="";
    bool starting=false;
    bool ending=true;
    for(int i=0;i<str.length();i++){
            if(str[i]=='<'){
                starting=true;
            }
            else if(str[i]=='>'){
                ending=false;
                break;
            }
            else if(starting&&ending){
                if(str[i]!=' '&&str[i]!='\n'&&str[i]!='\t'&&str[i]!='/'){
                    input+=str[i];
                }
            }
    }
    return input;
}

int main(){
    char input;
    int line=1;
    stack<string> s;
    ifstream myfile;
    string filepath;
    string handle="";
    string temp="";
    bool tagType[2];
    tagType[0]=tagType[1]=false;


    cout<<"Enter the name of the file :";
    cin>>filepath;
    myfile.open(filepath);

    if (!myfile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    while(!myfile.eof()){
        myfile.get(input);

        if(input=='\n'){
            line++;
        }
        if(input=='<'){

            while(input!='>'){
                temp+=input;
                myfile.get(input);
            }
            temp+=">";


            if(isTag(temp,tagType)){ // if the input string contains a tag
                if(tagType[1]){ //  it the is an closing tag then
                    handle=gettagName(temp);
                    if(toLowerCase(s.top())==toLowerCase(handle)){
                        s.pop();
                    }
                    else{
                        cout<<s.top()<<" tag is not Matching with the "<<temp<<" tag."<<endl;
                        cout<<"File is not valid error in line number :"<<line<<endl;
                        break;
                    }
                }
                else if(tagType[0]){ // if the tag is  opning tag
                    handle=gettagName(temp);
                    s.push(handle);
                }
                tagType[0]=tagType[1]=false;
                temp="";
            }
        }
    }
    if(s.empty()){// if at the end the stack is empty then the file is valid.
        cout<<"file is valid"<<endl;
    }

return 0;
}

