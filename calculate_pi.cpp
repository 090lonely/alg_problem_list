#include <omp.h>//包含openmp所需要的库
#include <iostream>
using namespace std;

#define MAX_N 10000
#define THREAD_NUM 5

int main() {
    double step = 1.0 / MAX_N;
    double sum[THREAD_NUM] = {0}; // 初始化数组
    double pi = 0.0;

    omp_set_num_threads(THREAD_NUM);

    #pragma omp parallel//线程执行方式为parallel（并行），同时线程编号设置为每个线程私有
    {
        int thread_id = omp_get_thread_num();
        double temp;
        // 确保每个线程处理正确数量的迭代
        for (int i = thread_id; i < MAX_N; i += THREAD_NUM) {
            temp = (i + 0.5) * step;//横坐标的值取为区间中间值（i/n+(i+1)/n)/2=(i+0.5)/n
            sum[thread_id] += 4.0 / (temp * temp + 1.0);
        }
    }

    // 累加所有线程的计算结果
    for (int i = 0; i < THREAD_NUM; i++) {
        pi += sum[i];
    }
    // 计算最终的 PI 值
    pi *= step;//所有矩形的长的和*1/n得到最后的PI值

    cout << "Calculated PI: " << pi << endl;

    return 0;
}