----------------------------------------------------------------
Minimum Sum Subarray
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
----------------------------------------------------------------

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int length=0;
        int minlength=INT_MAX;
        if (nums.size() == 1) {
            if (nums[0] >= target)
                return 1;
            else
                return 0;
        }
        queue<int> intq;
        int i=0;
        while(i<nums.size()) {
            sum += nums[i];
            intq.push(nums[i]);
            if(sum>=target) {
                if (intq.size() < minlength) {
                    minlength = intq.size();
                }
                while(intq.size() > 1) {
                    sum -= intq.front();
                    intq.pop();
                    if (sum < target) {
                        break;
                    }
                    if (intq.size() < minlength) {
                        minlength = intq.size();
                    }
                }
                if (sum>=target) {
                    return 1;
                }
            }
            i++;
        }
        return (minlength == INT_MAX)?0:minlength;
    }
};
