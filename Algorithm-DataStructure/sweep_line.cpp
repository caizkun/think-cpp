// summary for Sweep Line

// Useful for interval problems

// General idea:
// 1. split each interval to two points (pairs) with a flag: <start, 1> and <end, 0>
// 2. sort all the points
// 3. Loop over the points and dynamically update the overall result

// time complexity: O(n)


// eg. Meeting Room II
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        
        // split each interval to points
        vector<pair<int, int> > points;
        splitIntervals(intervals, points);
        
        // sort the points
        sort(points.begin(), points.end(), [] (pair<int, int> &a, pair<int, int> &b) {
            if (a.first == b.first) {
                return (a.second < b.second);   // end first, then start
            }
            return (a.first < b.first);
        });
        
        // sweep line
        int res = 0;
        int curr = 0;
        for (pair<int, int> item : points) {
            if (item.second == 0) {
                --curr;
            } else {
                ++curr;
            }
            res = max(res, curr);
        }
        return res;
    }
    
private:
    void splitIntervals(vector<Interval> &intervals, vector<pair<int, int> > &points) {
        for (Interval item : intervals) {
            points.push_back(make_pair(item.start, 1));
            points.push_back(make_pair(item.end, 0));
        }
        return;
    }
};

