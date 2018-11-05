#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	TVector<int> V1(3), V2(3), V3(3);
	for (int i = 0; i < 3; i++) {
		V1[i] = i;
		V2[i] = i;
		V3 = V1 + V2;
	}
	cout << V3;

}