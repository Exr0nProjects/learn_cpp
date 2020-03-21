# DP Framing 

| Problem | Structure | Frame | Equation |
|---------|-------|-----------|----------|
Number Triangle | Graph | `dp[r][c]` = Best score going down from `(r, c)` | `dp[r][c] = min(dp[r+1][c], dp[r+1][c+1])`
0/1 Knapsack | 2d Linear | `dp[i][j]` = Most value obtainable from first `i` items and having atleast `j` capacity remaining in the knapsack | `dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])`
DP1 (UVa 10003) | 2b Tree | `dp[l][r]` = Minimum cost to cut the segment from cut `l` to `r` | `dp[l][r] = pos[r]-pos[l] + min({dp[l][k] + dp[k][r] : l < k < r})`
DP9 (UVa 11584) Subproblem | 2d Linear | `dp[l][r]` = Whether the range from `l` to `r` is a palendrome | `dp[l][r] = dp[l-1][r-1] && str[l] == str[r]`
DP9 (UVa 11584) | 1d Linear | `dp[i]` = Mininmum number of partitions to palendromify from `str[0]` to `str[i]` | `dp[i] = min({dp[j]+1 : 0 <= j < i if is_palendrome[j][i]})`
DP21 (UVa 10285) | 1d Linear | `dp[(r, c)]` = Longest decreasing sequence starting from `(r, c)` | `dp[r][c] = max({dp[(r', c')] : (r', c') is a neighbor of (r, c) if height[(r', c')] < height[(r, c)]})`
DP22* (UVa 10118) | 4d  Linear | `dp[i, j, k, l]` = Most candies obtainable using the bottom `i` candies from the first pile, `j` from the second, etc. | `dp[i, j, k, l] = max(dp[i+1, j, k, l] + whether candy of color pile1[i] was already in the basket, same for j, etc)`
DP23 (UVa 1629) | 2b Tree in 2d Decision Space | `dp[i, j, k, l]` = Minimum cost to cut cake bounded by `i <= x < k` and `j <= y < l` | `dp[i, j, k, l] = min({topCost + bottomCost + width : j < y < l if both sides have atleast one cherry} U {leftCost + rightCost + height : i < x < k if both sides have atleast one cherry})`
DP24 (UVa 1630) | 2b Tree | `dp[string]` = Minimum cost to fold `string` | `dp[string] = min({dp[string[:k]] + dp[string[k:]] : 0 < k < k.length-1}) if string is unfoldable **or** "${fold_count}(${dp[string[:prefix]]})"`
DP25 (UVa 242) | 1d Linear | `dp[i]` = Minimum number of stamps to be worth `i` money | `dp[i] = min(dp[j] + 1 : 0 <= j < i if i-j is a valid denomination of stamp)`

Note on DP22: We store the basket state using a global that is updated through backtracking, which normally wouldn't work (because the basket state wouldn't necessarily be the same for each occurance of the subproblem) except that the basket state is already encoded in the frame the problem: the candies that have been through the basket can be determined by which candies have been taken, which is can be determined by how many candies have been taken from each pile. 
