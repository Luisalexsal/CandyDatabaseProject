// ============================================
// HW#: HW8 Hash Table
// Name: Alex Salmeron
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
{}

htable::~htable()
{}
// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{
  //My key function was done in the constructor
  //key = (ascii(asci of the first letter of the name) + access + sam + alex)*nameLength
   return (key % TSIZE);
}

// adds the element to the table and returns slot#
int htable::add(el_t element)
{
  int slot = hash(element.key);  // hash with the key part
  table[slot].addRear(element);
  return slot;// ** Note that this means adding the element to a slist in the slot
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{ 
 int slot = hash(skey); // hash with skey
 el_t selement(skey,"");  // this is the element to look for in slist
  // initialize selement with just the skey
 selement = table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 return selement; // return the found element from here (it could be blank)
}


// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < TSIZE; i++)
    { cout << i << ":" ;   
      table[i].displayAll(); // call slist's displayAll
    }
}
//displays link of where to buy the candy
void htable::displayLink(el_t element)
{
  cout << endl << "==================================================" << endl;

  cout << "Tha url for " << element.name << " is: " << element.link << endl;
  cout << endl << "==================================================" << endl <<endl;

}
//displays attributes of the candy
void htable::displayValues(el_t element)
{
  cout << endl << "==================================================" << endl;
  
  cout << "Name: " << element.name << endl;
  cout << "Accessibility: " << element.access << " (scale 1-5)" << endl;
  cout << "Personal Enjoyment: " << element.alexe << " (scale 1-5)" <<endl;
  cout << "Sam's Enjoyment: " << element.same << " (scale 1-5)";

  cout << endl << "==================================================" << endl << endl;

}
