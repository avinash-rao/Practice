
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

bool f(int x, int y) {
	return x > y;
}

void vectorDemo() {
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
	auto it2 = upper_bound(A.begin(), A.end(), 100);
	cout << *it2 << endl;				// How to print element at 'it2' (123)
	
	cout << it2 - it << endl;				// prints no. of 100 present in our vector
	
	// To sort the vector in reverse order
	sort(A.begin(), A.end(), f);				// f is defined in global space. It is a comparator
	
	// To change elements in vector
	for(int &x: A) { // reference
		x++;
	}
	
	vector<int>::iterator it3;
	// To print a vector
	//for (it3 = A.begin(); it3 != A.end(); it3++) {
	for(int x: A) {
		//cout << *it3 << " ";
		cout << x << " ";
	}
	cout << endl;
}

void setDemo() {
	set<int> S;
	S.insert(1);
	S.insert(2);
	S.insert(-10);
	S.insert(-1);
	S.insert(0);
	
	for(int x: S) 
		cout << x << " ";
	cout << endl;
	
	auto it = S.find(-1);
	if( it == S.end()) {
		cout << "Not present\n";
	} else {
		cout << "Present\n";
	}
	
	auto it2 = S.lower_bound(-1);  				// next element >= -1
	auto it3 = S.upper_bound(-1);				// next element > -1
	cout << *it2 << endl << *it3 << endl;
	auto it4 = S.upper_bound(2);				// it will store S.end() as upper_bound of 2 is not present in the set
	if(it4 == S.end()) 
		cout << "Can't find anything like that!";
	cout << *it4;
	
	S.erase(1);									// to delete an element
	
	for(int x: S) 
		cout << x << " ";
	cout << endl;
}

void mapDemo() {
	map<int, int> A;
	A[1] = 100;
	A[2] = -1;
	A[3] = 200;
	A[1234400001] = 1;
	
	// map character to int
	map<char, int> cnt;
	string x = "avinash rao";
	
	for(char c: x)
		cnt[c]++;
		
//	cout << cnt['a'] << " " << cnt['j'] << endl;
	// To print out all the map elements
	for(auto pair: cnt) {
		cout << pair.first << " " << pair.second << endl;
	}
}

void powerOfStl() {
	// [x, y]
	set< pair<int, int> > S;
	S.insert({401, 450});
	S.insert({10, 20});
	S.insert({2, 3});
	S.insert({30, 400});
	
	int point = 50;
//	auto it = S.upper_bound({31, 345});
	auto it = S.upper_bound({point, INT_MAX});
	if(it == S.begin()) {
		cout << "The given point does not lie in any interval" << endl;
		return; 
	}
	it--;
//	auto it2 = S.lower_bound({31, 345});
	pair<int, int> current = *it;
	if(current.first <= point && point <= current.second)
		cout << "yes its present: " << current.first << " " << current.second << endl;
	else 
		cout << "The point does not lie in any interval" << endl;
//	cout << (*it).first;
}

int main()
{	
//	vectorDemo();
	
//	setDemo();
//	mapDemo();
	powerOfStl();
}
