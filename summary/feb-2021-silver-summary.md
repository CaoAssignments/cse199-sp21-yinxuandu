# Summary - Feb 2021 Silver

**Author:** Nora Yinxuan Du

## Problem 1: Comfortable Cow

> **Keyword:** Flood fill, BFS, Greedy

### Solution
For any grid, as long as there are three cows in its neighboring grids, we should add a new cow in the blank neighboring grid to avoid "comfort". Since there are always four neighbors for grids (up, down, left, right), we always know where to add a new cow if we find out a grid with three neighbors which already have cows in it.

So this question is actually a flood-fill (breath-first search) question where we add a grid in the queue only if
- A cow is recently added in this grid by Farmer Nhoj;
- We has to add a cow in this grid to avoid "comfort" from its neighboring grid.

As grids only affect their neighboring grids, we can acheive BFS by checking all four directions and adding a new cow if there are three directions already with cows.

Notice that we don't really need to do BFS every time Farmer Nhoj adding a new cow. This is because cows we previously added should always be there to avoid "comfort" from previous cows. We only need to avoid extra counting where the cow Farmer Nhoj wants to add has already been added beforehand to avoid "comfort".


<br><hr><br>

## Problem 2: Year of the Cow
> **Keyword:** Sorting, 1d-array, Discretization

### Solution

<br><hr><br>

## Problem 3: Just Green Enough
> **Keyword:** 2d-array, Counting

### Solution
