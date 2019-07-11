level 2 page 7 problems

"di4 tui1"

problem 9402 {
  given n stairs and guy can go up at max k stairs at a time, how many ways to get up stairs?
  f(n) = f(n-k)  + f(n-k+1) + ........ + f(n-2) + f(n-1);
  given 5, 2
  {
    1 1 1 1 1
    2-- 1 1 1
    1 2-- 1 1
    1 1 2-- 1
    1 1 1 2--
    2-- 2-- 1
    2-- 1 2--
    1 2-- 2--
  }
}

problem Unknown, circle connecting {
  blog.csdn.net/jayye1994/article/details/37814965
  1 = 1
  2 = 5 = (add to center +1) + (for each prev 1) * (add to edge +2) * (per exposed dot/chain 1) * (rotate 2)
  3 = 16 = (add to center +1) + (for each prev 5) * (add to edge +2) * (rotate 3)

  -- nvm --
  from 2 to 3 outer
  can either connect to the center (+1)
  or connect to an edge point {
    for each "segment" exiting the center (+2) possibilities
  }
  -- nvm --
  for each version of last layer
    add 2x # spokes (ignoring rotations)
    multiply all by new n (rotations)
    add # of things in the last layer (adding to the center)
  from 2 -> 3
  4 + 2*2 *3(rotations)
}
