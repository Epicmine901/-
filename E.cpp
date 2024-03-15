#include <iostream>
#include <vector>
#include <set>
using namespace std;
int scan() {
    int a;
    cin >> a;
    return a;
}
int scroll(int n, int max) {
    if ((max - 1) < n)return n-(max);
    else return n;
}
int main() {
    int N;
    cin >> N;
    if (3 <= N and N <= 1000) {
        vector<int> a;
        multiset<int> b;
        for (int i = 0; i < N; i++) {
            a.push_back(scan());
        }
        for (int i = 0; i < N; i++) {
            b.insert(a[scroll(i, N)] + a[scroll(i + 1, N)] + a[scroll(i + 2, N)]);
        }
        
        int i=0;
        for (int n : b) {
            i++;
            if(i==N)
            cout << n << endl;
        }
    }
    else cout << 0;
    system("pause");
}