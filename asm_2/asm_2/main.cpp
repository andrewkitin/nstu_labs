#include <iostream> 
#include <fstream> 

extern "C" void FUNC(int* result_length,char* RESULT, int );
extern "C" char STRING[100] = { 0 };



void output(char* res, int length) {
	for (int i = 0; i < length; ++i) {std::cout << res[i];}
}

int main() {
	char RESULT[100] = { 0 }; //push it as a pointer, where solution is
    int str_length = 0;
	int res_length = 0; //push it into FUNC as a pointer and we get the length of RESULT
	std::ifstream f;
	f.open("input.txt");
	for (int i = 0; !f.eof() && i < 100; ++i) {
		f >> STRING[i];
		++str_length;
	}
	--str_length;
	FUNC(&res_length,RESULT,str_length); //deleting dots 
	output(RESULT,res_length); // you know
	system("pause");
}