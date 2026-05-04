class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Brute Force, find every single subarray's sum and return the largest.Need to optimize to pass all test cases
       vector<int> dp(nums);
        for (int i = 1; i < nums.size(); i++) {
            //dp[i] represents the maximum subarray sum ending at index i.
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }
        return *max_element(dp.begin(), dp.end());
    }
    
};