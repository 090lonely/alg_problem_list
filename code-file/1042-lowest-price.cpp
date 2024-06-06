//
//  main.cpp
//  minTicketsCost
//
//  Created by 胡昱 on 2021/12/20.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // 共nums组测试
    int nums;
    cin >> nums;
    while((nums--) > 0) {
        // 输入days数组
        int lengthOfDays;
        cin >> lengthOfDays;
        if(lengthOfDays <= 0) {
            // 处理极端情况
            cout << 0 << endl;
            continue;
        }
        int* days = new int[lengthOfDays];
        for(int i = 0; i < lengthOfDays; ++i) {
            cin >> days[i];
        }
        
        // 输入cost数组
        const int lengthOfCost = 3;
        int* cost = new int[lengthOfCost];
        for(int i = 0; i < lengthOfCost; ++i) {
            cin >> cost[i];
        }
        
        // 创建动态规划数组
        // dp[n]代表到第n天为止所需要的最低消费，因此共有366项元素（包括无意义的0）
        const int lengthOfDP = 366;
        int* dp = new int[lengthOfDP];
        // 初始化动态规划数组，即第1个旅行日之前的花费为0
        for(int n = 0; n < days[0]; ++n) {
            dp[n] = 0;
        }
        
        // 开始动态规划
        // 思路为：在旅行日时，我可以购买一张一天通行证、也可以在七天之前买一张七天通行证、也可以在三十天之前买一张三十天通行证，最后当然取三者最小
        // 因此动态规划在最后一个旅行日规划完成后就可以停止了，最终的结果为 dp[days[lengthOfDays - 1]]
        for(int i = 0; i < lengthOfDays; ++i) {
            int n = days[i];
            dp[n] = min(dp[max(0, n - 1)] + cost[0], min(dp[max(0, n - 7)] + cost[1], dp[max(0, n - 30)] + cost[2]));
            
            // 填满与下一个旅行日之间的动态规划数组
            if(i + 1 < lengthOfDays) {
                while((n++) < days[i + 1]) {
                    dp[n] = dp[n - 1];
                }
            }
        }
        
        // 输出结果并释放资源
        cout << dp[days[lengthOfDays - 1]] << endl;
        delete [] days;
        delete [] cost;
        delete [] dp;
    }
}

