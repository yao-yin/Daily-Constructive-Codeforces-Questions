// 20220711
// https://codeforces.com/problemset/problem/321/C

#include <cstddef>
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
int n;
const int MAXN = 100010;
inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int search_centroid(vector<vector<int>> & g, int idx, vector<char> & tag, char curr_tag, int sz, int & centroid, int prv) {
    
    if (centroid != -1) return MAXN;
    vector<int> subtree_size;
    for (auto nxt: g[idx]) {
        if (tag[nxt] == '\0') {
            if (nxt == prv) continue;
            int curr_subtree = search_centroid(g, nxt, tag, curr_tag, sz, centroid, idx);
            if (curr_subtree == MAXN) return MAXN;
            else subtree_size.push_back(curr_subtree);
        }
    }
    int top = sz - 1 - accumulate(subtree_size.begin(), subtree_size.end(), 0);
    subtree_size.push_back(top);
    if (*max_element(subtree_size.begin(), subtree_size.end()) <= sz / 2) {
        centroid = idx;
        tag[idx] = curr_tag;
        return MAXN;
    }
    return sz - top;
}

int real_find_centroid(vector<vector<int>> & g, int idx, vector<char> & tag, char curr_tag, int sz) {
    int centroid = -1;
    search_centroid(g, idx, tag, curr_tag, sz, centroid, -1);
    return centroid;
}

int dfs(vector<vector<int>> & g, int idx, vector<char> & tag, int prv) {
    int tot = 1;
    for (auto nxt: g[idx]) {
        if (nxt == prv) continue;
        if (tag[nxt] != '\0') continue;
        tot += dfs(g, nxt, tag, idx);
    }
    return tot;
}

int find_centroid(vector<vector<int>> & g, int idx, vector<char> & tag, char curr_tag) {
    // return the centroid index;
    int tot_size = dfs(g, idx, tag, -1);
    int res = real_find_centroid(g, idx, tag, curr_tag, tot_size);
    for (auto nxt: g[res]) {
        if (tag[nxt] != '\0') continue;
        find_centroid(g, nxt, tag, curr_tag+1);
    }
    return res;
}

void solve(vector<vector<int>> & g, vector<char> & tag) {
    char curr_tag = 'A';
    find_centroid(g, 0, tag, curr_tag);
    for (auto x: tag) {
        cout << x <<" ";
    }
    cout << endl;
}

int main() {
    quickread();
    cin >> n;
    vector<vector<int>> g(n);
    vector<char> tag(n, '\0');
    int a, b;
    for (int i = 0; i < n - 1; i ++) {
        cin >> a >> b;
        a --;
        b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve(g, tag);
    
    return 0;
}
