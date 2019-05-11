import heapq as h
from collections import defaultdict


class Graph:

    def __init__(self):
        self.g = defaultdict(list)

    def add_edge(self, u, v, w):
        self.g[u].append((v, w))
        self.g[v].append((u, w))

    def ucs(self, src, goal):
        li = []

        h.heappush(li, (src, str(src)))

        while True:

            if li[0][1][-1] == str(goal):
                print(li[0][1], li[0][0])
                break

            va, path = h.heappop(li)

            t = int(path[-1])
            for i in range(len(self.g[t])):
                des, weight = self.g[t][i]
                st = path
                st += str(des)
                value, pa = va+weight, st
                h.heappush(li, (value, pa))


print("enter no of egdes")
e = int(input().strip())
g = Graph()
for i in range(e):
    l = tuple(map(int, input().strip().split()))
    g.add_edge(l[0], l[1], l[2])

g.ucs(0, 4)




