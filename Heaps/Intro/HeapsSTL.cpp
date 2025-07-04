#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    /*
    Syntax:
    priority_queue<
    Datatype,                      // The type of elements
    Container (usually vector),    // Underlying container
    Comparator                     // How elements are compared (e.g., greater<> for min-heap)
    > heapName;

    or simply for maxheap do: priority_queue<datatype> heapname;

    */
    priority_queue<int> maxPQ; // by default max heap
    priority_queue<int,vector<int>,greater<int>> minPQ;
    vector<int> arr = {-5,16,1,10,100,21,53,58,569};
    for(auto &i:arr){
        maxPQ.push(i);
        minPQ.push(i);
    }
    cout<< "Size:" <<(maxPQ.empty() ? 0 : maxPQ.size()) << endl;
    cout<< "Size:" <<(minPQ.empty() ? 0 : minPQ.size()) << endl;
    cout<<"Max: "<<maxPQ.top()<<endl;
    maxPQ.pop();
    cout<<"Min: "<<minPQ.top()<<endl;
    minPQ.pop();
    for(auto &i:arr){
        cout<<"Max: "<<maxPQ.top()<<endl;
        maxPQ.pop();
        cout<<"Min: "<<minPQ.top()<<endl;
        minPQ.pop();
    }
}