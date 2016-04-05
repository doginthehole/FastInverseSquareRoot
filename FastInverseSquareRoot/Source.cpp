#include <iostream>
using namespace std;


float FastInvSqrt(float x) {
	float xhalf = 0.5f * x;
	int i = *(int*)&x;         // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);  // what the fuck?
	x = *(float*)&i;
	x = x*(1.5f - (xhalf*x*x));
	return x;
}

int main() {
	//cout << "hello world" << endl;
	float x = NULL;

	const int c = 20;

	float foo[c] = { 23423,4545,232111,234234,5432234,1,456486,4649,486489,
		789,67888,6789,786444,86779456,345664897978,38794564686,45612497,38794566454,86749 };


	for (int i = 0; i < c; i++) {
		cout << FastInvSqrt(foo[i]) << endl;
	}

	/*cout << "enter value to be inversely square rooted: ";
	cin >> x;

	cout << FastInvSqrt(x) << endl;*/
}