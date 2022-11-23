# Stars and Bars Theorem

## Problem

Given $K$ variables, $a_1, a_2, ..., a_k$, and a value N, how many ways
can we write $a_1 + a_2 + ... + a_k = N$ where $a_i$ is non-negative integer?

If K = 3, N = 2, there are 6 solutions.

```text
a b c
-----
2 0 0
0 2 0
0 0 2
1 1 0
1 0 1
0 1 1

```

## Solution

Let's visualize using stars, and bars.

```text
a  b  c
--------
**|  |
  |**| 
  |  |**
* |* |
* |  |*
  |* |*

```

This visualization paves the way to soln. There are K partitions (hence K - 1 bars), 
and N stars.

So, we can imagine (N + (K - 1)) blanks (in this case, 2 +  3 - 1 = 4 blanks)

```text
- - - - 4 Blanks
```

Remember from theories related to permutation, $n$ distinct objects can be permuted into $n$ blanks in $nPn = n!$ ways. 
If $p$ of them are same, the parmutation = $n!/p!$.

In this case, n = N + K - 1, N stars 
