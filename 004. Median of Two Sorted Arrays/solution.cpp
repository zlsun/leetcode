/** 004. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
**/

#include <iostream>
#include "../utils.h"
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        int mn = m + n;
        if (mn & 1) {
            return findKth(a, b, mn / 2);
        } else {
            int m = findKth(a, b, mn / 2 - 1);
            int n = findKth(a, b, mn / 2);
            return (m + n) * 0.5;
        }
    }
    int findKth(vector<int>& a, vector<int>& b, int k) {
        int m = a.size(), n = b.size();
        int p = k / 2, q, step = (k + 1) / 2;
        while (true) {
            p = (p > m) ? m : p < 0 ? 0 : p;
            q = k - p;
            q = (q > n) ? n : q < 0 ? 0 : q;
            p = k - q;
            if (p == m || (q < n && a[p] > b[q])) {
                if (p == 0 || a[p-1] <= b[q]) return b[q];
                p -= step;
                q += step;
            } else if (q == n || a[p] < b[q]) {
                if (q == 0 || b[q-1] <= a[p]) return a[p];
                p += step;
                q -= step;
            } else if (a[p] == b[q]) {
                return a[p];
            }
            step = (step + 1) / 2;
        }
    }
};

int main() {
    Solution s;
    vi a, b;
    a = {1, 2, 3}, b = {1, 2, 3};
    ASSERT s.findKth(a, b, 0) == 1;
    ASSERT s.findKth(a, b, 1) == 1;
    ASSERT s.findKth(a, b, 2) == 2;
    ASSERT s.findMedianSortedArrays(a, b) == 2;
    a = {1, 2, 3}, b = {1, 3};
    ASSERT s.findMedianSortedArrays(a, b) == 2;
    a = {1, 2, 3}, b = {4, 5};
    ASSERT s.findMedianSortedArrays(a, b) == 3;
    a = {1, 2, 3}, b = {4, 5, 6};
    ASSERT s.findMedianSortedArrays(a, b) == 3.5;
    return 0;
}
