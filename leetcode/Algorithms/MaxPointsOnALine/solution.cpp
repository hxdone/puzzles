// intuive solution by hxdone
// TODO: add necessary comments, and optimize the performance

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() == 0)
            return 0;
        
        unordered_map<long, int> uniq_points;
        for (int i = 0; i < points.size(); ++i) {
            long point_xy = points[i].x;
            point_xy = (point_xy<<32)|(points[i].y&0xffffffff);
            ++uniq_points[point_xy];
        }
        
        unordered_map<long, unordered_set<long>> normal;// kb->xy
        unordered_map<int, unordered_set<int>> vertical;// x->y
        for (auto iter = uniq_points.begin(); iter != uniq_points.end(); ++iter)
            for (auto iter2 = iter; iter2 != uniq_points.end();  ++iter2) {
                if (iter2 == iter)
                    continue;
                int x1 = ((iter->first)>>32);
                int y1 = (iter->first)&0xffffffff;
                int x2 = ((iter2->first)>>32);
                int y2 = (iter2->first)&0xffffffff;
                int cnt1 = iter->second;
                int cnt2 = iter2->second;
                if (x1 == x2) {
                    vertical[x1].insert(y1);
                    vertical[x2].insert(y2);
                } else {
                    long kb = getKB(Point(x1,y1),Point(x2,y2));
                    long point_xy = x1;
                    point_xy = (point_xy<<32)|(y1&0xffffffff);
                    normal[kb].insert(point_xy);
                    point_xy = x2;
                    point_xy = (point_xy<<32)|(y2&0xffffffff);
                    normal[kb].insert(point_xy);
                }
            }
        int max_points = 0;
        for (auto iter = vertical.begin(); iter != vertical.end(); ++iter) { // for each x
            int num = 0;
            for (auto iter2 = (iter->second).begin(); iter2 != (iter->second).end(); ++iter2) { // for each y
                long point_xy = iter->first;
                point_xy = (point_xy<<32)|((*iter2)&0xffffffff);
                num += uniq_points[point_xy];
            }
            max_points = max(max_points, num);
        }
        for (auto iter = normal.begin(); iter != normal.end(); ++iter) { // for each kb 
            int num = 0;
            for (auto iter2 = (iter->second).begin(); iter2 != (iter->second).end(); ++iter2) // for each xy
                num += uniq_points[*iter2];
            max_points = max(max_points, num);
        }
        for (auto iter = uniq_points.begin(); iter != uniq_points.end(); ++iter)
            max_points = max(max_points, iter->second);
        return max_points;
    }
    
private:
    long getKB(Point p1, Point p2) {
        long y_diff = p2.y-p1.y;
        long x_diff = p2.x-p1.x;
        long max_one = max(y_diff, x_diff);
        long min_one = min(y_diff, x_diff);
        float k, b;
        if (y_diff == 0) {
            k = 0;
            b = p1.y;
        } else {
            while (max_one % min_one != 0) {
                long t = min_one;
                min_one = max_one % min_one;
                max_one = t;
            }
            k = (y_diff/min_one)*1.0/(x_diff/min_one);
            b = (x_diff/min_one*p1.y-y_diff/min_one*p1.x)*1.0/(x_diff/min_one);
        }
        long kb = ((long(*(int*)(&k)))<<32) | ((*(int*)(&b))&0xffffffff);
        return kb;
    }
};
