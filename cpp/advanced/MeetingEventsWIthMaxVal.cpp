------------------------------------------------------------------------------------
  1751. Maximum Number of Events That Can Be Attended II
Hard

2061

40

Add to List

Share
You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

 

Example 1:



Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
Example 2:



Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
Example 3:



Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
-------------------------------------------------------
class Solution {
public:
    bool sortvec(vector<int> a, vector<int> b) {
        if(a[0] < b[0]) {
            return true;
        } else if(a[0] > b[0]) {
            return false;
        } else {
            if (a[1] < b[1]) {
                return true;
            }
        }
        return false;
    }
    int valIndex(vector<vector<int>>& events, int cidx) {
        int eidx=events.size()-1;
        int sidx=cidx+1;
        int mid=0;
        while(eidx>sidx) {
            mid=(sidx+eidx)/2;
            if(events[mid][0]>events[cidx][1]) {
                eidx=mid;
            } else {
                sidx=mid+1;
            }
        }
        return (events[eidx][0]>events[cidx][1])?eidx:INT_MAX;
    }
    int maxVal(vector<vector<int>>& events, int index, 
               int count, int maxv, vector<vector<int>> &dp) {
        if ((index >= events.size()) ||
            (count >= maxv)){
            return 0;
        }
        if(dp[index][count] > -1) {
            return dp[index][count];
        }
        int sel=events[index][2]+maxVal(events,valIndex(events, index), count+1, maxv, dp);
        int rej=maxVal(events, index+1, count, maxv, dp);
        return (dp[index][count]=max(sel, rej));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k+1, -1));
        return maxVal(events, 0, 0,k,dp);
    }
};
