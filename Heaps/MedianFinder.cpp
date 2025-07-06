#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
private:
    priority_queue<double> left; // Max-heap for the left half (stores smaller half of the numbers)
    priority_queue<double,vector<double>,greater<double>> right; // Min-heap for the right half (stores larger half of the numbers)
public:
    MedianFinder() {
        return; // does not need to do anything in constructor
    }
    
    void addNum(int num) {
        if(left.empty() || num < left.top()){ // agar left half khaali ho ya naya number left half ke top se chhota hai
            // toh naya number ko left half mein daal do
            left.push(num);
        } else { // agar naya number left half ke top se bada hai ya barabar hai
            // toh naya number ko right half mein daal do
            right.push(num);
        }
        if (left.size() > right.size() + 1) {
            /*
            agar left half mein elements zyada hain
            toh left half se top element ko right half mein daal do
            hm logon ne right.size() + 1 iss liye use kiya hai
            odd length ke case mein left half mein ek extra element hona chahiye
            */
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) { // agar right half mein elements zyada hain toh extra element ko left half mein daal do
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){ // agar dono halves mein elements barabar hain toh average nikaal lo
            return (left.top() + right.top())/2.0;
        } else { // aur agr unequal hain toh left half ka top element median hai
            return left.top();
        }
    }
};
int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.0
    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.5
    return 0;
}