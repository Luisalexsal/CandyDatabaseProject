//CS311 Yoshii
// =======================================================
// HW#: HW3P1 llist
// Your name: Alex Salmeron
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================
#include "elem.h"
// alias el_t : element type definition
//typedef Node *Nodeptr;
//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist: public el_t
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Check if Link List is Empty Returns true if it is
  bool isEmpty();
    
  //Displays The Element for each Node in the List
  void displayAll();

  //Appends a Node to the front
  void addFront(el_t);
    
  //Appends a Node to the rear
  void addRear(el_t);

  //Deletes the front Node
  void deleteFront(el_t&);
    
  //Deletes the rear Node
  void deleteRear(el_t&);
    
  //Deletes the Ith Node
  void deleteIth(int, el_t&);  // calls moveTo

  //Inserts Node at the Ith Position    
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
