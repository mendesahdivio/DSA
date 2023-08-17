#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template <typename element>
class DfsMatrix {

public:
vector<element> returnDfsOfMatrix(vector<vector<element>>& matrix) {
  
  std::vector<std::vector<bool>> seen(matrix.size(), std::vector<bool>(matrix[0].size(), false));

  vector<element> solution = {};

  dfs(matrix, 0, 0, seen, solution);

  return solution;
}


private: 
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

vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1,0}, {0,-1}};
};



int main() {

  unique_ptr<DfsMatrix<int>> dfs(new DfsMatrix<int>());
  vector<vector<int>> matrix = {
  {1, 2, 3, 4, 5},
  {6, 7, 8, 9, 10},
  {11, 12, 13, 14, 15},
  {16, 17, 18, 19, 20}
};

  vector<int> items = dfs->returnDfsOfMatrix(matrix);

  for(const auto item: items) {
    cout << item << endl;
  }
  
}
