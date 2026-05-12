#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
    }

    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {

        int rows = grid.size();
        int cols = grid[0].size();

        int totalLayers = min(rows, cols) / 2;

        for (int layer = 0; layer < totalLayers; layer++)
        {

            vector<int> elements;

            int top = layer;
            int left = layer;

            int bottom = rows - layer - 1;
            int right = cols - layer - 1;

            // Top row
            for (int col = left; col <= right; col++)
            {
                elements.push_back(grid[top][col]);
            }

            // Right column
            for (int row = top + 1; row <= bottom - 1; row++)
            {
                elements.push_back(grid[row][right]);
            }

            // Bottom row
            for (int col = right; col >= left; col--)
            {
                elements.push_back(grid[bottom][col]);
            }

            // Left column
            for (int row = bottom - 1; row >= top + 1; row--)
            {
                elements.push_back(grid[row][left]);
            }

            int size = elements.size();
            int rotateIndex = k % size;
            int index = rotateIndex;

            // Top row
            for (int col = left; col <= right; col++)
            {
                grid[top][col] = elements[index];
                index++;

                if (index == size)
                {
                    index = 0;
                }
            }

            // Right column
            for (int row = top + 1; row <= bottom - 1; row++)
            {
                grid[row][right] = elements[index];
                index++;

                if (index == size)
                {
                    index = 0;
                }
            }

            // Bottom row
            for (int col = right; col >= left; col--)
            {
                grid[bottom][col] = elements[index];
                index++;

                if (index == size)
                {
                    index = 0;
                }
            }

            // Left column
            for (int row = bottom - 1; row >= top + 1; row--)
            {
                grid[row][left] = elements[index];
                index++;

                if (index == size)
                {
                    index = 0;
                }
            }
        }

        return grid;
    }
};

int main()
{
}