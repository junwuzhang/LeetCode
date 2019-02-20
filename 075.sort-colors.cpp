/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (41.21%)
 * Total Accepted:    288.5K
 * Total Submissions: 700.2K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
/* Basically a quick sort algorithm */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        /* low  --> Starting index,  high  --> Ending index */
        int low = 0;
        int high = nums.size() - 1;
        quickSort(nums, low, high);           
    }
    
private:
    // A utility function to swap two elements 
    void swap(int* a, int* b) 
    { 
        int t = *a; 
        *a = *b; 
        *b = t; 
    }
    
    void quickSort(vector<int>& arr, int low, int high){
        if (low < high){
            /* pi is partitioning index, arr[pi] is now
           at right place */
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi-1); // Before pi
            quickSort(arr, pi+1, high); // After pi
        }
    }
    
    int partition (vector<int>& arr, int low, int high) { 
        int pivot = arr[high];    // pivot 
        int i = (low - 1);  // Index of smaller element 

        for (int j = low; j <= high- 1; j++) { 
            // If current element is smaller than or equal to pivot 
            if (arr[j] <= pivot) { 
                i++;    // increment index of smaller element 
                swap(&arr[i], &arr[j]); 
            } 
        } 
        swap(&arr[i + 1], &arr[high]); 
        return (i + 1); 
    }
};
