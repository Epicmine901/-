#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a - b > b)cout << b;
	else if (a - b < b)cout << a - b;
}