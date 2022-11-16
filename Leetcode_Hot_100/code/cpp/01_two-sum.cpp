// https://leetcode.cn/problems/two-sum

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        int res = target - nums[i];
        auto iter = m.find(res);
        if (iter != m.end())
            return vector<int>{i, m[res]};
        m.insert(pair<int, int>(nums[i], i));
    }
    return vector<int>{-1, -1};
}

int main()
{
    vector<int> nums{ 2, 7, 11, 15 };
    int target = 9;
    auto ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
}
