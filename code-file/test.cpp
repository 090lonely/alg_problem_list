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
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int, int> findMaxMin(const vector<int>& A, int left, int right, int& comparisons) {
    if (left == right) { // 只有一个元素
        return {A[left], A[left]};
    }
    if (right == left + 1) { // 只有两个元素
        comparisons += 1;
        if (A[left] < A[right]) {
            return {A[left], A[right]};//pair对{小值，大值}
        } else {
            return {A[right], A[left]};
        }
    }

    int mid = (left + right) / 2;
    auto leftResult = findMaxMin(A, left, mid, comparisons);
    auto rightResult = findMaxMin(A, mid + 1, right, comparisons);

    comparisons += 2;//合并的过程中产生的比较次数
    int minVal = min(leftResult.first, rightResult.first);
    int maxVal = max(leftResult.second, rightResult.second);

    return {minVal, maxVal};
}

int main() {
    vector<int> A = {1, 3, 5, 2, 9, 7, 8, 6, 4};
    int n = A.size();
    int comparisons = 0;

    pair<int, int> result = findMaxMin(A, 0, n - 1, comparisons);
    cout << "Minimum value: " << result.first << endl;
    cout << "Maximum value: " << result.second << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
