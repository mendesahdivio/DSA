#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 
Problem statement : You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/


/*
test cases 1: 
Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4


Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.


Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

      if (grid.size() == 0) {
        return -1;
      }



      
        //we know that 0 is null 
        //and 1 is fresh orrange 
        //and 2 is the rotten orrange 

        //first lets crate const for the above 
      int Empty = 0;
      int fresh = 1;
      int rotten = 2;


      //do a sequential search and maintain the count of fresh oranges and maintain a queue for the positions of the rotten oranges
      int countOfFreshOranges = 0;

      queue<vector<int>>  queue;


      for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
          if (grid[row][col] == fresh) {
            countOfFreshOranges ++;
          }
          if (grid[row][col] == rotten) {
            queue.push({row, col});
          }
        }
      }


      int minutes = 0;
      //now we know that a min will pass for per level of the conversion to rotten orange so we need to keep track of the levels we are rotting and completing for this we use the length of the queue to know when one level is complete and increment the count of the mins
      int currentQueueLeng = queue.size();

      while(queue.size()) {
        if (currentQueueLeng == 0) {
          currentQueueLeng = queue.size();
          minutes++;
        }

        vector<int> currentPostion = queue.front();
        queue.pop();
        currentQueueLeng--;
        int currentRow = currentPostion[0];
        int currentCol = currentPostion[1];

        for (int i = 0; i < this->direction.size(); i++) {
          vector<int> currentDir = this->direction[i];
          int nextRow =   currentRow + currentDir[0];
          int nextCol = currentCol + currentDir[1];

          if (nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size()) {
            continue;
          }

          if (grid[nextRow][nextCol] == fresh) {
            grid[nextRow][nextCol] = rotten;
            countOfFreshOranges--;
            queue.push({nextRow, nextCol});
          }
          
        }
      }


      if (countOfFreshOranges > 0) {
        return -1;
      }
        
      
      return minutes;
      
      
  }

private:
vector<vector<int>> direction = {{-1,0},{0,1},{1,0},{0,-1}};
};

