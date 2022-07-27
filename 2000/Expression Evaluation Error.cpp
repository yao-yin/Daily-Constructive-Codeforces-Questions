// 20220727
// https://codeforces.com/problemset/problem/1567/D

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
ll t, s, n;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    priority_queue<int, vector<int>, greater<int>> pq;
    ll idx = 1;
    while (s) {
        int cnt = s % 10;
        for (int j = 0; j < cnt; j ++) pq.push(idx);
        s /= 10;
        idx *= 10;
    }
    
    if (pq.size() < n) {
        int cnt_one = 0;
        while (!pq.empty() && (pq.size() + cnt_one) < n) {
            auto x = pq.top();
            pq.pop();
            
            if (x == 1) {
                cnt_one ++;
            } else {
                for (int i = 0; i < 10; i ++) {
                    pq.push(x/10);
                }
            }
        }
        for (int j = 0; j < cnt_one; j ++) {
            pq.push(1);
        }
    }
    //cout << "hello" << endl;
    int x = pq.size() - n;
    int curr = 0;
    while (x) {
        curr += pq.top();
        pq.pop();
        x --;
    }
    while (!pq.empty()) {
        auto c = pq.top();
        pq.pop();
        if (curr) {
            c += curr;
            curr = 0;
        }
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        cin >> s >> n;
        solve();
    }
    return 0;
}
