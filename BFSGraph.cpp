#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <memory>
using namespace std;

template<typename Element>
class GraphBFS {
public:

vector<Element> returnGraphBFSUsingAdjacencyList(vector<vector<Element>> adjacyList) {
  vector<Element> values;
  queue<Element> queueOfVertex;
  unordered_map<Element, bool> seenVertex;
  if (adjacyList.size() == 0) {
    return values;
  }

  //first add the first elemet to the queue since a adjacy list of int will start at 0 
  queueOfVertex.push(0);

  //loop while the lenght of the queue exist
  while(queueOfVertex.size()) {
    Element currentVertex = queueOfVertex.front();
    queueOfVertex.pop();

    values.push_back(currentVertex);
    seenVertex[currentVertex] = true;

    //get the the connections fromt the current vertex
    vector<Element> connections = adjacyList[currentVertex];

    for (int i = 0; i < connections.size(); i++) {
      if (!seenVertex[connections[i]]) {
        queueOfVertex.push(connections[i]);
      }
    }
  }

  return values;
}


vector<Element> returnGraphFromAdjacyMatrixBFS(const vector<vector<Element>>& AdjacyMatrix) {
  //we need the vector to hold the result
  vector<Element> values;
  //we need a queue since this bfs
  queue<Element> queueOfItems;
  //we need a map to varify which value is already traveserd in the graph
  unordered_map<Element, bool> seenMap;

  //first thing to do is push the first vertex of the graph in the queue
  queueOfItems.push(0);


  //now till the lenght of the queue is present loop through and keep adding the new vertices that you traverse and update the visited value in the map
  while(queueOfItems.size()) {
    Element currentNode = queueOfItems.front();
    values.push_back(currentNode);
    seenMap[currentNode] = true;
    queueOfItems.pop();
    
    vector<Element> connections = AdjacyMatrix[currentNode];

    //now we loop throug the items inside the connections
    for (int v = 0; v < connections.size(); v++) {
        if (connections[v] > 0 && !seenMap[v]) {
          queueOfItems.push(v);
        }
    }
  }

  return values;
  
}





};

int main() {
  std::cout << "Hello World!\n";
  vector<vector<int>> adjacencyList = {
  {1, 3},
  {0},
  {3, 8},
  {0, 2, 4, 5},
  {3, 6},
  {3},
  {4, 7},
  {6},
  {2}
};

  vector<vector<int>> adjacencyMatrix = {
  {0, 1, 0, 1, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0, 0}
};


  unique_ptr<GraphBFS<int>> graphTraversal(new GraphBFS<int>());

  vector<int> items1 = graphTraversal->returnGraphBFSUsingAdjacencyList(adjacencyList);
  vector<int> items2 = graphTraversal->returnGraphFromAdjacyMatrixBFS(adjacencyMatrix);
}
