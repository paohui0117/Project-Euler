# -*- coding: UTF-8 -*-
import math


def problem78():
    k = sum([[i * (3 * i - 1) / 2, i * (3 * i - 1) / 2 + i] for i in range(1, 250)], [])
    i = [1, 1, -1, -1]
    j = 1000000
    p = [1, 1, 2]

    ret = 2
    while (p[ret] != 0):
        cur = 0
        ret += 1
        m = 0
        while (ret >= k[m]):
            cur += p[ret - k[m]] * i[m % 4];
            m += 1;
        cur %= j;
        p.append(cur);
    return ret


def problem80():
    k = [i*i for i in range(1, 11)]
    def getall(a):
        m = 1
        n = 1
        temp = 0
        ret = 0
        for i in range(0, 12):
            temp = m * n * 2;
            n = n * n + a * m * m;
            m = temp
        for i in range(0, 100):
            temp = n / m;
            ret += temp;
            n %= m;
            n *= 10;
        return ret;

    ret = 0
    cur = 0
    for i in range(1, 101):
        if (k.count(i) == 0):
            ret += getall(i)
            cur += 1
            if (cur == 100):
                break;
    return ret

print problem80();