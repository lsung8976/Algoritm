#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	int* p;
	int time;
	int n;
	int gcd_num = 0;
	int total_gcd = 0;//gcd ��ü��

	cin >> time; // ��ü �ݺ� Ƚ��

	for (int i = 0; i < time; i++)
	{
		cin >> n; // Ƚ�� �Է�
		p = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
		}

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				total_gcd += gcd(p[i], p[j]);
			}
		}




		/*
		cin >> n;	//Ƚ�� �Է�

		p = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
		}

		gcd_num = gcd(p[0], p[1]);
		for (int i = 2; i < n; i++)
			gcd_num = gcd(gcd_num, p[i]);

		cout << gcd_num << endl;
		*/
		cout << total_gcd << endl;
		total_gcd = 0;
		delete[] p;
	}



	return 0;
}