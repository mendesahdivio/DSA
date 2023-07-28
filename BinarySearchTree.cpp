#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Node {
int data;
Node* leftNode;
Node* rightNode;
Node(int data) {
  this->data = data;
  this->rightNode = NULL;
  this->leftNode = NULL;
}
};

class BinarySearchTree {

public:
//constructor
BinarySearchTree() {
  this->rootNode = NULL;
}


//returns value of RootNode pointer
Node fecthRoot() {
  return *rootNode;
}


//retruns the Node pointer itself
Node* fecthRoot() {
  return rootNode;
}


//Insert Node Into The Tree 
//for a balanced binary search tree we need to make sure the parent or root node is grater then the other child nodes
void insert(const int& data) {
  Node* newNode = createNewNode(data);
  //base condition if root node is null update it to the first node
  if (this->rootNode == NULL) {
   this->rootNode = newNode;
    return;
  }

  Node* visitingNode = this->rootNode;

  while(true) {
    if (data > visitingNode->data) {
      //go right
      //check if the right node is empty

      if (!visitingNode->rightNode) {
        visitingNode->rightNode = newNode;
        return;
      }
    
        visitingNode = visitingNode->rightNode;
      
      
    }else {
      //go left

        if (!visitingNode->leftNode) {
        visitingNode->leftNode = newNode;
        return;
        }

       visitingNode = visitingNode->leftNode;
       
    }
  }
  
}




//LOOK UP TO FIND NODE
bool lookUp(int data) {
  //base condition
  if(this->rootNode == NULL) {
    return false;
  }

  Node * visitingNode = this->rootNode;
  while(true) {
    if (visitingNode->data == data) {
      return true;
    }

    if(data > visitingNode->data) {
      //move to right
      if(visitingNode->rightNode == NULL) {
        return false;
      }

      visitingNode = visitingNode->rightNode;
      
    } else {
      //move to the left
      if(visitingNode->leftNode == NULL) {
        return false;
      }

      visitingNode = visitingNode->leftNode;
      
    }
    
  }
}




//BREATH FIRST SEARCH
vector<int> breathFirstSearch() {
  Node* currentNode = this->rootNode;
  vector<int> result = {};
  //add the first item that is the root node of the tree to the queue
  queue<Node*> queueOfNodes;
  queueOfNodes.push(currentNode);

  //checks if the queue is empty
  while (queueOfNodes.size() > 0) {
    currentNode = queueOfNodes.front();
    queueOfNodes.pop();

    cout << currentNode-> data << endl;

    result.push_back(currentNode->data);

    if(currentNode->leftNode != NULL) {
      queueOfNodes.push(currentNode->leftNode);
    }


    if(currentNode->rightNode != NULL) {
      queueOfNodes.push(currentNode->rightNode);
    }

  }

  return result;

}





//BREATH FIRST SEARCH RECURSIVE APPROACH
vector<int> breathFirstSearchR(queue<Node*>& queueOfItems, vector<int> outPut) {
  if (queueOfItems.size() == 0){
    return outPut;
  }

  Node* currentNode = queueOfItems.front();
  
  queueOfItems.pop();
  outPut.push_back(currentNode->data);
  
  if (currentNode->leftNode != NULL) {
     queueOfItems.push(currentNode->leftNode);
  }


  if(currentNode->rightNode != NULL) {
    queueOfItems.push(currentNode->rightNode);
  }
  
  return breathFirstSearchR(queueOfItems, outPut);
}





//MARK: - DEPTH FIRST SEARCH
//returns a tree in a sorted array or list
void depthFirstSearchInOrder(Node* node, vector<int>& nodeValues) {
  if (node->leftNode) {
    depthFirstSearchInOrder(node->leftNode, nodeValues);
  }

  nodeValues.push_back(node->data);

  if (node->rightNode) {
    depthFirstSearchInOrder(node->rightNode, nodeValues);
  }
}




 private:
Node* rootNode;

Node* createNewNode(const int& data) {
  Node* newNode = new Node(data);
  return newNode;
}

};

int main() {
  std::cout << "Hello World!\n";

  BinarySearchTree* tree = new BinarySearchTree();
  // tree->insert(10);
  // tree->insert(100);
  // tree->insert(9);
  // tree->insert(200);
  // tree->insert(6);


  tree->insert(9);
  tree->insert(4);
  tree->insert(6);
  tree->insert(20);
  tree->insert(170);
  tree->insert(15);
  tree->insert(1);
  
 // Node returned =  tree->fecthRoot();
  // cout << returned.data << endl;
  // cout << returned.leftNode->data << endl;
  // cout << returned.rightNode->data << endl;

  //bool val = tree->lookUp(6);

  vector<int> items = tree->breathFirstSearch();
  //cout  << val << endl

  for (auto item: items) {
    cout << item << endl;
  }
  delete tree;
}
