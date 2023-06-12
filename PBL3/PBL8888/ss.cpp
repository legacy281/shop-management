#include <iostream>

using namespace std;

void MaxMin(int a[],int l, int r,int &min) {
	int min1, min2;
	if (l == r) {
		 min = a[l];
	}
	else {
		int mid = (l + r) / 2;
		min1 = l;
		min2 = mid + 1;
		MaxMin(a, l, mid,min1);
		MaxMin(a, mid + 1, r,min2);
		if (min1 < min2) {
			min = min1;
		}
		else {
			min = min2;
		}
		
	}
}
int main() {
	int c[5] = { 4,5,1,3,8 };
	int min = c[0];
	MaxMin(c, 0, 4,min);
	cout << min << endl;
	system("pause");

}
