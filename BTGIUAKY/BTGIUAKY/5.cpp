#include<iostream>
using namespace std;

void pushBackArr(int* a, int n, int x) {
	if (a == NULL)
	{
		n = 1;
		a = new int[n];
		a[0] = x;
	}
	else {
		int* aPrev = a;
		a = new int[n + 1];
		for (int i = 0; i < n; i++)
			a[i] = aPrev[i];
		a[n] = x;
		n = n + 1;
		delete[]aPrev;
	}
}

int* filter(int* a, int n, int& sl) {
	int* res;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			pushBackArr(res, sl, a[i]);
	}
	return res;
}

int main() {
	return 0;
}