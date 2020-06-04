# DP Framing

## Quick Tips

- To slow?
    - Reframe the problem
        - Can some dimensions be combined?
        - Can some dimensions be removed?
            - Maybe store part of the state as backtracking data
                - Make sure the backtracking storage is fully represented by the problem frame!
        - Can some dimensions be outsourced?
            - AKA: Can the deliverable be simplified and then modified later? (recombinind algebraic terms)
    - Make less decisions
        - Can you "collapse" the decisions to one end?
            - In range decisions, does order of ranges matter?
- Doesn't work?
    - Add dimensions
        - What would make the decision easier?
    - Add stages
        - Can you run a seperate dp which populates a table to help the larger one?

## Complexity and Limits
If running out of time (TLE):

- Frame the problem better? (less dimensions, smaller dimensions, outsource things)

If running out of space (MLE):

- Rolling array
    - How many iterations back do you need to look at? One? Two?
    - Swap vectors or arrays around with `std::swap`--It's O(1)
- State compression, pruning

## Frame the problem
- Sometimes states can be combined, such as a range colpasing to one end if order of "splitting" doesn't matter

## Subproblem Structures
**Common ways to frame the problem, organized by topological structure**

- Linear
    - Each subproblem only uses the solution of one smaller subproblem, although multiple may be considered.
    - 1d
        - `dp[i]` usually represents best value up to point `i`
        - `dp[i]` sometimes represents best value "using" point `i`, because more is not always "better" or "eaiser" in some problems
        - A problem using `dp[i][j]` may be considered one dimensional if `dp[i][j+1]` is completely unrelated to `dp[i][j]`, such as when `(i, j)` represents a node in a graph
            - These problems can be thought of as one dimensional `dp[(i, j)]`
        - If the topological structure of the problem (not of the equation) is a tree, then the problem is usually split by subtree.
            - Tree "dp" problems may not have overlapping subproblems, but are considered dp because they have similar solutions - you similarly need to think about subproblem structure and states.
            - Tree dp "sub dp"s usually use the height, weight, diameter, of subtrees.
    - 2d
        - `dp[i][j]` often represents a range in a 1d problem structure.
            - This often occurs when the value of `dp[0][i]` is not easily determinable from `dp[0][0:i]`
            - This also shows up when the problem itself involves segments and arbitrary splitting.
        - `dp[i][j]` can also represent the combinations between two 1d structures
            - For example, in the Longest Common Subsequence problem, where finding the subsequences are treated as two connected but independant problems.
        - `dp[i][j]` can represent two completely unrelated dimensions or constraints
            - eg. Knapsack problem, where both dimensions represent unrelated constraints that are modified using external mappings (arrays for value and weight of each item)
    - Higher Dimensions
        - Number of dimensions needed is usually the number of "independant" choices to optimize over.
- Tree
    - Similar to the linear structure of selecting "cut" locations, except the order of those cuts matters.
        - Where to "cut" is to choose from a range of options (such as indicies) along one dimension to split the problem into subproblems.
        - Where the order of selection matters (selecting indicies 1, 2, 3 is different from selecting 2, 1, 3).
        - Where the solution to a problem uses multiple subproblems, such as one for the left side and one for the right.
    - Because trees often deal with "segments" of the subproblem, they usually involve ranges (`dp[i][j]`)
        - The DP equation needs to select a way to "split" the subproblem, often by chosing `k : i < k < j`
        - The problem may incorporate multiple dimensions of splitting such as by chosing `a: i < a < j || b: k < b < l`, such as in DP23
- Graph
    - DP Equation represents value at each node, and includes a clause for every edge going out of the node, if some condition holds for that edge.
    - Problems with one "obvious" node may be longest path problems, which can be solved in `V+E` with a modified topological sort.
    - Problems with two "obvious" nodes may be shortest path or a variant.
    - Problems that care about all nodes are probably MST.
- Grid Graph
	- A graph DP problem on a multi-dimensional array/grid
	- No loop property is usually satisfied in two ways:
		- Coordinate based
			- For example: can only move to the right, can only move right and down/up
			- DP7
			- Can usually just simulate, taking the maximum of all options
		- External Factor
			- For example: external property `x` must increase/decrease with each step
			- DP21
			- Can usually sort by external factor and then do 1-d DP, or check all neighbors with an if condition
	- Use another array for path reconstruction, storing where you came from at each node
- Sub DP
    - If the dp equation for something is complete except requires knowing some property of the state, then it may be possible to run a "helper" dp to produce that value

## Per Problem
- PS : Problem Structure
    - What is the topological structure of the original problem?
    - What topological structures immedietly come to mind directly from the problem description?
- DC : Decision Complexity
    - How many subproblems are considered in the DP equation?
    - What is the branching factor of the recursive tree?
- SS : Subproblem Structure
    - How many subproblems are incorporated into each problem?
    - How many subproblems does the DP equation select and use?
        - 1: min/max, removing a constant chunk from the problem
        - 2: cutting the problem up
        - n: constant factor selection built into the problem
