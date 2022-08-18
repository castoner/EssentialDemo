#include <vector>
#include <iostream>


using namespace std;

inline bool judge_size(int size) {
	if (size < 0 || size > 64) {
		cout << "Sorry, Invalid size: " << size << endl;
		return false;
	}
	return true;
}

bool create_pentagonal(int size, vector<int>& vec);