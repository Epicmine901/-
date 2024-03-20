#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
vector<int> read(long long c, int max_size) {
  string s = to_string(c);
  int max = max_size - s.size();
  vector<int> a;
  for (int i = 0; i <= s.size() + max - 1; i++) {
    if (max - 1 >= i)a.push_back(0);
    else a.push_back(s[i - max] - '0');
  }
  return a;
}
string natija(int i, string b) {
  string Out = '(' + to_string(i) + ':' + b + ')';
  return Out;
}
string _0_ni_ochirish(string a) {
  for (; true;) {
    if (a[0] == '0' and !(a.size() == 1)) {
      a = a.substr(1, a.size() - 1);
    }
    else break;
  }
  return a;
}
bool TorF(int a, string b, int Input) {
  int max = 0;
  if (to_string(a).size() > b.size())max = to_string(a).size();
  else max = b.size();
  vector<int>i1, i2;
  string pilus;
  i1 = read(a, max);
  for (int size = 0; size < max; size++) {
    pilus = pilus + to_string(i1[size] + b[size] - '0');
  }
  if (pilus == to_string(Input)) {
    return true;
  }
  else return false;
}
int Output(long long Input,bool Dostup) {
  int next = 0,max= to_string(Input).size();
  bool again = false;
  vector<int>c,II,a = read(Input,max);
  vector<string>result;
  for (int i = 0; i <= Input; i++) {
    II = read(i,max);
    next = 0;
    c.clear();
    again = false;
    for (int j = max-1 ; 0 <= j; j--) {
      int size = II.size() - (1 + next);
      if ((a[j] >= II[size]) and !again) {
        c.push_back(a[j] - II[size]);
        next++;
      }
      else if (again) {
        if (a[j] == 1) {
          c.push_back((a[j] * 10 + a[j + 1]) - II[size]);
          next++;
          again = false;
        }
        else {
          break; 
        }
      }
      else again = true;
    }
    string pilus = "";
    if (!again) {
      for (int j = c.size() - 1; 0 <= j; j--) {
        pilus = pilus + to_string(c[j]);
      }
      if (TorF(i, pilus, Input)) {
        pilus = _0_ni_ochirish(pilus);
        result.push_back(natija(i, pilus));
      }
    }
  }
  if (Dostup) {
    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << endl;
    }
  }
  else return result.size();
}
bool T_or_f(int i1) {
	if (0 <= i1)return true;
	else return false;
}
vector<int> osonroq(string In) {
	int i1=0,j=0;
	vector<int>result,Out;
	for (int i = 0; i < In.size() ; i++) {
		if (In[i] == '1') {
			i1 = i1 + pow(10, j);
			j++;
            if(i==In.size()-1)result.push_back(i1);
		}
		else if (T_or_f(i - 1)) {
			if (In[i-1] == '1') {
				result.push_back(i1*10+In[i]-'0');
				i1 = 0;
				j = 0;
			}
			else result.push_back(In[i] - '0');
		}
		else result.push_back(In[i]-'0');
	}
	return result;
}
int main(){
    long long a,result=1;
    vector<int> b;
    cin>>a;
    b=osonroq(to_string(a));
    for(int i=0;i<b.size();i++){
    result=result*Output(b[i],false);
    }
    cout<<result;
}
