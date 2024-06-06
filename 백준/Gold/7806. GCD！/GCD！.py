from math import sqrt


MAX = int(sqrt(1000000000))
isPrime = [True] * (MAX + 1)

isPrime[0] = isPrime[1] = False


for i in range(2, int(sqrt(MAX)) + 1):
    if isPrime[i]:
        for j in range(i * i, MAX + 1, i):
            isPrime[j] = False

primes = []
for i in range(MAX + 1):
    if isPrime[i]:
        primes.append(i)


while True:
    try:
        n, k = map(int, input().split())
        v = []
        for prime in primes:
            if k == 1:
                break
            if k % prime == 0:
                cnt = 0
                while k % prime == 0:
                    cnt += 1
                    k //= prime
                v.append([prime, cnt])

        if k != 1:
            v.append([k, 1])

        answer = 1
        for num, cnt in v:
            _num = num
            total_cnt = 0
            while _num <= n:
                total_cnt += n // _num
                _num *= num
            answer *= num ** (min(total_cnt, cnt))

        print(answer)
    except:
        break
