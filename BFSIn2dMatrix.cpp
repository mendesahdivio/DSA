#include <iostream>
#include <vector>
#include <memory>
#include <queue>
using namespace std;



template <typename Element>
class BFSmatrix {
public:
  vector<Element> returnResultFromBFS(vector<vector<Element>>& matrix) {
    std::vector<std::vector<bool>> seen(matrix.size(), std::vector<bool>(matrix[0].size(), false));

    vector<Element> solution = {};

    queue<vector<int>> queue;

    queue.push({0,0});

    while(!queue.empty()) {
      vector<int> currentPosition = queue.back();
      queue.pop();

      int row = currentPosition[0];
      int col = currentPosition[1];

      if (row < 0 || row > matrix.size() || col < 0 || col > matrix[0].size() || seen[row][col]) {
        continue;
      }

      //set seen
      seen[row][col] = true;

      //append solution
      solution.push_back(matrix[row][col]);

      for(int i = 0; i < this->direction; i++) {
        vector<int> currentDir = this->direction[i];
        queue.push({row + currentDir[0], col + currentDir[1]});
      }
    }

    return solution;
    
  }

private:
vector<vector<int>> direction = {{-1,0}, {0, 1}, {1,0}, {0,-1}};
};

int main() {
  std::cout << "Hello World!\n";
}
