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
    static bool  cmp(Interval& a, Interval& b) {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int currEnd = intervals[0].end;
        for (int i=1; i<n; i++) {
            if (intervals[i].start < currEnd) return false;
            else currEnd = intervals[i].end;
        }

        return true;
    }

};
