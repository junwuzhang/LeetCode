/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.52%)
 * Total Accepted:    387.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\size2[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size size1 and size2 respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (size1+size2)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int size1 = nums1.size();
        const int size2 = nums2.size();
        int k = (size1+size2)/2;
        int mediumOdd = kth(nums1.begin(), size1, nums2.begin(), size2, k+1);
        if ((size1+size2) % 2 == 0){
            int mediumEven = kth(nums1.begin(), size1, nums2.begin(), size2, k);
            return ((double) mediumOdd + mediumEven )/2.0;
        }
        return mediumOdd;
    }

private:
    typedef vector<int>::iterator Iter;
    int kth (Iter start1, int size1, Iter start2, int size2, int k){
        // do another reverse search would eventually resolve the length problem
        if (size1 > size2) return kth(start2, size2, start1, size1, k);
        // if the second array is nothing, then the kth number must be in the first array
        if (size1 == 0) return *(start2 + k - 1);
        // if k is 1, then kth number should be the smallest number out of two arrays
        if (k == 1) return min(*start1, *start2);

        int idx1 = min(size1, k/2);    // this number is certainly less than k
        int idx2 = k - idx1;
        if (*(start1 + idx1 - 1) > *(start2 + idx2 - 1))    return kth(start1, size1, start2+idx2, size2-idx2, k-idx2);
        return kth(start1+idx1, size1 - idx1, start2, idx2, k-idx1);
    }
};

