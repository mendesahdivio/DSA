#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
using namespace std;

//lets create a max heap
template <typename element>
class PriorityQueue{
public:
PriorityQueue() {
  this->heap = {};
}

int size() {
  return this->heap.size();
}

element peep() {
  return this->heap[0];
}

bool isEmpty() {
  return size() == 0;
}

//MARK :- push element
void push(element data) {
  //push the element to last
  this->heap.push_back(data);
  //shift up
  shiftUp(); 
}

//MARK :- pop element
element pop() {
  //first check the size
  element item;
  if (isEmpty()) {
    return NULL;
  }

  //when size is only one just return the last element
  if (size() == 1) {
     item = this->heap.back();
     this->heap.pop_back();
     return item;
  }

  
  //first swap the first and the last elemtent to reduce the time complexty to O(1)
  swap(this->heap[0], this->heap[size() - 1]);
  //pop the last element and store it 
  item  = this->heap.back();
  this->heap.pop_back();


  //swift down the topmost the root value
  shiftDown();
  //printElements();
  return item;
}
 


// to store the data lets use an vector 
private:
//functions 
bool compare(element a, element b) {
  return (a > b) ? true : false;
}

//MARK: gets parent Index
int getParentIndex(int childIndex) {
  return floor((childIndex -1)/2);
}

//MARK: get left child index
int getLeftChildIndex(int parentIndex) {
  return ((parentIndex * 2) + 1);
}

//MARK: gets right Child Index
int getRightChildIndex(int parentIndex) {
  return ((parentIndex * 2) + 2);
}


bool isValidIndex(int index) {
  return (index < size() && index >=0) ?  true : false;
}


//MARK: shift up the element in the heap
void shiftUp() {
  int nodeIndex = size() - 1;

  if (!isValidIndex(nodeIndex)) {
    
    return;
  }

  int parentIndex = getParentIndex(nodeIndex);
  

   if (!isValidIndex(parentIndex)) {
    return;
  }

  //now why nodeIndex above 0 meaning it reached the heap the root node;
  while(nodeIndex > 0 && compare(this->heap[nodeIndex], this->heap[parentIndex])) {
    //swap the parent and nodeIndex values 
    swap(this->heap[nodeIndex], this->heap[parentIndex]);
    nodeIndex = getParentIndex(nodeIndex);
  }
  
}


void shiftDown() {
  int parentIndex = 0;
  //check if the left child Or the right child has a valid index
  int leftChildIndex = getLeftChildIndex(parentIndex);
  int rigthChildIndex = getRightChildIndex(parentIndex);

  while(isValidIndex(leftChildIndex) && compare(this->heap[leftChildIndex], this->heap[parentIndex]) || isValidIndex(rigthChildIndex) && compare(this->heap[rigthChildIndex], this->heap[parentIndex])) {
 
    //since any of the conditions on top can be true and the left is checked first the right might not be valid therfor we check the right again and extract the index of the greator value
    int greatorValueIndex = (isValidIndex(rigthChildIndex) && compare(this->heap[rigthChildIndex], this->heap[leftChildIndex])) ? 
    rigthChildIndex : leftChildIndex;

    swap(this->heap[greatorValueIndex], this->heap[parentIndex]);
    
    parentIndex = greatorValueIndex;
    leftChildIndex = getLeftChildIndex(parentIndex);
    rigthChildIndex = getRightChildIndex(parentIndex);
  }
}


void printElements() {
  cout << "----------------------- start" << endl;
  for (auto item: this->heap) {
    
    cout << item << endl;
   
  }
   cout << "----------------------- end" << endl;
}
//private variable
vector<element> heap;
};

int main() {
  std::cout << "Hello World!\n";
  unique_ptr<PriorityQueue<int>> priorityQueue = make_unique<PriorityQueue<int>>(PriorityQueue<int>());
    priorityQueue->push(15);
    priorityQueue->push(12);
    priorityQueue->push(50);
    priorityQueue->push(7);
    priorityQueue->push(40);
    priorityQueue->push(22);

  while(!priorityQueue->isEmpty()) {
  cout << priorityQueue->pop() << endl;
  }
}
