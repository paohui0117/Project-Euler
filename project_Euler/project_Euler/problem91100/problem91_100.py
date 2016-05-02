# -*- coding: UTF-8 -*-
import math
import copy
import itertools


def problem91():
    limit = 50
    temp = [0] * 3
    temp1 = temp2 = temp3 = 0
    ret = 0
    for y1 in range(1, limit + 1):
        for x1 in range(0, limit + 1):
            for y2 in range(0, y1 + 1):
                for x2 in range(x1, limit + 1):
                    # 第二个点的x坐标不能为0，且必须大于等于第一个点的x坐标
                    if (x2 == 0):
                        continue
                        # 不能是同一个点
                    if (x1 == x2 and y1 == y2):
                        continue
                        # 在第一个点的x坐标不为0的情况下，第二个点y坐标必须小于第一个点的y坐标
                    if (x1 != 0 and y1 == y2):
                        break
                    temp[0] = x1 * x1 + y1 * y1
                    temp[1] = x2 * x2 + y2 * y2
                    temp[2] = temp[0] + temp[1] - 2 * x1 * x2 - 2 * y1 * y2
                    temp.sort()
                    # 直角三角形
                    if (temp[0] + temp[1] == temp[2]):
                        ret += 1
    print ret


def problem92():
    ret = 1
    squarelist = [i * i for i in range(0, 10)]
    allret = [0] * 10000000
    for i in range(1, 10000000):
        temp = i
        curtemp = 0
        while (temp != 1 and temp != 89):
            if (temp > 999999 or allret[temp] == 0):
                curtemp = 0
                while (temp > 0):
                    cur = temp % 10
                    curtemp += squarelist[cur]
                    temp /= 10
                temp = curtemp
            else:
                curtemp = allret[temp]
                break
        allret[i] = curtemp
        if (curtemp == 89):
            ret += 1
    print ret


def problem93():
    alllist = list(itertools.combinations([i for i in range(1, 10)], 4))
    operlist = list(itertools.product(['+', '-', '*', '/'], repeat=3))

    def oper(a, b, c):
        if (c == '+'):
            return a + b
        if (c == '-'):
            return a - b
        if (c == '*'):
            return a * b
        if (c == '/'):
            if (b != 0):
                return a * 1.0 / b
            return 0

    ret = 0
    retlist = []
    for i in range(0, len(alllist)):
        templist = list(itertools.permutations(alllist[i], 4))
        curlist = [0] * 1000
        for j in range(0, len(templist)):
            for k in range(0, len(operlist)):
                # a b c d
                temp = oper(templist[j][0], templist[j][1], operlist[k][0])
                temp = oper(temp, templist[j][2], operlist[k][1])
                temp = oper(temp, templist[j][3], operlist[k][2])
                if (temp < 1000 and temp > 0 and temp - int(temp) < 0.00001):
                    curlist[int(temp)] = 1

                # a (b c d)
                temp = oper(templist[j][1], templist[j][2], operlist[k][1])
                temp = oper(temp, templist[j][3], operlist[k][2])
                temp = oper(templist[j][0], temp, operlist[k][0])
                if (temp < 1000 and temp > 0 and temp - int(temp) < 0.00001):
                    curlist[int(temp)] = 1

                # a (b (c d))
                temp = oper(templist[j][2], templist[j][3], operlist[k][2])
                temp = oper(templist[j][1], temp, operlist[k][1])
                temp = oper(templist[j][0], temp, operlist[k][0])
                if (temp < 1000 and temp > 0 and temp - int(temp) < 0.00001):
                    curlist[int(temp)] = 1

                # a b (c d)
                temp = oper(templist[j][2], templist[j][3], operlist[k][2])
                temp2 = oper(templist[j][0], templist[j][1], operlist[k][0])
                temp = oper(temp2, temp, operlist[k][1])
                if (temp < 1000 and temp > 0 and temp - int(temp) < 0.00001):
                    curlist[int(temp)] = 1

                # a (b c) d
                temp = oper(templist[j][1], templist[j][2], operlist[k][1])
                temp = oper(templist[j][0], temp, operlist[k][0])
                temp = oper(temp, templist[j][3], operlist[k][2])
                if (temp < 1000 and temp > 0 and temp - int(temp) < 0.00001):
                    curlist[int(temp)] = 1

                # (a b) (c d)
                temp = oper(templist[j][0], templist[j][1], operlist[k][0])
                temp2 = oper(templist[j][2], templist[j][3], operlist[k][2])
                temp = oper(temp, temp2, operlist[k][1])
                if (temp < 1000 and temp > 0 and temp - int(temp) < 0.00001):
                    curlist[int(temp)] = 1
        curtemp = 0
        for n in range(1, len(curlist)):
            if (curlist[n] == 0):
                if (ret < n):
                    ret = n
                    retlist = alllist[i]
                break
    print ret
    print retlist


