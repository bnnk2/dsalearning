----------------------------------------------------------------------------------
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
----------------------------------------------------------------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> ccount;
        int maxlen=INT_MIN;
        int length=0;
        int start=0;
        if(s.size() < 2) {
            return s.size();
        }
        for(int i=0;i<s.size();i++) {
            ccount[s[i]]++;
            length++;
            int j=start;
            while(ccount[s[i]] > 1) {
                ccount[s[j]]--;
                j++;
                length--;
            }
            start=j;
            if (length > maxlen) {
                maxlen = length;
            }
        }
        return maxlen;
    }
};
