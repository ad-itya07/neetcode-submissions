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
    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& ints) {
        int n = ints.size();

        sort(ints.begin(), ints.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;

        int res=0;
        for (int i=0; i<n; i++) {
            while (!pq.empty() && pq.top() <= ints[i].start) pq.pop();
            pq.push(ints[i].end);
            res = max(res, (int)pq.size());
        }

        return res;
    }
};
