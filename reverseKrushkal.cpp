#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>


using namespace std;

// this class represents a edge between two node with its own weight
class Edge{
public:
    Edge(int f,int s ,int w){
        first =f;  
        second=s;
        weight=w;
    }
    int getF(){
        return first;
    }
   
    int getS(){
        return  second;
    }

    int getW(){
        return  weight;
    }
private:
    int first;
    int second;
    int weight;
};

void printList(vector<vector<Edge> > list){
    for(int i=0;i<list.size();i++){
        cout<< i <<" ->";
        for(int j=0;i<list[i].size();j++){
            if(i>list[i][j].getS()){
                cout<<list[i][j].getS()<<" "<<list[i][j].getW()<<endl;
            }
        }
    }
    cout<<"this ended"<<endl;
}


bool checkpresence(vector<Edge> v,int f,int s){
    for(int i=0;i<v.size();i++){
        if((v.at(i).getS()==s&&v.at(i).getF()==f)||(v.at(i).getS()==f&&v.at(i).getF()==s)){
            return true;
        }
    }
    return false;
}

vector<Edge> selectionSort(vector<Edge> arr)  { 
    int i, j, min_idx;  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < arr.size(); i++)  {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < arr.size(); j++)  
        if (arr[j].getW()  > arr[min_idx].getW())  
            min_idx = j;  
        // Swap the found minimum element with the first element  
       // Swap the found minimum element with the first element  
        Edge temp=arr[min_idx];
        arr[min_idx]=arr[i];
        arr[i]=temp;

    }
    return arr;
} 

void initilaiseBool(bool arr[],int no){
    for(int i=0;i<no;i++){
        arr[i]=false;
    }
}

// try to traverse the tree
bool isJoint(vector<vector<Edge> > ve,int no){
    bool visited[no];
    initilaiseBool(visited,no);
    visited[0]=true;
    queue<Edge> q;

    // pushing the neighbours of the first node
    for(int i=0;i<ve[0].size();i++){
        q.push(ve[0][i]);
        visited[ve[0][i].getS()]=true;
    }

    while(!q.empty()){
        Edge temp=q.front();
        int root=temp.getS();
        for(int i=0;i<ve[root].size();i++){
            if(!ve[root][i].getS()==true){
                q.push(ve[root][i]);
                visited[ve[root][i].getS()]=true;
            }
        }
        q.pop();
    }
    for(int i=0;i<no;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}


void reverseKurshal(vector<vector<Edge> > ve,vector<Edge> list,int no){
    int counter=0;
    list=selectionSort(list);

    while(counter<no){
        Edge temp=list[counter];
        int fst=temp.getF();
        int wg=temp.getW();
        int sec=temp.getS();

        int index=-1;
        for(int i=0;i<ve[fst].size();i++){
            Edge t=ve[fst][i];
            if(t.getS()==sec&&t.getW()==wg){
                index=i;
            }
        }
        ve[fst].erase(ve[fst].begin()+index);

        for(int i=0;i<ve[sec].size();i++){
            Edge t=ve[sec][i];
            if(t.getS()==sec&&t.getW()==wg){
                index=i;
            }
        }
        ve[sec].erase(ve[sec].begin()+index);

        if(isJoint(ve,no)){
            list.erase(list.begin()+counter);
            cout<<"Removed "<<temp.getF()<<", "<<temp.getS()<<" "<<temp.getW()<<endl;
        }
        // after removing the edge the graph is disconnected then we have to psuh back the removed edges and move the counter ahead
        else{
            counter++;
            ve[fst].push_back(temp);
            ve[sec].push_back(temp);
        }
    }

}

int main(){
  int no=0;
  fstream myfile;
  myfile.open("sample.txt");
  if (!myfile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
  } 
  myfile>>no;
  cout<<no<<endl;
  // as the tree is undirected so we know the number of edges in the

  vector<vector<Edge> > ve(no);
  vector<Edge> elist;
  int first=0;
  int second=0;
  int weight=0;

  while(myfile>>first>>second>>weight){
    if(!checkpresence(elist,first,second)&&first!=second){
        Edge e1(first,second,weight);
        Edge e2(second,first,weight);
        cout<<first<<" "<<second<<" "<<weight<<" "<<endl;
        elist.push_back(e1);

    // new may of making a list pushing second element in the list of firs        
        ve[first].push_back(e1);
        ve[second].push_back(e2);    
    }   
  }
  printList(ve);

  //elist=selectionSort(elist);
  cout<<"done"<<endl;
  return 0;
}
