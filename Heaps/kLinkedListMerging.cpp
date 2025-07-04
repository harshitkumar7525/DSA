#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct Comp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val; // Min-heap ke liye, agar a ka value b se bada hai toh true return karo
            // Isse priority queue mein chhote value wale elements pehle aayenge
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Comp> pq; // Min-heap banane ke liye priority queue ka use kar rahe hain
        for(auto list: lists){
            if(list) pq.push(list); // Sirf non-null lists ko priority queue mein daal rahe hain
            // Agar list NULL hai, toh usse priority queue mein nahi daalna hai
        }
        ListNode sample; // Ek dummy node banate hain, jisse hum merged list ko asaani se return kar sakein
        ListNode* prev = &sample; // prev pointer ko dummy node ke address par set karte hain
        while(!pq.empty()){ // Jab tak priority queue khali nahi hota
            ListNode* curr = pq.top(); // Top element ko lete hain, jo sabse chhota value wala hoga
            if(curr->next) pq.push(curr->next); // Agar current node ka next hai, toh usse bhi priority queue mein daal dete hain
            pq.pop(); // Top element ko priority queue se nikaal dete hain
            prev->next=curr; // prev ke next pointer ko current node par set karte hain
            prev=curr; // prev pointer ko current node par update karte hain
        }
        prev->next=NULL; // Last node ke next pointer ko NULL set karte hain, taaki merged list ka end sahi ho
        return sample.next; // Dummy node ke next pointer ko return karte hain, jo merged list ka head hoga
    }
int main() {
    vector<ListNode*> lists;
    lists.push_back(new ListNode(1));
    lists.push_back(new ListNode(4));
    lists.push_back(new ListNode(5));
    lists.push_back(new ListNode(1));
    lists.push_back(new ListNode(3));
    lists.push_back(new ListNode(4));
    lists.push_back(new ListNode(2));
    lists.push_back(new ListNode(6));

    ListNode* mergedList = mergeKLists(lists);
    ListNode* curr = mergedList;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}