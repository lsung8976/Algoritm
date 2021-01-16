#include <iostream>
#include <vector>
#include <map>

using namespace std;

void func(map<int, int> m, vector<int> chk, int pnt)
{
	for (int i = 0; i < chk.size(); i++)
	{
		
	}
}

int main()
{
	int size;// 원소 갯수
	int temp;
	map<int, int> m1;
	
	vector<int> check_vec;

	cin >> size;
	for (int i = 1; i <= size; i++)
	{
		cin >> temp;
		m1.insert({ i, temp });
	}

	for (map<int, int>::iterator iter = m1.begin(); iter != m1.end(); iter++)
	{
		if (iter->first == iter->second)
		{
			check_vec.push_back(iter->first);
		}
	}

	for (int i = 1; i <= size; i++)
	{
		func(m1, check_vec, i);
	}



	


	/*
	vector<int> v1;
	vector<int> check_vec;
	vector<int> sort_vec;
	cin >> size;
	for (int i = 1; i <= size; i++)
	{
		cin >> temp;
		v1.push_back(temp);
	}

	// 중복 제거 후 내림차순으로 원소값 정렬
	sort_vec = v1;
	sort(sort_vec.begin(), sort_vec.end());
	sort_vec.erase(unique(sort_vec.begin(), sort_vec.end()), sort_vec.end());
	overlap_size = sort_vec.size();
	
	cout << "size : " << overlap_size << endl;
	for (vector<int>::iterator iter = sort_vec.begin(); iter != sort_vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;


	*/

	return 0;
}