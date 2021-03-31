#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <chrono>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{

unsigned long long int a;

ofstream fout;

/*-----------------------------------------/VECTOR/-------------------------------------------*/

	fout.open("iteration_vec.txt");

	for (unsigned long long int size = 10000; size <= 10000000; size += 10000)
	{
		vector<unsigned long long int> vec;
		vec.resize(10000000);

		for (unsigned long long int i = 0; i < size; i++)
		{
			vec.push_back(i);
		}
		
		auto begin = chrono::high_resolution_clock::now();
	
		for (int i = 0; i < size; i++)
		{
			a = vec[i]++;
		}
		
		auto end = chrono::high_resolution_clock::now();

		fout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
		fout << endl;
	}
	
	fout.close();

/*---------------------------------------/FORWARD_LIST/----------------------------------------*/

	fout.open("iteration_forwlist.txt");

	for (unsigned long long int size = 10000; size <= 10000000; size += 10000)
	{
		forward_list<unsigned long long int> flist;
		flist.resize(10000000);

		for (unsigned long long int i = 0; i < size; i++)
		{
			flist.push_front(i);
		}
		
		auto begin = chrono::high_resolution_clock::now();
	
		for (forward_list<unsigned long long int>::iterator it = flist.begin(); it != flist.end(); ++it)
		{
			(*it) ++;
		}

		auto end = chrono::high_resolution_clock::now();
		
		fout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
			
		fout << endl;
	}
	
	fout.close();
	
/*-------------------------------------------/LIST/---------------------------------------------*/

	fout.open("iteration_list.txt");

	for (unsigned long long int size = 10000; size <= 10000000; size += 10000)
	{
		list<unsigned long long int> llist;
		llist.resize(10000000);

		for (unsigned long long int i = 0; i < size; i++)
		{
			llist.push_back(i);
		}
	
		auto begin = chrono::high_resolution_clock::now();
		
		for (list<unsigned long long int>::iterator it = llist.begin(); it != llist.end(); ++it)
		{
			(*it) ++;
		}

		auto end = chrono::high_resolution_clock::now();

		fout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
			
		fout << endl;
	}
	
	fout.close();

/*-------------------------------------------/MAP/---------------------------------------------*/

	fout.open("iteration_map.txt");

	for (unsigned long long int size = 10000; size <= 10000000; size += 10000)
	{
		map<unsigned long long int, unsigned long long int> Map;

		for (unsigned long long int i = 0; i < size; i++)
		{
			Map.insert({i, 0});
		}
	
		auto begin = chrono::high_resolution_clock::now();
		
		for (map<unsigned long long int, unsigned long long int>::iterator it = Map.begin(); it != Map.end(); ++it)
		{
			(it->second) ++;
		}

		auto end = chrono::high_resolution_clock::now();

		fout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
			
		fout << endl;
	}
	
	fout.close();
	
/*--------------------------------------------/SET/--------------------------------------------*/

	fout.open("iteration_set.txt");

	for (unsigned long long int size = 10000; size <= 10000000; size += 10000)
	{
		set<unsigned long long int> Set;

		for (unsigned long long int i = 0; i < size; i++)
		{
			Set.insert(i);
		}
		
		auto begin = chrono::high_resolution_clock::now();
			
		for (set<unsigned long long int>::iterator it = Set.begin(); it != Set.end(); ++it)
		{
			a = (*it);
		}
	
		auto end = chrono::high_resolution_clock::now();
		
		fout << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << endl;
			
		fout << endl;
	}
	
	fout.close();
	
	
/*--------------------------------------------------------------------------------------------*/
	return 0;

}
