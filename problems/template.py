import argparse

funcs = {
    "create": "Initalize a template and place it in place for a given problem",
    "finish": "Mark a problem as completed",
    "push": "Push all changes to Git remote"
}

parser = argparse.ArgumentParser(description='File manager')
for key in funcs:
    parser.add_argument(key, help=funcs[key])
    
args = parser.parse_args()