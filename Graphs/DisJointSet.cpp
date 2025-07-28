#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int ultimateParent(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        // path compression
        // At each recursive call we update that level's parent
        return parent[u] = ultimateParent(parent[u]);
    }

    void unionByRank(int u, int v)
    { // almost O(1)
        // 1. find ultimate parent of u and v (pu and pv)
        // 2. find rank of pv and pu
        // 3. connect smaller rank to larger rank always in case of equality connect anyone to anyone.
        int pv = ultimateParent(v);
        int pu = ultimateParent(u);
        if (pv == pu)
        {
            // If they belong the same component return, we don't need to do anything
            return;
        }
        else if (rank[pu] < rank[pv])
        {
            // if rank of ultimate parent of u is less than that of ultimate parent of v
            // then we make v the parent of u
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            // if rank of ultimate parent of u is greater than that of ultimate parent of v
            // then we make u the parent of v
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu; // attach pv to pu
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v)
    {
        // 1. find ultimate parent of u and v (pu and pv)
        // 2. find size of pv and pu
        // 3. connect smaller size to larger size always in case of equality connect anyone to anyone.
        int pu = ultimateParent(u);
        int pv = ultimateParent(v);
        if (pu == pv)
        {
            // If they belong the same component return, we don't need to do anything
            return;
        }
        else if (size[pu] < size[pv])
        {
            // if size of ultimate parent of u is less than that of ultimate parent of v
            // then we make v the parent of u
            parent[pu] = pv;
            size[pv] += size[pu]; // update size of pv
        }
        else // if size[pu] >= size[pv]
        {
            // if size of ultimate parent of u is greater than that of ultimate parent of v
            // then we make u the parent of v
            parent[pv] = pu;
            size[pu] += size[pv]; // update size of pu
        }
    }
};

void checkParentOfTwoNodes(DisjointSet &ds, int u, int v)
{
    if (ds.ultimateParent(u) == ds.ultimateParent(v))
    {
        cout << u << " and " << v << " are connected" << endl;
    }
    else
    {
        cout << u << " and " << v << " are not connected" << endl;
    }
}

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    checkParentOfTwoNodes(ds, 3, 7);
    ds.unionBySize(3, 7);
    checkParentOfTwoNodes(ds, 3, 7);
    return 0;
}