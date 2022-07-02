// 20220702
// https://codeforces.com/problemset/problem/1385/E

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
int t, n, m;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    cin >> n >> m;
    vector<pii> undirect_edges;
    vector<vector<int>> g(n);
    vector<int> in_degrees(n, 0);
    int op, a, b;
    for (int i = 0; i < m; i ++) {
        cin >> op >> a >> b;
        a --;
        b --;
        if (op) {
            // a -> b
            g[a].push_back(b);
            in_degrees[b] ++;       
        } else {
            // a -- b
            undirect_edges.push_back({a, b});
        }
    }

    vector<int> topo_order(n, 0);
    int idx = 0;
    queue<int> q;
    for (int i = 0; i < n; i ++) {
        if (in_degrees[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        topo_order[x] = idx ++;
        for (auto nxt: g[x]) {
            if (-- in_degrees[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    for (auto x: in_degrees) {
        if (x) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i ++) {
        for (int j: g[i]) {
            cout << i+1 << " " << j+1 << endl;
        }
    }
    for (auto [x, y]: undirect_edges) {
        if (topo_order[x] > topo_order[y]) {
            cout << y+1 << " " << x+1 << endl;
        } else {
            cout << x+1 << " " << y+1 << endl;
        }
    }
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}
