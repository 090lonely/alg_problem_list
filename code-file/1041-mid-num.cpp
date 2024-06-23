#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    // Ensure nums1 is the smaller array
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int imin = 0, imax = m, half_len = (m + n + 1) / 2;
    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = half_len - i;
        if (i < m && nums2[j-1] > nums1[i]) {
            imin = i + 1; // i is too small
        } else if (i > 0 && nums1[i-1] > nums2[j]) {
            imax = i - 1; // i is too big
        } else { // i is perfect
            int max_of_left;
            if (i == 0) { max_of_left = nums2[j-1]; }
            else if (j == 0) { max_of_left = nums1[i-1]; }
            else { max_of_left = max(nums1[i-1], nums2[j-1]); }
            if ((m + n) % 2 == 1) {
                return max_of_left;
            }

            int min_of_right;
            if (i == m) { min_of_right = nums2[j]; }
            else if (j == n) { min_of_right = nums1[i]; }
            else { min_of_right = min(nums1[i], nums2[j]); }

            return (max_of_left + min_of_right) / 2.0;
        }
    }

    return 0.0;//the return value must obey the rule.
}

int main() {
    int nums;
    cin >> nums;
    while (nums--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums1(n), nums2(m);
        for (int i = 0; i < n; ++i) {
            cin >> nums1[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> nums2[i];
        }
        cout << findMedianSortedArrays(nums1, nums2) << endl;//这里不需要设置中位数的小数点后几位，应该是系统的bug。
    }
    return 0;
}
