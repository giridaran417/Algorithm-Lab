import sys
import random as ran


def isvalid(M1):
    if M1 == [1, 2, 3, 4, 5, 6, 7, 8, 0]:
        return True
    return False


def is_safe(x, y):
    if x < 3 and x >= 0 and y < 3 and  y >= 0:
        return True
    return False


def find_0(m1):
    for i in range(9):
        if m1[i] == 0:
            return i
    return -1


def convert_2D_1D(x, y):
    a = x*3 + y
    return a


def convert_1D_2D(x):
    return x//3, x%3


def swap1(m1, i, j, r, c):
    p1 = convert_2D_1D(i, j)
    p2 = convert_2D_1D(r, c)
    t = m1[p1]
    m1[p1] = m1[p2]
    m1[p2] = t


def left(m1, s, l, a, x, y):
    if is_safe(x, y-1):
        newm = m1[:]
        swap1(newm, x, y-1, x, y)
        if tuple(newm) not in s:
            flag = True
            s.add(tuple(newm))
            l.append(newm)
            if eight_puzzle(newm, s, l, a+1):
                return True

    return False

def right(m1, s, l, a, x, y):
    if is_safe(x, y+1) :
        newm = m1[:]
        swap1(newm, x, y+1, x, y)
        if tuple(newm) not in s:
            flag = True
            s.add(tuple(newm))
            l.append(newm)
            if eight_puzzle(newm, s, l, a+1):
                return True
    return False

def up(m1, s, l, a, x, y):
    if is_safe(x-1, y):
        newm = m1[:]
        swap1(newm, x-1, y, x, y)
        if tuple(newm) not in s:
            flag = True
            s.add(tuple(newm))
            l.append(newm)
            if eight_puzzle(newm, s, l, a+1):
                return True
    return False

def down(m1, s, l, a, x, y):
    if is_safe(x+1, y) :
        newm = m1[:]
        swap1(newm, x+1, y, x, y)
        if tuple(newm) not in s:
            flag = True
            s.add(tuple(newm))
            l.append(newm)
            if eight_puzzle(newm, s, l, a+1):
                return True
    return False


def randfun():
    s = set()
    r = ran.randint(0, 3)
    c = 0
    l = []
    while c != 4:
        while r in s:
            r = ran.randint(0, 3)
        l.append(r)
        s.add(r)
        c += 1

    return l



def eight_puzzle(m1, s, l, a):
    #print(m1)
    if isvalid(m1):
        return True
    if a > 50:
        return False
    t = find_0(m1)
    x, y = convert_1D_2D(t)

    l1 = randfun()
    i = 0
    while i != 4:
        if fun[l1[i]](m1, s, l, a, x, y):
            return True
        i += 1


    s.remove(tuple(m1))
    l.pop()

s = set()
l = []
fun = [left, right, up, down]
a = list(map(int, input().split()))
a1 = a[:]
sys.setrecursionlimit(100000)
s.add(tuple(a))
l.append(a)
while  eight_puzzle(a[:], s, l, 0) == False:
    s.clear()
    l.clear()
    s.add(a[:])
    l.append(a[:])
    eight_puzzle(a[:], s, l, 0)
i = 0
for x in l:
    i += 1
    print(x)

print(i)