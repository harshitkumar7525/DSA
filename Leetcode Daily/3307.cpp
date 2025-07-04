#include<bits/stdc++.h>
using namespace std;
/*
04th July 2025
*/
#include <vector>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        int changes = 0; // Kitni baar character change hua hai (1 operation = +1 character)
        long long len = 1; // Initial string ki length (shuru mein 'a' hai sirf)
        int it = 0; // Kitni baar doubling hui hai (kitne operations apply hue)

        // Jab tak current string ki length < k, doubling karte raho
        while (len < k) {
            len = len << 1; // Har operation mein string length double ho jaati hai
            it++; // operation count badha do
        }

        // Reverse simulation: k-th character ka original source trace kar rahe hain
        while (k > 1) {
            // Agar k right half mein aaya hai aur uss iteration mein operation 1 tha (i.e. change hua)
            // toh ek character change count karo
            if (k > len / 2 && it >= 1 && ops[it - 1] == 1) {
                changes++; // ek 'a' se next letter mein convert hua
            }

            // Agar k right half mein tha, toh left wale character ko trace karo
            if (k > len / 2 && it > 0) {
		        //(1 << (it-1)) ==> previous iteration ki length
                k -= (1ll << (it - 1)); // previous level pr left half ka index nikaalo
            }

            it--; // ek level upar jao (previous operation)
            len = len >> 1; // length ab half ho jaayegi (reverse of doubling)
        }

        // Final character calculate karo (kitne changes 'a' par lage)
        changes %= 26;
        return 'a' + changes; // Final character return karo
    }
};
int main() {
    Solution sol;
    vector<int> ops = {1, 0, 1, 1}; // Example operations
    long long k = 10; // Example k value
    char result = sol.kthCharacter(k, ops);
    cout << "The " << k << "-th character is: " << result << endl;
    return 0;
}