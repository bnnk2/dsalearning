-------------------------------------------------------------------------
  1353. Maximum Number of Events That Can Be Attended
Medium

3015

415

Add to List

Share
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.

 

Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.

---------------------------------------------------------------------------------------------------------------
  
class Solution {
public:
    static bool sortmyvec(vector<int> a, vector<int> b) {
        if (a[0] < b[0]) {
            return true; 
        } else if (a[0] > b[0]) {
            return false;
        } else {
            if (a[1] < b[1]) {
                return true; 
            }
        }
        return false;
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), sortmyvec);
        priority_queue<int, vector<int>, greater<int>> pq;
        int day=0;
        int index=0;
        int n = events.size();
        int numevents=0;
        while((pq.empty() == false) || 
              (index < n)) {
            if(pq.empty() == true) {
                day=events[index][0];
            }
            while((index < n) && 
                  (events[index][0] <= day)) {
               pq.push(events[index][1]); 
               index++;
            }
            numevents++;
            day++; 
            pq.pop();
            while((pq.empty() == false) && 
                  (pq.top() < day)) {
                pq.pop();
            }
        }
        return numevents;
    }
};
