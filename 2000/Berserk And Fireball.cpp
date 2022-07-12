// 20220712
// https://codeforces.com/problemset/problem/1380/D

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
ll n, m, x, k, y;
const int MAXN = 200010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[MAXN], b[MAXN];
bool st[MAXN];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll remove(int l, int r) {
    ll max_value = *max_element(a+l, a+r+1);
    // < K
    ll res = INF;
    ll tot = r + 1 - l;
    if (tot < k) {
        if (max_value < max(a[l-1], a[r+1])) {
            res = min(res, (tot)*y);
        }
    } else {
        ll cnt = tot / k;
        ll rem = tot % k;
        res = min(res, rem*y + cnt*x);
        res = min(res, x + (tot - k)*y);
        if (max_value < max(a[l-1], a[r+1])) {
            res = min(res, (tot)*y);
        }
    }
    return res;
}

int main() {
    quickread();
    cin >> n >> m;
    cin >> x >> k >> y;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i]; 
    }
    for (int j = 1; j <= m; j ++) {
        cin >> b[j];
    }
    int pa = 1, pb = 1;
    while (pa <= n) {
        if (a[pa] == b[pb]) {
            st[pa] = 1;
            pa ++;
            pb ++;
        } else {
            pa ++;
        }
    }

    if (pb != m+1) {
        cout << -1 << endl;
        return 0;
    }

    int lst = 0;
    int idx = 1;
    ll tot = 0; 
    while (idx <= n) {
        if (st[idx]) {
            lst = idx;
            idx ++;
        } else {
            while (idx <= n && !st[idx]) {
                idx ++;
            }
            ll curr = remove(lst+1, idx - 1);
            lst = idx;
            if (curr == INF) {
                cout << -1 << endl;
                return 0;
            }
            tot += curr;
        }
    }
    cout << tot << endl;

    return 0;
}
