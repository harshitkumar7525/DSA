#include<bits/stdc++.h>
using namespace std;
void nearlySorted(vector<int>& arr, int k) {
    priority_queue<int,vector<int>,greater<int>> pq; // ascending ke liye min heap
    int i=0; // index kaha prr element dalna hai
    for(auto &n:arr){ // arr ke elements ko loop krte hai
        pq.push(n); // min heap me dalte hai
        while(pq.size()>k){ // jab tak heap ka size k se bada hai
            arr[i++]=pq.top(); // heap ke top element ko arr me dalte hai aur index i ko badhate hai
            pq.pop(); // heap se top element ko nikaalte hai
        }
    }
    while(!pq.empty()){ // jab tak heap khali nahi hota
        // heap me jo elements bache hai unhe arr me dalte hai
        arr[i++]=pq.top();
        pq.pop();
    }
}
int main(){
    vector<int> arr = {2, 1, 4, 3, 5};
    int k = 2;
    cout << "Original array: ";
    for(auto &n:arr) cout<<n<<" ";
    nearlySorted(arr, k);
    cout << "\nSorted array: ";
    for(auto &n:arr) cout<<n<<" ";
    return 0;
}