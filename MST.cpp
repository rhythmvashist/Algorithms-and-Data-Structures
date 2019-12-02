#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <algorithm>

// this code is used to find the minimum spanning tree  using reverse krushkal algorithm

using namespace std;

// the class represents the edge of the graph with two nodes and weight of the edge
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


// this method helps to print the adjacent vector list created from the graph 
void printList(vector<vector<Edge> >ve){
    for(int i=0;i<ve.size();i++){
        for(int j=0;j<ve[i].size();j++){
            if(i>ve[i].at(j).getS())
                cout<<i<<"  "<<ve[i][j].getS()<<" " <<ve[i].at(j).getW()<<endl;
        }
    }
    cout<<endl;
}


bool check(vector<Edge> list,int sec){
    for(int i=0;i<list.size();i++){
        if(list.at(i).getS()==sec){
            return true;
        }
    }
    return false;
}

struct desc{
    bool operator()( Edge &node1, Edge &node2){
            return node1.getW()<node2.getW();
    }
};


vector<Edge> removeElement(vector<Edge> list,int counter/*,Edge temp*/){
    vector<Edge> newList;
    for(int i=0;i<list.size();i++){
        //if(!((list.at(i).getS()==temp.getS())&&(list.at(i).getW()==temp.getW())){
        if(i!=counter){
            newList.push_back(list.at(i));
        }
    }
    return newList;
}


void initilaiseBool(bool arr[],int no){
    for(int i=0;i<no;i++){
        arr[i]=false;
    }
}

void traversal(vector<vector<Edge> > &ve,int id,bool isvisited[]){
    isvisited[id]=true;
    for(int i=0;i<ve[id].size();i++){
            // if one of this is not visited the call the method for them
        int fst=ve[id][i].getF();
        int sec=ve[id][i].getS();
        if(!isvisited[fst] || !isvisited[sec]){
            traversal(ve,sec,isvisited);
        }
    }
}

// try to traverse the tree

bool isJoint(vector<vector<Edge> > ve,int no){
    bool visited[no];
    initilaiseBool(visited,no);

    traversal(ve,1,visited);

    for(int i=0;i<no;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
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

bool removedElem(vector<vector<Edge> > &ve,int fst,int sec,int wg){
    bool result=false;

    for(int i=0;i<ve[fst].size();i++){
            Edge t=ve[fst][i];
            if(t.getW()==wg){
                ve[fst].erase(ve[fst].begin()+i);
                result=true;
            }
    }
    return result;

}

void reverseKurshal(vector<vector<Edge> > ve,vector<Edge> list,int no){
    int counter=0;
    bool rm1=false;
    bool rm2=false;
    int sizel=list.size();
    //list=selectionSort(list);
    sort(list.begin(),list.end(),desc());


    for(int i=0;i<no;i++){
        Edge temp=list[i];
        int fst=temp.getF();
        int wg=temp.getW();
        int sec=temp.getS();

        int index=-1;
        for(int i=0;i<ve[fst].size();i++){
            Edge t=ve[fst][i];
            if(t.getW()==wg){
                rm1=true;
                ve[fst].erase(ve[fst].begin()+i);
            }
        }
        //ve[fst]=removeElement(ve[fst],index);

        for(int i=0;i<ve[sec].size();i++){
            Edge t=ve[sec][i];
            if(t.getW()==wg){
                //index=i;
                rm2=true;
                ve[sec].erase(ve[sec].begin()+i);
            }
        }
        //ve[sec].erase(ve[sec].begin()+index);



        if(rm1&&rm2&&isJoint(ve,sizel)){
            cout<<"remove:"<<fst<<" " <<sec<<" "<<wg<<endl;
            rm1=false;
            rm2=false;
        }

        if(!isJoint(ve,sizel)){
                Edge e1(fst,sec,wg);
                Edge e2(sec,fst,wg);
                ve[fst].push_back(e1);
                ve[sec].push_back(e2);
                 rm1=false;
                rm2=false;
                counter+=wg;
        }
        cout<<"the total disance us "<<counter<<endl;
    }
        /*

        if(isJoint(ve,no)){
            //list.erase(list.begin()+counter);
            list=removeElement(list,i);
            cout<<"Removed "<<temp.getF()<<", "<<temp.getS()<<" "<<temp.getW()<<endl;
        }
        // after removing the edge the graph is disconnected then we have to psuh back the removed edges and move the counter ahead
        else{
            //counter++;
            cout<<"counter is "<<counter<<endl;
            ve[fst].push_back(temp);
            ve[sec].push_back(temp);
        }
    }
    */
}



vector<vector<Edge> > generateGraph(string file,vector<Edge> &list){
    int no=0;
    int first=0;
    int sec=0;
    int wt=0;
    ifstream myfile(file);
    myfile>>no;
    cout<<no<<endl;
    vector<vector<Edge>> ve(no);

    while(myfile>>first>>sec>>wt){
            if(!check(ve[first],sec)&&first!=sec){
                Edge e1(first,sec,wt);
                Edge e2(sec,first,wt);
                ve[first].push_back(e1);
                ve[sec].push_back(e2);
                list.push_back(e1);
            }
    }
    return ve;
}

int main(){
    vector<Edge> list;
    string file="sample.txt";
    vector<vector<Edge> > ve=generateGraph(file,list);
    printList(ve);
    int no=ve.size();

    reverseKurshal(ve,list,no);
    return 0;
}
