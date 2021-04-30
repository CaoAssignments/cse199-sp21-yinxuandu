# Summary - Dec 2018 Silver

**Author:** Nora Yinxuan Du

## Problem 1: Convention

> **Keyword:** Binary search, greedy

### Solution

The problem wants us to find the minimum possible value of maximum waiting time of any one arriving cow. This is equivalent to say we need to find smallest k such that any maximum waiting time <= k.

This can be solved efficiently using binary search algorithm since the status of k with above condition is monotonously, meaning that we start at small k which doesn't acheive the condition, and then once k' works, any value of k no less than k' should also work.

We run binary search on this minimum value k and each turn we can validate k in O(n) time using greedy algorithm. 

Let's consider which cows should be in 1st Bus (bus with earliest time). From greedy, the cow with the earliest arriving time must be in this bus. Then since the maximum waiting time is no more than k, we can add as many cows as possible by the increasing order of their arriving time. Note that we should stop adding if the bus is full, i.e. already c cows in the bus.

And since each time we need to check the cows in the increasing order of their arriving time, we should sort the cows in the initialization step.

## Problem 2: Convention II

> **Keyword:** Heap, searching, sorting, greedy

### Solution
As the question defines the priority for cows to eat grass, the final order of the cows should be unique. So our goal is to get the answer as fast as possible.

We first go over what exact order we should follow. The first cow to eat grass should be always the cow with earliest arriving time. The next one should be the one with highest priority (i.e. at the smallest index of row in the input) that has already been waiting. If no cow is waiting at the time, we should then let the one with earliest arriving time among the rest of the cows to eat grass.

So, each turn, there are two things we need to keep track of: 

1. the cow with highest priority among cows that are waiting;
2. the cow with earliest arriving time in the rest of cows.

We can construct a heap (priority_queue) to get the first thing. And then we can sort all cows by the increasing order of their arriving time and iterate through cows to get the second thing.

## Problem 3: Mooyo Mooyo

> **Keyword:** Depth-first search, 2d-array

The idea is quite simple. Each time we run DFS on the current map, and mark every haybale we need to remove. Then we update the map by following the gravity pulls rule and filling in '0' with all empty haybale. Repeat above operations until we can't find any haybale we need to delete.

For DFS step, we can dye each connect component with different color. When reaching out to a new haybale, we increment the counter for this color. Then we can mark haybale that should be deleted based on whether the number of haybales in the current connected component is no less than k.

For Update step, we can update a column at a time since any deleted haybale only influences the haybales right above it due to gravity pulls rule.

The constrait of n is super small so we don't need to worry about time complexity XD

### Solution