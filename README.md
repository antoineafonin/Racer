# Racer
A C program that finds the optimal value of k to match a given total race time

# README for the Code

## Description

This C program calculates the value of `k` that modifies the speeds of objects so that the total time required for traveling a set of distances matches a specified target time. The program utilizes a binary search algorithm to efficiently find the value of `k` within a specified precision.

## Purpose

The program is designed to solve the problem where you are given a list of distances and corresponding speeds for objects, and you need to find a value `k` that, when added to the speeds of all objects, causes the total time of travel to equal a specified target time.

### Main Logic

1. **`compute_time`**: 
   - This function calculates the total time required for the objects to travel the given distances, using the modified speeds (`speed + k`).
   - It returns the total time or `INFINITY` if any modified speed is less than or equal to zero.

2. **`find_k`**: 
   - This function uses binary search to find the value of `k` that brings the total time close to the target time.
   - It operates within a specified range of `k` values (`-1000` to `1000`) and uses the `compute_time` function to check the resulting time at each mid-point.
   - The search continues until the difference between the calculated time and the target time is within a specified precision (`1e-9`).

3. **`main`**: 
   - The program reads the number of objects `n`, the target time, and the distances and speeds for each object.
   - It then calls `find_k` to calculate and print the required value of `k` with a precision of 9 decimal places.

## Requirements

- The program requires the standard C library `<math.h>`, `<stdio.h>`, and `<stdlib.h>`.
- Ensure the system supports `double` precision floating-point arithmetic.

## Input

- The first line contains two integers: `n` (number of objects) and `total_time` (the target total time).
- The following `n` lines each contain two integers: `distances[i]` (the distance each object travels) and `speeds[i]` (the speed of each object).

Example input:
```
3 10
10 2
20 3
30 4
```

## Output

- The program outputs a single floating-point number `k` (to 9 decimal places), which is the required modification to the speed for the total time to match the target.

Example output:
```
0.500000000
```

## Algorithm

1. The binary search is initialized with the values `low = -1000` and `high = 1000`, representing the search range for `k`.
2. In each iteration, the middle value `mid` is calculated and the total time for that value is computed using `compute_time`.
3. Depending on whether the calculated total time is greater or smaller than the target, the search range is adjusted (`low` or `high` is updated).
4. The binary search continues until the difference between the calculated time and the target time is smaller than the specified precision (`1e-9`).

## Complexity

- **Time complexity**: `O(n * log(max_k))`, where `n` is the number of objects and `max_k` is the range of possible values for `k` (bounded by the binary search iterations).
- **Space complexity**: `O(n)`, due to the storage of distances and speeds.

## Example

### Input:
```
3 10
10 2
20 3
30 4
```

### Output:
```
0.500000000
```

## Notes

- The program assumes that the input values are valid and that the number of objects `n` is a positive integer.
- If no solution is found within the specified precision, the program returns the closest value of `k` within the defined search space.

