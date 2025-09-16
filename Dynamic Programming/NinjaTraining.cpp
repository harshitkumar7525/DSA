#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    vector<vector<int>> dp; // dp array to store results of subproblems
    public:
    int helper(int idx,vector<vector<int>>& arr,int prev){
        if(idx<0) return 0; // no days left to perform any task
        if(dp[idx][prev]!=-1){ // if already computed, return the stored result
            return dp[idx][prev];
        }
        int ans = 0; // variable to store the maximum points for the current day
        // iterate through all tasks (0, 1, 2)
        for (int task = 0; task < 3; task++) {
            if (task != prev) { // ensure the same task is not performed on consecutive days
                ans = max(ans, arr[idx][task] + helper(idx - 1, arr, task)); // calculate maximum points
            }
        }
        return dp[idx][prev] = ans; // store the result in dp array and return it
    }
    int maximumPoints1(vector<vector<int>>& arr) { // using top-down dynamic programming
        int n=arr.size();
        dp.resize(n,vector<int>(4,-1)); // index 3 indicates free will to do any task on the first day
        return helper(n-1,arr,3);
    }

    int maximumPoints2(vector<vector<int>>& tasks) {
        // Code here
        int n=tasks.size();
        /* day[i][j]
        i th day par j th task nahi krne prr kya maximum hai
        */
        dp.resize(n,vector<int>(4,-1));
        dp[0][0]=max(tasks[0][1],tasks[0][2]);
        dp[0][1]=max(tasks[0][0],tasks[0][2]);
        dp[0][2]=max(tasks[0][1],tasks[0][0]);
        dp[0][3] = max(tasks[0][1],max(tasks[0][0],tasks[0][2]));
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                for(int task=0;task<3;task++){
                    if(task!=last){
                        int points = tasks[day][task]+dp[day-1][task];
                        dp[day][last]=max(dp[day][last],points);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
    int maximumPoints3(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<int> prev(4,0); // previous day results
        vector<int> curr(4,0); // current day results
        // base case
        prev[0]=max(tasks[0][1],tasks[0][2]);
        prev[1]=max(tasks[0][0],tasks[0][2]);
        prev[2]=max(tasks[0][1],tasks[0][0]);
        prev[3] = max(tasks[0][1],max(tasks[0][0],tasks[0][2]));
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                curr[last]=0;
                // "current day par 'last' task allow nahi hai, to maximum points kya banenge"
                // Hum har din `curr` ko reset karte hain kyunki naye din ke results calculate ho rahe hain
                for(int task=0;task<3;task++){
                    if(task!=last){
                        int points = tasks[day][task]+prev[task];
                        // aaj "day" prr "task" krne prr points + pichle din prr "task" nahi krne prr maximum points
                        curr[last]=max(curr[last],points);
                    }
                }
            }
            prev=curr;
        }
        return prev[3];
    }
};
int main(){
    Solution obj;
    vector<vector<int>> points = {{1,2,5},{3,1,1},{3,3,3}};
    cout<<obj.maximumPoints1(points)<<endl;
    return 0;
}