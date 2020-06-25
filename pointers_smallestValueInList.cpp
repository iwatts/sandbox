#include <iostream>
#include <cstdlib>
using namespace std;

class IntNode {
public:
   IntNode(int dataInit = 0, IntNode* nextLoc = nullptr);
   void InsertAfter(IntNode* nodePtr);
   IntNode* GetNext();
   void PrintNodeData();
   int GetDataVal();
private:
   int dataVal;
   IntNode* nextNodePtr;
};

// Constructor
IntNode::IntNode(int dataInit, IntNode* nextLoc) {
   this->dataVal = dataInit;
   this->nextNodePtr = nextLoc;

   return;
}

/* Insert node after this node.
 * Before: this -- next
 * After:  this -- node -- next
 */
void IntNode::InsertAfter(IntNode* nodeLoc) {
   IntNode* tmpNext = nullptr;
   
   tmpNext = this->nextNodePtr;    // Remember next
   this->nextNodePtr = nodeLoc;    // this -- node -- ?
   nodeLoc->nextNodePtr = tmpNext; // this -- node -- next

   return;
}

// Print dataVal
void IntNode::PrintNodeData() {
   cout << this->dataVal << endl;

   return;
}

// Grab location pointed by nextNodePtr
IntNode* IntNode::GetNext() {
   return this->nextNodePtr;
}

int IntNode::GetDataVal() {
   return this->dataVal;
}

int main() {
   IntNode* headObj = nullptr; // Create intNode objects
   IntNode* currObj = nullptr;
   IntNode* lastObj = nullptr;
   int i = 0;            
   
   headObj = new IntNode(-1);        // Front of nodes list
   lastObj = headObj;
   
   for (i = 0; i < 20; ++i) {        // Append 20 rand nums
      currObj = new IntNode(rand());
      
      lastObj->InsertAfter(currObj); // Append curr
      lastObj = currObj;             // Curr is the new last item
   }
   
   currObj = headObj;                // Print the list
   currObj = currObj->GetNext();
   while (currObj != nullptr) {
      currObj->PrintNodeData();
      currObj = currObj->GetNext();
   }

   // FIXME: Loop through list and find minimum dataVal
   currObj = headObj;
   currObj = currObj->GetNext();
   while (currObj != nullptr) {
      if(lastObj->GetDataVal() > currObj->GetDataVal()) {
         lastObj = currObj;
      }
      currObj = currObj->GetNext();
   }
   cout << endl;
   lastObj->PrintNodeData();
   
   return 0;
}
