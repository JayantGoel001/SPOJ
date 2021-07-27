primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103]

t = 20
while t:
    n = int(input())

    prod = 1
    for prime in primes:
        if prod * prime<=n:
            prod = prod * prime
        else:
            break
    print(prod)
    t-=1