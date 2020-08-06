// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

// Buildings Skyline Contour
// The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

// For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

// The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

// For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

// Notes:

// The number of buildings in any input list is guaranteed to be in the range [0, 10000].
// The input list is already sorted in ascending order by the left x position Li.
// The output list must be sorted by the x position.
// There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]


#include<queue>
#include<vector>
using namespace std;


class Solution {
    public:
    void heap_remove(priority_queue<int, vector<int>, greater<int>>& max_heap, int value) {
        vector<int> temp;
        while(max_heap.top() != value) {
            temp.push_back(max_heap.top());
            max_heap.pop();
        }
        max_heap.pop();
        for(auto val : temp) {
            max_heap.push(val);
        }
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        auto cmp_less = [](vector<int>& left, vector<int>& right) { return (left[0]) < (right[0]); };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp_less)> points(cmp_less);
        for (auto pnt: buildings) {
            points.push({pnt[0], pnt[2], 0});
            points.push({pnt[1], pnt[2], 1});            
        }
        
        priority_queue<int, vector<int>, greater<int>> heights;
        
        heights.push(0);
        vector<vector<int>> res;
        
        while (!points.empty()) {
            auto pnt = points.top();
            points.pop();
            
            auto x = pnt[0];
            auto h = pnt[1];
        
            if (pnt[2]) {   // start of a new building
                if (h > heights.top())
                    res.push_back({x, h});
                heights.push(h);
            }
            else {      // end of a previous building
                auto max_h = heights.top();
                heap_remove(heights, h);                
                if (max_h > heights.top())
                    res.push_back({x, h});
            }
        }
        return res;
    }
};