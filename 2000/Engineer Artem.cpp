// 20220629
// https://codeforces.com/problemset/problem/1438/C

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
int t, n, m;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    vector<vector<int>> grid(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j ++) {
            cin >> grid[i][j];
            if ((i + j) & 1) {
                if (grid[i][j] & 1) {
                    grid[i][j] ++;
                }
            } else {
                if (grid[i][j] % 2 == 0) {
                    grid[i][j] ++;
                }
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    quickread();
    cin >> t;
    while (t --) {
        cin >> n >> m;
        solve();
    }
    return 0;
}
