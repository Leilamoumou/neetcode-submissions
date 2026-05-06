class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*Let n be the length of the array.
Create three arrays of size n:
pref for prefix products
suff for suffix products
res for the final result
Set:
pref[0] = 1 (nothing to the left of index 0)
suff[n - 1] = 1 (nothing to the right of last index)
Build the prefix product array:
For each i from 1 to n - 1:
pref[i] = nums[i - 1] × pref[i - 1]
Build the suffix product array:
For each i from n - 2 down to 0:
suff[i] = nums[i + 1] × suff[i + 1]
Build the result:
For each index i, compute:
res[i] = pref[i] × suff[i]
Return the result array.
*/
        int n = nums.size();
        vector<int> res(n);
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = 1;
        suff[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i + 1] * suff[i + 1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = pref[i] * suff[i];
        }
        return res;
    }
};