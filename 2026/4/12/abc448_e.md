这个等式成立的核心在于，把被除数 $N$ 用 $M \times P$ 做带余除法展开。下面是具体的推导过程。

设 $N = q \cdot (M \times P) + r$，其中 $q = \left\lfloor \frac{N}{M \times P} \right\rfloor$ 是商，$r = N \bmod (M \times P)$ 是余数，且 $0 \le r < M \times P$。

**先看等式右边：**

$$
\left\lfloor \frac{N \bmod (M \times P)}{M} \right\rfloor = \left\lfloor \frac{r}{M} \right\rfloor
$$

由于 $r < M \times P$，所以 $\frac{r}{M} < P$，因此 $\left\lfloor \frac{r}{M} \right\rfloor$ 是一个在 $0$ 到 $P-1$ 之间的整数。

**再看等式左边：**

$$
\begin{aligned}
\left\lfloor \frac{N}{M} \right\rfloor &= \left\lfloor \frac{q \cdot (M \times P) + r}{M} \right\rfloor \\
&= \left\lfloor q \cdot P + \frac{r}{M} \right\rfloor \\
&= q \cdot P + \left\lfloor \frac{r}{M} \right\rfloor \quad (\text{因为 } qP \text{ 是整数})
\end{aligned}
$$

然后对 $P$ 取模：

$$
\begin{aligned}
\left\lfloor \frac{N}{M} \right\rfloor \bmod P &= \left( q \cdot P + \left\lfloor \frac{r}{M} \right\rfloor \right) \bmod P \\
&= \left\lfloor \frac{r}{M} \right\rfloor \bmod P
\end{aligned}
$$

因为 $0 \le \left\lfloor \frac{r}{M} \right\rfloor < P$，所以 $\left\lfloor \frac{r}{M} \right\rfloor \bmod P = \left\lfloor \frac{r}{M} \right\rfloor$。

至此，左右两边都等于 $\left\lfloor \frac{r}{M} \right\rfloor$，等式得证。
