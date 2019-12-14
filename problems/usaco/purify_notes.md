# Notes for writing pure code

## Storage

### Pointers

- Avoid.

### Arrays

- Use globals!
  - Globals get more space in the stack
  - Globals are accessible from anywhere, as long as your project isn't too big
- Prefer vectors over dynamicly allocated arrays

### Graphs

- EdgeList is fast but easy to break
  - Use only if comfortable!

## Input

- `scanf`
  - Fast but make sure to pass in memory positions! (`scanf("%d", &x);` not `scanf("%d", x)`)

## Sources

**Good repositories of code**

- [Arup Guha](http://www.cs.ucf.edu/~dmarino/progcontests/mysols/highschool/usaco/2014/bronze/)
- [GitHub - thecodingwizard](https://github.com/thecodingwizard/competitive-programming)