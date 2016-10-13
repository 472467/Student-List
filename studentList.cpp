/* WRITTEN BY BRENDAN
PROGRAM THAT YOU INPUT STUDENT INFO AND STUFF
NO GLOBAL VARIABLES THIS TIME
*/

#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;


struct STUDENT{
	char fName [100];
	char lName [100];
	int id;
	float gpa;
};
bool translateMove(char* input, vector<STUDENT*>* v);
//int studentNum = 0;

int main(){
  system("clear");//initially clears command line 
  vector <STUDENT*>* v = new vector<STUDENT*>;//pointer of pointers
	char input[30];
	for(int x = 0; x < 30; x++){
		input[x]= '\0';
	}
	while(true){
		cout << "Welcome to the student directory. Please 'ADD', 'PRINT'(prints list of ALL students) or 'DELETE' a student. Type EXIT to quit.\n";
		cin.clear();
		cin.sync();//cleans cin
		cin.getline(input, 30);
		translateMove(input, v);
		
	}
	
	
}

bool translateMove(char* input, vector<STUDENT*>* v){//converts input into a command that does stuff
	char in[100];
	if(strcasecmp(input, "ADD") == 0){//ignores capital letters
	  system("clear");//clears if statements to make it easy to delete after printing
	  STUDENT *s = new STUDENT();
	  char tmp [100];//work around for cin>> mixing with cin.getline segementation faults
		
		cout << "Input first name: ";
		cin.getline(in, 100);
		strcpy(s->fName, in);//uses arrow because it is a STUDENT pointer
		
		cout << "Input last name: ";
		cin.getline(in, 100);
		strcpy(s->lName, in);

		int id= 0;
		cout << "Input ID num: ";
		cin.getline(tmp, 100);
		istringstream buffer(tmp);//gets num as int first then converts it into an int
		buffer >> id;
		s->id = id;
		
		float grade = 0;
		cout << "Input GPA: ";
		cin.getline(tmp, 100);
		istringstream buffer2(tmp);//same here
		buffer2 >> grade;
		s->gpa = grade;
		
		(*v).push_back(s);//pushes it to end of vector
		return true;
	}else if(strcasecmp(input, "PRINT") == 0){
	  for(vector<STUDENT*>::iterator it = (*v).begin(); it != (*v).end(); ++it){//iterates through the vector
	    system("clear");
	    cout << fixed << showpoint;
	    cout << setprecision(2);//sets deicmal to be 5.00 even if just 5
	    cout << "\nName: " << (*(*it)).lName << ", " << (*it)->fName;
	    cout << "\nID: " << (*it)->id;
	    cout << "\nGPA: " << (*it)->gpa << "\n\n";//serparates the peopel
	  }
	    
	}else if(strcasecmp(input, "DELETE") == 0){
	  cout << "Please input the ID of the student you wish to delete: ";
	  cin.getline(in,100);
	  stringstream ss(in);//converts input to an int, to avoid that error
	  int delID = 0;
	  ss >> delID;
	  for(vector<STUDENT*>::iterator it = (*v).begin(); it != (*v).end(); ++it){
	    if(delID ==(*it)->id){
	      cout << "test" << endl;
	      (*v).erase(it);
	      break;//breaks to avoid iterating to an erased student
	    }
	  }
	  system("clear");//clears after so you can print, then delete the student you want to kill
	  return true;
	}else if(strcasecmp(input, "EXIT") == 0){
	  exit(0);//ends program
	}else{
	  return false;
	}
}
