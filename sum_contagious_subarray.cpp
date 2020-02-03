// Largest Sum Contiguous Subarray
// Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.

# include <iostream>
# include <vector>
using namespace std;

int get_sum_contagious_subarraay(vector<int> params){
    int maximum_so_far = 0;
    int maximum_till_here = 0;

    for(int i =0; i < params.size();i++){
        
        maximum_till_here = maximum_till_here + params[i] ;
        if(maximum_till_here < 0){
          maximum_till_here = 0;
        }
        if (maximum_till_here >maximum_so_far){
            maximum_so_far = maximum_till_here; 
        }

    }
    return maximum_so_far;
}

int main(){
    vector<int> vec ;
    // {-2, -3, 4, -1, -2, 1, 5, -3}; 
    vec.push_back(-2);
    vec.push_back(-3);
    vec.push_back(4);
    vec.push_back(-1);
    vec.push_back(-2);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(-3);
    int value = get_sum_contagious_subarraay(vec);
    cout<<value<<endl;
    return 0;
}