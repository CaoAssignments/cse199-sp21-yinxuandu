# Summary - Feb 2021 Silver

**Author:** Nora Yinxuan Du

## Problem 1: Comfortable Cow

> **Keyword:** Flood fill, BFS, Greedy

### Solution
For any grid that has three cows in its neighboring grids, we should add a new cow to the blank neighboring grid to avoid "comfort". Since grids always have four neighboring grids (top, bottom, left and right), if we find a grid with three neighbors that already have cows in that neighboring grid, we always know where to add the new cow.

So this question is actually a flood-fill (breath-first search) question where we add a grid in the queue only if
- A cow is recently added in this grid by Farmer Nhoj;
- We has to add a cow in this grid to avoid "comfort" from its neighboring grid.

Since the grid only affects its neighboring grids, we can achieve BFS by checking all four directions and adding a new cow if there are already cows in three directions.

Note that we do not need to BFS every time Farmer Nhoj adds a new cow. This is because the cow we added before should always be there to avoid the "comfort" of previous cows. We only need to avoid additional counts if the cow Farmer Nhoj wants to add has already been added beforehand to avoid "comfort".

<br><hr>

## Problem 2: Year of the Cow
> **Keyword:** Greedy, Sorting, 1d-array, Discretization

### Solution

Things you should know:
- Time is divided in intervals of 12 years. Since Bessie can only ride the time portal in multiples of 12 years, it does not matter how many years Bessie should travel to in each interval. Only the interval itself is important. In other words, there are only two kinds of intervals here: the interval where Bessie needs to go and the interval where Bessie does not need to go.
- The order of travel does not matter. For example, in the case of sample input, Bessie's travel as explained, or her travel to 108 years ago, wait 24 years, then travel to 48 years ago, wait 12 years, and then travel back, should be considered equivalent.

In this way, since we can determine the oldest interval by the farthest year that Bessie wants to go, all we really need to do is to minimize the number of intervals, i.e., to remove as many blank intervals as possible. 

For all K jumps, Bessie can travel to the oldest interval on the first jump and then return using the remaining jumps. And since blank intervals can be combined by adjacent intervals, we can remove (K-1) longest intervals after sorting all combined intervals.

<br><hr>

## Problem 3: Just Green Enough
> **Keyword:** 2d-array, Counting

### Solution
We want to find all possible sub-grids where 100 is the minimum value inside. As N is no more than 500, we can look for a O(N^3) solution.

One idea is to fix the sub-grid exactly between two rows and try to find the number of valid cases by changing the position of its length.

There are O(N^2) cases for fixing the sub-grid exactly between two rows. For each case, we can iterate through each column j and sum up all sub-grids whose length ends at j.

To do this in O(N) runtime, we maintain val[j] be the minimum value in column j between current two rows. The question then becomes for each column j, to find a smallest k, such that
- There is at least one 100 in val[k], val[k + 1], ... val[j];
- All val[k], val[k + 1], ... val[j] are no less than 100.

Then if there is such k for j, the total number of valid sub-grids between current rows and ending with column j is (k - j + 1).