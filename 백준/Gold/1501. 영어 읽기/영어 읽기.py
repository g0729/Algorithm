from collections import defaultdict


def word_parser(s):
    start = s[0] + s[-1]
    middle = s[1:-1]
    middle = "".join(sorted(middle))
    return start, middle


one_word = defaultdict(int)
dic = defaultdict(lambda: defaultdict(int))

for _ in range(int(input())):
    s = input()

    if len(s) == 1:
        one_word[s] = 1
        continue

    start, middle = word_parser(s)
    dic[start][middle] += 1

for _ in range(int(input())):
    res = 1
    for word in input().split():

        if len(word) == 1:
            res *= one_word[word]
            continue

        start, middle = word_parser(word)
        res *= dic[start][middle]
    print(res)
