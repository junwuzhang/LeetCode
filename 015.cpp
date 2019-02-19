class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int a=0, b=0, c=0;
        int start=0, end=0;
        int n = nums.size();
        
        set<vector<int>> outputSet;
        
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-2; i++){
            a = nums[i];
            start = i+1;
            end = n-1;
            while (start < end){
                b = nums[start];
                c = nums[end];
                if (a + b + c == 0){
                    vector<int> singleVec;
                    singleVec.push_back(c);
                    singleVec.push_back(b);
                    singleVec.push_back(a);
                    outputSet.insert(singleVec);
                    start = start + 1;
                    end = end - 1;
                }
                else if (a+b+c > 0){
                    end = end - 1;
                } else {
                    start = start + 1;
                }
            }          
        } 

        vector<vector<int>> output(outputSet.begin(), outputSet.end());
        return output; 
    }
};