#include <iostream>
#include <ctime>

using namespace std;

const int ROWS=10;
const int COLUMN =10;

void createbord(char board[][COLUMN]){
    for(int i=0;i<COLUMN;i++){
        for(int j=0;j<ROWS;j++){
            board[i][j]='-';
        }
    }
}

void printbord(char board[][COLUMN],char computerboard[][COLUMN]){
    for(int i=0;i<COLUMN;i++){
        for(int j=0;j<ROWS;j++){
            cout<<board[i][j];
        }
        cout<<"       ";
        for(int j=0;j<ROWS;j++){
            cout<<computerboard[i][j];
        }
        cout<<" "<<endl;
    }
}



void generateships(char board[][COLUMN],int size,char initial){
    int irows,jcolumns,orientation;
    randomizi:
    do{
        irows=rand()%ROWS;
        jcolumns=rand()%COLUMN;
        orientation=rand()%2;

    }while(board[irows][jcolumns] !='-');

    //for horizontal orientation
    if(orientation==0){

        while(jcolumns+size>=COLUMN){
            int sum=jcolumns+size;
            jcolumns=rand()%COLUMN;
        }

        // checking that no ship is present at the current defired position.
        int count1=0;
        for(int j =jcolumns;j<jcolumns+size;j++){
            if(board[irows][j] !='-'){
                goto randomizi;

            }
        }

        //printing the ship initial.
        for(int j =jcolumns;j<jcolumns+size;j++){
            board[irows][j]=initial;
            count1++;

        }


    }
    if(orientation==1){

        while (irows+size>=ROWS){
            irows=rand()%ROWS;
        }

        for(int i=irows;i<irows+size;i++){
            if(board[i][jcolumns] !='-'){
                goto randomizi;
            }
        }

        for(int i =irows;i<irows+size;i++){
            board[i][jcolumns]=initial;

        }

    }


}

void loopgenship(char board[][COLUMN]){
    int shipsize[5]={5,4,3,3,2};
    char shipinitials[5]={'C','B','K','S','D'};
    for(int i =0;i<5;i++){
        generateships(board,shipsize[i],shipinitials[i]);
    }
}


void gamestart(char board[][COLUMN],char computerboard[][COLUMN]){
    cout<<"GIVE THE CO-ORDINATES OF THE POSITION YOU WANT TO HIT STARTING WITH THE ROW CO-ORDINATE";
    int rowco=0;
    char colmco;
    int colm=(int)colmco-'A'+1;
    cin>>rowco>>colmco;


    if(board[rowco][colm]!='-'){
        cout<<"checking the board";
        char shipname=board[rowco][colm];
        board[rowco][colm]='X';


    }

}


int main() {

    std::cout << "Hello, World!" << std::endl;
    char board[ROWS][COLUMN];
    char computerboard[ROWS][COLUMN];
    srand(time(0));

    createbord(board);
    createbord(computerboard);

    loopgenship(computerboard);
    loopgenship(board);



    printbord(board,computerboard);
    gamestart(board,computerboard);
   // printbord(board,computerboard);
    return 0;

}
