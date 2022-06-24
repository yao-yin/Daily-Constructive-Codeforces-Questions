// 20220624
// https://codeforces.com/problemset/problem/1348/D
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
const ll MAXN = 1e9 + 10;
const int MAXD = 10010;
int d;
int t;
ll n;
ll cnt[MAXD];
ll c[MAXD];

void preprocess() {
    cnt[0] = 1;
    c[0] = 1;
    ll curr = 1;
    ll tot = 1;
    int idx = 1;
    while (tot <= MAXN) {
        curr *= 2;
        c[idx] = curr;
        tot += curr;
        cnt[idx ++] = tot;
    }
    d = idx;
}

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int res = lower_bound(cnt, cnt + d, n) - cnt;
    if (res < 2) {
        if (n == 2) {
            cout << 1 << endl;
            cout << 0 << endl;
            return;
        } else if (n == 3) {
            cout << 1 << endl;
            cout << 1 << endl;
        }
    } else {
        ll a = cnt[res - 2];
        ll diff = n - a - 2*c[res - 2];
        ll x = min(diff/2, c[res - 2]);
        ll y = diff - 2*x;
        cout << res << endl;
        for (int i = 0; i < res - 2; i ++) {
            cout << c[i] << " ";
        }
        cout << x << " " << y << endl;
    }

}

int main() {
    quickread();
    preprocess();
    cin >> t;
    while (t --) {
        cin >> n;
        solve();
    }
    return 0;
}
