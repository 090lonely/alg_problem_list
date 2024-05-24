//这道题应该是使用匈牙利二分图匹配算法进行解决，
//找一个dfs找增广路径的方法。
//#include<bits/stdc++.h>
//我至今不理解为什么我的过不了测试用例，生气。。。。还是不行。
#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int MAXN = 55;
int n, m;
vector<int> g[MAXN]; // 邻接表表示图
bool seen[MAXN]; // 标记数组，用于DFS
int match[MAXN]; // 记录匹配关系

//深度优先搜索，尝试为当前顶点u找到匹配
bool dfs(int u) {//u is the boy,v is the girl;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!seen[u]) {//v没有被匹配，则直接将其跟u匹配。match[v] == -1  match[v] = u; !seen[v]  seen[v] = true;
            seen[u] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
// bool dfs(int u) {
//     for (int v : g[u]) {
//         if (match[v] == -1 || (seen[match[v]] && dfs(match[v]))) {
//             match[v] = u;
//             seen[u] = true;
//             return true;
//         }
//     }
//     return false;
// }


// 匈牙利算法主体
int hungarian() {
    memset(match, -1, sizeof(match));
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        memset(seen, 0, sizeof(seen));
        if (dfs(i)) {//给第i个男生找匹配
            res++;
        }
    }
    return res;
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            int k;
            cin >> k;
            while (k--) {
                int v;
                cin >> v;
                g[i].push_back(v);
            }
        }
        cout << hungarian() << endl;
    }
    return 0;
}