def problem95():
    limit = 1000000
    allsum = [1] * limit
    for i in range(2, limit):
        for j in xrange(2 * i, limit, i):
            allsum[j] += i
    allret = [-1] * limit
    for i in range(1, limit):
        templist = [i]
        cur = allsum[i]
        while 1:

            if (cur == 1 or cur > limit - 1):
                for j in range(0, len(templist)):
                    allret[templist[j]] = 0
                break
            if (allret[cur] != -1):
                for j in range(0, len(templist)):
                    if (allret[templist[j]] == -1):
                        allret[templist[j]] = 0
                break
            if (cur in templist):
                curset = templist.index(cur)
                curlen = len(templist) - curset
                for j in range(0, curset):
                    allret[templist[curset]] = 0
                for j in range(curset, len(templist)):
                    allret[templist[curset]] = curlen
                break
            else:
                templist.append(cur)
                cur = allsum[cur]
    ret = max(allret)
    retset = allret.index(ret)
    print ret
    print retset


def problem96():
    myfile = open('p096_sudoku.txt')
    def CheckList(alist):
        lastnum = 0
        while 1 :
            curnum = 81
            for i in range(0, 9):
                for j in range(0, 9):
                    if (len(alist[i][j]) == 1 ):
                        curnum -= 1
                        continue
                    templist = [0] * 10
                    for k in range(0, 9):
                        if (k == i):
                            continue
                        templistj = [0] * 10
                        if (len(alist[k][j]) == 1):
                            templist[alist[k][j][0]] += 1
                            templistj[alist[k][j][0]] += 1
                            if (templistj[alist[k][j][0]] > 1):
                                return -1
                    templistj = [0] * 10
                    for k in range(0, 9):
                        if (k == j):
                            continue
                        if (len(alist[i][k]) == 1):
                            templist[alist[i][k][0]] = 1
                            templistj[alist[i][k][0]] += 1
                            if (templistj[alist[i][k][0]] > 1):
                                return -1
                    curi = i / 3
                    curj = j / 3
                    templistj = [0] * 10
                    for tempi in range(curi * 3, (curi + 1) * 3):
                        for tempj in range(curj * 3, (curj + 1) * 3):
                            if (len(alist[tempi][tempj]) == 1):
                                templist[alist[tempi][tempj][0]] = 1
                                templistj[alist[tempi][tempj][0]] += 1
                                if (templistj[alist[tempi][tempj][0]] > 1):
                                    return -1
                    if (len(alist[i][j]) == 0):
                        for k in range(1, 10):
                            if (templist[k] == 0):
                                alist[i][j].append(k)
                    else:
                        curtemp = []
                        for k in range(0, len(alist[i][j])):
                            if (templist[alist[i][j][k]] == 0):
                                curtemp.append(alist[i][j][k])
                        alist[i][j] = curtemp
                    if (len(alist[i][j]) == 1):
                        curnum -= 1
                    if (len(alist[i][j]) == 0):
                        return -1
            if (curnum == 0):
                ret = alist[0][0][0] * 100 + alist[0][1][0] * 10 + alist[0][2][0]
                return ret
            if (curnum == lastnum):
                return 0
            lastnum = curnum

    def TryAll(a):
        listnum = []
        listset = []
        curnum = 0
        curset = 0

        while 1:
            templist = copy.deepcopy(a)
            if (len(listnum) == 0):
                curi = curnum / 9
                curj = curnum % 9
                while (len(templist[curi][curj]) == 1):
                    curnum += 1
                    curi = curnum / 9
                    curj = curnum % 9
                listnum.append(curnum)
                listset.append(-1)

            listset[-1] += 1
            curset = listset[-1]
            curnum = listnum[-1]
            curi = curnum / 9
            curj = curnum % 9

            if (curset > len(a[curi][curj]) - 1):
                listnum.pop()
                listset.pop()
                continue

            for i in range(0, len(listnum)):
                curi = listnum[i] / 9
                curj = listnum[i] % 9
                templist[curi][curj] = [a[curi][curj][listset[i]]]
            tempret = CheckList(templist)
            if (tempret > 0):
                return tempret
            if (tempret == -1):
                continue
            if (tempret == 0):
                while (len(templist[curi][curj]) == 1):
                    curnum += 1
                    curi = curnum / 9
                    curj = curnum % 9
                listnum.append(curnum)
                cursett = a[curi][curj].index(templist[curi][curj][0])
                listset.append(cursett - 1)



    def CalcList(f):
        curlist = []
        for i in range(0, 9):
            curline = f.readline()
            templist = [0] * 9
            for j in range(0, 9):
                if (curline[j] == '0'):
                    templist[j] = []
                else:
                    templist[j] = [int(curline[j])]
            curlist.append(templist)
        curret = CheckList(curlist)
        if (curret > 0):
            return curret
        templist = []
        while 1:
            bwork = 0
            for i in range(0, 9):
                for j in range(0, 9):
                    if (len(curlist[i][j]) > 1):
                        bfind = 0
                        templist = curlist[i][j]
                        for k in range(0, len(templist)):
                            temp = copy.deepcopy(curlist)
                            temp[i][j] = [templist[k]]
                            tempret = CheckList(temp)
                            if (tempret > 0):
                                return tempret
                            if (tempret == -1):
                                bfind = 1
                                bwork = 1
                                templist[k] = 0
                        if (bfind):
                            curlist[i][j] = []
                            for k in range(0, len(templist)):
                                if (templist[k] > 0):
                                    curlist[i][j].append(templist[k])
                            if (len(curlist[i][j]) == 1):
                                tempret = CheckList(curlist)
                                if (tempret > 0):
                                    return tempret
            if (not bwork):
                return TryAll(curlist)
                break
    ret = 0
    for i in range(0, 50):
        myfile.readline()
        ret += CalcList(myfile)
    print ret


