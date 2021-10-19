// CS311 Alex Salmeron
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  key = -1;  // cannot be 0 because 0 is a valid key
  name = link = "";
  access = same = alexe = 0;
}

// initializing constructor to create an el_t object 
el_t::el_t(string aname, int accessv, int sam, int alex, string url)
{  
  name = aname;
  access = accessv;
  same = sam;
  alexe = alex;
  link = url;
  
  char c;
  c = aname[0];
  int asci;
  asci = int(c);
  int multiplier = name.length();
 
  //CREATES MY KEY TO BE HASHED
  key = (asci + accessv + sam + alex)*multiplier;
}
el_t::el_t(int akey,string aname)
{
  key = akey;
  name = aname;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key) return true; else return false;
}

// overload != for search based on the key part only
bool el_t::operator!=(el_t OtherOne)
{
  if (key != OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.key << "+" << E.name;
  return os;  
}
//EXPLAINS ACCESSIBILITY
void el_t::explainAccess()
{
  cout << endl << "===================================================" << endl<< endl;
  cout << "Accessibility is a value that lets you know how easy or difficult a certain candy will be to find." << endl;
  cout << "Accessibility of 0: impossible to find today" <<endl;
  cout << "Accessibility of 1: Very rare or limited edition" <<endl;
  cout << "Accessibility of 2: Not available in the USA and I must go to Mexico to buy it" <<endl;
  cout << "Accessibility of 3: Only found online" <<endl;
  cout << "Accessibility of 4: Available at some stores near me" <<endl;
  cout << "Accessibility of 5: Available virtually everywhere" <<endl;
  cout << endl << "======================================================" << endl << endl; 
}  
