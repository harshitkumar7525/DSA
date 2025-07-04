#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii; // first: distance, second: element
/*
agar priority queue mein pairs daalte hain, toh by default wo first element ke according sort hota hai.
agar first element same hai, toh second element ke according sort hota hai.
isliye, agar hum distance ko first element aur element ko second element ke roop mein daalte hain,
toh priority queue mein distance ke hisaab se sort hoga.
*/
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pii> pq;
    for (auto& n : arr) {
        pq.push({abs(n - x),n}); // abs(n - x) ko first element aur n ko second element ke roop mein daal rahe hain
        // priority queue mein distance ke hisaab se sort hoga
        if (pq.size() > k) pq.pop(); // agar size k se bada ho jata hai, toh top element ko nikaal dete hain
    }
    vector<int> ans; // result store karne ke liye vector
    while (!pq.empty()) { // jab tak priority queue khali nahi hota
        ans.push_back(pq.top().second); // top element ko result mein daal rahe hain
        pq.pop(); // top element ko nikaal rahe hain
    }
    sort(ans.begin(), ans.end()); // result ko sort kar rahe hain, kyunki priority queue mein elements distance ke hisaab se hain
    return ans;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    cout << "Original array: ";
    for (auto& n : arr) cout << n << " ";
    vector<int> result = findClosestElements(arr, k, x);
    cout << "\nClosest elements: ";
    for (auto& n : result) cout << n << " ";
    return 0;
}