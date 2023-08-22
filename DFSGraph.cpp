#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*
so what are the things we require for the dfs
1) we need a recursive tail function 
2) we need to pass the graph adjacy list, the values vector to store the vertices, the vertice param and the did see unordered map
*/ 

class GraphDFS {
 void UsingAdjecancyList(vector<vector<int>>& AdjecancyList, vector<int> valuesArr, int vertex, unordered_map<int, bool> isSaved) {
   //first push the vertex value inside the valuesArr
   valuesArr.push_back(vertex);
   //now update the is saved part 
   isSaved[vertex] = true;

   vector<int> currentVertices = AdjecancyList[vertex];

   for (int i = 0; i < currentVertices.size(); i++) {
     int nextVetex = currentVertices[i];
     if(!isSaved[nextVetex]) {
       UsingAdjecancyList(AdjecancyList, valuesArr, nextVetex, isSaved);
     }
   }
   
 }
};
