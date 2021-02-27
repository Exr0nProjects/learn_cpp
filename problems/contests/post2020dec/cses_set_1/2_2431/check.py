from tqdm import tqdm

with open('test.out', 'r') as rf:
    count = 0
    c = 1
    s = str(c)
    for line in tqdm(rf):
        count += 1
        if len(s) == 0:
            c += 1
            s = str(c)
        if line[0] != s[0]:
            print(count)
            breakpoint()
        s = s[1:]

