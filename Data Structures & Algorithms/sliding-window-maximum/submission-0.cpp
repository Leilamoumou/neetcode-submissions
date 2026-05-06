class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       //MAX HEAP APPROACH, i'm a bit more familiar with so i used 
        //Use a max-heap to store pairs of (value, index) for all elements we encounter.
        priority_queue<pair<int, int>> heap;
        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            //Expand the window by inserting each new element into the heap.
            heap.push({nums[i], i});
           //Once the window size becomes k:
            if (i >= k - 1) {
               //Remove elements from the heap if their index is outside the current window.

                while (heap.top().second <= i - k) {
                    heap.pop();
                }
                //The top of the heap now gives the maximum for the window.
                //Add this maximum to the result list.
                output.push_back(heap.top().first);
            }
        }
        return output;
    }
};
