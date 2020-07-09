def pi(s):
    ret = []
    pre = 0
    for i in range(len(s)):
        if (s[i] == s[pre] and i != 0):
            pre += 1
        else:
            pre = 0
        ret.append(pre)
    return ret

s = input()
print(' '.join(map(lambda x: str(x), pi(s))) + ' ')

