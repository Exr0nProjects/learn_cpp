import subprocess as sub
from colorama import Fore, Style
import argparse

COMPILE_ARGS="-std=c++11"
PREFIX="main_"


def main(args: argparse.Namespace):
    def getLast():
        ret = ""
        with open("../.template_state/last.txt", "r") as rf:
            ret = rf.read()
        return ret.strip()

    path = args.path or getLast()
    name = PREFIX + path.split('/')[-1]
    path += "/" + name + ".cpp"

    def compile(path, out=None):
        out = out or path.split('/')[-1][:-4]
        res = sub.run(f'g++ {COMPILE_ARGS} ../{path} -o {name}', shell=True)
        if (res.returncode == 0):
            print(f'{Fore.GREEN}{Style.BRIGHT}Compiled {path} to {name}.{Style.RESET_ALL}')
        else:
            print(f'{Fore.RED}{Style.BRIGHT}Compilation of {path} failed! Exiting...{Style.RESET_ALL}')
            raise SystemExit(1)
        return out

    # compile the file to this directory
    compile(path, name)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Python tool to run test cases.')
    parser.add_argument('path', metavar='file', type=str, nargs='?',
            help="The path of the folder containing the main_.cpp file. Defaults to the value stored in .template_state/last.txt.")

    main(parser.parse_args())
