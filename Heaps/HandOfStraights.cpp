#include <bits/stdc++.h>
using namespace std;
bool isNStraightHand(vector<int>& hand, int grpSize) {
    int n = hand.size(); // size of the hand
    if(n%grpSize!=0) return false; // agar total number of cards is not divisible by group size, return false
    if(grpSize==1) return true; // if group size is 1, return true
    unordered_map<int,int> cnt; // map mein sabhi cards ki frequency store karenge
    priority_queue<int,vector<int>,greater<int>> heap; // minheap to get the smallest card first
    for(auto &i:hand){
        heap.push(i); // push all cards into the minheap
        cnt[i]++; // increment the frequency of the card in the map
    }
    while(!heap.empty()){ //jb tak heap khali nahi hota
        int curr = heap.top(); // get the smallest card
        heap.pop(); // remove it from the heap
        /*
        agar curr card ki freq 0 hai
        iska matlab ye card already used ho chuka hai, continue to next iteration
        */
        if (cnt[curr] == 0) continue; 
        for(int i=0;i<grpSize;i++){ // try to form a group of size grpSize starting from curr
            /*
            agar curr card ki frequency 0 hai
            iska matlab ye card already used ho chuka hai, return false
            */
            if(cnt.find(curr)==cnt.end()){
                return false;
            }
            cnt[curr]--; // update the frequency of the current card since we are using it
            if(cnt[curr]==0){ // if frequency becomes 0, remove it from the map
                cnt.erase(curr);
            }
            curr++; // move to the next card in the group
        }
    }
    return true;
}
int main(){
    vector<int> hand = {1,2,3,4,5};
    int groupSize = 3;
    cout << (isNStraightHand(hand, groupSize) ? "True" : "False") << endl;
    return 0;
}