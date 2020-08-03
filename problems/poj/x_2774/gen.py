from random import choice
import string

MX = 1000
for i in range(2):
    print(''.join(choice(list(string.ascii_lowercase)) for i in range(MX)))

