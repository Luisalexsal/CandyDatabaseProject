// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Alex Salmeron
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{}


// positions always start at 1
//searches the list for a certain element
int slist::search(el_t key)
{
  int c = 1;
  // int c=1;
  Node *P;
  P = Front;

    if(isEmpty())
      {
        return 0;
      }
    else
      {
        while(P!=NULL)
          {
            if(P->Elem == key)
              {
                return c;
              }
	    else if(P==NULL)
	      {
		break;
	      }
            else
              {
		P=P->Next;
		c++;
               
              }
	    
          }
	if(P==NULL)
	  {
	    return 0;
	  }
      }
    return 0;
  
}
el_t slist::search2(el_t key)
{
  int c = 1;
  // int c=1;
  Node *P;
  P = Front;
  el_t blank;
  if(isEmpty())
    {
      return blank;
    }
  else
    {
      while(P!=NULL)
	{
	  if(P->Elem == key)
	    {
	      return P->Elem;
	    }
	  else if(P==NULL)
	    {
	      break;
	    }
	  else
	    {
	      P=P->Next;
	      c++;

	    }

	}
      if(P==NULL)
	{
	  return blank;
	}
    }
  return blank;

}

//replaces the element in a specific node
// don't forget to throw OutOfRange for bad pos 
void slist::replace(el_t element, int pos)
{
  if(pos==0 || pos >Count)
    {
      throw OutOfRange();
    }
  else
    {
      Node *P;
      P = Front;
      moveTo(pos,P);
      P->Elem = element; 
    }
}
//overloads the == operator to check if two lists are the same
bool slist::operator==(const slist& OtherOne)
{
  if(this->Count != OtherOne.Count)
    {
      return false;
    }
  else
    {
      Node *L1;
      Node *L2;
      L1 = this->Front;
      L2 = OtherOne.Front;
      while(L1!=NULL)
	{
	  if(L1->Elem == L2->Elem)
	    {
	      L1= L1->Next;
	      L2 = L2->Next;
	    }
	  else
	    {
	      return false;
	    }
	}
      return true;
    }
  // if not the same length, return false
  // if the same lengths,
  //  check each node to see if the elements are the same
}
