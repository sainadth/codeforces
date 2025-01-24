import math

te = int(input())
def solve():
    l, r = [int(i) for i in input().split()]
    res = 0
    while(r >= l):
        cur = int(math.log(r)/math.log(3)) + 1
        if(r == l):
            res += cur
        res += cur
        r /= 3
    print(res)
for _ in range(te):
    solve()