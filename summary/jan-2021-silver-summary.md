# Summary - Jan 2020 Silver

**Author:** Nora Yinxuan Du

## Problem 1: Berry Picking

> **Keyword:** Greedy, 1d-array

### Solution

The intuition here is to minimize the number of berries in Elsie's baskets in order to maximize the number of berries assigned to Bessie. To achieve this, we let each of those (k / 2) baskets of Elsie always contain the same number of berries as the maximum number of berries in Bessie's baskets. Even though there are cases where Elsie can get more berries without deriving Bessie's berries, we just ignore this point because here we just want to maximize Bessie's profit.

With this strategy, we change the maximum possible number of berries in Bessie's basket and calculate the total number of maximum berries Bessie can get in this case.

For each maximum number of m, we can complete the computation in O(N). Elsie's berries are easy to obtain: there are (k / 2) baskets with m berries in each basket. For each berry tree, we make m groups and if there are less than m berries left, we make an additional group. Bessie's maximum possible number of berries should be the sum of (k / 2 + 1)-th to k-th number of berries in baskets.

## Problem 2: Load Repayment

> **Keyword:** Binary Search, Math

### Solution

First look at the input constraints (N, M, K <= 10^12). We must arrive at a solution that does not exceed O(logN) in order to avoid Time Limit Exceed.

Notice that the problem wants us to maximize X. This gives us a hint that all X that are not greater than this maximum value would satisfy all conditions. This easily reminds us of the binary search algorithm, which can help us find the extrema in monotone sequences.

So we do binary search on X (X <= 10^12), and for each turn, we check if the current X satisfies the conditions. The most straightforward solution is to iterate through all K (K <= 10^12) days and check if total G reaches to N. But that would take O(K) time which would cause Time Limit Exceed.

To optimize, w then realize that Farmer John may give away same amount of milk in the neighboring days. And as X turns larger, there will be more continuing days with same amount of milk. Therefore, we can classify K days based on amoun of milk Farmer John needs to give away and process each group together.