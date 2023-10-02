#include "bits/stdc++.h"
#include "leetcode.h"
using namespace std;

class Solution {
public:
    vector<int> g;

    vector<int> color;
    vector<int> pre;
    vector<int> size;
    vector<int> ans;

    void build_cycle(int start, int end) {
        vector<int> c;
        c.push_back(start);
        for (int cur = end; cur != start; cur = pre[cur])
            c.push_back(cur);

        for (int i : c)
            size[i] = c.size();
    }

    void dfs(int x) {
        color[x] = 1;

        int y = g[x];
        if (color[y] == 0) {
            pre[y] = x;
            dfs(y);
        }
        else if (color[y] == 1) {
            build_cycle(y, x);
        }
        color[x] = 2;
    }

    int getSize(int x) {
        if (ans[x] != 0)
            return ans[x];

        if (size[x] != 0)
            return size[x];

        ans[x] = 1;
        ans[x] += getSize(g[x]);

        return ans[x];
    }

    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        g = edges;
        color.resize(n);
        pre.resize(n);
        size.resize(n);
        ans.resize(n, 0);

        for (int i = 0; i < n; i++) {
            if (color[i] == 0)
                dfs(i);
        }

        for (int i = 0; i < n; i++)
            getSize(i);

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    Solution solution;
    vector<int> i{1,2,0,0};
    cout << solution.countVisitedNodes(i);
}