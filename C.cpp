#include <iostream>
using namespace std;
int main() {
	int N, wins = 0, win_ = 0;
	string koloda_1, koloda_2;
	cin >> N;
	if (1 <= N and N <= 50) {
		cin >> koloda_1 >> koloda_2;

		for (int i = 0; i < N; i++) {
			for (int win = 0; win < N; win++) {
				if ((koloda_1[i] == 'R') and (koloda_2[win] == 'S')) { win_ = 1; koloda_2[win] = '0'; break; }
				else if ((koloda_1[i] == 'S') and (koloda_2[win] == 'P')) { win_ = 1; koloda_2[win] = '0'; break; }
				else if ((koloda_1[i] == 'P') and (koloda_2[win] == 'R')) { win_ = 1; koloda_2[win] = '0'; break; }
				else win_ = 0;
			}
			wins = wins + win_;
			win_ = 0;
		}
		cout << wins;
	}
	else cout << 0;
}