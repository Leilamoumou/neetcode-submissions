class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     //store single interval 
       vector<vector<int>> result;
       //iterate through index
      //  for (int i = 0; i < intervals.size(); ++i){
       //   for (int x = 0; x < i; ++x )  {
         //   if (intervals[i+1])
         /* past intuition  ^, actual solution
-Sort all intervals by their start time.
-Initialize the result list output with the first interval.
-Iterate through each interval (start, end) in the sorted list:
-Let lastEnd be the end of the last interval in output.
-If the current interval overlaps with the last one (start <= lastEnd):
    Merge them by updating the end:
    output[-1][1] = max(lastEnd, end)
         */
         
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for (auto& interval : intervals) {
            //-Sort all intervals by their start time.
            int start = interval[0];
            int end = interval[1];
            int lastEnd = output.back()[1];

            if (start <= lastEnd) {
                output.back()[1] = max(lastEnd, end);
            } else {
                output.push_back({start, end});
            }
        }
        return output;
    }
};
