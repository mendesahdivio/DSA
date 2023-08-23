#include <iostream>
#include <vector>
using namespace std;
/*
1376. Time Needed to Inform All Employees
A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.

 

Example 1:

Input: n = 1, headID = 0, manager = [-1], informTime = [0]
Output: 0
Explanation: The head of the company is the only employee in the company.
Example 2:


Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1
Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.
 

Constraints:

1 <= n <= 105
0 <= headID < n
manager.length == n
0 <= manager[i] < n
manager[headID] == -1
informTime.length == n
0 <= informTime[i] <= 1000
informTime[i] == 0 if employee i has no subordinates.
It is guaranteed that all the employees can be informed.*/



/*

-----------------------------------------------------------------------------------------------------

SOLUTION

-----------------------------------------------------------------------------------------------------

let us first think of the employees they go from 0 to n -1 
 meaning if employees are lets say 8
 then employees = [0, 1, 2, 3, 4, 5, 6, 7]
 we are also given the managers array 
 
             0  1  2  3   4  5  6  7   employees
 managers = [2, 2, 4, 6, -1, 4, 4, 5]
 
         0  1  2  3  4  5  6  7   employees
 time = [0, 0, 4, 0, 7, 3, 6, 0]


 from this we know that we can build a graph
                    Manager
                      4   time: 7
                  /   |    \
                /     |      \
              /       |        \
time:4      2  time:3 5         6  time: 6
          /  \        |           \
         /    \       |             \
        0      1      7               3

time for the last layer is 0;


        so the above graph tells us the relations ship right 
since the vertices of the all levels arent connected so much we need to use the adjacency list as the way to travese through        
*/


class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      std::vector<std::vector<int>> adjList(manager.size());

         //now to create adjList we meed to loop through the managers array usin the m employees 
      for (int employee = 0; employee < n; employee ++) {
             int manager = manager[employee];

             if (manager == -1) {
                continue;
             }

             adjList[manager].push_back(employee);
      }

      
       return  dfs(headID, adjList, informTime);
         
    }

private: 
   int dfs(int employeeCurrnId, vector<vector<int>>& adjacentList, vector<int>& informedTime) {
     if (adjacentList[employeeCurrnId].size() == 0) {
       return 0;
     }

     int maxTime = 0;
     
     vector<int> subordinatesForEmployee = adjacentList[employeeCurrnId];

     for (int e = 0; e < subordinatesForEmployee.size(); e ++) {
       int currentSubordinateId = subordinatesForEmployee[e];
       maxTime = max(maxTime, dfs(currentSubordinateId, adjacentList, informedTime));
     }

     return (maxTime + informedTime[employeeCurrnId]);
   }
};
