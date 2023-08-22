#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <memory>
using namespace std;

template<typename Element>
class GraphBFS {
public:

vector<Element> returnGraphBFS(vector<vector<Element>> adjacyList) {
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


  unique_ptr<GraphBFS<int>> graphTraversal(new GraphBFS<int>());

  vector<int> items = graphTraversal->returnGraphBFS(adjacencyList);


  for (const auto& item: items) {
    cout << item << " ";
  }

  cout << endl;
}
