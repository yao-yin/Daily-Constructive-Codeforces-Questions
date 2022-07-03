// 20220704
// https://codeforces.com/problemset/problem/1344/B

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
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;
int white_row;
int white_col;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool checkrows() {
    bool flag = false;
    for (int i = 0; i < n; i ++) {
        // row
        flag = false;
        for (int j = 0; j < m; j ++) {
            if (flag && j > 0 && mat[i][j] == '#' && mat[i][j-1] == '.') return false;
            if (mat[i][j] == '#') flag = true;
        }
        if (!flag) white_row ++;

    }
    return true;
}

bool checkcols() {
    bool flag = true;
    for (int j = 0; j < m; j ++) {
        // row
        
        flag = false;
        for (int i = 0; i < n; i ++) {
            if (flag && i > 0 && mat[i][j] == '#' && mat[i-1][j] == '.') return false;
            if (mat[i][j] == '#') flag = true;
        }
        if (!flag) white_col ++;
    }
    return true;
}

void bfs(int x, int y) {
    vector<int> dx {0, 1, 0, -1};
    vector<int> dy {1, 0, -1, 0};
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = true;
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int nx = u + dx[i];
            int ny = v + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && mat[nx][ny] == '#') {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int cnt() {
    int tot = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (mat[i][j] == '#' && !vis[i][j]) {
                tot ++;
                bfs(i, j);
            }
        }
    }
    return tot;
}

int main() {
    quickread();
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i ++) {
        cin >> s;
        for (int j = 0; j < m; j ++) {
            mat[i][j] = s[j];
        }
    }

    if (checkrows() && checkcols() && ((white_col && white_row)|| (white_col == 0 && white_row == 0)) ) {
        int res = cnt();
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
