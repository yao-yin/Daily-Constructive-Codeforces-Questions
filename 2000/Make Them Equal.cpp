// 20220704
// https://codeforces.com/problemset/problem/1416/B

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

struct Op {
    int i, j;
    ll x;
};

void solve() {
    vector<ll> a(n+1, 0);
    ll tot = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        tot += a[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    if (tot % n) {
        cout << -1 << endl;
        return;
    }
    ll avg = tot / n;
    vector<Op> ops;
    for (int i = 2; i <= n; i ++)  {
        ll x = a[i] % i;
        ll y = x ? i - x : 0;
        ops.push_back({1, i, y});
        a[1] -= y;
        a[i] += y;
        ops.push_back({i, 1, a[i]/i});
        a[1] += a[i];
        a[i] = 0;
    }

    for (int i = 2; i <= n; i ++) {
        ops.push_back({1, i, avg});
    }
    cout << ops.size() << endl;
    for (auto && [x, y, z]: ops) {
        cout << x << " " << y << " " << z << endl;
    }
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
