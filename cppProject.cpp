#include <iostream>
#include <vector>
#include <queue>
#include <tuple> 

using namespace std;

bool canReach(vector<vector<int>>& grid, int health) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, -1)); // To track max health visited at each cell (no re-calculation if current health < max health in visit[][])
    queue<tuple<int, int, int>> q; // To store {row, col, remaining health}

    // Starting point
    q.push({0, 0, health});
    visited[0][0] = health;

    // Directions for up, down, left, right
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
        auto [x, y, h] = q.front();
        q.pop();

        // Check if we've reached the bottom-right corner with h>0
        if (x == m - 1 && y == n - 1 && h > 0) {
            return true;
        }

        // Explore all neighbors
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy, nh = h;

            // Make sure we don't move out of grid
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                // Update health if the cell is unsafe
                if (grid[nx][ny] == 1) {
                    nh -= 1;
                }

                // If health is positive and we haven't visited this cell with better health (no redundant calculations)
                if (nh > 0 && nh > visited[nx][ny]) {
                    visited[nx][ny] = nh;
                    q.push({nx, ny, nh});
                }
            }
        }
    }

    return false;
}
/***
 * Test case from LeetCode:
int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0}
    };
    int health = 1;

    if (canReach(grid, health)) {
        cout << "Safe Walk Exists!" << endl;
    } else {
        cout << "No Sage Walks!" << endl;
    }

    return 0;
}
 */
//My own test case:
int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 0},
        {0, 0, 0, 0}
    };
    int health = 2;

    if (canReach(grid, health)) {
        cout << "Safe Walk Exists!" << endl;
    } else {
        cout << "No Safe Walks!" << endl;
    }

    return 0;
}

