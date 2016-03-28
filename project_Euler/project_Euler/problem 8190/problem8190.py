# -*- coding: UTF-8 -*-
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
problem82('p082_matrix.txt')