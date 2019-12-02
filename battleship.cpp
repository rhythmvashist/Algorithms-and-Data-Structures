/*
 * name : Rhythm vashist
 */
#include <iostream>
#include <ctime>

using namespace std;
const int ROWS=10;
const int COLUMN =10;


/** this method take the 2d array as the input and initalise each element with character '-'
 *
 * @param board : it takes 2d array as the input
 */
void createbord(char board[][COLUMN]){
    for(unsigned int i=0;i<COLUMN;i++){
        for(unsigned int j=0;j<ROWS;j++){
            board[i][j]='-';
            cout<<board[i][j];
        }
        cout<<" "<<endl;
    }
}

/**  this methiod tales 2d array as the input and print both of them simualtanoeusly
 *
 * @param board  : it the user side of the board
 * @param computerboard : this is 2d array of the computer side of teh board
 */

void printbord(char board[][COLUMN],char computerboard[][COLUMN]){
    std::cout << "   ABCDEFGHIJ       ABCDEFGHIJ" << '\n';
    for(unsigned int i=0;i<COLUMN;i++){
        std::cout <<i <<"| " ;

        for(unsigned int j=0;j<ROWS;j++){
            cout<<board[i][j];
        }
        cout<<"       ";
        for(unsigned int j=0;j<ROWS;j++){
            cout<<computerboard[i][j];
        }
        cout<<" "<<endl;
    }
}

/** it loops through the  2-D array passed as  a parameter and generate various ships at different locations
 *
 * @param board : the 2d array on which the ships are generated
 * @param size : it is the size of the ship that is to be generated
 * @param initial  : it is the initial letter of the name of the ship that is generated
 */

void generateships(char board[][COLUMN],int size,char initial){
    int irows,jcolumns,orientation;
    repeatrandom:
    do{
        irows=rand()%ROWS;
        jcolumns=rand()%COLUMN;
        orientation=rand()%2;

    }while(board[irows][jcolumns] !='-');

    //for horizontal orientation
    if(orientation==0){
        while(jcolumns+size>=COLUMN){
            jcolumns=rand()%COLUMN;
        }
        // checking that no ship is present at the current defired position.
        int count1=0;
        for(unsigned int j =jcolumns;j<jcolumns+size;j++){
            if(board[irows][j] !='-'){
                goto repeatrandom;
            }
        }
        //printing the ship initial.
        for(unsigned int j =jcolumns;j<jcolumns+size;j++){
            board[irows][j]=initial;
        }
    }
    if(orientation==1){
        while (irows+size>=ROWS){
            irows=rand()%ROWS;
        }
        for(unsigned int i=irows;i<irows+size;i++){
            if(board[i][jcolumns] !='-'){
                goto repeatrandom;
            }
        }

        for(unsigned int i =irows;i<irows+size;i++){
            board[i][jcolumns]=initial;
        }
    }
}

/** this function helps to run the generateship function untill all the ships are gnererated.
 *
 * @param board  : the board on which different  ships are  to be made.
 */

void loopgenship(char board[][COLUMN]){
    int shipsize[5]={5,4,3,3,2};
    char shipinitials[5]={'C','B','K','S','D'};
    for(int i =0;i<5;i++){
        generateships(board,shipsize[i],shipinitials[i]);
    }
}

/** this function takes the character input and changes it into its uppercase.
 *
 * @param key : the character which is to be converted into its uppercase
 * @return  : it retuns the uppercaseed charcter if the character given as input
 */

char touppercase(char key){
    if(key>='a'&&key<='z'){
        key=key-('a'-'A');
    }

    return key;
}

/** this methid help us to generate the random x and y co-ordinate for automatuc paly of the game .
 *
 * @param xcor  : integer value that denotes the row of the 2d array
 * @param ycor  : charcater value that denotes the colum iof the 2d  array
 */
void takecomputerinput(int &xcor ,char &ycor){
    xcor=rand()%10;
    int compycor=rand()%10;
    ycor='A'+compycor-1;
    ycor=touppercase(ycor);
}


/**this function help us to takes the input from the user
 *
 * @param xcor : integer value that denotes the row of the 2d array
 * @param ycor :charcater value that denotes the colum iof the 2d  array
 */

void takeinput(int &xcor,char &ycor){
    cout<<"Enter the co-ordinate of the index you want to hit first enter  the x-cordinate and the then  alphabet denoting the  y codinate   ";
    cin>>xcor>>ycor;
    ycor=touppercase(ycor);
}

