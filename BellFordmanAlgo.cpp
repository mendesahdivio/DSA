#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1


Here we are trying to solve the problem of max time taken for the signal to reach every node on the shortest path for that reason lets say we have negative values and no negative cycles then we can use BELLFORDMANS ALGO

basically what we do is we loop through N - 1 paths to the furthermost node and use Dynamic programming as our base idea right so with this we will definately go through all the posible ways in the graph to reach the destination through which we will update the distance array Holding the values of the distace between the edges we also use a count value to brake from N-1 loop if there are no more changes in the distace values 

When to use Bellfordman :
to check the smallest distance with edges with negative values 
you can also use bell fordman to check for negative cycle by looping one more of N -1 to see if there is any change in the distace array

---------------------------------------------------------------------

BELL FORDMAN GRAPH ALGO

---------------------------------------------------------------------
     
*/

class Solution {
public:
int implementBellFordMan(vector<vector<int>> times, int n, int k) {
  //first we make the distace array where each of the values is the max value like infinity
  vector<int> distance(n, 999);

  //now we will loop through the N-1 nodes
  for (int i = 0; i < n -1; i++){
    //now we se the count every time for each iteration
    int count = 0;

    //now we will loop through the time array and use that to leverage
    for (int j = 0; j < times.size(); j++){
      int sourceNode = times[j][0];
      int destinationNode = times[j][1];
      int weight = times[j][2];

      if (distance[sourceNode -1] + weight < distance[destinationNode - 1]) {
        distance[destinationNode - 1] = distance[sourceNode -1] + weight;
        //increment the count
         count++;
      }
    }

    //if there is no change in the count that means that there is no more change in the distance to be less meaning we already reach our desire node for the shortest path
    if (count == 0) {
      break;
    }
    
  }

  int maxDistace = *max_element(distance.begin(), distance.end());


  if (maxDistace == 999) {
    return -1;
  }

  
  return maxDistace;
}
};
