//S311 Alex Salmeron Linked List class

// ====================================================
//HW#: HW3P1 llist
//Your name: Alex Salmeron
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{  Front = Rear = NULL;
  Count = 0;
}

llist::~llist()
{
}
//PURPOSE: Check if the list is empty
//PARAMETER: None
bool llist::isEmpty()
 {
   if(Front==NULL && Rear==NULL && Count==0)
     {
       return true;
     }
   else
     return false;
 } // be sure to check all 3 data members

//PURPOSE: Displays the Elements Of each Node in order
//PARAMETER:Non
void llist::displayAll() 
{
  if(isEmpty())
    {
      cout << "[empty]" << endl;
    }
  else
    {
      Node *P;
      P = Front;
      cout << "[ ";
      while(P!=NULL)
	{	  
	  cout << P->Elem << " ";
	  P=P->Next;
	}
      cout << "]";
      //cout << "]" << " " << "Count: " << Count <<  endl;
      cout << endl;
  }
}  
//PURPOSE:Appends a Node to the Rear of LList
//PARAMETER:Int Element to place in Node
void llist::addRear(el_t NewNum) 
{
  if(isEmpty())//Creates a Link List from scratch
    {
      Front = new Node;
      Rear = Front;;
      Rear->Next = NULL;
      Rear->Elem = NewNum;
      Count++;
    }
  else//Appends the node to the rear of the Linked List
    {
      Rear->Next = new Node;
      Rear->Next->Elem = NewNum;
      Rear = Rear->Next;
      Rear->Next = NULL;
      Count ++;
    }
}
//PURPOSE:Appends a Node to the Front of LList
//PARAMETER:Int Element to place in Node
void llist::addFront(el_t NewNum) 
{
  if(isEmpty())//Creates a Link List from scratch
    {
      Node *P;
      P = new Node;
      Front = P;
      Rear = P;
      P->Next = NULL;
      P->Elem = NewNum;
      Count++;
    }
  else//Appends a Node to the Front of the Linked List
    {
      Node *P;
      P = new Node;
      P->Elem = NewNum;
      P->Next = Front;
      Front = P;
      Count++;
    }

}
//PURPOSE:Deletes Front Node
//PARAMETER:Returns the int Element(through reference) for use
void llist::deleteFront(el_t& OldNum) 
{
  if(isEmpty())//We can't delete an empty List(Throws an Underflow)
    {
      throw Underflow();
    }
  else if(Count==1)//If there is only one element We must clean up our Pointers
    {
      OldNum = Front->Elem;
      delete Front;
      Front = Rear = NULL;
      Count--;
    }
  else//Normal Case that will delete our front element
    {
      OldNum = Front->Elem;
      Node *P;
      P = Front;
      Front = Front->Next;
      delete P;
      Count--;
      P = NULL;
    }
}

//PURPOSE:Deletes Rear Node in LList
//PARAMETER:Returns the int Element(through reference) for use
void llist::deleteRear(el_t& OldNum)
{
  if(isEmpty())//We can't delete an empty List(Throws an Underflow)
    {
      throw Underflow();
    }
  else if(Count==1)//If there is only one element We must clean up our Pointers
    {
      OldNum = Rear->Elem;
      delete Rear;
      Front = Rear = NULL;
      Count--;
    }
  else//Normal Case that will Loop P to one before Rear and then Delete the Rear
    {
      Node *P;
      P = Front;
      while(P->Next!=Rear)
	{
	  P = P->Next;
	}
      OldNum = Rear->Elem;
      delete Rear;
      
      Rear = P;
      Rear->Next =NULL;
      Count--;
    }
}
// Utility Function to move a local pointer to the Ith node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times
  for ( int K = 0;K<(J-1);K++)
    {  
      temp = temp->Next;
    }
  
}

//PURPOSE:Deletes the Node in the Ith position
/*PARAMETER:I is the Position of Node to be deleted and OldNum
Is the element that will be returned(by reference) of the deleted
Node*/
void llist::deleteIth(int I, el_t& OldNum) 
{
  if(I>Count || I==0)//If I is Invalid Throw Error(OutOfRange)
    {
      throw OutOfRange();
    }
  else if(I==1)//If I is the Front call deleteFront
    {
      deleteFront(OldNum);
    }
  else if(I==Count)//If I is the Rear call deleteRear
    {
      deleteRear(OldNum);
    }
  else//Regular Case That will delete the Ith Node
    {
      Node *P;
      P = new Node;
      P = Front;
      moveTo(I-1,P);
      Node *Q;
      Q = new Node;
      Q = P;
      P = P->Next;
      Q->Next = P->Next;
      OldNum = P->Elem;
      delete P;
      P = NULL;
      Count--;
    }
}
//PURPOSE:Creates and inserts a node in the Ith Position
/*PARAMETER:I is the Position of Node to be deleted and NewNum
Is the element that will be used to set a value for our new Node*/

void llist::insertIth(int I, el_t newNum) 
{
  if(isEmpty())//If Our List is Empty Throw Error(Underflow)
    {
      throw Underflow();
    }
  else if(I>(Count+1) || I==0)//If I is Invalid Throw Error(OutOfRange)
    {
      throw OutOfRange();
    }
  else if(I==1)//If I is the Front call deleteFront
    {
      addFront(newNum);
    }
  else if(I==(Count+1))//If I is the Rear call deleteRear
    {
      addRear(newNum);
    }
  else//Regular Case that will Create and Insert at Ith Node
    {
      Node *P;
      P = new Node;
      P = Front;
      moveTo(I-1,P);
      Node *Q;
      Q = new Node;
      Q = P;
      P = P->Next;
      Node *NewNode;
      NewNode = new Node;
      NewNode->Elem = newNum;
      NewNode->Next = P;
      Q->Next = NewNode;
      Count++;
    }

}
//PURPOSE:Sets our Target Linked List to our Source Linked List
//PARAMETER:Our Source Linked List
llist& llist::operator=(const llist& OtherOne)
{  el_t x;
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	this->deleteRear(x);  
      // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  P = P->Next;                         // Go to the next node in OtherOne   
	} 
    }// end of if              
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.
} 
//
//PURPOSE:Copy Constructor for Our Linked list
//PARAMETER:Creates a New list In the Copy of our Original
llist::llist(const llist& Original)
{
  //  this->'s data members need to be initialized here first
  Front = NULL; Rear = NULL; Count = 0;
  //  this-> object has to be built up by allocating new cells
  //  and copying the values from Original into each cell as we did with 
  //  operator= above. To do this,
  // this-> object has to be built up by allocating new cells with OtherOne elements (**)
  Node* P;  // local pointer for OtherOne
  P = Original.Front;
  while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
    {
      this->addRear(P->Elem);    //P’s element is added to this->
      P = P->Next;                         // Go to the next node in OtherOne   
    } 

    //  Nothing to return because this is a constructor.
}



