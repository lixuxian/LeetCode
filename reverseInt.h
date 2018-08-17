//
// Created by 李旭贤 on 2018/8/17.
//

#ifndef LEETCODE_REVERSEINT_H
#define LEETCODE_REVERSEINT_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class reverseIntSolution {
public:
    int reverse(int x) {
        char xx[20] = {0};
        bool neg = false;
        if (x < 0) {
            neg = true;
            x = -x;
        }
        printf("neg: %d\n", neg);
        sprintf(xx, "%d", x);
        if (neg)
            printf("xx: -%s\n", xx);
        else
            printf("xx: %s\n", xx);

        int len = strlen(xx);
        printf("len: %d\n", len);

        for (int i = 0; i < ceil(len/2); i++)
        {
            char temp = xx[i];
            xx[i] = xx[len - i - 1];
            xx[len - i - 1] = temp;
        }
        long res = strtol(xx, NULL, 10);
        if (res > pow(2, 31))
            return 0;
        if (neg)
        {
            printf("xx: -%s\n", xx);
            res = -res;
        }
        else
        {
            printf("xx: %s\n", xx);
        }
        printf("res: %ld\n", res);
        return res;
    }

    int reverse2(int x)
    {
        if(x == (0x1<<31))
        {
            return 0;
        }
        long ans = 0;
        int flag = 1;

        if(x < 0)
        {
            flag = -1;
            x = -x;
        }
        while(x)
        {
            long temp;
            if((temp = ans * 10 + x % 10)>2147483647)
                return 0;
            ans = temp;
            x /= 10;
        }

        return ans * flag;
    }
};
#endif //LEETCODE_REVERSEINT_H
