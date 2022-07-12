// 20220712
// https://codeforces.com/problemset/problem/1493/C

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
int t, n, k;
string s;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool check(vector<int> & cnt, int idx, int ch) {
    if (ch == 25) return false;
    if (idx == n) {
        for (int i = ch + 1; i < 26; i ++) {
        if (cnt[i] % k) return false;
    }
    return true;
    }
    // case 1: don't need to create
    bool hasCandidate = false;
    for (int i = ch + 1; i < 26; i ++) {
        if (cnt[i] % k) hasCandidate = true;
    }

    int tot = 0; 
    for (int i = 0; i < 26; i ++) {
        tot += (k - cnt[i] % k) % k;
    }

    return (hasCandidate && tot <= (n - idx)) || (tot + k <= (n - idx));
}

void fix(vector<int> & cnt, int idx) {
    for (int i = idx; i < n; i ++) {
        for (int j = 0; j < 26; j ++) {
            if (i == idx && j <= s[i] - 'a') continue;
            s[i] = 'a' + j;
            cnt[j] ++;
            if (check(cnt, i + 1, -1)) {
                break;
            } else {
                cnt[j] --;
            }
        }
    }
    cout << s << endl;
}

void solve() {
    if (n % k) {
        cout << -1 << endl;
        return;
    }
    vector<int> cnt(26, 0);
    for (auto c: s) {
        cnt[c - 'a'] ++;
    }

    bool flag = true;
    for (int i = 0; i < 26; i ++) {
        if (cnt[i] % k) flag = false;
    }
    if (flag) {
        cout << s << endl;
        return;
    }

    int idx = n - 1;
    
    while (idx >= 0) {
        cnt[s[idx] - 'a'] --;
        if (check(cnt, idx, s[idx] - 'a')) {
            break;
        }
        idx --;
    }

    if (idx == -1) {
        cout << -1 << endl;
        return;
    }
    
    fix(cnt, idx);
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        cin >> n >> k;
        cin >> s;
        solve();
    }    
    return 0;
}
