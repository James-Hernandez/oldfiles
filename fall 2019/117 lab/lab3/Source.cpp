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
#include <array>

using namespace std;

struct node {//created a structure that will hold the values for each node
	char id;
	string type;
	double value;

};

struct node symbol_t[100];//an array that will hold 100 nodes

int Exp(), Term(), Exp2(int), Term2(int), Fact(), Fact2(int), Num();

//New functions that were introduced to accomodate the new file we are reading
void Declorations();

int Decloration(string);

void Statements();

void Statement(string);

void PrintSt();

void AssignSt(string);
///////////////////////////////////////////////

string prog; //string for reading 1-line input expression (program)
int indexx = 0; //global index for program string
string num_str = "";
string word;//globally declared
string id;//gloabal
int finalResult;
ifstream file;//globally declared
int symbol_Tindex = 0;// start the symbol tables index at 0 for first input into the array

int main(int argc, const char **argv)
{

	//Reading the File and taking in the first word
	string  fileName;
	fileName = "data2.txt";
	file.open(fileName.c_str());
	file >> word;
	// //// ///// /////// ////////// ///////
	cout << word << endl;

	if (word == "program") {//if the first word that it reads is program than execute functions Declorations and Statements

		Declorations();
		Statements();
	}
	else {
		//exit(1);
		cout << "hi";// else we cout hi, should be exit the program but had to test
		//return 0;
	}

	cout << endl;// here we are printing the values that are in the symbol table on their own line
	//this will be executed last
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "answers from form are: " << endl;
	for (int i = 0; i < 3; i++) {
		cout << symbol_t[i].value << " " << endl;
	}
	cout << finalResult << endl;
	cout << endl;

	system("pause");
	return 0;
}



void Declorations() {
	//read a word
	file >> word;//read the word 
	cout << word << " from Declorationss" << endl;
	if (word == "begin") {//if the word is begin than what would have happened is exitting the program
		return;
	}
	else if (word == "int" || word == "double") {//we want the word we are reading in to be the data type of int or double
		//and if so then what we are going to do is throw that word into the the decloration function.
		Decloration(word);
		//cout << word << endl;

	}
	
	Declorations();// we make a recursive call to the declorations function so that it keeps reading in the next word.
	


}


int Decloration(string wordT) {//change into while loop
	/*
	so here we make a loop that to where the word that is being passed through does not end in the ';' to read in the next word
	print out the word and than by using the global symbol table index to put in the word just read to placed in the index's 
	id, type. And then we increement the symbol tables index again to move to the next element into the array
	then make a recursive call back to the decloration that will have the same type.
	*/
	if (word.at(word.length() - 1) != ';') {
		file >> word;
		cout << word << "from decloration" << endl;
		symbol_t[symbol_Tindex].id = word.at(0);
		symbol_t[symbol_Tindex].type = wordT;
		symbol_Tindex++;
		Decloration(wordT);
		
	}

	else {
		//then if not return
		return 0;
	}
	
	
	
	


}

void Statements() {
	/*
	Once we are in statments and we were called into the function from main.
	here we are going to read in a word  and if the word is equal to end then what we will do return
	if there is anthing else we will execute statment passing in the word we just read in and then after the if else cases
	have been done, we will then execute statments again recursively
	*/
	file >> word;
	if (word == "end") {
		return;
	}
	else {
		Statement(word);
	}
	Statements();

}

void Statement(string word) {
	/*
	in the function we will be taking in the a word that was passed in from Statements and if the word that is being brought in 
	is print then we will execute the print stament function else we will see if the word being brought in is a single letter 
	a,b,c,etc... we will then assign statment to the word that was brought in
	*/
	if (word == "print") {
		PrintSt();//print string
	}
	else if (word.length() == 1 && isalpha(word[0])) {
		cout << "statement: " << word << endl;
		AssignSt(word);//assign strng with id

	}
	else {
		//syntax error
	}
}

void PrintSt() {
	/*
	okay so what we are doing here is first creating a temp word to make equal to the most current word that word is holding
	next we will read iin the next word and check if to see if its a character instead of an integer, and if so we basically
	search the array for that character and if we find it, then we will print out its value.
	else what would happen is meaing we read in the whole expression '2-3..' we will make prog equal to current word and 
	and call Exp();
	*/
	string temp_word = word;
	file >> word;
	if (isalpha(word[0])) {
		for (int i = 0; i < 100; i++) {
			if (symbol_t[i].id == word[0]) {
				cout << symbol_t[i].value;
			}
		}
	}
	else {//expression case
		//here we have to get back one space.
		cout << "calculating expression" << endl;
		prog = word;
		cout << Exp();
	}

}



void AssignSt(string wordT) {
	/*
	firstly we read in the word and if the word is a '=' meaning we haave reached the expression then we will read in the next 
	word which will be the expression, then we set prog equal to the word that was just read and then we have to reset indexx
	back to zero because it was moved during other executions so we just reset, next we create a for loop to traverse the array
	and if we find the id of the word that was passed into the function we will break from the loop still retainging the 
	index to which i broke from.
	*/
	file >> word;
		if (word == "=") {
			file >> word;
			prog = word;
			indexx = 0;
			int i = 0;//index of wordT
				for (i = 0; i < 100; i++) {
					if (symbol_t[i].id == wordT[0]) {// the found part in here
						//symbol_t[symbol_Tindex].value = temp;
						break;
					}
				}
				/*
				now as we are reading in the assignment statments  we first have to see if its the kind of assignment statement we 
				are looking for 'x = y;' sort of thing. then we will go through the array again and find the answer from the previous
				statemtns and give that value also to the new variables value.
				*/
				cout << "asssign to another variable " << word.length() << endl;
			if (word.length() == 2 && isalpha(word[0])) {
				for (int j = 0; j < 100; j++) {
					if (symbol_t[j].id == word[0]) {// the found part in here
						//symbol_t[symbol_Tindex].value = temp;
						symbol_t[i].value = symbol_t[j].value;
					}
				}
			}
			else {
				/*
				else we are making a temp varialbe and making it equal to exp and making that its new value.
				*/
				int temp = Exp();
				
				symbol_t[i].value = temp;

				

				cout << "--" << wordT << "=" << word <<  endl;
				cout << "expression answer" << temp << endl;
			}

			
			
		}
		else {
			cout << "syntax error from AssignSt" << endl;
		}

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

	//cout << "random: " << result << endl;
	finalResult = result;
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

		num_str = "";
		while ((a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9') && indexx < prog.length()) {

			num_str += a;
			a = prog.at(indexx++);
		}
		indexx--;
		num_str += a;

		return atoi(&num_str.at(0));  //converts a char to a numeric number and return
		
		//return atoi(&a);//this will convert the string char to integer

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


