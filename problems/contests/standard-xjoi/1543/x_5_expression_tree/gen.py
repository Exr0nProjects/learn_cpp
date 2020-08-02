MAXDEP = 1     # maximum parenthesis depth
MAXNUM = 10     # maximum absolute value of a base number
MAXLEN = 4     # expressions per group
MAXSTACK = 2    # max number of useless parens

from random import randint, choice

def genexp(dep = 0):
    if dep > MAXDEP:
        return str(randint(0, MAXNUM))
    exp = ''
    parens = randint(0, MAXSTACK)
    if parens:
        exp += '('*parens
        if randint(0, 1):
            exp += choice(('-', '+'))

    for _ in range(randint(1, MAXLEN)):
        exp += genexp(dep+1) + choice(('-', '+', '*'))

    exp = exp[:-1]

    if parens:
        exp += ')'*parens
    # if not exp:
        # exp = '2'
    return exp

print(genexp())
