#include "bits/stdc++.h"
using namespace std;

const int M = 100;

int get (int mul, int base) {
	for (int i = 1; i < M; i++){
		cout << "? " << base + i * mul << '\n' << flush;
		string reply;
		cin >> reply;

		if (reply == "True")
			return base + (i - 1) * mul;
	}

	return base + (M - 1) * mul;
}

int main(){

	int X = get(1, get(1'00, get(1'00'00, get(1'00'00'00, 0))));

	cout << "! " << X << flush;

}