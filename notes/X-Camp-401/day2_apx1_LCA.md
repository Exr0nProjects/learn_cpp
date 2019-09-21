# Notes

## LCA (Lowest Common Ancestor)

### What

LCA is an algorithm that finds the lowest common ancestor of two nodes in a binary tree. According to Wikipedia, it is used in the context of distributed systems, somehow?

### How

LCA traverses a binary tree once, so the time complexity is `O(d)`. At each node, it tests to see if the target decendants that we are looking for the LCA of are in the right, left, or both branches. If they are in both branches, then the current node must be the LCA because no lower nodes can be the ancestor of both target decendants. Otherwise, go to whichever side both decendants are on and repeat. 

LCA is a recursive algorithm
