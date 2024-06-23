//this question isbest for the greeady algorithm;
//
//  main.cpp
//  MachineOperation
//
//  Created by 胡昱 on 2021/12/31.
//

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// 作业结构体
struct Operation{
    int ddl;    // 截止时间
    int w;      // 收益
};

// 根据收益比较作业
int compareByW(const void* a, const void* b) {
    return -(int)(((Operation*)a)->w - ((Operation*)b)->w);
}

int main(int argc, const char * argv[]) {
    // 共T组测试数据
    int T;
    cin >> T;
    while((T--) > 0) {
        // 输入作业数量
        int N;
        cin >> N;
        
        // 创建并输入作业数组N
        Operation* ops = new Operation[N];
        int maxDDL = 0;     // 记录最大截止时间
        for(int ni = 0; ni < N; ++ni) {
            Operation op;
            cin >> op.ddl >> op.w;
            ops[ni] = op;
            if(op.ddl > maxDDL) {
                maxDDL = op.ddl;
            }
        }
        
        // 最大截止时间等于0的话说明没有活动可以被选择
        if(maxDDL == 0) {
            cout << 0 << endl;
            continue;
        }
        
        // 创建时间数组来记录每个时间是否被占用，并初始化
        int* busyTime = new int[maxDDL + 1];
        for(int ti = 0; ti <= maxDDL; ++ti) {
            busyTime[ti] = 0;
        }
        
        // 因为是贪心算法，所以我们按收益大小进行排序
        qsort(ops, N, sizeof(Operation), compareByW);
        
        // 初始化结果
        long long result = 0;//托关浩然兄弟得福，这里只有把result改成long long才能过
        
        // 开始选择作业//the key part；
        for(int opi = 0; opi < N; ++opi) {
            // 是否有空闲时间执行该作业
            bool hasFreeTime = false;
            
            // 从DDL开始往前寻找空闲时间
            int time = ops[opi].ddl;//ops是作业数组，opi是作业循环变量
            while(time > 0) {
                if(busyTime[time] == 0) {
                    hasFreeTime = true;
                    break;
                }
                else {
                    --time;
                }
            }
            
            // 判断是否执行该作业
            if(hasFreeTime) {
                // 设置改时间已被占用
                busyTime[time] = 1;
                
                // 增加收益
                result += ops[opi].w;
            }
        }
        
        // 输出结果并释放资源
        cout << result << endl;
        delete [] ops;
        delete [] busyTime;
    }
    return 0;
}
