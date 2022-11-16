#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s)
    {
        int left = 0, right = 0;
        int maxLength = 0;
        bool flag[128] = { false };
        while(right < s.size())
        {
            if (!flag[s[right]]) // 右指针滑动
            {
                flag[s[right]] = true;
                right++;
            }
            else
            {
                maxLength = std::max(maxLength, right - left);
                if (s[left] != s[right])
                {
                    flag[s[left]] = false;
                    left++;
                }
                else
                {
                    left++;
                    right++;
                }
            }
        }
        return std::max(maxLength, right - left);
    }
};