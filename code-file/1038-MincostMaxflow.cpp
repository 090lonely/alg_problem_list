#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
//此题使用最小费用最大流问题，以此为解决问题的办法。显然你是gpt。
//但是不同于gpt-3.5给出的答案，这个4给的答案直接就对。
using namespace std;

const int MAXN = 105;
const int MAXM = 10005;
const int INF = INT_MAX;
//该代码详细实现了利用SPFA算法解决最小费用最大流问题。
//在这个具体问题中，源节点与所有男嘉宾相连，所有女嘉宾与汇节点相连，男嘉宾和他们中意的女嘉宾相连并设定相应的费用，
//通过最小费用最大流算法得到最多匹配对数及最小费用。

struct Edge {
    int from, to, cap, cost, flow;
};

vector<Edge> edges;
vector<int> G[MAXN];
int n, m;
int in_queue[MAXN], d[MAXN], p[MAXN], a[MAXN], vis[MAXN];

void addEdge(int from, int to, int cap, int cost) {
    edges.push_back({from, to, cap, cost, 0});
    edges.push_back({to, from, 0, -cost, 0});
    int k = edges.size();
    G[from].push_back(k - 2);
    G[to].push_back(k - 1);
}

bool SPFA(int s, int t, int& flow, int& cost) {
    memset(in_queue, 0, sizeof(in_queue));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < MAXN; i++) d[i] = INF;
    d[s] = 0; in_queue[s] = 1; vis[s] = 1; a[s] = INF; p[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        in_queue[u] = 0;
        for (int i = 0; i < G[u].size(); i++) {
            Edge& e = edges[G[u][i]];
            if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost;
                p[e.to] = G[u][i];
                a[e.to] = min(a[u], e.cap - e.flow);
                if (!in_queue[e.to]) {
                    Q.push(e.to);
                    in_queue[e.to] = 1;
                }
            }
        }
    }
    if (d[t] == INF) return false;
    flow += a[t];
    cost += d[t] * a[t];
    for (int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[u];
        edges[p[u] ^ 1].flow -= a[u];
    }
    return true;
}

int minCostMaxFlow(int s, int t, int& cost) {
    int flow = 0;
    cost = 0;
    while (SPFA(s, t, flow, cost));
    return flow;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        edges.clear();
        for (int i = 0; i < MAXN; i++) G[i].clear();

        cin >> n >> m;
        int costMatrix[55][55];
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> costMatrix[i][j];

        int s = 0, t = n + m + 1;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            addEdge(s, i, 1, 0);
            for (int j = 0; j < k; j++) {
                int girl;
                cin >> girl;
                addEdge(i, n + girl, 1, costMatrix[girl][i]);
            }
        }

        for (int i = 1; i <= m; i++) {
            addEdge(n + i, t, 1, 0);
        }

        int cost = 0;
        int flow = minCostMaxFlow(s, t, cost);
        cout << flow << " " << cost << endl;
    }
    return 0;
}
