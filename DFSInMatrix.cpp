#include <iostream>
#include <vector>
using namespace std;

template <typename element>
class DfsMatrix {

public:
vector<element> returnDfsOfMatrix(vector<vector<element>>& matrix) {
  
}

void dfs(vector<vector<element>>& matrix, int row, int column,  vector<vector<bool>>& seen, vector<element>& solution) {
  //MARK :- base condition
  if (row < 0 || row >= matrix.size() || column < 0 || column >= matrix[0].size() || seen[row][column]) {
    return;
  }

  //add the item to the solution matrix and update the seen matrix
  solution.push_back(matrix[row][column]);

  seen[row][column] = true;

  //MARK :- loop through the directions
  for (int i = 0; i < this->directions.size(); i++) {
    vector<int> currentDir = directions[i];
    dfs(matrix, row + currentDir[0], column + currentDir[1], seen, solution);
  }
}


private: 
vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1,0}, {0,-1}};
};

int main() {
  
}
