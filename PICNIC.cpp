#include <iostream>
#include <vector>
using namespace std;

class areFriend
{
public:
	int a;
	int b;
	areFriend(int _a, int _b) : a(_a), b(_b) {}
};

vector<areFriend> f_vec;
int cnt = 0;

// num : ÃÑ¿ø, toPick: ÃÑ¿ø / 2(ÇÔ¼ö È£Ãâ È½¼ö),  b_v ´Â ÃÑ¿ø Å©±âÀÇ ¹è¿­
bool makeTeam(int num, int toPick, vector<bool>& b_v, int first)
{
	int sum = 0;

	for (int i = 0; i < num; i++)
	{
		sum += b_v[i];
	}

	if (num == 2)
		return true;
	if (toPick == 0)
	{
		if (sum == 0)
		{
			cnt++;
			return true;
		}
		else
		{
			b_v[f_vec[first].a] = b_v[f_vec[first].a] ? 0 : 1;
			b_v[f_vec[first].b] = b_v[f_vec[first].b] ? 0 : 1;
			return false;
		}
		
	}

	first = (sum == num) ? 0 : first + 1;

	for (int i = first; i < num ; i++)
	{
		b_v[f_vec[i].a] = b_v[f_vec[i].a] ?  0 : 1;
		b_v[f_vec[i].b] = b_v[f_vec[i].b] ? 0 : 1;
		makeTeam(num, toPick - 1, b_v, first);
	}
}



int main()
{
	int Case;
	int n, m;
	int toPick;
	
	cin >> Case;
	while (Case != 0)
	{
		cin >> n;
		cin >> m;
		
		vector<bool> chk_vec(n, 1);
		

		for (int i = 0; i < m; i++)
		{
			int temp1, temp2;
			cin >> temp1;
			cin >> temp2;
			f_vec.push_back(areFriend(temp1, temp2));
		}

		toPick = n / 2;

		if (makeTeam(n, toPick, chk_vec, 0)) cnt++;

		cout << cnt << endl;

		cnt = 0;

		Case -= 1;

		f_vec.clear();
	}
	return 0;
}