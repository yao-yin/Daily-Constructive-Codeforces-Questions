// 20220620
// https://codeforces.com/problemset/problem/1396/B

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
int t;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tot = accumulate(a.begin(), a.end(), 0);
    int max_v = *max_element(a.begin(), a.end());
    if (max_v > tot / 2) {
        cout << "T" << endl;
    } else {
        if (tot & 1) {
            cout << "T" << endl;
        } else {
            cout << "HL" << endl;
        }
    }
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}
