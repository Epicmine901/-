#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> read(long long c) {
	string s = to_string(c);
	vector<int> a;
	for (int i = 0; i <= (s.size() - 1); i++) {
		a.push_back(s[i] - '0');
	}
	return a;
}

vector<int> read(long long c,int max_size) {
	string s = to_string(c);
	int max = max_size - s.size();
	vector<int> a;
	for (int i = 0; i <= s.size()+max-1; i++) {
		if (max-1 >= i)a.push_back(0);
		else a.push_back(s[i-max] - '0');
	}
	return a;
}
string _0_ni_ochirish(string a) {
	for (; true;) {
		if (a[0] == '0' and !(a.size()==1)) {
			a = a.substr(1, a.size()-1);
		}
		else break;
	}
	return a;
}
void Output(long long Input,bool razrisheniye) {
	string pilus="";
	int Out = 0,max = to_string(Input).size();
	vector<int>i1, i2;
	for (int i_1 = 0; i_1 <= Input; i_1++) {
		i1=read(i_1,max);
		for (int i_2 = 0; i_2 <= Input; i_2++) {
			i2= read(i_2, max);
			for (int size=0; size<max; size++) {
				pilus = pilus + to_string(i1[size]+i2[size]);
			}
			if(_0_ni_ochirish(pilus) == to_string(Input)){
				if (razrisheniye)cout << '(' << i_1 << ':' << i_2 << ')' << endl;
				else Out++;
				pilus = ""; 
				break;
			}
			else pilus = "";

		}
	}
	if (!razrisheniye)cout << Out;
}

int main() {
	long long a;
	cin >> a;
	Output(a,false);
}