/**
 *
 * @param board
 * @param computerboard
 */
 void computergamestart(char board[][COLUMN],char computerboard[][COLUMN],char computershow[][COLUMN],int usershipcount,int computercount){

   while(usershipcount>1&&computercount>1){

  // THIS IS USER

   int xxcor=0;
   char yycor;

   takecomputerinput(xxcor,yycor);
     int inyycor=(int)yycor-'A';

     std::cout << "xcor is " <<xxcor<< '\n';
     std::cout << "ycor if " <<inyycor<< '\n';

     //std::cout <<"             this is the value in the board "<<board[xcor][inycor]  << '\n';
          if(computerboard[xxcor][inyycor]!='-'){
            if(computerboard[xxcor][inyycor]!='X'){
                if(computerboard[xxcor][inyycor]!='H'){
                  computershow[xxcor][inyycor]='H';
                  computercount--;
                  std::cout << "computer cout :" <<computercount<< '\n';
                  printbord(board,computershow);
                }
              }
            }
          else{
            computershow[xxcor][inyycor]='X';
            printbord(board,computershow);
          }

          //// THIS is PC
          // THIS IS FOR  COMPUTER GUESS AND COMPUTER TURN

           xxcor=0;
           yycor;
          takecomputerinput(xxcor,yycor);
           inyycor=(int)yycor-'A';

          std::cout << "xcor  of computer is " <<xxcor<< '\n';
          std::cout << "ycor of computer is  " <<inyycor<< '\n';

           if(board[xxcor][inyycor]!='-'){
              if(board[xxcor][inyycor]!='X'){
                if(board[xxcor][inyycor]!='H'){
                  board[xxcor][inyycor]='H';
                  printbord(board,computershow);
                  usershipcount--;
                  std::cout << "usershipcount :"   <<usershipcount<< '\n';
                  std::cout << "user ship counts is " <<usershipcount<< '\n';
                  std::cout << "the value of the user ship cpunt is " <<usershipcount<< '\n';
                }
              }
            }
            else {
              std::cout << "else  condition is running" << '\n';
              board[xxcor][inyycor]='X';
              printbord(board,computershow);
            }
          }
          if(usershipcount<1){
            std::cout << "Computer wins the game" << '\n';
          }
          else if(computercount<1){
           std::cout << "User wins" << '\n';
          }
        //  return computergamestart(board,computerboard,computershow,usershipcount,computercount);



 //  std::cout << "computer finished the game" << '\n';
 }

/** this a recursive function that runs untill  all ship of one of the user  gets destroyed. and tells us the winner
 *
 * @param board  : the character 2d array that denotes the user board
 * @param computerboard : 2d array depicting the user board
 * @param computershow  : the 2d array linked to the board of the computer that shoes hits or miss accordingly.
 * @param usershipcount  : the total number of the user ships active
 * @param computercount : the total number of the computer ships active
 */

void usergamestart(char board[][COLUMN],char computerboard[][COLUMN],char computershow[][COLUMN],int usershipcount,int computercount){

    if(usershipcount<1||computercount<1){
        if(usershipcount<1){
            std::cout << "Computer wins the game" << '\n';
        }
        else if(computercount<1){
            std::cout << "User wins" << '\n';
        }

        return;
    }

    /// THIS IS FOR THE USER PART

    int xcor=0;
    char ycor;

    takeinput(xcor,ycor);
    int inycor=(int)ycor-'A';

    if(computerboard[xcor][inycor]!='-'){
        if(computerboard[xcor][inycor]!='X'){
            if(computerboard[xcor][inycor]!='H'){
                computershow[xcor][inycor]='H';
                printbord(board,computershow);
                computercount--;

            }
        }
    }
    else {
        computershow[xcor][inycor]='X';
        printbord(board,computershow);
    }

    // THIS IS FOR  COMPUTER GUESS AND COMPUTER TURN

    xcor=0;
    ycor;
    takecomputerinput(xcor,ycor);
    inycor=(int)ycor-'A';

    if(board[xcor][inycor]!='-'){
        if(board[xcor][inycor]!='X'){
            if(board[xcor][inycor]!='H'){
                board[xcor][inycor]='H';
                printbord(board,computershow);
                usershipcount--;
            }
        }
    }
    else {
        board[xcor][inycor]='X';
        printbord(board,computershow);
    }
    return usergamestart(board,computerboard,computershow,usershipcount,computercount);
}

/**
 * this method helps to clear the clutter int the main method.
 */
void substitute(){
    char board[ROWS][COLUMN];
    char computerboard[ROWS][COLUMN];
    char computershow[ROWS][COLUMN];

    srand(time(0));
    createbord(board);
    createbord(computerboard);
    createbord(computershow);

    loopgenship(board);
    loopgenship(computerboard);


    printbord(board,computershow);


    int usershipcount=18;
    int computershipcount=18;
    usergamestart(board,computerboard,computershow,usershipcount,computershipcount);
}

int main() {
    substitute();
    return 0;
}
