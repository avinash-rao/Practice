
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool f(int x, int y) {
	return x > y;
}

int main()
{
    vector<int> A = {11,2,3,14};    // #include <vector>
	cout << A[1] << endl;					// Indexing starts from 0
	sort(A.begin(), A.end());			// {2, 3, 11, 14}
	for(int i = 0; i < A.size(); i++ ){
		cout << A[i] << " ";				// Displaying the vector elements
	}
	cout << endl;
	
	bool present = binary_search(A.begin(), A.end(), 3);     // Performing searching operation
	A.push_back(100);										// To add an element at the end	{2, 3, 11, 14,100}
	A.push_back(100);
	A.push_back(123);										// {2, 3, 11, 14,100, 100, 123}
	
	// 'it' holds the value which is just lesser than or equal to 100
	vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100);				// lower bound is not as strict as upperbound that's why it holds 100
	cout << *it << endl;				// How to print element at 'it' (100)
	
	// 'it2' holds the value which is just greater than 100
	vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100);
	cout << *it2 << endl;				// How to print element at 'it' (100)
	
	cout << it2 - it << endl;				// prints no. of 100 present in our vector
	
	// To sort the vector in reverse order
	sort(A.begin(), A.end(), f);				// f is defined in global space. It is an comparator
	
	vector<int>::iterator it3;
	// To print a vector
	for (it3 = A.begin(); it3 != A.end(); it3++) {
		cout << *it3 << " ";
	}
	cout << endl;
	
	
}
