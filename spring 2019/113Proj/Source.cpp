//By James Hernandez Simulation Program//

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include <cmath>
#include <stdio.h>

using namespace std;
struct block
{
	int valid=0;//0s
	int tag=0;
	int data=0;
	int history=0;
	int dirty = 0;
}blocks[8][2];

int regField[2] = { 0 };
int mem[32] = { 0 };
//
//initalization of memory for every address increment by 5; create for loop to fill the array
//
void memInit() {
	int memory = sizeof(mem);
	for (int i = 0; i < memory; i++) {
		mem[i] = i + 5;
	}
}

//
//funciton for history bit update: two for loops one for set number and one for block nmber pass in set number and current increment"i" block[i][j].history = 0 block[set num][inc] = 1;
//
void HUE(int set, int col) {
	int j = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 2; j++) {
			blocks[i][j].history = 0;

		}

		blocks[set][col].history = 1;

	}
}

//
//
///////////////////////////////////////////////////////////////////////////
void rH(int rt_num, int j) {
	regField[j] = rt_num;
	int registerSize = sizeof(regField);
	if (j = registerSize) {
		j = 0;
	}
	else {
		j = j + 1;
	}
}

void wH(int numS, int j, int position) {
	blocks[numS][j].data = regField[position];
	blocks[numS][j].dirty = 1;
}
////////////////////////////////////////////////////////////////////////////
void rM(int numS, int j, int t, int position) {
	if (blocks[numS][j].dirty = 1)
	{
		int memoryAddress;
		memoryAddress = t * 8 + numS;
		int tem = mem[memoryAddress];
		blocks[numS][j].data = tem;
		blocks[numS][j].valid = 1;
		blocks[numS][j].tag = t;
		rH(blocks[numS][j].data, position);
	}
}
void wM(int position, int wA) {
	mem[wA] = regField[position];
}
//////////////////////////////////////////////////////////////////
void regInit() {//to initialize the registers
	int i = 0;
	for (i = 0; i < 8; i++) {
		for (int j = 0; j < 2; j++) {
			
			blocks[i][j].valid = 0;
			blocks[i][j].tag = 0;
			blocks[i][j].data = 0;
			blocks[i][j].history = 0;
		}
	}

	
}

void readCache(int numS, int t, int regesterT, int hit, int miss, int position) {
	for (int i = 0; i < 1; i++) {
		if (blocks[numS][i].valid = 1) {
			if (blocks[numS][i].tag = t) {
				hit = hit + 1;
				HUE(numS, i);
				rH(regesterT, position);
				cout << "HIT FOUND!" << endl;
			}
			else {
				miss = miss + 1;
				HUE(numS, i);
				rM(numS, i, t, position);
				cout << "MISS FOUND!" << endl;
			}
		}
		else {
			miss = miss + 1;
			HUE(numS, i);
			rM(numS, i, t, position);
			cout << "MISS FOUND!" << endl;
		}
	}

}

