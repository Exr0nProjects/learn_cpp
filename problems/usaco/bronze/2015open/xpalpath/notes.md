# Palpath reflection - 7 Jan 2020

This problem gave me many issues.
From the beginning, I didn't know to use two seperated parts dfs instead of one big one, because there was alot of subproblem overcounting.
Later, my break condition for the two part bfs didn't return properly when the palendrome half it found on the bottom right half wasn't in the top left half, and so it kept going and actually ran extra computations that made it as slow as a full size dfs.
Then, my palendrome string counter didn't take into account where on the diagonal it ended, so it would count strings that would form palendromes if they had connected but instead were just disjointed.
After adding an `int` to the `set` template instantiation to store where the string ended, `unorederd_set` stoped working because there was no hash for `pair<int, string>`.
Finally, I gave up using `unordered_set` because normal `set` was fast enough, and I had to add another set to make sure that I didn't double count palendromes that were the same but intesected the diagonal at different places.

That finally got accepted, as [palpath_5.cpp](./palpath_5.cpp).
