
// #include <stdio.h>
// #include <iostream>
// #include <algorithm>
// #include <cstdlib>
// #include <cmath>
// using namespace std;
// void merge(int* a, int low, int mid, int hight)  //合并函数
// {
// 	int* b = new int[hight - low + 1];  //用 new 申请一个辅助函数
// 	int i = low, j = mid + 1, k = 0;    // k为 b 数组的小标
// 	while (i <= mid && j <= hight)  
// 	{
// 		if (a[i] <= a[j])
// 		{
// 			b[k++] = a[i++];  //按从小到大存放在 b 数组里面
// 		}
// 		else
// 		{
// 			b[k++] = a[j++];
// 		}
// 	}
// 	while (i <= mid)  // j 序列结束，将剩余的 i 序列补充在 b 数组中 
// 	{
// 		b[k++] = a[i++];
// 	}
// 	while (j <= hight)// i 序列结束，将剩余的 j 序列补充在 b 数组中 
// 	{
// 		b[k++] = a[j++];
// 	}
// 	k = 0;  //从小标为 0 开始传送
// 	for (int i = low; i <= hight; i++)  //将 b 数组的值传递给数组 a
// 	{
// 		a[i] = b[k++];
// 	}
// 	delete[]b;     // 辅助数组用完后，将其的空间进行释放（销毁）
// }
// int count1=0;
// void mergesort(int* a, int low, int hight) //归并排序
// {
// 	if (low < hight)
// 	{
// 		int mid = (low + hight) / 2;
// 		mergesort(a, low, mid);          //对 a[low,mid]进行排序
// 		mergesort(a, mid + 1, hight);    //对 a[mid+1,hight]进行排序
//         count1++;
// 		merge(a, low, mid, hight);       //进行合并操作
// 	}
// }
// int main(){

// int a[100]={3,4,6,1,2,9,5};
// mergesort(a,0,6);
//    for(int i=0;i<7;i++){
//     cout<<a[i]<<endl;

//    }

//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right, int depth) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, depth+1);//depth+1保证层数
        mergeSort(arr, mid + 1, right, depth+1);
       // ++depth;
        if (depth >= 2) {
            merge(arr, left, mid, right);
        }
       
    }
}

int main() {
    int t=0;cin>>t;int n=0;  
    while(t--){
        cin>>n;vector<int> arr;//这个数组一定要放在循环里面。
        for(int i=0;i<n;i++){
           int temp;cin>>temp;
            arr.push_back(temp);
        }    
    int depth = 0;
  //  int targetDepth = 2; // 输出倒数第三次递归的结果
    int n = arr.size();
    mergeSort(arr, 0, n - 1, depth);
    for (int i = 0; i < n; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
    }

    return 0;
}
//zhongyuAC