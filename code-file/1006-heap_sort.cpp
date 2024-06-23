//c++ have the standard algorithm ,that is priority_queue;
//first ,i will try the standard;
#include <bits/stdc++.h>


using namespace std;

// the two function: heapify and build MinHeap;
void heapify(vector<int>& heap, int n, int i);
void buildMinHeap(vector<int>& heap, int n);

int main() {
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        vector<int> heap(n);
        for (int i = 0; i < n; ++i) {
            cin >> heap[i];
        }
//build the minheap;
        buildMinHeap(heap, n);

        for (int i = 0; i < n; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// 自底向上构建最小堆
void buildMinHeap(vector<int>& heap, int n) {
    // 从第一个非叶子节点开始调整
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(heap, n, i);
    }
}

// 堆调整函数
void heapify(vector<int>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;//the left child 
    int right = 2 * i + 2;//the right child

    //***这一步体现总是优先以交换左子树为主，就因为先跟左子树元素进行比较，如果我小的话，那么我记录下来比我小的孩子的下标
    // 比较当前节点和左子节点
    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }//****smallest只做记录，表示当前三个点的最小值对应的下标我要找出来

    // 比较当前节点和右子节点
    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }

    // 如果当前节点不是最小，则交换并“继续调整”
    if (smallest != i) {
        swap(heap[i], heap[smallest]);//在alg库函数里面
        heapify(heap, n, smallest);
    }
}
