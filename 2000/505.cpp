// 20220711
// https://codeforces.com/problemset/problem/1391/D

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
int n, m;
const int MAXM = 1000010;
const int MAXN = 4;
int mat[MAXN][MAXM];
int dp[MAXM][(1 << MAXN)];

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int pop_count(int x) {
    int cnt = 0;
    while (x) {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}

int getValue(int x) {
    int res = 0;
    for (int i = 0; i < n; i ++) {
        res += (1 << i) * mat[i][x];
    }
    return res;
}

vector<vector<bool>> preprocess() {
    int tot = (1 << n);
    vector<vector<bool>> res(tot, vector<bool> (tot, 1));
    for (int i = 0; i < tot; i ++) {
        for (int j = 0; j < tot; j ++) {
            for (int k = 0; k + 1 < n; k ++) {
                // check square [k, k+1]
                int curr = ((i >> k) & 1) + ((i >> (k + 1)) & 1);
                curr += ((j >> k) & 1) + ((j >> (k + 1)) & 1);
                if((curr & 1)== 0) {
                    res[i][j] = false;
                    break;
                }
            }
        }
    }
    return res;
}

int main() {
    quickread();
    cin >> n >> m;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (n >= 4) {
        cout << -1 << endl;
        return 0;
    }

    string s;
    for (int i = 0; i < n; i ++) {
        cin >> s;
        for (int j = 0; j < m; j ++) {
            mat[i][j] = s[j] - '0';
        }
    }
    memset(dp, 0x3f3f3f3f, sizeof dp);
    int row0 = getValue(0);
    for (int st = 0; st < (1 << n); st ++) {
        dp[0][st] = pop_count(row0 ^ st);
    }


    vector<vector<bool>> check = preprocess();
 
    for (int i = 1; i < m; i ++) {
        int curr = getValue(i);
        for (int st = 0; st < (1 << n); st ++) {
            for (int prv = 0; prv < (1 << n); prv ++) {
                if (check[st][prv]) {
                    dp[i][st] = min(dp[i][st], dp[i-1][prv] + pop_count(curr ^ st));
                }
            }
        }
    }
    int res = 0x3f3f3f3f;
    for (int i = 0; i < (1 << n); i ++) {
        res = min(res, dp[m-1][i]);
    }
    cout << res << endl;
    return 0;
}
