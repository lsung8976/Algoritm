#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector<int> prime;
	bool IsPrime[1000001] = { 0, };
	
	int end_num = 1000000;


	for (int i = 2; i <= end_num; i++) 
	{
		if (IsPrime[i] == false)
		{
			prime.push_back(i);
			for (int j = i + i; j <= end_num; j += i)
				IsPrime[j] = true;
		}
		else
			continue;
	}

	for (vector<int>::size_type i = 0; i < prime.size(); i++)
		cout << prime[i] << " ";
	cout << endl;

};