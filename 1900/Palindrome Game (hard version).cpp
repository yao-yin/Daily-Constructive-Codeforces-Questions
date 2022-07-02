// 20220630
// https://codeforces.com/problemset/problem/1527/B2

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
string s;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int cnt_one_side = 0;
    int cnt_both = 0;
    int cnt_center = 0;
    for (int i = 0; i < n / 2; i ++) {
        if ((s[i] == '0' && s[n-i-1] == '1') || (s[i] == '1' && s[n-i-1] == '0')) {
            cnt_one_side ++;
        } else if (s[i] == '0' && s[n-i-1] == '0') {
            cnt_both += 1;
        }
    }
    if (n % 2 == 1 && s[n/2] == '0') {
        cnt_center += 1;
    }
    //cout << cnt_center << " " << cnt_one_side << " " <<  cnt_both << endl;
    if (cnt_one_side > 0) {
        if (cnt_one_side == 1 && cnt_center == 1 && cnt_both == 0) {
            cout << "DRAW" << endl;
        } else {
            cout << "ALICE" << endl;
        }
    }  
    else {
        if (cnt_center) {
            if (cnt_both == 0) {
                cout << "BOB" << endl;
            } else {
                cout << "ALICE" << endl;
            }
        } else {
            cout << "BOB" << endl;
        }
    }
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        cin >> n >> s;
        solve();
    }
    return 0;
}
