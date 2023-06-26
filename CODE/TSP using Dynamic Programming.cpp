#include <stdio.h>
#include <limits.h>

#define N 4
#define VISITED_ALL (1 << N) - 1

int dist[N][N] = {
    {0, 16, 11, 6},
    {8, 0, 13, 16},
    {4, 7, 0, 9},
    {5, 12, 2, 0}
};

int dp[16][4];

int tsp(int mask, int pos) {
    if (mask == VISITED_ALL) {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = ans < newAns ? ans : newAns;
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    printf("Travelling Salesman Distance is: %d\n", tsp(1, 0));
    return 0;
}
