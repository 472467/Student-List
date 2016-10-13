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
        system("clear");
	vector <STUDENT*>* v = new vector<STUDENT*>;
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

bool translateMove(char* input, vector<STUDENT*>* v){
	char in[100];
	if(strcasecmp(input, "ADD") == 0){
	  system("clear");
	  STUDENT *s = new STUDENT();
		char tmp [100];
		
		cout << "Input first name: ";
		cin.getline(in, 100);
		strcpy(s->fName, in);
		
		cout << "Input last name: ";
		cin.getline(in, 100);
		strcpy(s->lName, in);

		int id= 0;
		cout << "Input ID num: ";
		cin.getline(tmp, 100);
		istringstream buffer(tmp);
		buffer >> id;
		s->id = id;
		
		float grade = 0;
		cout << "Input GPA: ";
		cin.getline(tmp, 100);
		istringstream buffer2(tmp);
		buffer2 >> grade;
		s->gpa = grade;
		
		(*v).push_back(s);
		return true;
	}else if(strcasecmp(input, "PRINT") == 0){
	  for(vector<STUDENT*>::iterator it = (*v).begin(); it != (*v).end(); ++it){
	    system("clear");
	    cout << "\nName: " << (*(*it)).lName << ", " << (*it)->fName;
	    cout << "\nID: " << (*it)->id;
	    cout << "\nGPA: " << (*it)->gpa << "\n\n";
	  }
	    
	}else if(strcasecmp(input, "DELETE") == 0){
	  cout << "Please input the ID of the student you wish to delete: ";
	  cin.getline(in,100);
	  stringstream ss(in);
	  int delID = 0;
	  ss >> delID;
	  for(vector<STUDENT*>::iterator it = (*v).begin(); it != (*v).end(); ++it){
	    if(delID ==(*it)->id){
	      cout << "test" << endl;
	      (*v).erase(it);
	      break;
	    }
	  }
	  system("clear");
	  return true;
	}else if(strcasecmp(input, "EXIT") == 0){
		exit(0);
	}else{
	  return false;
	}
}
