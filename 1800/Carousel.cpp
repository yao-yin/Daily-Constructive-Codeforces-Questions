// 20220620
// https://codeforces.com/problemset/problem/1328/D

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
int q, n;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void fixup(vector<int> & t, vector<int> & color) {
    bool flag = false;
    for (int i = 1; i < n; i ++) {
        if (t[i] == t[i-1]) {
            if (!flag) {
                color[i] = 3 - color[i-1];
                flag = true;
            } else {
                color[i] = color[i-1];
            }
        } else {
            color[i] = 3 - color[i-1];
        }
    }
    if (color[n-1] == color[0] && t[n-1] != t[0]) {
        color[0] = 3;
        for (int i = 1; i < n; i ++) {
            if (t[i] == t[i-1]){
                color[i] = color[i-1];
            } else {
                break;
            }
        }
    } 
    cout << *max_element(color.begin(), color.end()) << endl;
    for (int i = 0; i < n; i ++) {
        if (i) cout << " ";
        cout << color[i];
    }
    cout << endl;
}

void solve() {
    cin >> n;
    vector<int> t(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> t[i];
    }
    vector<int> color(n, 0);
    color[0] = 1;
    for (int i = 1; i < n; i ++) {
        if (t[i] == t[i-1]) {
            color[i] = color[i-1];
        } else {
            color[i] = 3 - color[i-1];
        }
    }

    if(color[n-1] == color[0] && t[n-1] != t[0]) {
        fixup(t, color);
        return;
    }
    cout << *max_element(color.begin(), color.end()) << endl;
    for (int i = 0; i < n; i ++) {
        if (i) cout << " ";
        cout << color[i];
    }
    cout << endl;
}

int main() {
    quickread();
    cin >> q;
    while (q --) {
        solve();
    }    
    return 0;
}
