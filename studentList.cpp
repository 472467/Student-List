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
STUDENT translateMove(char* input, vector<STUDENT>* v);
//int studentNum = 0;

int main(){
	vector <STUDENT>* v;
	char input[30];
	for(int x = 0; x < 30; x++){
		input[x]= '\0';
	}
	while(true){
		cout << "Welcome to the student directory. Please 'ADD', 'PRINT'(prints list of ALL students) or 'DELETE' a student. Type EXIT to quit.\n";
		cin.clear();
		cin.sync();//cleans cin
		cin.getline(input, 30);
		STUDENT structLoc = translateMove(input, v);
		
	}
	
	
}

STUDENT translateMove(char* input, vector<STUDENT>* v){
	char in[100];
	system("clear");
	if(strcasecmp(input, "ADD") == 0){
		STUDENT s;
		char tmp [100];
		
		cout << "Input first name: ";
		cin.getline(in, 100);
		strcpy(s.fName, in);
		
		cout << "Input last name: ";
		cin.getline(in, 100);
		strcpy(s.lName, in);

		int id = 0;
		cout << "Input ID num: ";
		cin.getline(tmp, 100);
		istringstream buffer(tmp);
		buffer >> id;
		s.id = id;

		float grade = 0;
		cout << "Input GPA: ";
		cin.getline(tmp, 100);
		istringstream buffer2(tmp);
		buffer2 >> grade;
		s.gpa = grade;

		cin.ignore();
		
		(*v).push_back(s);
	}else if(strcasecmp(input, "PRINT") == 0){
	  for(vector<STUDENT>::iterator it = (*v).begin(); it != (*v).end(); ++it){
	    cout << "Name: " << (*it).fName << " " << (*it).lName;
	    cout << "ID: " << (*it).id;
	    cout << "GPA: " << (*it).gpa;
	  }
	    
	}else if(strcasecmp(input, "DELETE") == 0){
	}else if(strcasecmp(input, "EXIT") == 0){
		exit(0);
	}else{
	  
		STUDENT error;
		strcpy(error.fName, '\0');
		return error;
	}
}
