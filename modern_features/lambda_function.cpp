#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Display(vector<int> & arr){
	for_each (arr.begin(), arr.end(), [](int ele){ cout << ele << " ";});
	cout << endl;
}

int main(){
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	
	Display(arr);
	
	sort(arr.begin(), arr.end(), [](const int x, const int y){
		return x > y;
	});
	
	Display(arr);
	return 0;
}
