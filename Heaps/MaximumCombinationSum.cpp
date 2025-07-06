#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(); // array ka size
        if(n==0 || k==0) return {}; // agar array khaali hai ya k zero hai toh khaali vector return karo
        // Step 1: Sort both arrays in descending order
        // Kyu? taaki maximum values aage aayein
        sort(a.rbegin(),a.rend()); // a ko descending order mein sort karo
        sort(b.rbegin(),b.rend()); // b ko descending order mein sort karo
        set<pii> visited; // visited set banate hain taaki hum duplicate pairs ko na consider karein
        vector<int> ans;
        priority_queue<pip> pq; // max heap banate hain taaki hum maximum sum pairs ko efficiently nikaal sakein
        // Step 2: Push the first pair (a[0], b[0])
        // mark (0, 0) as visited
        pq.push({a[0]+b[0],{0,0}});
        visited.insert({0,0});
        // Step 3: Extract k pairs with maximum sums
        // jab tak hmlogo ko k pairs nahi mil jaate
        // ya priority queue khaali nahi ho jaati tab tak
        while(ans.size()<k && !pq.empty()){
        // Step 4: Get the top element from the priority queue
        // aur uska sum aur indices ko nikaal lo
        auto ele = pq.top();
        pii pair = ele.second;
        int sum = ele.first;
        pq.pop();
        int i=pair.first,j=pair.second;
        ans.push_back(sum); // Step 5: Add the sum to the result vector
        // Step 6: Push the next pairs into the priority queue
        // check for boundary conditions
        // agar diagonal pair (i+1, j) ya (i, j+1) visited nahi hai toh unhe push karo
        // aur visited set mein unhe add karo
        if(i+1<n && j<n && !visited.count({i+1,j})){
            pq.push({a[i+1]+b[j],{i+1,j}});
            visited.insert({i+1,j});
        }
        if(i<n && j+1<n && !visited.count({i,j+1})){
            pq.push({a[i]+b[1+j],{i,j+1}});
            visited.insert({i,j+1});
        }
    }
    return ans; 
}
int main() {
    vector<int> a = {1, 4, 2};
    vector<int> b = {3, 5, 6};
    int k = 3;
    vector<int> result = topKSumPairs(a, b, k);
    cout << "Top " << k << " sum pairs: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}