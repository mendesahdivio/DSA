#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.


----------------------------------------------------------------------
SOLUTION
----------------------------------------------------------------------

the brute force approach would be we prepare an adjacency list from the prequisites list and then we do a bfs on each and every node so its like we do a bfs on every node so we will loop through every node and the desiding factor would be is if the current value store in the queue is eqval to the current node then we will have detected a cycle


*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return canFinishInBruteForece(numCourses, prerequisites);
    }
private:
   bool canFinishInBruteForece(int numCourses, vector<vector<int>>& prerequisites) {
     //first we prepare our adjacency list
     vector<vector<int>> adjacency(numCourses, vector<int>());

     //we know that in the prequisite its the oppostie direction so we need to loop through it
     //with this the adjacency list is ready
     for(int i = 0; i < prerequisites.size(); i++){
       vector<int> currentPrequisiteVal = prerequisites[i];
       adjacency[currentPrequisiteVal[1]].push_back(currentPrequisiteVal[0]);
     }

     //now we need to loop through the vertices
     for (int v = 0; v < numCourses; v++) {
       //initialise a queue and a seen map
       //this will get initialised for every vertex
       queue<int> queueItems;
       unordered_map<int, bool> seen;

       //we loop through the adjacency list and add the items to the queue
       for (int i = 0; i < adjacency[v].size(); i++) {
         queueItems.push(adjacency[v][i]);
       }

       while(queueItems.size()) {
         int currentVertex = queueItems.front();
         queueItems.pop();

         seen[currentVertex] = true;

         //base condition iVP
         if (currentVertex == v) {
           return false;
         }

         vector<int> adjacentVertices = adjacency[currentVertex];


         for(int i = 0; i < adjacentVertices.size(); i++) {
           int nextAdjacentvertex = adjacentVertices[i];
           if (!seen[nextAdjacentvertex]) {
             queueItems.push(nextAdjacentvertex);
           }
         }

       }
       
     }

     return true;

     
   }
};

int main() {
  std::cout << "Hello World!\n";
}
