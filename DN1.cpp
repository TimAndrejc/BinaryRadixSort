#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
	ifstream input(s);
	int st;

	if (!input.is_open()) {
		return false;
	}

	while (!input.eof()) {
		input >> st;
		vec.push_back(st);
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
	ofstream output("out.txt");

	for (int i = 0; i<velikost; i++)
		output << polje[i] << ' ';
}

void BitRadixSort(int* polje, unsigned int velikost) {
	int * D = new int[velikost];
	for (int k = 0; k<8; k++) {
		for (int i = 0; i < velikost; i++) {
			D[i] =  (polje[i] >> k) & 1;
		}
		for (int i = 0; i < velikost; i++) {
			int changes = 0;
			for (int j = 0; j < velikost -1; j++) {
				if (D[j] > D[j + 1]) {
					swap(D[j], D[j + 1]);
					swap(polje[j], polje[j + 1]);
					changes++;
				}
			}
			if (changes == 0) {
				break;
			}
		}
	}
	delete [] D;
}

int main(int argc, const char* argv[]) {
	vector<int> A;

	//if (argc < 2) return 0;
	if (!Branje_Stevil(A, "input.txt")) return 0;

	BitRadixSort(&A[0], A.size());
	Izpis_Stevil(&A[0],A.size());

	return 0;
}