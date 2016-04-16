# -*- coding: UTF-8 -*-
import string
import math
import re
def problem81(a):
    f = open(a);
    line = f.readline();
    k = []
    temp = []
    while(line):
        temp = line.split(',')
        line = f.readline()
        k.append([int(temp[i]) for i in range(0, len(temp))])

    ret = [[0] * 80] * 80;
    ret[0][0] = k[0][0];
    for i in range(1, 80):
        ret[0][i] = ret[0][i - 1] + k[0][i];
        ret[i][0] = ret[i - 1][0] + k[i][0];

    for i in range(1, 80):
        for j in range(1, 80):
            ret[i][j] = k[i][j] + min(ret[i-1][j], ret[i][j - 1])

    print ret[79][79]


def problem82(a):
    b = 80
    f = open(a);
    line = f.readline();
    k = []
    temp = []
    while(line):
        temp = line.split(',')
        line = f.readline()
        k.append([int(temp[i]) for i in range(0, len(temp))])

    ret = []
    for i in range(0, b):
        ret.append([0] * b)
    ret[0][0] = k[0][0];
    templist = []
    tempcur = 0
    tempcur2 = 0
    for i in range(0, b):
        ret[i][0] = k[i][0];
    for j in range(1, b - 1):
        for i in range(0, b):
            tempcur = 0
            tempcur2 = 0
            templist = []
            for cur in range(i, b):
                tempcur += k[cur][j]
                templist.append(tempcur + ret[cur][j - 1])
            tempcur = 0
            for cur in range(i, -1, -1):
                tempcur += k[cur][j]
                templist.append(tempcur + ret[cur][j - 1])
            ret[i][j] = min(templist)

    for i in range(0, b):
        ret[i][b - 1] = ret[i][b - 2] + k[i][b - 1]

    print min(ret[i][b - 1] for i in range(0, b))

def problem83(a):
    b = 80
    f = open(a);
    line = f.readline();
    k = []
    temp = []
    while(line):
        temp = line.split(',')
        line = f.readline()
        k.append([int(temp[i]) for i in range(0, len(temp))])

    ret = [9999999] * (b * b)
    allpoint= [0] * (b * b)
    ret[0] = 0
    ret[1] = k[0][1]
    ret[b] = k[1][0]
    curcalc = 1

    curi = 0
    while(curcalc < b * b):
        cur = 9999999
        for i in range(1, b*b):
            if (allpoint[i] == 0) and (cur > ret[i]):
                cur = ret[i]
                curi = i
        tempi = curi / b
        tempj = curi % 80
        curcalc += 1
        allpoint[curi] = 1
        if (tempj == 0):    #left
            templ = -1
        else:
            templ = curi - 1
        tempt = curi - b    #top

        if (tempj == b - 1):#right
            tempr = -1
        else:
            tempr = curi + 1

        if (tempi == b - 1):#bottom
            tempb = -1
        else:
            tempb = curi + b

        if (templ > -1) and (cur + k[tempi][tempj - 1] < ret[templ]):
            ret[templ] = cur + k[tempi][tempj - 1]
        if (tempt > -1) and (cur + k[tempi - 1][tempj] < ret[tempt]):
            ret[tempt] = cur + k[tempi - 1][tempj]
        if (tempr > -1) and (cur + k[tempi][tempj + 1] < ret[tempr]):
            ret[tempr] = cur + k[tempi][tempj + 1]
        if (tempb > -1) and (cur + k[tempi + 1][tempj] < ret[tempb]):
            ret[tempb] = cur + k[tempi + 1][tempj]

    print ret[b *b -1] + k[0][0]

def problem86():
    def GetGreatest(a, b):
        while(b > 0):
            temp = b
            b = a % b
            a = temp
        return a
    a = 0
    b = 0
    c = 0
    temp = [0, 0, 0]
    all = []
    for i in range(2,6000):
        for j in range(1, i):
            if (GetGreatest(j, i) == 1) and (i - j) % 2 == 1:
                temp[0] = i * i - j * j
                temp[1] = 2 * i * j
                temp[2] = temp[1] + temp[0]
                temp.sort()
                if (temp[0] > 6000):
                    break
                for k in range(1, 6000):
                    if (temp[2] * k > 6000):
                        break
                    all.append([temp[0] * k, temp[1] * k, temp[2] * k])

    all.sort(None, key=lambda l:l[2])
    ret = [0] * 2000
    for i in range(3, 2000):
        ret[i] = ret[i - 1]
        for j in range(0, len(all)):
            if (i < all[j][2] / 3):
                break
            if (i == all[j][1]):
                ret[i] += all[j][0] / 2
            elif (i == all[j][0]):
                if (i > all[j][1] / 2 - 1):
                    ret[i] += i - all[j][1] / 2
                    if (all[j][1] % 2 == 0):
                        ret[i] += 1
        if (ret[i] > 1000000):
            print  i
            break


