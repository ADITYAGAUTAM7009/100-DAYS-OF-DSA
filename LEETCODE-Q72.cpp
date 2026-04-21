// Problem Name: Travelling Salesman Problem (TSP)
// Author: Aditya Gautam

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int n;
    int dp[1 << 15][15];

    int solve(int mask, int pos, vector<vector<int>>& cost) {
        if (mask == (1 << n) - 1) {
            return cost[pos][0];
        }

        int &ans = dp[mask][pos];

        if (ans != -1) return ans;

        ans = INT_MAX;

        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                ans = min(ans,
                          cost[pos][city] +
                          solve(mask | (1 << city), city, cost));
            }
        }

        return ans;
    }

    int tsp(vector<vector<int>>& cost) {
        n = cost.size();

        if (n == 1) return 0;

        memset(dp, -1, sizeof(dp));

        return solve(1, 0, cost);
    }
};