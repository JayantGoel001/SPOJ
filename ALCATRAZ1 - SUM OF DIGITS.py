t = int(input())
while t:
    n = int(input())
    sum = 0
    while n!=0:
        sum += n%10
        n//=10
    print(sum)
    t-=1