void printReg(int blocks[8][2]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; i < 2; j++) {
			cout << blocks[i][j] << " ";
		}
		cout << endl;
	}
}
void writeCache(int numS, int t, int registerT, int hit, int miss,int position, int wA) {
	for (int i = 0; i < 2; i++) {
		if (blocks[numS][i].valid = 1) {
			if (blocks[numS][i].tag = t) {
				hit = hit + 1;
				HUE(numS, i);
				wH(numS, i, position);
				cout << "HIT FOUND!" << endl;

			}
			else {
				miss = miss + 1;
				wM(position, wA);
				cout << "MISS FOUND!" << endl;
			}
		}
		else {
			miss = miss + 1;
			wM(position, wA);
			cout << "MISS FOUND!" << endl;
		}
	}
}
void readFile(string fileName) {
	regInit();
	int flag[8][2];
	bool loader;
	bool storer;
	int hC = 0;
	int mC = 0;
	int j = 0;
	int wA = 0;
	string line;
	ifstream code(fileName);
	if (code.is_open()) {

		while (getline(code, line)) 
		 {
			//istringstream field(line);
			//field >> pattern >> x >> y;
			int opcode;//35 = load, 43 = store
			int base_reg;//assume always $zero(0)
			int rt_num;

			//determine opcode
			if (line.substr(0, 6) == "100011") {
				opcode = 35;//load
				cout << opcode << " ";
				
			}
			else if (line.substr(0, 6) == "101011") {
				opcode = 43; //store
				cout << opcode << " ";
			}
			////determin base_register(rs) content
			if (line.substr(6, 5) == "00000") {
				base_reg = 0;//$zero
				cout << base_reg << " ";
			}
			////determin rt register number
			if (line.substr(11, 5) == "10000") {
				rt_num = 16;//$s0
				cout << rt_num << " ";
			}
			else if (line.substr(11, 5) == "10001") {
				rt_num = 17;//$s1
				cout << rt_num << " ";
			}
			else if (line.substr(11, 5) == "10010") {
				rt_num = 18;//$s2
				cout << rt_num << " ";
			}
			else if (line.substr(11, 5) == "10011") {
				rt_num = 19;//$s3
				cout << rt_num << " ";
			}
			else if (line.substr(11, 5) == "10100") {
				rt_num = 20;//$s4
				cout << rt_num << " ";
			}
			else if (line.substr(11, 5) == "10101") {
				rt_num = 21;//$s5
				cout << rt_num << " ";
			}
			else if (line.substr(11, 5) == "10110") {
				rt_num = 22;//$s6
				cout << rt_num << " ";
			}
			else if (line.substr(11, 5) == "10111") {
				rt_num = 23;//$s7
				cout << rt_num << " ";
			}
			int reg_file_index = rt_num - 16;// to access register file array (index 0-7)
				////determin byte_offset value
				int offset = 0;
			int mask = 1;
			for (int i = 31; i > 15; i--) {
				if (line.at(i) == '1') {
					offset = offset | mask;
				}
				mask <<= 1;//left_shift 1 bit
			}
			//////compute effective address
			int byte_addr = base_reg + offset;
			cout << byte_addr << " ";
			
			int word_addr = byte_addr / 4;
			cout << word_addr << " ";
			int setNum = word_addr % 8;//used for finding hit or miss
			cout << setNum << " ";
			int tag = word_addr / 8;//used for finding hit or miss
			cout << tag << endl;
			cout << "opcode is the :" << opcode << endl;
			cout << "base register is: " << base_reg << endl;

			cout << "this is the rt_num: " << rt_num << endl;
			if (opcode = 35) {
				loader = true;
				storer = false;
			}
			else if (opcode = 43) {
				loader = false;
				storer = true;
			}
			if (loader) {
				readCache(setNum, tag, rt_num, hC, mC, j);
			}
			if (storer) {
				writeCache(setNum, tag, rt_num, hC, mC, j, wA);
			}

	    }
		code.close();
	}
      //

}


void bitPrint(int x) {
	int i;
	int num;
	unsigned int mask;
	//in windows machine, >>(right_shift) is arithmetic_shift
	//so , if using >> operation on mask in windows mchine
	//musht declare mask as "unsigned int mask"

	mask = 1; //mask = 00000000000000000000000000001
	mask <<= 31;//mask = 10000000000000000000000000000
		for (i = 1; i <= 32; i++) {
			if ((x & mask) == 0) {//check the leftmost bit only
				num = 0;
			}
			else {
				num = 1;
			}
			cout << num;
			x <<= 1;
			//instead of "v <<= 1", can use "mask >>=1" with unsigned int mask
			//">>" is regarded as arithmetic sift riht with int type;
			//">>" is regarded as logical shift right with unsigned int type
		}
	cout << endl;
}
void cacheDisplay() {
	
	
	int registerSize = sizeof(regField); 
    int memorySize = sizeof(mem); 
	cout << endl << "CONTENTS OF MAIN MEMORY: " << endl; 
	for (int i = 0; i < memorySize; ++i)
	{
		cout << i << ": ";// << mem[i] << " " << endl;
		bitPrint(mem[i]);
	}
	cout << endl;

	cout << "CONTENTS OF REGISTERS: " << endl; 
	for (int i = 0; i < registerSize; ++i)
	{
		cout << "S" << i << ": " << regField[i] << " ";
	}
	cout << endl;

	cout << "CONTENTS OF CACHE " << endl; 
	for (int i = 0; i < 8; ++i)
	{
		cout << "SET #:" << i << ": " << endl;
		for (int j = 0; j < 2; ++j)
		{
			cout << "Blocks" << j << " Valid: " << blocks[i][j].valid << " Tag: " << blocks[i][j].tag << " Data: " << blocks[i][j].data << " History: " << blocks[i][j].history << " Dirty: " << blocks[i][j].dirty << endl;
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	
	//int a = 12342;
	////bitPrint(a);
	//int c = 234;
	//bitPrint(c);
	
	readFile("text.txt");
	cacheDisplay();
	system("pause");
	return 0;
}