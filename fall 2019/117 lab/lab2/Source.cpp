//// Interpreter for simplified infix expression with {+, -, *, / } operations;
//// Keyboard input, single digit numbers only and no spaces are allowed;
//// compile: $>g++ prog1.cpp
//// run with: >2+3*4/2+3+4*2
//

// okay james for this rewrite with a while loop
#include <cstdlib> //for atoi()
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>// so i can use the remove function
#include <cmath>//to use the pow
#include <math.h>

using namespace std;
int Exp(), Term(), Exp2(int), Term2(int), Fact(), Fact2(int), Num();
string prog; //string for reading 1-line input expression (program)
int indexx = 0; //global index for program string


int main(int argc, const char **argv)
{
	string line;// here we have handler to tke in the string from file
	ifstream infile;// we will open the the file here
	infile.open("data1.txt");//opening the file
	//openFile("text.txt");
	while (!infile.eof()) {// while the file hsa not reached the end continue with the code
		getline(infile, line);//get the line from infle and put it into line
		cout << line << endl;// here we will cout to see if the line is correct
	}
	int count = 0;
	/*
	for (int i = 0; i < line.length(); i++) {// now we will get rid of the white space by using a for loop for the entire lenth
		if (line[i] == ' ') {// if we encounter a whitespace we will earase the space for a single space
			line.erase(i, 1);// here will are earsing

		}

	}*/
	line.erase(remove(line.begin(), line.end(), ' '), line.end());// this removes all spaces from the line
	cout << line;// here we output the string so that we can see the white space is gone

	infile.close();//close the file 

	cout << ">";
	
	prog = line;
	cout << "result= " << Exp() << endl;

	system("pause");
	return 0;
}
int Exp()
{
	cout << "Exp()" << endl;
	return Exp2(Term());
}
int Term()
{
	cout << "Term()" << endl;
	return Term2(Num());//this will handle the 2nd part of the expression
}

int Num() {
	//read a char
	//skip the spaces
	//if parantheses
	//recursive call
	//else
	//convert to numeric value and return it
	/*
	
	*/
	cout << "num()" << endl;
	return Fact2(Fact());
}

int Exp2(int inp)
{
	cout << "Exp2" << endl;
	int result = inp;
	if (indexx < prog.length()) //if not the end of program string
	{
		char a = prog.at(indexx++); //get one chr from program string
		while (a == ' ' && (indexx < prog.length()))
			a = prog.at(indexx++);
		if (indexx > prog.length()) return result;//
		if (a == '+')
			result = Exp2(result + Term()); //handles T+T
		else if (a == '-')
			result = Exp2(result - Term()); //handles T-T
	}
	return result;
}
int Term2(int inp)
{
	cout << "Term2" << endl;
	int result = inp;
	if (indexx < prog.length()) //if not the end of program string
	{
		char a = prog.at(indexx++); //get one chr from program string
		while (a == ' ' && indexx < prog.length())
			a = prog.at(indexx++);
		if (indexx > prog.length()) { 
			return result; 
		}//
		if (a == '*')
			result = Term2(result * Fact()); //handles consecutive * operators
		else if (a == '/')
			result = Term2(result / Fact()); //handles consecutive / operators
		else if (a == '+' || a == '-' || a == ')') //if + or -, get back one position
			indexx--;
	}
	return result;
}

int Fact()
{
	/*
	cout << "fact()" << endl;
	char a = prog.at(indexx++); //get one chr from program string
	return atoi(&a); //converts a char to a numeric number and return
	*/
	cout << "Fact()" << endl;
	if (indexx < prog.length())//to make sure that indexx placement is less than string size
	{
		char a = prog.at(indexx++);// assigns a to indexx placement
		while (a == ' ' && (indexx < prog.length())) {//goes through to scan and assign a to char
			a = prog.at(indexx++);
		}
		if (a == '(') {// if the character ( is found recall expression function
			return Exp();
		}
		return atoi(&a);//this will convert the string char to integer

	}
	/*return Fact2(Num());*/
}

int Fact2(int inp) {
	//read a char
	// skip the spaces
	//if '^' symbol
	//recursive call
	//else indexx--
	cout << "fact2" << endl;
	int result = inp;
	if (indexx < prog.length()) //to make sure that indexx placement is less than string size
	{ 
		char a = prog.at(indexx++);// assigns a to indexx placement
	while (a == ' ' && (indexx < prog.length())) {//goes through to scan and assign a to char
		a = prog.at(indexx++);
	}

	if (indexx > prog.length()) { 
		return result;//if the indexx goes beyond string it has finished and returns result
	}

	if (a == '(') { result = result * Fact2(Exp()); }//this will be the handler for the parenthese equation

	else if (a == '^') {//n
		result = pow(result, Num());
	}//n
	else if (a == '+' || a == '-' || a == '*' || a == '/' || a == ')') {
		indexx--;// okay so we have this for the addition of the ')' so that when it encounters the parenteses it will back off and know it has completed the expression
	}
		
	}
	return result;
}


