// 20220628
// https://codeforces.com/problemset/problem/1365/E
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
const int MAXN = 510;
ll a[MAXN], n;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    quickread();
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }    
    ll res = 0;
    if (n <= 2) {
        for (int i = 0; i < n; i ++) {
            res |= a[i];
        }
        cout << res << endl;
        return 0;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            for (int k = j + 1; k < n; k ++) {
                res = max(res, a[i] | a[j] | a[k]);
            }
        }
    }
    cout << res << endl;
    return 0;
}
