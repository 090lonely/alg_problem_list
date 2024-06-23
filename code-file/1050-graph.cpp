#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 定义订单结构体
struct Order {
    int id;       // 订单编号（从0开始）
    int pickup;   // 取货区域（从0开始）
    int delivery; // 送达区域（从0开始）
    int earliest; // 最早送达时间
    int latest;   // 最晚送达时间
    int cost;     // 送达时间成本
};

// 定义外卖小哥结构体
struct DeliveryMan {
    int id;                // 人员编号（从0开始）
    int currentLocation;   // 当前位置（从0开始）
    int nextAvailableTime; // 下一空闲时间
    vector<Order> orders;  // 分配订单列表
};

// 按照最晚送达时间排序订单，如果相同，则按照最早送达时间排序
bool compareOrders(const Order &a, const Order &b) {
    return a.latest == b.latest ? a.earliest < b.earliest : a.latest < b.latest; // 分数：0.864
}

// 分配订单给外卖小哥
void assign_orders(vector<Order> &orders, vector<DeliveryMan> &deliveryMen, const vector<vector<int>> &dist) {
    for (Order &order : orders) {
        if (order.latest < order.cost)
            continue;
        int bestMan = -1;
        int minTime = INT_MAX; // 最早空闲时间
        for (DeliveryMan &man : deliveryMen) {
            if (man.currentLocation == -1 || man.nextAvailableTime + dist[man.currentLocation][order.pickup] + order.cost <= order.latest) {
              
                if (man.nextAvailableTime < minTime) {
                    bestMan = man.id;
                    minTime = man.nextAvailableTime;
                }

            }
        }
        if (bestMan != -1) {
            deliveryMen[bestMan].orders.push_back(order);
            // 外卖小哥的下一个空闲时间等于订单的实际开始时间加上通勤时间
            deliveryMen[bestMan].nextAvailableTime = max(deliveryMen[bestMan].nextAvailableTime + (deliveryMen[bestMan].currentLocation == -1) ? 0 : dist[deliveryMen[bestMan].currentLocation][order.pickup] + order.cost, order.earliest);
            deliveryMen[bestMan].currentLocation = order.delivery;
        }
    }
}

// 初始化图
void initialize_graph(int n, vector<vector<int>> &graph, vector<vector<int>> &dist, vector<vector<int>> &next_node) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == j)
                dist[i][j] = 0;
            else if (graph[i][j] != -1)
                dist[i][j] = graph[i][j];
            if (graph[i][j] != -1)
                next_node[i][j] = j;
        }
}

// Floyd-Warshall算法
void floyd_warshall(int V, vector<vector<int>> &dist, vector<vector<int>> &next_node) {
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next_node[i][j] = next_node[i][k];
                }
}

void print_path(int begin, int end, const vector<vector<int>> &next_node) {
    if (begin == end)
        return;
    vector<int> path;
    for (path.push_back(begin); begin != end; begin = next_node[begin][end])
        path.push_back(next_node[begin][end]);
    cout << "goto " << path.size() << ' ';
    for (int location : path)
        cout << location + 1 << ' ';
    cout << '\n';
}

// 主函数
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {

        int n, e, r, x; // 顶点数、边数、订单数、外卖小哥人数
        cin >> n >> e >> r >> x;

        vector<vector<int>> graph(n, vector<int>(n, -1));     // 邻接矩阵
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // 最短路径长度
        vector<vector<int>> next_node(n, vector<int>(n, -1)); // 最短路径下一节点

        // 读取路网信息
        for (int i = 0; i < e; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u - 1][v - 1] = w;
            graph[v - 1][u - 1] = w;
        }

        // 初始化图并运行Floyd-Warshall算法
        initialize_graph(n, graph, dist, next_node);
        floyd_warshall(n, dist, next_node);

        // 读取订单信息
        vector<Order> orders(r);
        for (int i = 0; i < r; ++i) {
            int pickup, delivery, earliest, latest;
            cin >> pickup >> delivery >> earliest >> latest;
            orders[i].id = i; // 设置订单编号
            orders[i].pickup = pickup - 1;
            orders[i].delivery = delivery - 1;
            orders[i].earliest = earliest;
            orders[i].latest = latest;
            orders[i].cost = dist[orders[i].pickup][orders[i].delivery];
        }

        // 对订单进行排序
        sort(orders.begin(), orders.end(), compareOrders);

        // 初始化外卖小哥信息
        vector<DeliveryMan> deliveryMen(x);
        for (int i = 0; i < x; ++i) {
            deliveryMen[i].id = i;
            deliveryMen[i].currentLocation = -1;
            deliveryMen[i].nextAvailableTime = 0;
        }

        // 分配订单给外卖小哥
        assign_orders(orders, deliveryMen, dist);

        // 输出配送情况
        for (DeliveryMan &man : deliveryMen) {
            if (man.orders.empty())
                continue; // 如果外卖小哥没有订单，则跳过
            cout << "solution " << man.id + 1 << '\n';
            int currentLocation = man.orders.front().pickup;
            for (Order &order : man.orders) {
                // 从当前位置前往订单的取货点
                print_path(currentLocation, order.pickup, next_node);
                cout << "pick " << order.id + 1 << '\n';
                // 从取货点前往送达点
                print_path(order.pickup, order.delivery, next_node);
                cout << "serve " << order.id + 1 << '\n';
                currentLocation = order.delivery;
            }
        }
        cout << '\n';
    }
    return 0;
}