//
// Created by 李旭贤 on 2018/8/16.
//

#ifndef LEETCODE_TWOSUM_H
#define LEETCODE_TWOSUM_H
#include <vector>
using namespace std;

class twoSumSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int remain;
        vector<int>::iterator it;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            remain = target - nums[i];
            it = find(nums.begin(), nums.end(), remain);
            if (it != nums.end() && (it-nums.begin()) != i)
            {
                result.push_back(i);
                result.push_back(it - nums.begin());
                break;
            }
        }
        return result;
    }
};
#endif //LEETCODE_TWOSUM_H
