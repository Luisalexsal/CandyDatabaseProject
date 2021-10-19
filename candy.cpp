// Name: **
// File type: client candy database
//===========================================
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
#include "htable.h"

int main()
{
  string name,fname,url; //Name of Candy ; File Name ; Url of candy
  int access,sam,alex; //Accessibility Level ; Sam's EnJoyment ; Alex's Enjoyment
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname
  el_t badelem; // Bad element to compare
  htable h; 
  while (fin >> name)  // WHILE I CAN READ THE NAME CREATE MY HASH TABLE
    {
      fin >> access >> sam >> alex >> url;
      el_t temp(name,access,sam,alex,url); //CANDY ELEMENT
      h.add(temp);
    }
  fin.close();
  h.displayTable();
  int input;
  el_t temp1;

  //MENU TABLE
  cout << endl << "==================================================" << endl << endl; 
  cout << "To display a candies attributes...Enter 1" << endl;
  cout << "To display a candies url...Enter 2" << endl;
  cout << "To see extra details on Accessibility...Enter 3" << endl;
  cout << "To add a candy...Enter 4" << endl;
  cout << "To display the database...Enter 5" << endl;
  cout << "Otherwise enter any other number to exit" << endl;
  cin >> input;
  cout << endl << "==================================================" << endl << endl;

  
  while(input<6 && input>0)
    {
      if(input == 1)//DISPLAYS CANDY ATTRIBUTE BASED ON KEY
	{
	  int input1;
	  cout << "Enter a key... Or enter -1 to stop: ";
	  cin >> input1;
	  while (input1 != -1)
	    {
	      temp1 = h.find(input1);
	      if(temp1 == badelem)//ERROR IF THEY ENTER FAULTY KEY
		{
		  cout << "Error entered a faulty key." << endl;
		}
	      else
		{
		  h.displayValues(temp1);	      
		}
	      cout << "Enter a key... Or enter -1 to stop: ";
	      cin >> input1; 
	    }
	}
      else if(input == 2)//DISPLAYS CANDY URL BASED ON KEY
	{
	  int input1;
	  cout << "Enter a key... Or enter -1 to stop: ";
	  cin >> input1;
	  while (input1 != -1)
	    {
	      temp1 = h.find(input1);
	      if(temp1 == badelem)
		{
		  cout << "Error entered a faulty key." << endl;//ERROR IF THEY ENTER A FAULTY KEY
		}
	      else
		{
		  h.displayLink(temp1);
		}
	      cout << "Enter a key... Or enter -1 to stop: ";
	      cin >> input1;
	    }
	}
      else if(input == 3)//GIVES EXPLANATION OF THE ACCESSIBILITY VALUES
	{
	  badelem.explainAccess();
	}
      
      else if(input == 5)//DISPLAYS HASH TABLE
	{
	  h.displayTable();
	}
      else if(input == 4)//ADDS A NEW VALUE TO THE TEXT FILE AND TO THE HASH TABLE
	{
	  string tempName,tempLink;
	  int tempAccess,tempSam,tempAlex;
	  cout << endl << endl << "==========================================" << endl << endl;
	  cout << "Enter Candy Name: ";
	  cin >> tempName;
	  cout << endl << "Enter Accessibility: ";
	  cin >> tempAccess;
	  cout << endl << "Enter Sam's enjoyment: ";
	  cin >> tempSam;
	  cout << endl << "Enter Alex's enjoyment: ";
	  cin >> tempAlex;
	  cout << endl << "Enter url: ";
	  cin >> tempLink;
	  cout << endl;
	  cout << endl << "==================================================" << endl << endl;

	  ofstream fout;
	  fout.open(fname.c_str(),std::ios_base::app);
	  fout << tempName << " " << tempAccess << " " << tempSam << " " << tempAlex << " " << tempLink << endl;
	  el_t temp(tempName,tempAccess,tempSam,tempAlex,tempLink);
	  h.add(temp);
	}
      cout << endl << "==================================================" << endl << endl;

      cout << "To display a candies attributes...Enter 1" << endl;
      cout << "To display a candies url...Enter 2" << endl;
      cout << "To see extra details on Accessibility...Enter 3" << endl;
      cout << "To add a candy...Enter 4" << endl;
      cout << "To display the database...Enter 5" << endl;
      cout << "Otherwise enter any other number to exit" << endl;
      cin >> input;
      cout << endl << "==================================================" << endl << endl;

    }
}
