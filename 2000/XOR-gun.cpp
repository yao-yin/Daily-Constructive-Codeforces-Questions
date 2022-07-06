// 20220706
// https://codeforces.com/problemset/problem/1415/D

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
const int MAXN = 100010;
int a[MAXN], prv[MAXN], n;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1;i <= n; i ++) {
        prv[i] = prv[i-1] ^ a[i];
    }
    int res = n;
    for (int i = 0; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            for (int k = j + 1; k <= n; k ++) {
                int x = prv[j] ^ prv[i];
                int y = prv[k] ^ prv[j];
                if (x > y) {
                    res = min(res, (j - i - 1) + (k - j - 1));
                }
            }
        }
    }
    if (res == n) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
}

int main() {
    quickread();
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    if (n >= 100) {
        cout << 1 << endl;
    } else {
        solve();
    }
    return 0;
}
