def GCD(a,b):
    if b==0:
        return a
    else:
        return GCD(b,a%b)

t = int(input())
for _ in range(t):
    a,b = map(int,input().split())
    print(GCD(a,b))
