config = {
  "script1": "main_balancing.cpp",
  "script2": "bash_balancing.cpp",
  "infile": "balancing.in",
  "outfile": "balancing.out"
}

def generateTestCase(writeFile):
  wf = writeFile;
  import random;
  N = random.randint(3, 10);
  wf.write(f'{N} 1000\n')
  for i in range(N):
    wf.write(f'{random.randint(1, 500)*2+1} {random.randint(1, 500)*2+1}\n')
  
  return;

def compile(path):
  import os
  os.system("clear && g++ " + path + " -o " + path[:-4])

compile(config['script1'])
compile(config['script2'])

import os
for i in range(1000):
  with open(config['infile'], 'w+') as wf:
    generateTestCase(wf);
  
  out1 = None
  out2 = None
  
  os.system('./' + config['script1'][:-4])
  with open(config['outfile'], 'r') as rf:
    out1 = rf.read()
    
  os.system('./'+config['script2'][:-4])
  with open(config['outfile'], 'r') as rf:
    out2 = rf.read()
  
  if (out1 != out2):
    print("This test case didn't match!")
    print("> " + out1)
    print("> " + out2)
    input("Press enter to continue testing...")
  
  os.system('clear')
