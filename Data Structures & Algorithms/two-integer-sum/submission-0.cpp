class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     /*Create a hash map to store the value and index of each element in the array.
Iterate through the array and compute the complement of the current element, which is target - nums[i].
Check if the complement exists in the hash map.
If it does, return the indices of the current element and its complement.
If no such pair is found, return an empty array.*/
   unordered_map<int, int> indices;  // val for map == index

        for (int i = 0; i < nums.size(); i++) {
            //key is index
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (indices.count(diff) && indices[diff] != i) {
                return {i, indices[diff]};
            }
        }

        return {};
    }
};
