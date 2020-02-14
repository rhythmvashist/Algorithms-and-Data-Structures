
#include "coffeeshopsim.h"
#include "coffeeshopsim.cpp"
#include <iostream>
#include <ctime>
#include <cmath>


// struct for a customer containing the time and the money
struct customer{
    int time ;
    double amount;
};

//struct for the cashier containing the totaltime , total money and number of customers that acashier handles
struct cashier{
    int totaltime=0;
    double totalamount=0;
    int count=0;
};

void letsgetstarted();//function 1
void entercustomers(Queue<customer> & que);//function 2
void generaterandocustomers(Queue<customer> & que);//function 3
void premadecustomer(Queue<customer> & que);//function 4
void simulatetime(Queue<customer> & que);//function 5
bool stillserving(customer temp[],int);//function 6
void print(cashier server[],int ,int );//function 7
using namespace std;

int main(){
    letsgetstarted();//calling function1
    return 0;
}

//this is a void function that does not return anything but asks for the customer to make choices and then furtur calls other functions accordingly
void letsgetstarted(){
    srand(time(0));
    Queue <customer>que;//creating object of queue class

    int choice;
    cout<<"Press 0 if u want to enter customers one by one"<<endl;
    cout<<"Press 1 if u want to generate random customers"<<endl;
    cout<<"Press 2 if u want to use  pre made customers"<<endl;
    cin>>choice;
    if(choice==0){
        entercustomers(que); //calling function 2
    }
    else if(choice==1){
        generaterandocustomers(que); //calling function 3
    }
    else if(choice==2){
        premadecustomer(que); //calling function 4
    }
    else {
        cout<<"Invalid choice!"<<endl;
        exit(1);
    }
}


//function 2- this is a void function  that imports the queue class object
// this function asks the user  to enter the customers one by one and enter -1  when he is done
// it furthur calls function 5 for simultaing money and time
void entercustomers(Queue<customer> & que){
    int t =0;
    double c=0;
    cout<<"Enter time and money for customers"<<endl;
    cout<<"Enter -1 when you are done "<<endl;
    while(true){
        cin>>t;
        if(t==-1){
            break;
        }
        cin>>c;
        customer cstmr={t,c};
        que.enqueue(cstmr);
    }
    simulatetime(que); //calling function 5
}

//function 3- this is a void function  that imports the queue class object
// this function generates 100 random customers and store them in a queue
// it furthur calls function 5 for simultaing money and time
void generaterandocustomers(Queue<customer> & que){
    customer c[100]={{0,0.0}};
    for (int i=0;i<100;i++){
        c[i]={1+rand()%20,((1+rand()%500)*1.0)/100};
    }
    for (int i=0;i<100;i++){
        que.enqueue(c[i]);
    }
    simulatetime(que);  //calling fnction 5
}

//function 4- this is a void function  that imports the queue class object
// this function uses the premade 100 customers and stores them in a queue
// it furthur calls function 5 for simultaing money and time
void premadecustomer(Queue<customer> & que){
    customer c[100]=
    {{18,5.49},{25,2.23},{18,4.16},{10,2.13},{3,3.01},{5,4.79},{9,2.31},{25,4.77},{10,1.59},{20,3.86},{13,4.1},{8,2.48},{7,5.56},{12,2.15},{25,2.63},{13,4.09},{22,4.15},{15,2.85},{24,3.42},{19,1.81},{24,5.89},{24,5.32},{17,4.39},{17,3.47},{25,4.37},{11,2.52},{23,1.21},{6,5.77},{5,5.07},{16,1.6},{17,5.98},{1,2.93},{19,5.64},{21,4.59},{5,4.49},{13,5.45},{10,3.15},{6,5.3},{16,3.8},{19,1.79},{17,5.09},{14,5.47},{23,5.99},{15,2.83},{5,5.43},{6,2.63},{15,2.02},{6,1.82},{1,4.81},{8,4.72},{4,4.65},{13,5.62},{25,1.12},{10,1.54},{24,3.69},{6,3.67},{13,1.04},{14,1.17},{11,1.79},{6,3.02},{5,5.04},{22,3.43},{19,1.82},{11,1.77},{9,1.85},{9,4.91},{6,2.34},{12,1.07},{12,3.14},{10,2.25},{2,5.13},{25,3.47},{11,3.84},{20,4.25},{2,5.38},{24,4.77},{20,3.44},{12,3.98},{25,2.1},{6,5.1},{13,1.18},{6,2.02},{25,4.65},{1,4.61},{13,1.74},{23,3.54},{4,3.3},{18,4.12},{4,1.73},{18,2.52},{19,1.11},{21,3.42},{19,4.66},{24,4.66},{25,2.5},{23,4.86},{6,5.33},{4,2.4},{4,5.78},{11,3.72}};
    for (int i=0;i<100;i++){
        que.enqueue(c[i]);
    }
    simulatetime(que); //calling function 5
}

//function 5-this is a void function but basically does all the work
// this imports the queue class object
//it asks the user to enter numbeer of cashiers and furthur calls other functions

/// here this function replicates the three function of the like

// adjust time
void simulatetime(Queue<customer> & que){
	//run  queue is here 
    int numofcashiers=0;
    cout<<"Enter the number of cashiers  at the shop "<<endl;
    cin>>numofcashiers;
    int totaltime=0;
    customer *temp=new customer[numofcashiers];
    cashier *server=new cashier[numofcashiers];
    for(int i=0;i<numofcashiers;i++){ // assigning the cashiers the customers
        if(!(que.isempty())){
            temp[i]=que.dequeue();
            server[i].totalamount+=temp[i].amount;
            server[i].count++;
        }
        
    }
	
	//adjust time is workig here 
    while(stillserving(temp,numofcashiers)){ // simulating the money and time for next customers
        totaltime++;
        for(int i=0;i<numofcashiers;i++){
            if(temp[i].time>0)
                temp[i].time--;
            if(temp[i].time==0){
                if(!(que.isempty())){//dequeue only  if the queue is not empty
                    temp[i]=que.dequeue();
                    server[i].count++;
                    server[i].totalamount+=temp[i].amount;
                }
            }
        }
    }
    delete[]temp; //managing memeory leaks
    print(server,numofcashiers,totaltime); //calling function 7
    delete[]server; //managing memory leaks
}

// fnction 6 - this function checks if the cashiers are still serving any of the customers
// this is abool type function
bool stillserving(customer temp[],int size){
    for(int i =0;i<size;i++){
        if(temp[i].time>0){
            return true;
        }
    }
    return false;
}

//function 7 - this is void function that justs print the results
// it takes in the cashier array(server) but does not return anything
void print(cashier server[],int numofcashiers,int totaltime){
    cout<<"total time "<<totaltime<<endl;
    for( int i=0;i<numofcashiers;i++){
        cout<<"cashier "<<i<<" helped "<<server[i].count<<" customers and took in $ "<<server[i].totalamount<<endl;
    }
}
