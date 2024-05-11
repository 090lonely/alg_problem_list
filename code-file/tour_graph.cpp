#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();//这一行感觉很多地方都会用到

struct Edge {
    int to;
    int weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

typedef vector<vector<Edge>> Graph;//图使用邻接表的方式实现

vector<int> dijkstra(const Graph& graph, int source, int destination,int B[],int M) {//B is the cost,M is the money
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push(make_pair(0, source));
    int now=0;//report the current cost;
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (u == destination) {
            break; // 如果已经到达目标顶点，就不需要再继续搜索了
        }

        if (d > dist[u]) {
            continue; // 如果当前距离大于已知最短距离，就跳过
        }

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if ((dist[u] + weight < dist[v])&&(now+B[v]<=M)) {
                now+=B[v];
                dist[v] = dist[u] + weight;//只有当满足条件也就是有钱而且最短路更新的时候才会将v节点加入队列
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, E, s, t,M;
        cin >> n >> E >> s >> t>> M;
        int B[505];
        Graph graph(n);
        for(int i=0;i<n;i++)cin>>B[i];
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u - 1].push_back(Edge(v - 1, w));
            graph[v - 1].push_back(Edge(u - 1, w)); // 无向图，需双向添加边
        }

        vector<int> dist = dijkstra(graph, s - 1, t - 1,B,M);

        if (dist[t - 1] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[t - 1] << endl;
        }
    }

    return 0;
}