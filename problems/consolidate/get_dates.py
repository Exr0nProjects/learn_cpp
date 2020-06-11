INPUT_FILE = 'out.txt'
OUTPUT_FILE = 'dates.txt'
DIRECTORY = '..'

from os.path import join

with open(INPUT_FILE, 'r') as inp, open(OUTPUT_FILE, 'w+') as oup:
    for path in inp:
        path = path.split(':')[0]
        # print(f'processing {path}...', end='\r')

        with open(join(DIRECTORY, path), 'r') as code:
            for line in code:
                if "Create" in line:
                    toks = line.strip().split(' ')
                    final = ','.join((' '.join(toks[-6:-3]), ' '.join(toks[-2:]))) + ','
                    oup.write(final + '\n')
                    print(final)
                    break

