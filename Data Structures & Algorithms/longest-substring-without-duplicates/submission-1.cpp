class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //SLIDING WINDOW
        //set to keep track of characters
        unordered_set<char> charSet;
        int l= 0;
        int result = 0;

        for (int i=0;i<s.size();++i){
            while (charSet.find(s[i]) != charSet.end()) {
                //rid of it and check the next
                charSet.erase(s[l]);
                l++;
        }
        charSet.insert(s[i]);
            result = max(result, i - l + 1);
        }
        return result;
    }
};
