// 20220704
// https://codeforces.com/problemset/problem/1674/E

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
const int MAXN = 200010;
int a[MAXN];
int n;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int calc(int x, int y) {
    int one_third = (x + y + 2) / 3;
    if (2*x <= y) {
        return (y + 1) / 2 ;
    }
    if (2*y <= x) {
        return (x + 1) / 2;
    }
    return one_third;
}


int two_adjacent() {
    int res = 0x3f3f3f3f;
    for (int i = 0; i + 1 < n; i ++) {
        res = min(res, calc(a[i], a[i+1]));
    }
    return res;
}

int two_far() {
    int low1 = -1;
    int low2 = -1;
    for (int i = 0; i < n; i ++) {
        if (low1 == -1) {
            low1 = a[i];
            continue;
        }
        
        if (low1 >= a[i]) {
            low2 = low1;
            low1 = a[i];
        } else if (low2 == -1 || low2 > a[i]) {
            low2 = a[i];
        }
    }

    return (low1 + 1) / 2 + (low2 + 1) / 2;
}

int two_skip_one() {
    if (n == 2) {
        return 0x3f3f3f3f;
    }
    int res = 0x3f3f3f3f;
    for (int i = 0; i + 2 < n; i ++) {
        res = min(res, max(a[i], a[i+2]));
        res = min(res, min(a[i], a[i+2]) + (abs(a[i] - a[i+2]) + 1) / 2);
    }
    return res;
}

int main() {
    quickread();
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    cout << min(min(two_adjacent(), two_skip_one()), two_far()) << endl;
    return 0;
}
