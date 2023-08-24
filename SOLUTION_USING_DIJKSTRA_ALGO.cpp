#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <memory>
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


-----------------------------------------------------------------------

SOLUTION USING DIJKSTRA ALGO

----------------------------------------------------------------------

why so ?
since we are asked the time taken for all the nodes to recieve the signal the faster path would be the probable ans since the singnal is not traversing one node at a time but rather like a sound wave so the best path would be by suing DIJKSTRA algo as the improvment of the greedy algo

How do we approach ?
we are given the time array which contains the source the destination and the weight that we will use to generate the adjacecny list and also the distance array shall be starting from k - 1 since the number of nodes start from 1 to N

*/

class Solution {
public:

    //MARK: - DIJKSTRAS ALGO
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      //first we create the distance array of the specific size of n
      vector<int> distace(n, 1256);
      //also we will create adjecancy list of size of n
      std::vector<std::vector<std::pair<int, int>>> adjList(n);

      // set the distance of the K-1 node since the Nodes are N and we set the distance to 0
      distace[k -1] = 0;

      //since we need the shortest distace between nodes at any give point we need a data structure to give us that so we need some kind od DS to give us the shortest path that we can achive using priority queue that is the min heap

      priority_queue<int, vector<int>, greater<int>> minHeap;

      //now we add the first node that is K -1 to the min heap
      minHeap.push(k -1);

      //now we loop through the times array and prepare the adjacency list
      for (int i = 0; i < times.size(); i++) {
        int node = times[i][0];
        int destinationNode = times[i][1];
        int weightOfTravel = times[i][2];
        //here we take node and the destiantion as minus one reminder that we are usiing nodes to n hence the indices should be n-1 which are the nodes
        adjList[node - 1].push_back({destinationNode -1 , weightOfTravel});
      }


      while(!minHeap.empty()) {
        int currentVertex = minHeap.top();
        cout << "the lowest value there == " << currentVertex << endl;
        minHeap.pop();

        //get the adjacent list for this vertex
        vector<pair<int, int>> adjListForVertex = adjList[currentVertex];

        for (int i = 0; i < adjListForVertex.size(); i++) {
          //get immediate neighbour
          int neighboringVertex = adjListForVertex[i].first;
          int weight = adjListForVertex[i].second;

          //now we have to check to the destination distance from the current vertex + weight to the already present data of distance to the neighbourhood vertex and see if its smaller if so then replace the data in the distance array
          if(distace[currentVertex] + weight < distace[neighboringVertex]) {
            distace[neighboringVertex] = distace[currentVertex] + weight;
            //and push the value of the neighbours vertex to the heap if the distace was less
            minHeap.push(neighboringVertex);
          }

        }

      }

      
      //now we need to get the max value from the distance array 
      int maxTime = *max_element(distace.begin(), distace.end());


      if (maxTime == 1256) {
        cout << "it came here" << endl;
        return -1;
      }

      
     return maxTime;
      
    }
};

int main() {
  unique_ptr<Solution> sol(new Solution());
  vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
  int n = 4;
  int k = 2;
  int val = sol->networkDelayTime(times, n, k);
  cout << val << endl;
}