def problem87():
    all = []
    def IsPrime(a):
        if (a < 4):
            return 1
        b = int(math.sqrt(a))
        for i in range(2, b + 1):
            if (a % i == 0):
                return  0
        return 1

    all2 = []
    all3 = []
    all4 = []
    cur = 2
    while (1):
        if (IsPrime(cur)):
            temp = cur * cur
            if (temp > 50000000):
                break
            all2.append(temp)
            temp *= cur
            if (temp > 50000000):
                cur += 1
                continue
            all3.append(temp)
            temp *= cur
            if (temp > 50000000):
                cur += 1
                continue
            all4.append(temp)
        cur += 1

    ret = 0
    temp = 0
    dicret = dict()
    for i in range(0, len(all2)):
        for j in range(0, len(all3)):
            if (all2[i] + all3[j] > 50000000):
                break
            for k in range(0, len(all4)):
                temp = all2[i] + all3[j] + all4[k]
                if (temp > 50000000):
                    break
                else:
                    if (not dicret.has_key(temp)):
                        dicret[temp] = 0
                        ret += 1
    print ret


def problem88():
    allret = [12000 * 2 + 1] * 12001
    alltemp = []
    for i in range(0, 12000 * 2 + 1):
        alltemp.append([])
    def GetAll(a):
        temp = int(math.sqrt(a) + 1)
        for i in range(2, temp):
            curtemp = a
            if (a % i == 0):
                curtemp /= i
                cur = a - curtemp - i + 2
                alltemp[a].append(cur)
                if (cur < 12001 and allret[cur] > a):
                    allret[cur] = a
                for j in range(0, len(alltemp[curtemp])):
                    curret = alltemp[curtemp][j] - 1 + cur
                    alltemp[a].append(curret)
                    if (curret < 12001 and allret[curret] > a):
                        allret[curret] = a

    for i in range(4, 12000 * 2 + 1):
        GetAll(i)
    tempdic = dict()
    ret = 0
    for i in range(2, 12000):
        if (not tempdic.has_key(allret[i])):
            ret += allret[i]
            tempdic[allret[i]] = 1

    print ret

def problem89(a):
    alllist = []
    curfile = open(a)
    if (not curfile):
        return 0
    allline = curfile.read()
    lencur = len(allline)
    temp = re.compile('VIIII|LXXXX|DCCCC|IIII|XXXX|CCCC')
    lencur -= len(temp.sub('KK', allline))
    print lencur

def problem90():
    alllist = []
    temp = ['1'] * 6 + ['0'] * 4
    alllist.append('1111110000')
    while(1):
        bfind = 0
        cursize = 0
        for i in range(0, 9):
            if (temp[i] == '1'):
                if (temp[i + 1] == '0'):
                    bfind = 1
                    temp[i] = '0'
                    temp[i + 1] = '1'
                    for j in range(0, cursize):
                        temp[j] = '1'
                    for j in range(cursize, i):
                        temp[j] = '0'
                    alllist.append(''.join(temp))
                    break
                cursize += 1
        if (not bfind):
            break
    allstr = dict()
    ret = 0
    for i in range(0, len(alllist)):
        for j in range(i + 1, len(alllist)):
            if (alllist[i][0] + alllist[j][1] != '11' and alllist[j][0] + alllist[i][1] != '11') :
                continue
            if (alllist[i][0] + alllist[j][4] != '11' and alllist[j][0] + alllist[i][4] != '11'):
                continue
            if (alllist[i][0] + alllist[j][9] != '11' and alllist[j][0] + alllist[i][9] != '11' and
                alllist[i][0] + alllist[j][6] != '11' and alllist[j][0] + alllist[i][6] != '11'):
                continue
            if (alllist[i][1] + alllist[j][6] != '11' and alllist[j][1] + alllist[i][6] != '11' and
                alllist[i][1] + alllist[j][9] != '11' and alllist[j][1] + alllist[i][9] != '11'):
                continue
            if (alllist[i][2] + alllist[j][5] != '11' and alllist[j][2] + alllist[i][5] != '11'):
                continue
            if (alllist[i][3] + alllist[j][6] != '11' and alllist[j][3] + alllist[i][6] != '11' and
                alllist[i][3] + alllist[j][9] != '11' and alllist[j][3] + alllist[i][9] != '11'):
                continue
            if (alllist[i][4] + alllist[j][9] != '11' and alllist[j][4] + alllist[i][9] != '11' and
                alllist[i][4] + alllist[j][6] != '11' and alllist[j][4] + alllist[i][6] != '11'):
                continue
            if (alllist[i][6] + alllist[j][4] != '11' and alllist[j][6] + alllist[i][4] != '11' and
                alllist[i][9] + alllist[j][4] != '11' and alllist[j][9] + alllist[i][4] != '11'):
                continue
            if (alllist[i][8] + alllist[j][1] != '11' and alllist[j][8] + alllist[i][1] != '11'):
                continue

            temp1 = alllist[i] + '_' + alllist[j]
            temp2 = alllist[j] + '_' + alllist[i]
            if (not allstr.has_key(temp1) and not allstr.has_key(temp2)):
                allstr[temp1] = 1
                allstr[temp2] = 1
                ret += 1
    print ret
problem90()