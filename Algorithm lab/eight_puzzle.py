import copy

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

def eight_puzzle(m1, s, l):
    print(m1)
    if isvalid(m1):
        return True
    t = find_0(m1)
    x, y = convert_1D_2D(t)
    flag = False
    #left
    if is_safe(x, y-1):
        newm = m1[:]
        swap1(newm, x, y-1, x, y)
        if tuple(newm) not in s:
            flag = True
            s.add(tuple(newm))
            l.append(newm)
            if eight_puzzle(newm, s, l):
                return True

    if is_safe(x, y+1):
        newm = m1[:]
        swap1(newm, x, y+1, x, y)
        if tuple(newm) not in s:
            flag = True
            s.add(tuple(newm))
            l.append(newm)
            if eight_puzzle(newm, s, l):
                return True

    if is_safe(x-1, y):
        newm = m1[:]
        swap1(newm, x-1, y, x, y)
        if tuple(newm) not in s:
            flag = True
            s.add(tuple(newm))
            l.append(newm)
            if eight_puzzle(newm, s, l):
                return True

    if is_safe(x+1, y):
        newm = m1[:]
        swap1(newm, x+1, y, x, y)
        if tuple(newm) not in s:
            flag = True
            s.add(tuple(newm))
            l.append(newm)
            if eight_puzzle(newm, s, l):
                return True

    s.remove(tuple(m1))
    l.pop()

s = set()
l = []
a = [1,2,3,4,5,6,7,0,8]
s.add(tuple(a))
l.append(a)
print(eight_puzzle(a, s, l))