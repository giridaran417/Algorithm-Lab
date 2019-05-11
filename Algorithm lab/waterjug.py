def waterjug(x,y, m, n):
    res.append((x,y))
    if (x == 0 and y == d) or (x==d and y==0):
        return True
    if x==0 and (m,y) not in s:
        s.add((m,y))
        return waterjug(m,y,m,n)
    if y==0 and (x,n) not in s:
        s.add((x,n))
        waterjug(x,n,m,n)
    if (0, y) not in s:
        s.add((0,y))
        return  waterjug(0,y, m, n)
    if (x, 0) not in s:
        s.add((x,0))
        return  waterjug(x, 0, m, n)
    if x + y >= n and ((x-(n-y)),n) not in s:
        s.add(((x-(n-y)),n))
        return waterjug(m-(n-y),n,m,n)
    if x + y >= n and ( (m, y-(m-x)) ) not in s:
        s.add((m, y-(m-x)))
        return waterjug(m, y-(m-x),m,n)
    if x + y < n:

        if (0,x+y) not in s:
            s.add((0, x + y))
            return waterjug(0, x+y, m, n)

        if (x+y,0) not in s:
            s.add((x + y, 0))
            return waterjug((x+y,0),m ,n)
    res.remove(res[-1])
    return False



m, n, d = map(int,input().strip().split())
s = set()
s.add((m,n))
res = []
waterjug(m, n, m, n)
print(res)

