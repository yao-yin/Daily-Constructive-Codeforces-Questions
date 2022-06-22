// 20220622
// https://codeforces.com/problemset/problem/5/C
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
const int MAXN = 1000010;
string s;
int n;
int ori[MAXN];
int prv[MAXN];

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    quickread();
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; i ++) {
        if (s[i-1] == '(') {
            ori[i] = 1;
        } else {
            ori[i] = -1;
        }
    }

    for (int i = 1; i <= n; i ++) {
        prv[i] = prv[i-1] + ori[i];
    }

    stack<int> stk;
    int res = 0;
    unordered_map<int, int, custom_hash> mp;
    for (int i = 0; i <= n; i ++) {
        while (!stk.empty() && prv[stk.top()] > prv[i]) {
            stk.pop();
        }

        if (!stk.empty() && prv[stk.top()] == prv[i]) {
            res = max(res, i - stk.top());
            mp[i-stk.top()] ++;
            continue;
        }

        stk.push(i);
    }
    if (res == 0) {
        cout << "0 1" << endl;
        return 0;
    }
    
    cout << res << " " <<mp[res] << endl;
    return 0;
}
