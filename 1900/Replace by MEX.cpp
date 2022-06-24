// 20220623
// https://codeforces.com/problemset/problem/1375/D
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
int t, n;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void modify(vector<int> & nums, int idx, set<int> & s, map<int, int> & mp) {
    int val = nums[idx];
    nums[idx] = *s.begin();
    int new_val = nums[idx];
    mp[val] --;
    mp[new_val] ++;
    s.erase(new_val);
    if (mp[val] == 0) {
        s.insert(val);
    }
}

void solve() {
    cin >> n;
    vector<int> nums(n, 0);
    map<int, int> mp;
    set<int> s, uf;
    for (int i = 0; i <= n; i ++) {
        s.insert(i);
    }
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        mp[nums[i]] ++;
        s.erase(nums[i]);
        if (i != nums[i]) {
            uf.insert(i);
        }
    }
    vector<int> ops;
    while (!uf.empty()) {
        if (*s.begin() == n) {
            // a permutation
            int x = *uf.begin();
            uf.erase(x);
            modify(nums, x, s, mp);
            if (nums[x] != x) {
                uf.insert(x);
            }
            ops.push_back(x);
        } else {
            int x = *s.begin();
            uf.erase(x);
            modify(nums, x, s, mp);
            ops.push_back(x);
        }
    }
    cout << ops.size() << endl;
    for (int i = 0; i < ops.size(); i ++) {
        if (i) cout << " ";
        cout << ops[i]+1;
    }
    cout << endl;
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}
