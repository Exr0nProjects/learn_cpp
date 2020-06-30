Method: PSTs that store the prefix sum of frequency from root to each node. (N log N space)

find LCA in log N with bei zeng (rmq) or constant time rmq: sparse table of dfs order of nodes, value = depth of that node.

basically, for each tree take dfs order (add pre, in, and post order) into the sparse table (2\*N elements). sparse table stores depth of each node. query minimum between two elemnts as indicies, will be the lca because the dfs order between each pair of nodes contains the LCA, and that lca must be the highest (lowest depth) node between.

