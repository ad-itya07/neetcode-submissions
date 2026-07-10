    /**
    * Definition of Interval:
    * class Interval {
    * public:
    *     int start, end;
    *     Interval(int start, int end) {
    *         this->start = start;
    *         this->end = end;
    *     }
    * }
    */

    class Solution {
    public:
        static bool cmp(Interval& a, Interval& b) {
            return a.start < b.start;
        }
        int minMeetingRooms(vector<Interval>& intervals) {
            int n = intervals.size();

            if (n==0) return 0;
            sort(intervals.begin(), intervals.end(), cmp);

            priority_queue<int, vector<int>, greater<int>> pq;
            
            int ans = 0;
            
            for (int i=0; i<n; i++) {
                while (!pq.empty() && pq.top() <= intervals[i].start) pq.pop();
                pq.push(intervals[i].end);
                ans = max(ans, (int)pq.size());
            }

            return ans;
        }
    };
