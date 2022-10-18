# Extended Euclidean Algorithm

Normal Euclidean Algorithm gives us gcd(a, b).

In the extended Euclidean algorithm, we try to find x, y such that

$$
    ax + by = gcd(a, b)
$$

So, we want to develop a recursive relation. Let we know that for the very next step, the unknown variables will be $x1$, $y1$.
if we know the values of $x1$, $y1$, and on the next step, since $ gcd(a, b) == gcd(b, a \mod b) $, therefore,

$$
  b x1 + (a mod b) y1 = gcd(b, a mod b)
$$

We want to find the pair $(x, y)$ for $(a, b)$ such that:
$$
ax + by = g
$$

We can represent $a \mod b$ as,

$$
    a \mod b = a - \lfloor {a \over b} \rfloor b
$$

S, we can write

$$
    g = b.x1 + (a mod b).y1 = b.x1 + (a - \lfloor {a \over b} \rfloor b).y1 \\

      = b.x1 + a.y1 - \lfloor {a \over b} \rfloor b.y1 \\
      = a.y1 + b.(x1 - \lfloor {a \over b} \rfloor .y1) \\
$$

Therefore $x = y1$, and $y = x1 - \lfloor {a \over b} \rfloor .y1$.

$$
\therefore  \biggl\{
  {
  x = y1, \\
 y = x1 - \lfloor {a \over b} \rfloor .y1
  }

$$

Based on this, write a recursive function.
