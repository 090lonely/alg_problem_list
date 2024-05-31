#include <bits/stdc++.h>
using namespace std;

struct Month {
    int cost; // 生产成本
    int demand; // 需求量
};

bool compare(const Month &a, const Month &b) {
    return a.cost < b.cost;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<Month> months(N);
        for (int i = 0; i < N; ++i) cin >> months[i].cost;
        for (int i = 0; i < N; ++i) cin >> months[i].demand;
        
        sort(months.begin(), months.end(), compare);

        long long total_cost = 0;
        int current_inventory = 0;
        
        for (int i = 0; i < N; ++i) {
            int month_cost = months[i].cost;
            int month_demand = months[i].demand;

            // 计算这个月生产的数量
            if (current_inventory >= month_demand) {
                total_cost += month_cost * 0; // 这月不需要生产
                total_cost += month_demand; // 使用库存
                current_inventory -= month_demand;
            } else {
                int produce = month_demand - current_inventory;
                total_cost += month_cost * produce; // 生产
                total_cost += current_inventory; // 使用库存
                current_inventory = 0; // 库存用完
            }

            // 计算剩余库存的存储成本
            current_inventory += month_demand;
        }

        cout << total_cost << endl;
    }
    return 0;
}



