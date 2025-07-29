#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> size, parent;

public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void uni(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n = acc.size();
        DisjointSet ds(n); // Har account ko initially alag-alag group (component) me rakha

        unordered_map<string, int> emailIdx; // Email ko map karenge us account index se jisme wo pehli baar mila

        // Step 1: Har account ke emails ko iterate kar ke, unhe union-find se connect karte hain
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < acc[i].size(); j++) {
                string mail = acc[i][j];
                if (emailIdx.find(mail) != emailIdx.end()) {
                    // Agar yeh email pehle kisi aur account me mil chuka hai,
                    // to current account i aur previous account ko merge (union) kar do
                    ds.uni(i, emailIdx[mail]);
                } else {
                    // Nahi mila to map me daal do is email ko, point karke current account par
                    emailIdx[mail] = i;
                }
            }
        }

        // Step 2: Ab har email ka ultimate parent account find karo
        // Taki hum group-wise saare emails ek sath rakh sakein
        vector<vector<string>> mergedMails(n); // Grouped emails, index will be group leader's index
        for (auto& it : emailIdx) {
            string mail = it.first;
            int node = ds.findParent(it.second); // Email jis account me mila tha uska final representative
            mergedMails[node].push_back(mail);   // Us group me email ko add karo
        }

        // Step 3: Har group ka final output banao
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMails[i].empty())
                continue; // Agar group empty hai, skip karo

            // Group ke emails ko lexicographically sort karo (requirement ke according)
            sort(mergedMails[i].begin(), mergedMails[i].end());

            // Final merged list: pehle account ka name daalo, fir sorted emails
            vector<string> temp;
            temp.push_back(acc[i][0]); // Name of the account holder (same for merged group)
            temp.insert(temp.end(), mergedMails[i].begin(), mergedMails[i].end());

            ans.push_back(temp); // Result list me push karo
        }

        return ans; // Final merged accounts return karo
    }
};

int main() {
    Solution sol;

    vector<vector<string>> accounts1 = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    vector<vector<string>> accounts2 = {
        {"Alex", "alex@mail.com", "alex2@mail.com"},
        {"Alex", "alex3@mail.com"},
        {"Alex", "alex2@mail.com", "alex3@mail.com"},
        {"Bob", "bob@mail.com"}
    };

    auto merged1 = sol.accountsMerge(accounts1);
    auto merged2 = sol.accountsMerge(accounts2);

    cout << "Merged Accounts 1:\n";
    for (const auto& account : merged1) {
        for (const auto& item : account) {
            cout << item << " ";
        }
        cout << endl;
    }

    cout << "\nMerged Accounts 2:\n";
    for (const auto& account : merged2) {
        for (const auto& item : account) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}
