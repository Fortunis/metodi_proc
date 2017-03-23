#include <iostream>
#include <fstream>
#include "container_atd.h"

using namespace std;

namespace simple_shapes {
	// Сигнатуры требуемых внешних функций
	void Clear(container &c);
	void In(container &c, ifstream &ifst) ;
	void Out(container &c, ofstream &ofst) ;
	void Sort(container &c);
}

using namespace simple_shapes;

int main(int argc, char* argv[]) {
	/*if(argc !=3) {
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		exit(1);
	}*/
	//argv[1] = "in";
	//argv[2] = "out";

	ifstream ifst(argv[1]);
	//ifstream ifst("in.txt");
	ofstream ofst(argv[2]);
	//ofstream ofst("out.txt");

	cout << "Start"<< endl;
	container c;
	In(c, ifst);
	ofst << "Filled container. " << endl;
	Out(c, ofst);
	Sort(c);
	ofst << "Sorted container. " << endl;
	Out(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop"<< endl;
	return 0;
}