# Sparse table, RMQ, LCA

## RMQ = Ranged Minimum Query
given a1, al+1, ... ..., an
Q = [L, R]
min(al, al+1, ..., ar) = ?

What are our options to find RMQ?
* Segment tree   => build complexity O(N), query O(lg N)
* BIT? not exactly...
* SQRT decomposition => init O(N), O(sqrtN) 

    a1, a2, a3   a4,a5,a6   a7,a8,a9
min     m1         m2          m3      <-- O(N)

Q[2, 8] = min( forLoop (a2, a3) , blockMin, forLoop(a7, a8) ) 
           O( lte sqrtN )     O( sqrtN )     O( lte sqrtN )



* Sparse table: init O(N lg N), query O(1)

What happens in a segment tree?
      1 2 3 4 5 6 7 8               <-- Root
   1 2 3 4            5 6 7 8 
1 2     [3 4]        [5 6]      7 8
1   [2]   3   4    5   6    [7]    8     


We divide the input into small blocks, and make a recursive call. 

In this case, Q[2,7]  = min( [2] , [3, 4] , [5, 6] , [7] )

Now let's try to derive the intuition for the sparse tree.


  1   2   3   4   5   6   7   8

  Q[2, 6] = ?

  Len[2, 6] = 6 - 2 + 1 = 5

  len[2, 6] = 5 = 101 = 2^2 + 2^0  ~ lg (N) = lg(5) etogulo space lagte pare
                      =  4  + 1  , We'll divide the query ranges into these sizes

7 = 111 = 2^2 + 2^1 + 2^0 ~ lg(7)
        = 4  + 2 + 1   ,  We'll divide the query ranges into these sizes


Preprocess:
  1, 2, 3, 4, ... , 7, 8                                           1 length   ---> 8
  [1,2], [2,3], [3,4], ... [6,7], [7,8]                            2 length   ---> 7
  [1,2,3,4], [2,3,4,5], [3,4,5,6], [4,5,6,7], [5,6,7,8]            4 length   ---> 5
  [1,2,3,4,5,6,7,8]                                                8 length   ---> 1
                                                                     total         21 we'll preprocess these 21 blocks.

2^0, 2^1, ..., 2^lgN

total segments = O(N lg N)


let K = lgN

ST[K][N]

ST[i][j] = segment of length 2^i, that starts from j

**Calculate ST[i][j] using dynamic programming**

Let, we know ST[i-1][0], ... ST[i-1][N-1].

What does ST[i][j] look like?

a_j ... ... ...a_( j + (2^i) - 1 )   a_j + 2^i

len = 2( j + (2^i) - 1 ) - j + 1 = 2^i
so if we divide it into 2, we get:
leftEnd = j + (2^i) / 2 = j + 2^(i-1), and rightStart = j + 2^(i-1) + 1

ST[2][0] = ?

a0 a1 a2 a3  a4
-----------
  2^2, a_3 = a_(0 + (2^2)-1)



a0   a1    a2    a3
-------------------   segment length 2^i
a0   a1    a2    a3
-------    --------   each segment length = 2^(i-1)

s[i][j] = s[i-1][j] + s[i-1][j + 2^(i-1) + 1]

to be continued from 56:23 min...


