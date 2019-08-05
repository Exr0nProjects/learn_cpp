import argparse

funcs = {
    "-c": ["--create", "Initalize a template and place it in place for a given problem",
    "finish": "Mark a problem as completed",
    "push": "Push all changes to Git remote"
}

parser = argparse.ArgumentParser(description='File manager')
group = parser.add_mutually_exclusive_group(required=True)

for key in funcs:
    group.add_argument(key, help=funcs[key], required=False)
  
args = parser.parse_args()
