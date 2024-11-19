# FinalProjectCMSC510

This problem involves navigating a grid while managing limited resources (health) in the presence of "unsafe" cells that decrease your health. Starting from the top-left corner, the goal is to determine if you can reach the bottom-right corner using valid moves (up, down, left, right) without depleting your health. Unsafe cells (denoted by 1) reduce your health by one, so you must plan your path carefully to ensure you reach the destination with a health value of at least 1.
Specific problem statement can be found here: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/?envType=problem-list-v2&envId=shortest-path
A real-world application could be a video game scenario where a player needs to navigate through a maze while avoiding traps that decrease their health. The goal is to reach the exit of the maze with enough health remaining to survive. This problem models the pathfinding logic needed to guide the player safely to the destination.
My approach to the problem involves using Breadth-First Search, which is suitable for finding shortest or possible paths in a grid. Below are steps that I took to solve the problem:
1: Start from (0, 0) and try to reach (m - 1, n - 1) while ensuring the health remains above 0. 
2: Maintain a visited matrix to track cells already explored with specific health values stored to avoid redundant calculations. 
3: Use a queue to simulate BFS. For each cell pushed onto the queue, check its neighbors and whether moving to them is valid (within bounds, not visited with the current health, and health > 0). 
4: If the bottom-right corner (m - 1, n - 1) is reached with health ≥ 1, return true. 
5: If all possibilities are explored without reaching the target cell, return false.
Some problems I had when solving the problem includes:
1: How to make sure that we do not move out of the grid.
2: How to represent the movement from one cell to another.
3: How to use the visited matrix to store max health and avoid redundant calculations.

