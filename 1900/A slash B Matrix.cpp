// 20220628
// https://codeforces.com/problemset/problem/1360/G

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
int t, n, m, a, b;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool check(priority_queue<pii, vector<pii>, greater<pii>> & pq) {
    while (!pq.empty()) {
        auto [cnt, idx] = pq.top();
        pq.pop();
        if (cnt != b) return false;
    }
    return true;
    
}

void solve() {
    vector<vector<int>> matrix(n, vector<int> (m, 0)); 
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < m; i ++) pq.push({0, i});
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < a; j ++) {
            auto [cnt, idx] = pq.top();
            pq.pop();
            matrix[i][idx] = 1;
            pq.push({cnt + 1, idx}); 
        }
    }
    if (check(pq)) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        cin >> n >> m >> a >> b;
        solve();
    }
    return 0;
}
