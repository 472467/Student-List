/* WRITTEN BY BRENDAN
*/

#include <iostream>
#include <string>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

bool translateMove(char* input);
struct STUDENT{
	char fName [100];
	char lName [100];
	int id;
	float gpa;
}

STUDENT[99999];
int studentNum = 0;

int main(){
	char input[30];
	for(int x = 0; x < 30; x++){
		input[x]= '\0';
	}
	while(true){
		system("clear");
		cout << "Welcome to the student directory. Please 'ADD', 'PRINT'(prints list of ALL students) or 'DELETE' a student. Type EXIT to quit.\n";
		cin.clear();
		cin.sync();//cleans cin 
		cin.getline(input, 30);
		translateMove(input);
	}
	
	
}

bool translateMove(char* input){
	if(strcasecmp(input, "ADD") == 0){
		cout << "add\nInput: " << input << "\n";
	}else if(strcasecmp(input, "PRINT") == 0){
		cout << "print\n";
	}else if(strcasecmp(input, "DELETE") == 0){
		cout << "delete\n";
	}else if(strcasecmp(input, "EXIT") == 0){
		exit(0);
	}else{
		return false;
	}
}