//Given a 2D matrix of characters and a target word, 
//write a function that returns whether the word can be found in the matrix by going left-to-right, or up-to-down.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int row=10;
const int colm=10;

/** this method takes the name of the file from which grid is to be readeen
 *
 * @return : it returns the string filename entered  by the user
 */

string getfilename(){
    string filename="";
    std::cout << "put the name of the file you want to search " << '\n';
    std::cin >> filename;
    return filename;
}


/** this methid is used to initialise all the index of the empty array
 *
 * @param grid : 2d array that need to be initialised
 * @param ch :it is the character to which all index are given value from
 */


void initialise(char grid[][colm],char ch){
    for(int i=0;i<row;i++){
        for(int j=0;j<colm;j++){
            grid[i][j]=ch;
        }
    }
}


/** this method is used to take the word input from the user that need to be searched from the grid
 *
 * @return : the word that is entred by the user
 */

string getword(){
    string word="";
    std::cout << "Put the word you want to look in the file" << '\n';
    std::cin >> word;
    return word;
}


/** this methid is used to convert each character if the word to uppercase
 *
 * @param key : the input that needs to be converted to uppercase
 * @return : it returns the uppercased key
 */

string touppercase(string key){
    for(unsigned i=0;i<key.length();i++){
        if(key[i]>='a'&&key[i]<='z'){
            key[i]=key[i]-('a'-'A');
        }
    }
    return key;
}


/** this array is used to print the 2d ARRAYS
 *
 * @param grid : the character array that is neede to be supported
 */

void printarray(char grid[][colm]){
    std::cout << "grid is " << '\n';
    for(int i=0;i<row;i++){
        for(int j=0;j<colm;j++){
            std::cout << grid[i][j]<<" " ;
        }
        std::cout  << '\n';
    }
}

/**  this is the recursive method that repeats itself utill it find the right path of the word.
 *
 * @param grid : the 2d array on which the path is neede to be searched
 * @param xc : its the index of row where the first letter of the word is found
 * @param yc :its the index of column where the first letter of the word is found
 * @param pos : it is  the index position of the word's character tat is being serached
 * @param word : the word that is been looked for
 * @param rows : it the total number of rows given int the text file
 * @param colmn:it the total number of column given int the text file
 * @param output : it is a empty 2d array with same dimension as of grid it is used to represent the output
 * @return:  it returns boolean value depending upon the conditions tested
 */

bool searchword(char grid[][colm],int xc,int yc,unsigned  pos ,string word,int rows,int colmn,char output[][colm]){
    if(grid[xc][yc]!=word[pos]){
        return false;
    }
    if(pos==word.length()-1){
        output[xc][yc]='*';
        return true;
    }
    if(0>xc||xc>=rows||0>yc||yc>=colmn){
        return false;
    }
    if(searchword(grid,xc+1,yc,pos+1,word,row,colm,output)){
        output[xc][yc]='V';
        return true;
    }
    if(searchword(grid,xc-1,yc,pos+1,word,rows,colm,output)){
        output[xc][yc]='^';
        return true;
    }
    if(searchword(grid,xc,yc+1,pos+1,word,rows,colm,output)){
        output[xc][yc]='>';
        return true;
    }
    if(searchword(grid,xc,yc-1,pos+1,word,row,colm,output)){
        output[xc][yc]='<';
        return true;
    }
    return false;
}

/**  this method reads the text file for getting the value for rows and colum and then callong the recursive funtion
 *
 * @param filename  : the name of the file on ehich the text is given
 * @param word : the word that is to be found from the grid given by the user
 * @param grid : the 2d array that has the grids stored in it
 * @param output : the empty 2d array that is used to show output
 * @return  : it return a boolean value depending upon if the word is found or not
 */

bool initialstart(string filename,string word,char grid[][colm],char output[][colm]){
    int rows=0;
    int colms=0;
    int pos =0;
    string line="";

    ifstream myfile(filename);
    if(myfile.is_open()){
        if(getline(myfile,line)){
            rows=(int)line[0]-'0';
        }
        if(getline(myfile,line)){
            colms=(int)line[0]-'0';
        }
        myfile.close();
    }
    else{
        std::cout << "file not found" << '\n';
    }

    /////////////// FILE IS READ AND GRID ARRAY IS  IS MADE /////////////////


    for(int i=0;i<rows;i++){
        for (int j=0; j<colms;j++){
            if(grid[i][j]==word[pos]){
                if(searchword(grid,i,j,pos,word,rows,colms,output)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    char grid[row][colm];
    char output[row][colm];

    initialise(grid,' ');
    initialise(output,'_');
    string filename=getfilename();
    string line="";
    ifstream myfile(filename);
    if(myfile.is_open()){
        getline(myfile,line);
        getline(myfile,line);
        int i=0;
        while(getline(myfile,line)){
            for(unsigned int j=0;j<line.length();j++){
                grid[i][j]=line[j];
            }
            i++;
        }
    }
    else{
        std::cout << "unable to open file" << '\n';;
    }
    printarray(grid);
    string word=getword();
    word=touppercase(word);
    std::cout << "word is " <<word<< '\n';
    if(initialstart(filename,word,grid,output)){

        printarray(output);
    }
    else{
        std::cout << "Unable to find the Path" << '\n';
    }
    return 0;
}