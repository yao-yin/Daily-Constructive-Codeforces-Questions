// 20220713
// https://codeforces.com/problemset/problem/1244/E

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
ll n, k;
const int MAXN = 100010;
ll a[MAXN], value[MAXN], cnt[MAXN], prefix_cnt[MAXN], suffix_cnt[MAXN], prefix[MAXN], suffix[MAXN];
ll unique_n;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void preprocess() {
    map<ll, ll> mp;
    for (int i = 1; i <= n; i ++) {
        mp[a[i]] ++;
    }
    int idx = 1;
    for (auto [num, ct]: mp) {
        value[idx] = num;
        cnt[idx] = ct;
        prefix_cnt[idx] = prefix_cnt[idx - 1] + ct;
        prefix[idx] = prefix[idx - 1] + prefix_cnt[idx - 1] * (value[idx] - value[idx-1]); 
        idx ++;
    }
    unique_n = idx - 1;
    for (int i = unique_n; i >= 1; i --) {
        
        suffix_cnt[i] = suffix_cnt[i+1] + cnt[i];
        suffix[i] = suffix[i+1] + suffix_cnt[i+1]*(value[i+1] - value[i]);
    }
}

bool check(ll x) {
    // forward
    int idx = 1;
    for (int i = 1; i <= unique_n; i ++) {
        // value[idx+1] >= value[i] + x 
        while (idx <= unique_n && value[idx] - value[i] <= x) {
            idx ++;
        }
        if (idx == unique_n + 1) {
            if (prefix[i] <= k) return true;
        } else {
            ll cost = prefix[i];
            cost += suffix[idx];
            cost += suffix_cnt[idx]*(value[idx] - x - value[i]);
            if (cost <= k) return true;
        }
    }
    // backward
    idx = unique_n;
    for (int i = unique_n; i >= 1; i --) {
        // value[idx-1] <= value[i] - x;
        while (idx >= 1 && value[i] - value[idx] <= x) {
            idx --;
        }
        if (idx == 0) {
            if (suffix[i] <= k) return true;
        } else {
            ll cost = suffix[i];
            cost += prefix[idx];
            cost += prefix_cnt[idx]*(value[i] - x - value[idx]);
            if (cost <= k) return true;
        }
    }
    return false;
}

void solve() {
    ll l = 0;
    ll r = (value[unique_n] - value[1]);
    ll res = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
}

int main() {
    quickread();
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    preprocess();
    solve();
    return 0;
}
