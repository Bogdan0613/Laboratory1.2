#include<iostream>
#include<string>
using namespace std;
int do_minus(int* x, int* y, int* z, int length, int smaller_length);
int main() {
	string num1;
	string num2;
	int k = 0;
	cout << "Enter the first big number:";
	getline(cin, num1);
	int* first_number = new int[num1.length()];
	for (int i = (int)num1.length() - 1; i >= 0; i--) {
		first_number[k] = num1[i] - '0';
		k++;
	}
	cout << "Enter the second big number:";
	getline(cin, num2);
	k = 0;
	int* second_number = new int[num2.length()];
	for (int i = (int)num2.length() - 1; i >= 0; i--) {
		second_number[k] = num2[i] - '0';
		k++;
	}
	int compare = 0;
	int length;
	int smaller_length;
	length = (int)num1.length();
	if (num1.length() > num2.length()) {
		length = (int)num1.length();
		compare = 1;
		smaller_length = (int)num2.length();
	}
	else {
		if (num2.length() > num1.length()) {
			length = (int)num2.length();
			compare = 2;
			smaller_length = (int)num1.length();
		}
		else {
			for (int i = length - 1; i >= 0; i--) {
				if (first_number[i] > second_number[i]) {
					compare = 1;
					break;
				}

				if (second_number[i] > first_number[i]) {
					compare = 2;
					break;
				}
			}
		}
	}
	int* result = new int;
	if (compare == 1) {
		do_minus(first_number, second_number, result, length, smaller_length);
	}
	if (compare == 2) {
		do_minus(second_number, first_number, result, length, smaller_length);
	}
	cout << endl;
}
int do_minus(int* x, int* y, int* z, int length, int smaller_length) {
	for (int i = 0; i <= length - 1; i++) {
		if (i > smaller_length - 1) y[i] = 0;
		if (i < length - 1) {
			x[i + 1]--;
			z[i] = (x[i] + 10) - y[i];
		}
		else {
			if (i == length - 1) {
				z[i] = x[i] - y[i];
			}
		}
		if (z[i] / 10 > 0) {
			x[i + 1]++;
			z[i] %= 10;
		}
	}
	cout << endl;
	cout << "The difference of big numbers is:";
	for (int i = length - 1; i >= 0; i--) {

		cout << z[i];
	}
	return 0;
}
