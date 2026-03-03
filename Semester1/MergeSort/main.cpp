#include <iostream>

using namespace std;

void mergeSort(const int f1[], const int l1, const int f2[], const int l2, int f3[], int l3)
{
    int i = 0, j = 0, k = 0;
    while (i < l1 && j < l2) {
        if (f1[i] < f2[j]) {
            f3[k++] = f1[i++];
        } else {
            f3[k++] = f2[j++];
        }
    }

    while (i < l1) {
        f3[k++] = f1[i++];
    }
    while (j < l2) {
        f3[k++] = f2[j++];
    }

    l3 = l1 + l2;
}



int main()
{
	const int l1 = 4;
	const int l2 = 4;
	int f1[l1] = { 1,3,4,5 };
	int f2[l2] = { 2,6,7,8 };
	const int l3=l1+l2;
	int f3[l3];
	mergeSort(f1, l1, f2, l2, f3, l3);
    

    cout << "Sorted l3: " << endl;
    for (int i = 0; i < l3; i++) {
        cout << f3[i] << " ";
    }
	return 0;
}