class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> duplicates;
    for(size_t i =0;i<nums.size();++i)
        {
            auto it = std::find((nums.begin()+i+1), nums.end(),nums[i]);
            if(it!=nums.end()){
            return true;
            }
        }
        return false;
    }
};
