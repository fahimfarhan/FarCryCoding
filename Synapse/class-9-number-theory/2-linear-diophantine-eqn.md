# Linear Diophantine Equation

In extended euclidean algorithm, we learned that for given a, b, we can find x, y such that,

$$
   ax + by = gcd(a,b) = g
$$

Now we try to answer, can we find x, y for given a, b, c such that,

$$
  ax + by = c
$$

## Algorithmic solution

$$
   ax + by = g \\
=> ax/g + by/g = 1 \\
=> axc/g + byc/g = c \\
=> ax_0 + by_0 = c \\

$$

Hence if c is divisible by g, we can find $x_0$, and $y_0$, where

$$
x_0 = xc / g \\
y_0 = yc / g
$$

## Analytical solution

$$
   ax + by = c \\
=> ax \equiv c (\mod b), and \\
   by \equiv c (\mod a)

$$

Assume that b != 0, and consider the first equation. When a and b are coprime, the solution is
$$
   x \equiv ca^{-1} (\mod b)
$$

Where $a^{-1}$ is modular inverse of a modulo b.

If a and b are not coprimes, they have a common divisor g = gcd(a, b). In this case the solution exists iff c\g,
 can be found by reducing the equation to,

$$
   { {a \over g}x} {\equiv}  {c \over g}  ({\mod { {b \over g}}}) \\
=> {x} {\equiv}  ({c \over g}) ( {a \over g} )^{-1}  ({\mod { {b \over g}}}) \\
$$
Therefore, we get,
$$
\therefore x = {x} {\equiv}  ({c \over g}) ( {a \over g} )^{-1}  ({\mod{{b \over g}}}) \\
y = {(c - ax) \over b}
$$

## Degenerate case

if a = b = 0, then we have no solutions if c != 0, or we have infinite solutions if c == 0. These 2 are degenerate cases.

## Finding All solutions

$$
a cx_g/g + b cy_g/g = c \\
=> a cx_g/g + b cy_g/g + ab/g - ab/g = c \\
=> a cx_g/g + ab/g + b cy_g/g - ab/g = c \\
=> a(cx_g/g - b/g) + b(cy_g/g - a/g) = c \\
=> ax_1 + by_1 = c
$$

Where,

$$
   x_1 = cx_g/g - b/g \\
   y_1 = cy_g/g + a/g
$$

Instead of $ab/g$, if we take $k.ab/g$, we get

$$
   x_1 = cx_g/g - kb/g \\
   y_1 = cy_g/g + ka/g
$$

Therefore we have infinitely many solutions. This is the set of all possible solutions.

## Finding all solutions in a given interval

**Note that if a xor b = 0, there is only one solution. We aren't considering that case here.**

Since we have 2 independent variables x, y, we need to consider 2 intervals:

$$
{[x_{min}, x_{max}]},\\
{[y_{min}, y_{max}]}
$$

### Solve for x

1. Find $ x_0 >= x_{min} $
2. Find $ x_n <= x_{max} $
3. let $p = b/g$, then there are $(x_n - x_0) / p + 1$ solutions. We can iterate to find the set $ \{ x_0, x_0 + p, \dots,x_n-p, x_n  \}$.
4. Let the interval be $[x_1, x_2]$

### Solve for y

1. Find $ y_0 >= y_{min} $
2. Find $ y_n <= y_{max} $
3. let $p = b/g$, then there are $(y_n - y_0) / p + 1$ solutions. We can iterate to find the set $ \{ y_0, y_0 + p, \dots,y_n-p, y_n  \}$.
4. Now denote the corresponding x values. Then let the interval be $[x_3, x_4]$

### Find the interval that satisfies both  of the conditions

Simply find the intersection of intervals $[x_1, x_2]$, and $[x_3, x_4]$.

## Find the solution of minimum value of x+y

let the minimum values are $x', y'$ such that $x'+y'$ is minimum. then,
$$
   x' = x_0 - kb/g \\
   y' = y_0 + ka/g
$$
Then
$$
x' + y' = x_0 + y_0 + ka/g- kb/g = x_0 + y_0 + k(a - b)/g
$$

if a == b, then all pairs will give the same smallest sum.
if a > b, then k = 0, -1, -2, ... will gradually decrease the value. so, find the smallest value of k in the given interval.
if a < b, then k = 0, 1, 2, ...  will gradually decrease the value. So find the maximum value of k in the given interval.
