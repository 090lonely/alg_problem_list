// // //this file is only for test,you know sometimes i might get mycode wrong.
// // #include<bits/stdc++.h>
// // using namespace std;
// // void print(int a[]){
// //     for(int i=0;i<3;i++)cout<<a[i]<<endl;
// // }
// // int main(){
// //     int a[3]={1,2,3};
// //     print(a);
// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 155;
// struct Sensor {
//     double L, R, T;
// };

// Sensor sensors[N];

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         double D;
//         cin >> n >> D;

//         for (int i = 0; i < n; ++i) {
//             cin >> sensors[i].L >> sensors[i].R >> sensors[i].T;
//         }

//         // Sort sensors by starting point L
//         sort(sensors, sensors + n, [](const Sensor &a, const Sensor &b) {
//             return a.L < b.L;
//         });

//         vector<double> points;  // Change points
//         vector<double> speeds;  // Speeds at change points

//         double currentPosition = 0.0;
//         for (int i = 0; i < n; ++i) {
//             if (currentPosition < sensors[i].L) {
//                 // There's a gap before this sensor's range, set speed to cover this gap
//                 points.push_back(sensors[i].L);
//                 speeds.push_back((sensors[i].L - currentPosition) / (sensors[i].L - currentPosition)); // speed to move to the sensor's range
//                 currentPosition = sensors[i].L;
//             }

//             // Calculate the required speed for this sensor
//             double requiredSpeed = (sensors[i].R - sensors[i].L) / sensors[i].T;
//             points.push_back(sensors[i].R);
//             speeds.push_back(requiredSpeed);
//             currentPosition = sensors[i].R;
//         }

//         // Check if there's a gap between the last sensor and the end point
//         if (currentPosition < D) {
//             points.push_back(D);
//             speeds.push_back((D - currentPosition) / (D - currentPosition));
//         }

//         // Output the results
//         int m = points.size();
//         cout << m << endl;
//         for (double point : points) {
//             cout << fixed << setprecision(7) << point << " ";
//         }
//         cout << endl;
//         for (double speed : speeds) {
//             cout << fixed << setprecision(7) << speed << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
//基于分治法的找到最大最小数的算法。
// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// pair<int, int> findMaxMin(const vector<int>& A, int left, int right, int& comparisons) {
//     if (left == right) { // 只有一个元素
//         return {A[left], A[left]};
//     }
//     if (right == left + 1) { // 只有两个元素
//         comparisons += 1;
//         if (A[left] < A[right]) {
//             return {A[left], A[right]};//pair对{小值，大值}
//         } else {
//             return {A[right], A[left]};
//         }
//     }

//     int mid = (left + right) / 2;
//     auto leftResult = findMaxMin(A, left, mid, comparisons);
//     auto rightResult = findMaxMin(A, mid + 1, right, comparisons);

//     comparisons += 2;//合并的过程中产生的比较次数
//     int minVal = min(leftResult.first, rightResult.first);
//     int maxVal = max(leftResult.second, rightResult.second);

//     return {minVal, maxVal};
// }

// int main() {
//     vector<int> A = {1, 3, 5, 2, 9, 7, 8, 6, 4};
//     int n = A.size();
//     int comparisons = 0;

//     pair<int, int> result = findMaxMin(A, 0, n - 1, comparisons);
//     cout << "Minimum value: " << result.first << endl;
//     cout << "Maximum value: " << result.second << endl;
//     cout << "Number of comparisons: " << comparisons << endl;

//     return 0;
// }
#include<omp.h>//包含openmp所需要的库
#include<iostream>
using namespace std;
#define MAX_N 10000//定义n的值为10000
#define THREAD_NUM 5//定义线程个数为5

int main()
{
	int thread_id;
	double step = 1.0 / MAX_N;//将[0,1]等分为n个小区间
	double sum[THREAD_NUM];//定义记录总和的数组，每个线程对应其中的一个元素
	double pi = 0.0;//初始化结果值
	omp_set_num_threads(THREAD_NUM);//线程创建
    #pragma omp parallel private(thread_id)//线程执行方式为parallel（并行），同时线程编号设//置为每个线程私有
	{
		double temp;
		thread_id = omp_get_thread_num();//获取当前线程的编号
		for (int i = thread_id; i < MAX_N; i += THREAD_NUM)
		{
			if (i == thread_id)//若当前执行任务为该线程中的第一个任务，则首先需要初始化sum数组
			sum[thread_id] = 0.0;
			temp = (i + 0.5) * step;//横坐标的值取为区间中间值（i/n+(i+1)/n)/2=(i+0.5)/n
			sum[thread_id] += 4.0/(temp*temp+1.0);//运用积分中的函数，计算矩形的长，并加到sum上去
		}
	}
	for (int i = 0; i < THREAD_NUM; i++){//将多个线程的sum加起来，得到所有矩形的长的和
		pi += sum[i];
		pi *= step;//所有矩形的长的和*1/n得到最后的PI值
		cout << pi << endl;
}
}
