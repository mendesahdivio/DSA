//some programmes for sorting

#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> integerVector;
class PracticeSorting {


public:
//INSERTION SORT
//where A is the pointer to the Array
void sortUsingInsertion(int *A, int n) {
  
  for(int i = 1; i < n; i++) {
    //keep pointer to current value for the current index
    int currentKey = A[i];
    //prepare a pointer to the 
    int j = i - 1;

    //this will sort within the array that is arranged before
    while(j >= 0 && A[j] > currentKey) {
      A[j + 1] = A[j];
      j = j - 1;
    }


    //finally we update the A[j + 1] to the currentKey
    A[j + 1] = currentKey;
    
  }
}

//SELCTION SORT
void selectionSort(int *A, int size) {
  //we will create 2 loops here one will go from 0 to n - 1 and the other loop wiil go from i + 1 to n

  //outer loop
  for(int i = 0; i < size - 1; i++) {
    //first keep referece to the first element index as the lowest values
    int minValueIndex = i;

    //inner loop 
    for(int j = i + 1; j < size; j++) {
      if (A[j] < A[minValueIndex]) {
        minValueIndex = j;
      }
    }


    if (minValueIndex != i) {
      swap(A[minValueIndex], A[i]);
    }
  }
}


//BUBLE SORT
void bubbleSort(int *A, int length) {
  
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) { 
      if(A[j] > A[j+1]) {
        //Swap the numbers
        int temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }        
  }

}


  
  integerVector mergeSort(integerVector& arr) {
    if (arr.size() == 1) {
      return arr;
    }

    //split the array in half by finding the midpoint index
    int midPoint = arr.size()/2;

    //okay now prepare a left and right vector here
    vector<int> left(arr.begin(), arr.begin() + midPoint);
    vector<int> right(arr.begin() + midPoint, arr.end());

    return merge(mergeSort(left), mergeSort(right));
  }


private:
vector<int> merge(integerVector left, integerVector right) {
  //prepare a new vector to hold the data
  integerVector result = {};
  int leftIndex = 0;
  int rightIndex = 0;

  while(leftIndex < left.size() && rightIndex < right.size()) {
    if(left[leftIndex] < right[rightIndex]) {
      result.push_back(left[leftIndex]);
      //increment the left index
      cout << "the left " << left[leftIndex] << endl;
      leftIndex++;
    } else {
      result.push_back(right[rightIndex]);
      cout << "the right " << right[rightIndex] << endl;
      rightIndex++;
    }
  }

   result.insert(result.end(), left.begin() + leftIndex, left.end());

    // Concatenate elements from rightIndex to the end of the right vector
    result.insert(result.end(), right.begin() + rightIndex, right.end());

  

  return result;
}

  
};



int main() {
  PracticeSorting*  sorter = new PracticeSorting();
 //  int A[] = {22, 33, 45, 10, 1, 3};
 // // sorter->sortUsingInsertion(A, 6);
 //  //sorter->selectionSort(A, 6);

 //  sorter->bubbleSort(A, 6);


  vector <int> arr = {22, 33, 45, 10, 1, 3};

  integerVector test = sorter->mergeSort(arr);
  for (auto val: test) {
    cout << val << endl;
  }
}


