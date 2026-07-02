# 69. Sqrt(x)

## Problem Statement

Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer.

The returned integer should also be non-negative.

**Note:**
- You must not use any built-in exponent function or operator.
- Do **not** use `pow(x, 0.5)` or `x ** 0.5`.

### Examples

#### Example 1

```
Input: x = 4
Output: 2
```

**Explanation**

The square root of `4` is `2`.

---

#### Example 2

```
Input: x = 8
Output: 2
```

**Explanation**

The square root of `8` is `2.828...`, and the floor value is `2`.

---

### Constraints

```
0 <= x <= 2^31 - 1
```

---

# Approach

Since we need to find the largest integer whose square is less than or equal to `x`, we can use **Binary Search**.

### Why Binary Search?

The square of numbers increases monotonically:

```
0² < 1² < 2² < 3² < ...
```

This sorted nature allows us to eliminate half of the search space in every iteration.

### Steps

1. Handle edge cases (`x = 0` or `x = 1`).
2. Initialize:
   - `low = 1`
   - `high = x`
3. Find the middle element.
4. Instead of checking

   ```
   mid * mid <= x
   ```

   use

   ```
   mid <= x / mid
   ```

   to avoid integer overflow.

5. If the condition is true:
   - Store `mid` as the current answer.
   - Search in the right half for a larger valid answer.

6. Otherwise:
   - Search in the left half.

7. Return the stored answer.

---

# Dry Run

### Input

```
x = 8
```

**Output**

```
2
```

---

# Complexity Analysis

### Time Complexity

```
O(log x)
```

Binary Search halves the search space in every iteration.

### Space Complexity

```
O(1)
```

No extra space is used.

---


class Solution {
    public :
int mySqrt(int x) {

        if (x == 0 || x == 1)
            return x;

        int low = 1;
        int high = x;
        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Prevent integer overflow
            if (mid <= x / mid) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
}
```

---

# Key Observations

- The square function is **monotonically increasing**, making Binary Search applicable.
- Using

```java
mid <= x / mid
```

instead of

```java
mid * mid <= x
```

prevents integer overflow.
- The algorithm returns the **floor** of the square root.

---

# Interview Tips

- Mention why Binary Search works:
  - The search space is sorted based on square values.
  - We are looking for the maximum integer satisfying `mid² <= x`.

- Explain overflow handling:
  - `mid * mid` can exceed the `int` limit.
  - `mid <= x / mid` safely performs the same comparison.

- Alternative approaches:
  - Linear Search → **O(√x)** (less efficient)
  - Binary Search → **O(log x)** (optimal)
  - Newton's Method → Faster convergence but more mathematical.
