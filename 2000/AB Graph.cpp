// 20220719
// https://codeforces.com/problemset/problem/1481/D
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
const int MAXN = 1010;
char g[MAXN][MAXN];
int t, n, m;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; i ++) {
        cin >> s;
        for (int j = 1; j <= n; j ++) {
            g[i][j] = s[j-1];
        }
    }

    if (n == 2) {
        if (g[1][2] == g[2][1]) {
            cout << "YES" << endl;
            for (int i = 0; i <= m; i ++) {
                if(i & 1) {
                    cout << 1 << " ";
                } else {
                    cout << 2 << " ";
                }
            }
            cout << endl;
        } else {
            if (m & 1) {
                cout << "YES" << endl;
                for (int i = 0; i <= m; i ++) {
                    if(i & 1) {
                        cout << 1 << " ";
                    } else {
                        cout << 2 << " ";
                    }
                }
                cout << endl;
            } else {
                cout << "NO" <<endl;
            }
        }
        return;
    }

    cout << "YES" << endl;

    int circle1 = -1;
    int circle2 = -1;
    int circle3 = -1;

    if (g[1][2] == g[2][1]) {
        circle1 = 1;
        circle2 = 2;
    }
    if (g[2][3] == g[3][2]) {
        circle1 = 2;
        circle2 = 3;
    }
    if (g[1][3] == g[3][1]) {
        circle1 = 1;
        circle2 = 3;
    }

    if (circle1 != -1) {
        // circle with length 2

        for (int i = 0; i <= m; i ++) {
            if (i & 1) {
                cout << circle1 << " ";
            } else {
                cout << circle2 <<" ";
            }
        }
        cout << endl;
        return;
    }

    if (g[1][2] == g[2][3] && g[2][3] == g[3][1]) {
        circle1 = 1;
        circle2 = 2;
        circle3 = 3;
    }

    if (g[2][1] == g[3][2] && g[3][2] == g[1][3]) {
        circle1 = 3;
        circle2 = 2;
        circle3 = 1;
    }

    if (circle3 != -1) {
        // circle with length 3
        for (int i = 0; i <= m; i ++) {
            int curr = i % 3;
            if (curr == 0) {
                cout << circle1 <<" ";
            }else if (curr == 1) {
                cout << circle2 <<" ";
            } else {
                cout << circle3 <<" ";
            }
        }
        cout << endl;
        return;
    }

    int node1, node2, node3;
    // aba

    if (g[1][2] == g[3][1]) {
        node1 = 1;
        node2 = 2;
        node3 = 3;
    }

    else if (g[1][2] == g[2][3]) {
        node1 = 2;
        node2 = 3;
        node3 = 1;
    } 

    else {
        node1 = 3;
        node2 = 1;
        node3 = 2;
    }

    // 1->2 : a 2->3: b 3->1: a
    //cout << node1 << " ?? " << node2 << " ?? " << node3 << endl;
    if (m & 1) {
        int h = m / 2;
        if (h & 1) {
            for (int i = 0; i <= h; i ++) {
                if (i & 1) cout << node2 <<" ";
                else cout << node1 << " ";
            }
            for (int i = 0; i <= h; i ++) {
                if (i & 1) cout << node1 <<" ";
                else cout << node3 << " ";
            }
            cout << endl;
        } else {
            for (int i = 0; i <= h; i ++) {
                if (i & 1) cout << node1 <<" ";
                else cout << node2 << " ";
            }
            for (int i = 0; i <= h; i ++) {
                if (i & 1) cout << node1 <<" ";
                else cout << node3 << " ";
            }
            cout << endl;
        }
    } else {
        if (m == 2) {
            cout << node3 <<" " << node1 <<" " << node2 << endl;
        } else {
            int h = m / 2;
            
            if (h & 1) {
                for (int i = 0; i < h; i ++) {
                    if (i & 1) cout << node1 <<" ";
                    else cout << node3 <<" ";
                }
                for (int i = 0; i <= h; i ++) {
                    if (i & 1) cout << node2 <<" ";
                    else cout << node1 << " ";
                }
                cout << endl;
            } else {
                for (int i = 0; i <= h; i ++) {
                    if (i & 1) cout << node3 <<" ";
                    else cout << node1 <<" ";
                }
                for (int i = 0; i < h; i ++) {
                    if (i & 1) cout << node1 <<" ";
                    else cout << node2 << " ";
                }
                cout << endl;
            }
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