- SD : State Dimensionality
    - How complex is the state representation?
    - What attributes are needed to frame the problem?
    - How are optimal solutions to subproblems stored?
> **TODO: Linear subproblem structure currently means that the dp equation uses one subproblem in the final expression. A dp equation that uses two subproblems is considered `2b tree`. However, shouldn't both of these be considered constant, where the first has a subproblem dimensionality of `1` and the second of `2`? Linear subproblem structure *should* mean that the dp equation uses a linear complexity of subproblems.**

| Problem | PS | DC | SS | SD | Frame | Equation |
|---------|----|----|----|----|-------|----------|
Number Triangle | Tree-like | Constant | Linear | 2 | `dp[r][c]` = Best score going down from `(r, c)` | `dp[r][c] = min(dp[r+1][c], dp[r+1][c+1])`
0/1 Knapsack | 2d Linear | Constant | Linear | 2 | `dp[i][j]` = Most value obtainable from first `i` items and having atleast `j` capacity remaining in the knapsack | `dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])`
DP1 (UVa 10003) | 1d Linear | Linear | 2b Tree | 2 | `dp[l][r]` = Minimum cost to cut the segment from cut `l` to `r` | `dp[l][r] = pos[r]-pos[l] + min({dp[l][k] + dp[k][r] : l < k < r})`
DP9 (UVa 11584) Subproblem | 1d Linear (range) | Constant | Linear | 2 | `dp[l][r]` = Whether the range from `l` to `r` is a palendrome | `dp[l][r] = dp[l-1][r-1] && str[l] == str[r]`
DP9 (UVa 11584) | 1d Linear | Linear | < | 1 | `dp[i]` = Mininmum number of partitions to palendromify from `str[0]` to `str[i]` | `dp[i] = min({dp[j]+1 : 0 <= j < i if is_palendrome[j][i]})`
DP21 (UVa 10285) | Grid Graph, 1d Linear | Constant | Linear | 1 | `dp[(r, c)]` = Longest decreasing sequence starting from `(r, c)` | `dp[r][c] = max({dp[(r', c')] : (r', c') is a neighbor of (r, c) if height[(r', c')] < height[(r, c)]})`
DP22* (UVa 10118) | 4x Linear | Constant | 1d Linear | 4 | `dp[i, j, k, l]` = Most candies obtainable using the bottom `i` candies from the first pile, `j` from the second, etc. | `dp[i, j, k, l] = max(dp[i+1, j, k, l] + whether candy of color pile1[i] was already in the basket, same for j, etc)`
DP23 (UVa 1629) | 2x 2b Tree | Linear | 2x 2b Tree | 4 | `dp[i, j, k, l]` = Minimum cost to cut cake bounded by `i <= x < k` and `j <= y < l` | `dp[i, j, k, l] = min({topCost + bottomCost + width : j < y < l if both sides have atleast one cherry} U {leftCost + rightCost + height : i < x < k if both sides have atleast one cherry})`
DP24 (UVa 1630) | 1d Linear | Linear | 2b Tree | 1 | `dp[string]` = Minimum cost to fold `string` | `dp[string] = min({dp[string[:k]] + dp[string[k:]] : 0 < k < k.length-1}) if string is unfoldable **or** "${fold_count}(${dp[string[:prefix]]})"`
DP25 (UVa 242) | 1d Linear | Linear | < | 1 | `dp[i]` = Minimum number of stamps to be worth `i` money | `dp[i] = min(dp[j] + 1 : 0 <= j < i if i-j is a valid denomination of stamp)`
Tree Max Points Without Direct Connection | Unbounded Tree | Constant | Unbounded Tree | 1 | `dp[i][0]` = best score in subtree of `i` without picking `i` and `dp[i][1]` = best score with picking `i` | `dp[i][0] = max{dp[k][0], dp[k][1] : k is a child of i}` and `dp[i][1] = max{dp[k][0] : k is a child of i} + 1` (+1 because we are picking `i`)
Tree Diameter* | Unbounded Tree | Linear | < | 1 | First, `height[i]` = the height of the subtree rooted at `i`. Then, `longest[i]` = longest path contained in the subtree rooted at `i` | `height[i] = max{height[k] : k is child of i}` and `longest[i] = max({longest[k] : k is child of i} U {height[l] + height[r] : l,r are children of i && l != r})` (longest[i] = longest of a subtree or sum of height of two subtrees)
Tree Minimum Centroid | Unbounded Tree | Linear | Linear | 1 | `weight[i]` = weight of the subtree rooted at `i`, and `cost[i]` = maximum weight of trees in the forest created by removing `i` | `weight[i] = sum{weight[k] : k is child of i} +1` and `cost[i] = max({weight[k] : k is child of i}, weight[root] - weight[i])` (`weight[root]-weight[i]` is the weight of the tree above the subtree `i`)
DP13 (UVa 12186) percentage to raise | Tree | Linear | x-branch tree | 1 | `dp[i]` = min leaf nodes needed to convince `i` | `dp[i] = (min T%){dp[k] : k ∈ i}`
DP14 (UVa 1220) max unconnected nodes | See "Tree Max Points Without Direct Connection" | < | < | < | < | < |
DP37 (tm 1039) weighted max unconnected nodes | " | < | < | < | < | `dp[i][0]` = same as above; `dp[i][1] = sum{dp[k][0] : k ∈ i} + value[i]` (add value instead of `1`)
g19o1 snakes | 1d Linear | Linear | Linear | 2 | `dp(n,k)` = min sum of net sizes to catch first n groups w/ k changes | `dp(n,k)=min(dp(i,k−1)+(n−i)*max{ai+1,…,am} for i < n)` (`dp(possible previous change location) + (num groups between loc and here)*max{from prev change loc to here}`)
g18d3 teamwork | Linear | < | < | < | `dp[i]` = Best score up to cow `i` | `dp[i] = max{dp[i-k] + k*(max skill[i-k, k]) for 0 < k <= i}` (previous split at `i-k`)
g14d2 feast | Linear | Constant | Linear | 1 | `dp[i]` = Maximum fullness less than `i` without drinking water | `dp[i] = max{dp[i-1], dp[i-A]+A, dp[i-B]+B}`, then the answer is a sweep over that incorporating water drinking: `value of drinking at k = dp[k]/2`(just after drinking)`+ dp[T-dp[k]/2]`(grand total after eating more fruit)
g16o oj248 | Linear | < | < | 2 | `dp[i][j]` = Max score after entirely collasping the range from `i` through `j` | `dp[i][j] = max{dp[i][k] + 1 for i <= k < j if dp[i][k] == dp[k+1][j]}`
DP36 tm1018 (tree) | Tree | Linear | < | 2 | `dp[i][k]` = Maximum retainable apples in subtree `i` keeping `k` branches (just node `i` counts as one branch) | `dp[i][k] = max{dp[i*2][s] + dp[i*2+1][k-s-1] : 0 <= s < k} +apples[i/2][i]` (`+apples[...]` is the number of apples on the branch holding this subtree.
DP2 oj10029 (longest path) | Graph | Linear | < | < (map of strings) | `dp[str]` = longest path from str | `dp[str] = max{dp[prev] : prev is an edit step of str}`, calculated during the input because input is lexographically ordered to save N^2 `strcmp`s
DP3 oj1025 (abstract shortest path) | Linear | Constant | Linear | 2 | `dp[i][t]` = shortest wait to get to station `i` at time `t` | `dp[i][t] = min{dp[i][t-1], (dp[i-1][t-dist[i][t]] if exists train T : T.start_time = t-dist[0][i] && T.start_position = 0), similarly for the right side}`
DP4 oj347 (abstract longest path) | Graph | Linear | < | 1 | `dp[i]` = tallest tower with block `i` at the top, where a block is a permutation of orientations | `dp[i] = max{dp[j] + height[i] for block[j] is longer and wider than block[i]}`, basically construct the graph on the fly, total N^2
DP7 uva12563 (multi-value knapsack rolling array) | Linear | Constant | Linear | 2 -> 1 | `dp[\_][i]` = Best value with max weight `i` with the first `\_` items (0/1 knapsack with rolling array). `dp` stores an array of pairs, since this problem asks to optimize two values. | `dp[i] = max(dp[i], { dp[i-duration[j] for item j if i >= duration[j] }), for every i`. loop through items on outer, and `i` from high to low (`for (int i=T; i>0; --i)`) because rolling array requires lower `i` to be from previous.
DP6 uva116 | Grid Graph | Constant | Linear | 2 | `dp[i][j]` = min cost to get to row i col j. | `dp[i][j] = min{dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1]}` with modulo.

Note on DP22: We store the basket state using a global that is updated through backtracking, which normally wouldn't work (because the basket state wouldn't necessarily be the same for each occurance of the subproblem) except that the basket state is already encoded in the frame the problem: the candies that have been through the basket can be determined by which candies have been taken, which is can be determined by how many candies have been taken from each pile.

Note on Tree Diameter: Another way to do the tree diameter problem is with two search traversials of the tree. Start with some node `u`, and then find the fartherst node from that node, call it `v`. Then, find the farthest node from `v` and call it `w`. The path from `v` to `w` is maxamal, because the node `v` is a "corner" aka one of the two endpoints. `v` is a corner because were it not a corner, there would be two nodes `a` and `b` that form the diameter and are corners, but because `a` and `b` are closer to `u` than `v` (that's how we found `v`), replacing the farther from `v` of `a` and `b` with `v` would result in a longer path (with the other corner being the one not replaced). Thus, `v` is a corner and `w` is the farthest from a corner, another corner.

