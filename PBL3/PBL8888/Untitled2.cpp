#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	bitset<8> b1(20);
	cout<<b1.test(1);
	cout<<b1.test(2);
	return 0;
}
