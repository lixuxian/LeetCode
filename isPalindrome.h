//
// Created by 李旭贤 on 2018/8/17.
//

#ifndef LEETCODE_ISPALINDROME_H
#define LEETCODE_ISPALINDROME_H

class isPalindromeSolution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        if (x == 0)
        {
            return true;
        }
        int re = 0;
        while (x > re)
        {
            re = re * 10 + x % 10;
            x /= 10;
        }
        if (re == x || x == re / 10)
            return true;
        return false;
    }
};

#endif //LEETCODE_ISPALINDROME_H
