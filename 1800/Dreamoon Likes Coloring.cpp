// 20220622
// https://codeforces.com/problemset/problem/1329/A
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
int n, m;
const int maxn = 100010;
int L[maxn], P[maxn];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void move_right() {
    int r = n + 1;
    for (int i = m; i >= 1; i --) {
        P[i] = max(r - L[i], P[i]);
        r = P[i];
    }
}
int main() {
    quickread();
    cin >> n >> m;
    ll tot = 0;
    for (int i = 1; i <= m; i ++) {
        cin >> L[i];
        tot += L[i];
    }
    if (tot < n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= m; i ++) {
        if (i + L[i] - 1 <= n) {
            P[i] = i;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    move_right();
    for (int i = 1; i <= m; i ++) {
        cout << P[i] <<" ";
    }
    cout << endl;
    return 0;
}