def problem97():
    temp210 = int(math.pow(2, 1000))
    cur = temp210
    cur %= 10000000000
    for i in range(1, 7830457 / 1000):
        cur *= temp210
        if (cur > 10000000000):
            cur %= 10000000000
    temp = int(math.pow(2, 457))
    cur *= temp
    if (cur > 10000000000):
        cur %= 10000000000
    cur *= 28433
    cur += 1
    if (cur > 10000000000):
        cur %= 10000000000
    print cur

def problem98():
    wordlist = []
    f = open('p098_words.txt')
    if (not f):
        return
    curline = f.readline()
    while (curline):
        wordlist.extend(curline.split(','))
        curline = f.readline()
    wordlist.sort(key = lambda a : len(a))
    templist = [0] * len(wordlist)
    samecharword = []
    intA = ord('A')
    #获取相同字符的单词
    for i in range(0, len(wordlist)):
        if (templist[i] == 1 or len(wordlist[i]) == 3):
            continue
        templist[i] = 1
        samelist = [wordlist[i]]
        tempcharlist = [0] * 27
        for k in range(1, len(wordlist[i]) - 1):
            tempchar = ord(wordlist[i][k]) - intA
            tempcharlist[tempchar] += 1
        for j in range(i + 1, len(wordlist)):
            if (templist[j] == 1):
                continue
            if (len(wordlist[i]) != len(wordlist[j])):
                break
            curtemp = copy.deepcopy(tempcharlist)
            bsame = 1
            for k in range(1, len(wordlist[j]) - 1):
                cur = ord(wordlist[j][k]) - intA
                curtemp[cur] -= 1
                if (curtemp[cur] < 0):
                    bsame = 0
                    break
            if (bsame):
                samelist.append(wordlist[j])
                templist[j] = 1
        if (len(samelist) > 1):
            samecharword.append(samelist)
    samecharword.sort(key = lambda a : len(a[0]), reverse=1)
    #获取相同数字组成的平方数
    squaremap = dict()

    def GetNum(stra, intb, strb):
        print stra
        print intb
        mapchar = dict()
        mapnum = dict()
        for i in range(0, len(stra) - 2):
            mapchar[stra[len(stra) - 2 - i]] = intb % 10
            if (mapnum.has_key(intb % 10)) and (mapnum[intb % 10] != stra[len(stra) - 2 - i]):
                print 'none'
                return 0
            mapnum[intb % 10] = stra[len(stra) - 2 - i]
            intb /= 10
        strlen = len(strb) - 2
        ret = 0
        cur = 1
        for j in range(0, len(strb) - 2):
            ret +=  mapchar[strb[len(strb) - 2 - j]] * cur
            cur *= 10
        print strb
        print ret
        return ret

    ret = 0
    for i in range(0, len(samecharword)):
        curlen = len(samecharword[i][0]) - 2
        tempcharlist = [0] * 27
        for j in range(1, len(samecharword[i][0]) - 1):
            tempcharlist[ord(samecharword[i][0][j]) - intA] += 1
        tempcharlist.sort(None, None, 1)
        if (not squaremap.has_key(curlen)):
            squaremap[curlen] = []
        if 1:
            min = pow(10, curlen - 1)
            min = int(math.sqrt(min))
            max = pow(10, curlen)
            max = int(math.sqrt(max))
            tempsqurt = []
            for j in range(min, max):
                tempsqurt.append(j * j)
            retset = set()
            for j in range(0, len(tempsqurt)):
                if (tempsqurt[j] in retset):
                    break
                tempnum = [0] * 10
                cur  = tempsqurt[j]
                buse = 1
                while cur > 0:
                    tempnum[cur % 10] += 1
                    cur /= 10
                test = tempnum[:]
                test.sort(None, None, 1)
                for k in range(0, len(test)):
                    if (test[k] != tempcharlist[k]):
                        buse = 0
                        break
                if (not buse):
                    continue
                curtemplist = [tempsqurt[j]]
                for k in range(j + 1, len(tempsqurt)):
                    cur = tempsqurt[k]
                    templist = copy.deepcopy(tempnum)
                    bfind = 1
                    while cur > 0:
                        curtemp = cur % 10
                        templist[curtemp] -= 1
                        if (templist[curtemp] < 0):
                            bfind = 0
                            break
                        cur /= 10
                    if (bfind):
                        curtemplist.append(tempsqurt[k])
                        retset.add(tempsqurt[k])
                if (len(curtemplist) > 1):
                    squaremap[curlen].append(curtemplist)

        #匹配数字与单词
        for j in range(0, len(squaremap[curlen])):
            for k in range(0, len(squaremap[curlen][j])):
                cur = GetNum(samecharword[i][0], squaremap[curlen][j][k], samecharword[i][1])
                if (cur in squaremap[curlen][j]):
                    nmax = squaremap[curlen][j][k]
                    if (nmax < cur):
                        nmax = cur
                    if (ret < nmax):
                        ret = nmax

    print ret

def problem99():
    f = open('p099_base_exp.txt')
    curline = f.readline()
    allnum = []
    while curline:
        allnum.append(curline.split(','))
        curline = f.readline()
    retnum = allnum[0][:]
    ret = 0
    for i in range(1, len(allnum)):
        cur =  math.log(int(allnum[i][0]), int(retnum[0]))
        if (int(retnum[1]) < cur * int(allnum[i][1])):
            retnum = allnum[i][:]
            ret = i
    print ret + 1

def problem100():
    # 佩尔方程   2a平方 - y平方 = 1
    #2x - 1 = a
    #n = （y + 1） / 2
    #n为总数   x为蓝色碟子数
    MAX = 10**12
    x = 21
    y = 15
    while x<MAX:
        print x,y
        tmpx = 17*x + 24*y -20
        tmpy = 12*x + 17*y -14
        x = tmpx
        y = tmpy
    print x, y
problem100()

