//穷游这道题不是用dijkstra，而是用动态规划来的
#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct State {
    int dist;
    int u;
    int cost;

    bool operator>(const State& other) const {
        return dist > other.dist;
    }
};//用于存储当前的距离、顶点和费用，并重载>运算符以便在优先队列中按距离升序排列。

void solve(int n, int E, int s, int t, int M, const vector<int>& B, const vector<vector<pair<int, int>>>& adj) {
    vector<vector<int>> dp(n, vector<int>(M + 1, INF));
    dp[s][0] = 0; // Start at s with 0 cost

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, s, 0}); // Distance, vertex, cost

    while (!pq.empty()) {
        State state = pq.top();
        pq.pop();
        int dist = state.dist;
        int u = state.u;
        int cost = state.cost;

        if (dist > dp[u][cost]) continue; // Skip if not the best distance

        for (const auto& neighbor : adj[u]) {//遍历u的所有邻接点，当费用满足条件而且距离更短时会加入优先级队列
            int v = neighbor.first;
            int w = neighbor.second;
            int new_cost = cost + B[v];
            if (new_cost <= M && dist + w < dp[v][new_cost]) {
                dp[v][new_cost] = dist + w;
                pq.push({dist + w, v, new_cost});
            }
        }
    }

    int result = INF;
    for (int i = 0; i <= M; ++i) {
        result = min(result, dp[t][i]);
    }

    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, E, s, t, M;
        cin >> n >> E >> s >> t >> M;
        s--; // 0-based index
        t--; // 0-based index

        vector<int> B(n);
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        B[s] = 0; // No entry fee for the starting country

        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; // 0-based index
            v--; // 0-based index
            adj[u].emplace_back(v, w);//这些都是最基本的对于vector的操作，但是老出问题/
            adj[v].emplace_back(u, w);
        }

        solve(n, E, s, t, M, B, adj);
    }
    return 0;
}
