#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ofstream fout;

	fout.open("push_back.txt");

	vector<int> vec; 
	for (int i = 0; i < 500000; i++)
	{
		vec.push_back(i);
		fout << vec.size() << " " << vec.capacity() << endl;
	}
}

