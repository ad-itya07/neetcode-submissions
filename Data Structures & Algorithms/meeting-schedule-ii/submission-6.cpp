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
    int minMeetingRooms(vector<Interval>& ints) {
        int n = ints.size();
        if (n==0) return 0;
        
        sort(ints.begin(), ints.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> pq;

        int res = 1;
        pq.push(ints[0].end);

        for (int i=1; i<n; i++) {
            if (!pq.empty() && pq.top() > ints[i].start) {
                res++;
                pq.push(ints[i].end);
            }
            else {
                pq.pop();
                pq.push(ints[i].end);
            }
        }

        return res;
    }
};
