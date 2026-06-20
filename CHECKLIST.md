# ✅ PRE-FLIGHT CHECKLIST — Hema Vardhan

> **How this works (your choice): YOU say each check OUT LOUD, Kira confirms or catches the gap.**
> Kira does NOT run these for you — the whole point is to make them YOUR reflex, so that in an
> interview (alone, no Kira) you catch your own leaks before you submit. Recognition is already
> strong; this drills the **execution** leaks that actually cost you (see the leak scoreboard in
> `COMMAND_CENTER.md`).

---

## 🛫 GATE A — before you write any code
Say these out loud:
1. **Restate** the problem in ONE sentence, in your own words. (Not the title — the actual ask.)
2. **3-element dry run** — make up a tiny input, hand-run what the answer should be.
> *Why:* your reading misses (MISTAKE #10) happen when you skip this under pressure. 30 seconds here saves a wrong solution.

## 🌉 GATE B — IF you reduced this to a problem you already know
*(e.g. "this is just LC560", "this is Koko", "this is divisible-by-k")* — say:
1. Name the reduction: "I'm treating X as Y because ___."
2. **Attack it with a HOSTILE input** — pick an input designed to break it (an element `> p`, a negative, a duplicate, the empty case).
3. **Hand-run BOTH** the original problem AND your reduction on that input. Same answer? ✅ keep it. Different? 🛑 the reduction dropped a constraint — find what.
> *Why:* you've fallen in the reduction trap twice on P19 (dropped the `%p`). This gate is your defense. (MISTAKE #12.)

## 🛬 GATE C — before you say "done" / hit submit
Say each:
1. **Sorted?** → if NOT sorted, is this really two-pointers, or is it **hashing**? (#9)
2. **Container right?** → `set` vs `map`, `int[26]` vs `unordered_map` — does the type match what I store? (today's `unordered_set<int,int>` bug)
3. **The 4 boundary edges:** empty `[]` · size-1 `[x]` · first/last position · the **ANSWER edge** (does "none exists / the whole thing / do-nothing/0" get handled?). *Most of your bugs hide in the ANSWER edge.*
4. **Magnitude / overflow:** any `+`, `*`, or accumulator that exceeds `int` (~2.1e9)? Is every **seed type** right (`0LL` not `0`)? `mid = lo+(hi-lo)/2`? (#8)
5. **Stress test it** (below) — let the brute oracle catch what you missed.

---

## 🪣 THE 3-BUCKET EDGE FRAMEWORK  *(boss's reference — the source of Gate C's edges)*
> Before submit, interrogate the input from **three angles**. Every bug hides in one of these.
> The drill: walk all three OUT LOUD and ask *"does my code survive each one?"* Not every problem
> hits every bucket — a bucket being **empty is a valid check**, not a quota to fill.

**1. 🔲 SHAPE — the *structure*, ignoring the values.** *"What's the smallest/weirdest shape this input can take?"*
- Array: empty `[]` · size-1 `[x]` · size-n
- String: `""` · length-1 · all-same-char
- Matrix: `0×0` · `1×n` row · `n×1` col · square
- Linked list: empty · single node · **has a cycle**
- Tree: empty · single node · skewed vs balanced

**2. 🔢 VALUE — the *contents*.** *"What nasty values could be inside?"*
- Duplicates · negatives · zero
- Huge numbers → **overflow** (leak #8 lives here — check `int` ~2.1e9, seed types `0LL`)

**3. 🎯 ANSWER — the *output* extremes.**  ← **boss's #1 blind spot. Logic-right, answer-edge-wrong.**
- The answer is **"none exists"** (return -1 / 0 / empty)
- The answer is **"the whole thing"** (use the entire input)
- The answer is **"do nothing"** (input already satisfies the goal → return it untouched)
> *Proof it's your leak:* every P19 hole was an ANSWER edge ("whole array can't be removed", "S%p==0 → 0").
> And on P20 the empty-array SHAPE edge **collided** with your "no run → return 1" ANSWER rule
> (empty must return 0). SHAPE finds the case; ANSWER tells you the value. Run both.

---

## 🧪 STRESS-TEST HARNESS (standing rule — fill `main()` on every coded problem)
The **brute is the oracle** (correct-by-construction). Generate random tiny inputs, run brute vs
optimal, `assert` they match, loop thousands of times. The first disagreement is a bug — usually
an edge case you'd never have hand-written. *(This is the real reason we write brute first.)*

```cpp
// ---- stress test: brute (oracle) vs optimal ----
#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(12345);                          // fixed seed = reproducible failures
    for (int t = 0; t < 100000; t++) {
        int n = rand() % 6 + 1;            // tiny n so brute is cheap & bugs are easy to read
        vector<int> a(n);
        for (int& x : a) x = rand() % 11 - 2;   // include negatives & zeros; widen if needed
        int p = rand() % 7 + 1;            // any extra param the problem needs

        Solution s1, s2;
        auto got  = s1.optimalFn(a, p);    // <-- your optimal
        auto want = s2.bruteFn(a, p);      // <-- the brute oracle (vectors copy-safe per call)
        if (got != want) {
            cout << "MISMATCH  got=" << got << " want=" << want << "  input: ";
            for (int x : a) cout << x << ' ';
            cout << " | p=" << p << "\n";
            return 1;                       // stop at the first failing case
        }
    }
    cout << "all tests passed\n";
    return 0;
}
```
**Tuning:** keep `n` small (≤6–8) — bugs surface on tiny inputs and are readable. Make the value
range include the nasty stuff (negatives, zeros, duplicates, values `> p`). If brute mutates its
input, pass a copy. Run via `./run.sh <path>`.

---

## 📝 After any bug: the "which gate would've caught this?" line
When a bug appears, name the gate that *would* have caught it (A/B/C/stress). One line. This is
how the ritual earns trust — and it feeds the leak scoreboard in `COMMAND_CENTER.md`.
