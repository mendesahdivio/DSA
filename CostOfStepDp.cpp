#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/*
Question: -- 
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.



------------------------------------------------------------

Solution
Dynamic Programming

------------------------------------------------------------


why are we using dynamic programming here?
because this is an optimisation problem since we are asked the min coast to reach the final step

How do we solve it from dynamic programming point of view:
steps:
step 1) we build a recursive Relation: in this we build a recursive formula meaning we need to check which steps are repeated and how to achive our goal from this we will get the formula of relation ship 

if look at the input 1:

we are given array  cost = [10,15,20] now we need to find the min cost to reach the lst step beyonf 20 so lets assume 
cost = [10, 15, 20] n

where n is the last step but how do we get the cose of on n ?

we know that we can reach n from 15 or from 20 
meaning if ww can go to n from (n -2) that is from 15 and (n -1) from 20 but we want the minimum of these two values that is cost 
so we get 

min(minCost((n-2), (n -1)));

now if we look at all the steps drawing a state tree to reach n
we seen that we get the cost at n to be 
minCost(n) = cost[n] + min(minCost(n - 1), minCost(n - 2));

 if(n < 0) return 0;
 and  if(n === 0 || n === 1) return cost[i];

so we got our formula please draw the tree you will be able to know more especially the fact that we want to go to a value where the n = 0 

Step 2): 
we build our recursive function 

int minCostClimbingStairs(vector<int>& cost) {
     //we need to get the size of the arry
     int n = cost.size() - 1;

     return min(minCost(n -1, cost), minCost(n -2, cost));

}

int minCost(int n, vector<int>& cost) {

  if (n < 0 ){
    retrun 0;
  }

  if (n == 0 || n == 1) {
     return cost[n];
  }

  return (cost[n] + min(minCost(n-1, cost), minCost(n-2, cost));

}

step 3: 
As you can see above this is the recursinve solution but now we also notivce that for each call we actually calling teh function 2 times hence the time taken would 2^n where n is the depth of the tree


so how do we stop that ?

if we look at the graph we notice that some of the steps in the tree are repeating now the problem here is i cant paste the tree since i need to manually write it it will be difficult but from there we will

so remembering that in dynamic programming to memoize any value we need to do it with the same data structure as that of the input is so we will take an array as the memoizing data structuire


int minCost(int n, vector<int>& cost, vector<int>& memoize, ) {

  if (n < 0 ){
    retrun 0;
  }

  if (n == 0 || n == 1) {
     return cost[n];
  }

  if (n < memoize.size()) {
     return memoize[n];
  }

   memoize[n] = cost[n] + min(minCost(n-1, cost), minCost(n-2, cost)
  return memoize[n];

}

*/


class Solution {
public:
   int minCostClimbingStairs(vector<int>& cost) {
     //we need to get the size of the arry
     int n = cost.size();
     vector<int> memoize(n , -1);

     return min(minCost(n -1, cost, memoize), minCost(n -2, cost, memoize));
  }

private: 
int minCost(int n, vector<int>& cost, vector<int>& memoize) {

  if (n < 0 ){
    return 0;
  }

  if (n == 0 || n == 1) {
     return cost[n];
  }

  if (memoize[n] != -1) {
     return memoize[n];
  }

   
   memoize[n] = cost[n] + min(minCost(n-1, cost, memoize), minCost(n-2, cost, memoize));

  return memoize[n];

}

};
