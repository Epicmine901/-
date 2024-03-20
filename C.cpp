#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long  N, wins = 0;
	long RSP[6] = {};
	string koloda_1, koloda_2;
	cin >> N;
	if (1 <= N and N <= 100000) {
		cin >> koloda_1 >> koloda_2;
		for (int i = 0; i < N; i++) {
			if (koloda_1[i] == 'R')RSP[0]++;
			if (koloda_2[i] == 'S')RSP[4]++;

			if (koloda_1[i] == 'S')RSP[1]++;
			if (koloda_2[i] == 'P')RSP[5]++;

			if (koloda_1[i] == 'P')RSP[2]++;
			if (koloda_2[i] == 'R')RSP[3]++;		
		}
		wins = wins + min(RSP[0], RSP[4]);
		wins = wins + min(RSP[1], RSP[5]);
		wins = wins + min(RSP[2], RSP[3]);
		cout << wins <<endl;
	}
	else cout << 0;
	system("pause");
}
