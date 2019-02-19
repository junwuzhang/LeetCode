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