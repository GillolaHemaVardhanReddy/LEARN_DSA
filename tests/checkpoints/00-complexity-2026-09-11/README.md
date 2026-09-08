# Checkpoint · 00 complexity · Fri 2026-09-11 (M#13 repair)

**Rule:** for each algorithm below, state time AND space **as a sentence with the work in it**, then name
**which line produces each factor**. "O(n log n)" with no line behind it is a ❌. Per-item cost × number of
items = total. Pass = **6/6 with the line named** (and this is checkpoint 1 of the "3 consecutive" rule
that unfreezes 00). No hints; a statement clarification is allowed and not scored. No answer key here.

1. `for i in 0..n-1: for j in i+1..n-1: if a[i]+a[j]==t: return true` — and the same loop with `break` on the first `a[j] > t`.
2. `sort(a); for each of q queries x: binary_search(a, x)` — give the bound in terms of n and q; what if q = n²?
3. `f(n): if n<=1 return; f(n/2); f(n/2); for i in 0..n-1: work()` — count the work per level of the call tree, then the levels.
4. `while (x > 0) { x = x / 2; steps++; }` — in terms of the *value* x, then in terms of its number of bits.
5. `for each element: if (seen.count(a[i]-t)) ans++; seen.insert(a[i])` — time AND the size of `seen` (the space factor).
6. `for each element: while (!st.empty() && a[st.top()] < a[i]) st.pop(); st.push(i)` — why is it not O(n²)? name what each element does at most once.

**Bonus (not scored):** the recursion `g(n) = g(n-1) + g(n-2)` without memo — how many calls, roughly, and which line makes it explode?
