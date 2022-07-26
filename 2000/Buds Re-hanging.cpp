// 20220727
// https://codeforces.com/problemset/problem/1566/E

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int mod = 1e9+7;
int t, n;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(vector<vector<int>> & g, vector<int> & p, vector<int> & inDeg, int idx, int prv) {
    for (auto nxt: g[idx]) {
        if (nxt == prv) continue;
        p[nxt] = idx;
        inDeg[idx] ++;
        dfs(g, p, inDeg ,nxt, idx);
    }
}

void solve() {
    vector<vector<int>> ug(n);
    vector<int> parent(n, -1);
    vector<int> inDeg(n, 0);
    int u, v;
    for (int i = 1; i < n; i ++) {
        cin >> u >> v;
        u --;
        v --;
        ug[u].push_back(v);
        ug[v].push_back(u);
    }
    dfs(ug, parent, inDeg, 0, -1);
    queue<int> q;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i ++) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }
    int tot = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == 0) break;
        int pa = parent[x];
        if (cnt[x] == 0) {
            cnt[pa] ++;
        } 
        inDeg[pa] --;
        if (inDeg[pa] == 0) {
            q.push(pa);
            if (cnt[pa]) {
                tot += (cnt[pa] - 1);
            } 
            
        }
    }
    cout << tot + 1 << endl;
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        cin >> n;
        solve();
    }
    return 0;
}
