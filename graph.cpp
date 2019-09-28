/*
  @auhtor:Rhythm Vashist
// this file implemennts spare undirectd weighted graph and dense direted weighted graph using adjacent matrix and adjacent list 
*/

#include <iostream>
#include <vector>
#include <ctime>
#include<cstdlib>
#include <fstream>

using namespace std;

// this class represents a edge between two node with its own weight
class Edge{
public:
    Edge(int f,int s,int w){
        first =f;
        second=s;
        weight=w;
    }
    int getF(){
        return first;
    }
    int getS(){
        return second;
    }

    int getW(){
        return  weight;
    }
private:
    int first;
    int second;
    int weight;
};


//this methis helps us to print the adjacent list corresponding the spares graph
void printList(vector<vector<int> > list,int number){
    for(int i=0;i<number;i++){
        //some part of this code taken from geeksforgeek
      
        cout<<"index "<<i<<": {";
        for (int j=0;i<list[i].size();j++){
            int x=list[i][j];
            cout << x <<",";

        }
           
        cout<<"}"<<endl;

    }
}

// this method checks if the current nodes are already present in the list of edges or not
bool checkpresence(vector<Edge> v,int f,int s){
    for(int i=0;i<v.size();i++){
        if((v.at(i).getS()==s&&v.at(i).getF()==f)||(v.at(i).getS()==f&&v.at(i).getF()==s)){
            return true;
        }
    }
    return false;
}

// this method prints the edges present corresponding each graph
void printedges(vector<Edge> v){
    for(int i=0;i<v.size();i++){
        cout<<"("<<v.at(i).getF()<<","<<v.at(i).getS()<<")"<<endl;
    }
    cout<<endl;
}

// this method takes the string name and the edge list and print that on a new text file
void printGraph(string filename,vector<Edge>v){
    fstream file; //object of fstream class

   //opening file "sample.txt" in out(write) mode
    file.open("sample.txt",ios::out);
    if(!file){
       cout<<"Error in creating file!!!"<<endl;
       exit(0);
    }
    cout<<"File created successfully."<<endl;
    file<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        file<<v.at(i).getF()<<" "<<v.at(i).getS()<<" "<<v.at(i).getW()<<endl;
    }
    file.close();
}

// this method is used to implement spare undirectd graph and print the adjacent list 
void makeSparseUDWG(int n){
    srand(time(0));
    if(n>5){
        int edgeC=rand()%(3*n)+1;
        if(edgeC>0){
            vector<Edge> ve;
            vector<vector<int> >result(edgeC,vector<int>(0));
            srand(time(0));
            int count=0;

            while(count<edgeC){
                int f=rand()%n;
                int s=rand()%n;
                int w=(rand()%(9*n))+n;
                if(!checkpresence(ve,f, s)&&f!=s){
                    Edge e1(f,s,w);
                    ve.push_back(e1);
                    count++;
                }
            }
            cout<<"Spare UDWG edges : "<<edgeC<<endl;
            printedges(ve);
            printGraph("sample.txt",ve);

            for(int i=0;i<edgeC;i++){
                Edge temp=ve.at(i);
                int source=temp.getF();
                int dest=temp.getS();
                result[source].push_back(dest);
                result[dest].push_back(source);
            }
            cout<<"calling cout"<<endl;
            printList(result,n);
            cout<<endl;
        }
    }

}

// this method is used to implement dense directd graph and print the adjacent matrix 
void makeDenseDWG(int n){
    if(n>5){
        int cons=((n-2)*n)/2;
        int edgeCount=(rand()%2*n)+cons;

        int matrix[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=0;
            }
        }
        vector<Edge> ve;
        srand(time(0));
        int count=0;
        while(count<edgeCount){
            int f=rand()%n;
            int s=rand()%n;
            int w=(rand()%(9*n))+n;
            // checks if the edge is already presen in the list


           /*if(!checkpresence(ve,f, s)&&f!=s){
                Edge e1(f,s,w);
                ve.push_back(e1);
                count++;
            }
            */
            if(matrix[f][s]!=1){// here i am checking for f to s and the s to f 2 nodes no pt (dll)
                Edge e1(f,s,w);
                ve.push_back(e1);
                matrix[f][s]=1;
                count++;

            }
        }
        cout<<"Dense DWG edges: "<<edgeCount<<endl;
        printedges(ve);

        /*
        for(int i=0;i<edgeCount;i++){
            Edge temp=ve.at(i);
            matrix[temp.getF()][temp.getS()]=1;
        }
        */
        // for printing
        cout<<"  ";
        for(int i=0;i<n;i++){
            cout<<i<<" ";
        }
        cout<<endl;

        for(int i=0;i<n;i++){
            cout<<i<< "|";
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

    }
}

int main(){
    int number=6;
    makeSparseUDWG(number);
    makeDenseDWG(number);

    cout<<"sample.txt file made"<<endl;

    return 0;
}
