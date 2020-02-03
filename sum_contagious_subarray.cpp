# include <iostream>
# include <vector>
using namespace std;

int get_sum_contagious_subarraay(vector<int> params){
    for (int i = 0; i < params.size; i++){
        cout<<params[i]<<endl;
    }
    

    return 0;
}

int main(){
    vector<int> size {1,2,4,4};
    int value = get_sum_contagious_subarraay(size);
    return 0;
}