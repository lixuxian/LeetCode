//
// Created by 李旭贤 on 2018/8/16.
//

#ifndef LEETCODE_LENGTHOFLONGESTSUBSTRING_H
#define LEETCODE_LENGTHOFLONGESTSUBSTRING_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class lengthOfLongestSubstringSolution {

public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int tempLen = 1;
            vector<char> char_map;
            vector<char>::iterator it;
            char_map.push_back(s[i]);

            for (int j = i + 1; j < s.size(); j++)
            {
                it = find(char_map.begin(), char_map.end(), s[j]);
                if (it != char_map.end())
                {
                    break;
                }
                else
                {
                    tempLen++;
                    char_map.push_back(s[j]);
                }
            }
            if (maxLen < tempLen)
            {
                maxLen = tempLen;
            }
        }
        return maxLen;
    }

    int lengthOfLongestSubstring2(string s) {
        int i = 0, j = 0, maxLen = 0;
        long len = s.length();
        set<char> char_set;
        set<char>::iterator it;

        while(i < len && j < len)
        {
            it = char_set.find(s[j]);
            if (it != char_set.end() )
            {
                char_set.erase(it);
                i++;
            }
            else
            {
                char_set.insert(s[j++]);
                maxLen = maxLen > (j - i) ? maxLen : (j - i);
            }
        }
        return maxLen;
    }

    void test()
    {
        string s1 = "abcabcbb";
        string s2 = "pwwkew";
        cout << "s1: " << lengthOfLongestSubstring2(s1) << endl;
        cout << "s2: " << lengthOfLongestSubstring2(s2) << endl;
    }
};
#endif //LEETCODE_LENGTHOFLONGESTSUBSTRING_H
