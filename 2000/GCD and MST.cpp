// 20220728
// https://codeforces.com/problemset/problem/1513/D

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
typedef tuple<int, int, int> tiii;
//const int mod = 1e9+7;
int t, n, p;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    vector<int> a(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<bool> isConnected(n, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i ++) {
        pq.push({a[i], i});
    }

    ll tot = 0;

    while (!pq.empty()) {
        auto [x, idx] = pq.top();
        pq.pop();
        if (x >= p) break;
        for (int j = idx - 1; j >= 0; j --) {
            if (isConnected[j]) break;
            if (a[j] % x == 0) {
                isConnected[j] = true;
                tot += x;
            } else {
                break;
            }
        }

        for (int j = idx; j < n - 1; j ++) {
            if (isConnected[j]) break;
            if (a[j+1] % x == 0) {
                isConnected[j] = true;
                tot += x;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < n - 1; i ++) {
        if (!isConnected[i]) tot += p;
    }
    cout << tot << endl;
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        cin >> n >> p;
        solve();
    }
    return 0;
}
