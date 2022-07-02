// 20220701
// https://codeforces.com/problemset/problem/1366/D

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
const int MAXN = 10000010;
int minDiv[MAXN];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void preprocess() {
    iota(minDiv, minDiv + MAXN, 0);
    for (int i = 2; i < MAXN; i ++) {
        if (minDiv[i] == i) {
            for (int j = 2; j*i < MAXN; j ++) {
                minDiv[i*j] = min(i, minDiv[i*j]);
            }
        }
    }
}

int main() {
    quickread();
    preprocess();
    int n;
    cin >> n;
    vector<ll> v(n), f(n, -1), s(n, -1);
    for (int i = 0; i < n; i ++) {
        cin >> v[i];
    }

    
    for (int i = 0; i < n; i ++) {
        vector<int> curr;
        int val = v[i];
        while (val != 1) {
            int fac = minDiv[val];
            val /= fac;
            if (curr.empty() || curr.back() != fac) {
                curr.push_back(fac);
            }
        }
        if (curr.size() < 2) {
            continue;
        } else {
            int a = 1;
            for (auto x: curr) {
                a *= x;
            }
            f[i] = (curr[0]);
            s[i] = (a/curr[0]);
        }
    }
    for (auto x: f) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x: s) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
