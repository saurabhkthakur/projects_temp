

from cmath import inf
import time

INF = inf


def floyd(G):
    n= len(G)
    m= len(G[0])

    for k in range(4):
        for i in range(n):
            for j in range(m):
                G[i][j] = min(G[i][j], G[i][k] +G[k][j])

    print(G)


if __name__=="__main__":
    G = [[0, 3, INF, 5],
         [2, 0, INF, 4],
         [INF, 1, 0, INF],
         [INF, INF, 2, 0]]

    
    # print(list(map{lambda j:j,i}),G))
    
    distance = list(map(lambda i: list(map(lambda j: j, i)), G))
    print(distance)
    floyd(G)

    start = time.time()
    print(list(map( lambda i: list(map(lambda j : j,i)),G)))
    end = time.time()
    print(start-end)
