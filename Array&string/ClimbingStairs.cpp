# 🪜 LeetCode 70 - Climbing Stairs

> **Difficulty:** Easy  
> **Language:** Java  
> **Topic(s):** Dynamic Programming, Recursion, Fibonacci

---

## 📖 Problem Statement

You are climbing a staircase. It takes **n** steps to reach the top.

Each time you can either:

- Climb **1 step**, or
- Climb **2 steps**

Return the total number of **distinct ways** to reach the top.

### Example 1

```text
Input: n = 2

Output: 2

Explanation:
1. 1 + 1
2. 2
```

### Example 2

```text
Input: n = 3

Output: 3

Explanation:
1. 1 + 1 + 1
2. 1 + 2
3. 2 + 1
```

---

## 💡 Intuition

To reach the **nth** stair, there are only two possible ways:

- Come from **(n-1)th** stair by taking **1 step**
- Come from **(n-2)th** stair by taking **2 steps**

Therefore,

```
Ways(n) = Ways(n-1) + Ways(n-2)
```

This is exactly the **Fibonacci recurrence**, making it a Dynamic Programming problem.

---

## 🧠 Approach

1. Handle the base cases:
   - `n = 1 → 1 way`
   - `n = 2 → 2 ways`
2. Store only the previous two answers.
3. Iterate from `3` to `n`.
4. Compute the current number of ways.
5. Update the previous values.


class Solution {

    int climbStairs(int n) {

        if (n <= 2)
            return n;

        int first = 1;
        int second = 2;

        for (int i = 3; i <= n; i++) {

            int current = first + second;

            first = second;
            second = current;
        }

        return second;
    }
}
```

---

## 🔍 Dry Run

### Input

```
n = 5
```

| Iteration | first | second | current |
|-----------|------:|-------:|--------:|
| Initial | 1 | 2 | - |
| i = 3 | 2 | 3 | 3 |
| i = 4 | 3 | 5 | 5 |
| i = 5 | 5 | 8 | 8 |

**Output**

```
8
```

---

## 🌳 Recurrence Relation

```
Ways(n)
   │
   ├── Ways(n-1)
   │
   └── Ways(n-2)
```

Hence,

```
Ways(n) = Ways(n-1) + Ways(n-2)
```

---

## ⏱️ Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(1)** |




---

⭐ If you found this solution helpful, consider giving the repository a star!
