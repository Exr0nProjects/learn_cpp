## Summary for Day 13 (22 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
vjudge.net contest 313134 | A | Contest questions listing | AC | N/A
"" | B | Circle surround radius | AC | N/A
"" | C | Chess rooks and king | WA | Don't know how to do
c1204 | 1 | Euclid GCD | AC | N/A
"" | 2 | Merge Sorted Arrays | AC | N/A
"" | 5 | Number Statistics | WIP | Can do, the number limits were written wrong and actually only need to worry about ints up to 10e7.
"" | 6 | Tree Depth and Width | CE | Not sure why it doesn't work
"" | 7 | Maximize Customer Calls | WA | DP got messed up, test case `1 10 2 4 6 9` doesn't work.
"" | 8 | Hamster Whacking Game | WA | Greedy algorithm doesn't work, should probably use DP.



#### Concepts:
- **Trie**: Multi-level overlapping storage for segment-able types
    A trie is a way of storing data that has "overlapping" sections, such as strings. For example, if we would like to store the words `"these"` and `"there"`, we can store the first three identical characters on the same branch and at the `'e'` node we would branch off into the other characters. Each node can be represented with a struct such as the following:
    ```c ++
    const int ALPHABETSIZE = 26;

    struct TrieNode
    {
      TrieNode children[ALPHABETSIZE];
      bool isLeaf = false; // is this letter the end of a word?
    }
    ```
    In this way, we can search the tree in `O(L)` time where `L` is the length of the word. This is significantly faster than a structure such as a Self Balancing BST, where `search`, `insert`, and `delete` are usually `O(L log n)`. They are also often faster than hashing, because while they have the same time complexity, there is no need to compute a hash function or worry about collisions.
    Additionally, tries are good for printing the words in alphabetical order because everything is stored in that kind of logical way. They are also good for prefix search, because the structure is put together in a way that highlights words that start the same way.

    However, tries take up a lot of storage, because each node must be able to point to `ALPHABETSIZE` children nodes. In these situations, we should prefer to use other data structures such as a Ternary Search Tree, which supports similar operations but is slightly slower than a trie.

    A summary of the pros and cons of the trie:
    | Pros | Cons |
    |------|------|
    - O(L) for insert, search, and delete | - Takes up massive amounts of  memory
    - Easy alphabetical access | -
    - Easy prefix search | -

    More resources on tries: { [Geeks for Geeks](https://www.geeksforgeeks.org/advantages-trie-data-structure/), [Boston University CS](https://www.cs.bu.edu/teaching/c/tree/trie/) }

#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 9

There was no lecture today, we just did a bunch of contest problems. I think I am too slow at debugging still so I need to spend some time grinding earlier pages. I should get more familiar with C++ syntax and practice debugging more simple structures so that I can more efficiently do problems that require more thinking and a deeper understanding of the underlying algorithms.
