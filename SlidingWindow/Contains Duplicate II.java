# 219. Contains Duplicate II

## Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if there are two distinct indices `i` and `j` in the array such that:

- `nums[i] == nums[j]`
- `abs(i - j) <= k`

Otherwise, return `false`.

### Examples

**Example 1**

```text
Input: nums = [1,2,3,1], k = 3
Output: true
```

**Example 2**

```text
Input: nums = [1,0,1,1], k = 1
Output: true
```

**Example 3**

```text
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

---

## Approach

We use a **HashMap** to store each element along with its most recent index.

### Algorithm

1. Create a `HashMap<Integer, Integer>`.
2. Traverse the array.
3. If the current element already exists in the map:
   - Calculate the distance between the current index and the previous index.
   - If the distance is less than or equal to `k`, return `true`.
4. Update the current element's latest index in the map.
5. If no such pair is found, return `false`.

---

## Dry Run

**Input**

```text
nums = [1,2,3,1]
k = 3
```

| Index | Value | HashMap | Result |
|-------:|------:|---------|--------|
|0|1|{1=0}|Store index|
|1|2|{1=0,2=1}|Store index|
|2|3|{1=0,2=1,3=2}|Store index|
|3|1|Previous index = 0|3-0 = 3 ≤ 3 → Return true|

---

## Java Solution

```java
import java.util.HashMap;

class Solution {

    public boolean containsNearbyDuplicate(int[] nums, int k) {

        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {

            if (map.containsKey(nums[i])) {

                if (i - map.get(nums[i]) <= k) {
                    return true;
                }
            }

            map.put(nums[i], i);
        }

        return false;
    }
}
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## Why HashMap?

- Provides **O(1)** average-time lookup.
- Stores the latest occurrence of each element.
- Makes it easy to calculate the index difference.

---

## Edge Cases

- `k = 0` → Always returns `false` unless duplicate exists at the same index (which is impossible).
- Array with all unique elements.
- Duplicate elements farther than `k`.
- Multiple duplicates of the same element.

---

## Key Interview Points

- Brute Force Solution: `O(n²)`
- Optimized Solution: `O(n)` using HashMap.
- Updating the index is important because the latest occurrence gives the smallest possible distance.
- Hashing is the preferred technique for this problem.

---

## Tags

- Array
- HashMap
- Sliding Window
- LeetCode Easy
- Java
- Interview Preparation
