// 老师想给孩子们分发糖果，有N个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

// 你需要按照以下要求，帮助老师给这些孩子分发糖果：
// 每个孩子至少分配到 1 个糖果。
// 评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
// 那么这样下来，老师至少需要准备多少颗糖果呢？

#include "00_commonHeader.hpp"

class Solution {
  public:
    int candy(vector<int> &ratings) {
        auto size = ratings.size();
        if (size < 2) {
            return size;
        }

        vector<int> candies(size, 1);
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = size - 1; i > 0; i--) {
            if (ratings[i] < ratings[i - 1]) {
                candies[i - 1] = max(candies[i - 1], candies[i] + 1);
            }
        }
        auto num_candies = accumulate(candies.begin(), candies.end(), 0);
        return num_candies;
    }
};