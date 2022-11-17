#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
        vector<int> m[26];
        for (int i = 0; i < s.size(); i++)
            m[s[i] - 'a'].push_back(i);
        int count = 0;
        for (string word : words)
        {
            bool match = true;
            int idx = -1;
            for (char c : word)
            {
                auto iter = upper_bound(m[c - 'a'].begin(), m[c - 'a'].end(), idx);
                if (iter == m[c - 'a'].end())
                {
                    match = false;
                    break;
                }
                idx = *iter;
            }
            if (match)
                count++;
        }
        return count;
        // vector<int> flag(26, -1);
        // vector<vector<int>> m(s.size(), vector<int>(26, -1));
        // for (int i = 0; i < s.size(); i++)
        // {
        //     if (flag[s[i] - 'a'] == -1)
        //         flag[s[i] - 'a'] = i;
        //     for (int j = i + 1; j < s.size(); j++)
        //     {
        //         if (m[i][s[j] - 'a'] == -1)
        //             m[i][s[j] - 'a'] = j;
        //     }
        // }
        // int count = 0;
        // for (string word : words)
        // {
        //     int idx = flag[word[0] - 'a'];
        //     if (idx == -1)
        //         continue;
        //     bool match = true;
        //     for (int i = 1; i < word.size(); i++)
        //     {
        //         if (m[idx][word[i] - 'a'] < idx)
        //         {
        //             match = false;
        //             break;
        //         }
        //         idx = m[idx][word[i] - 'a'];
        //     }
        //     if (match)
        //         count++;
        // }
        // return count;
    }
};
