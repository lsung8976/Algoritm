#include <iostream>
#include <vector>
using namespace std;
/*
* n : ��ü ���� ��
* picked : ���ݱ��� �� ���ҵ��� ��ȣ
* toPick : �� �� ������ ��
* �϶�, ������ toPick���� ���Ҹ� ���� ��� ����� ����Ѵ�.
* */
void printPicked(vector<int>& picked)
{
	for (vector<int>::iterator iter = picked.begin(); iter != picked.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void run(int n, vector<int>& basket, int pick_num)
{
	//���� ��� : �� �� ���Ұ� ���� �� �� ���ҵ��� ����Ѵ�.
	if (pick_num == 0) { printPicked(basket); return; }
	//�� �� �ִ� ���� ���� ��ȣ�� ����Ѵ�.
	int first = basket.empty() ? 0 : basket.back() + 1;
	// �� �ܰ迡�� ���� �ϳ��� ����.
	for (int i = first; i < n; i++)
	{
		basket.push_back(i);
		run(n, basket, pick_num - 1);
		basket.pop_back();
	}
}

int main()
{
	vector<int> v;
	run(7, v, 4);

	return 0;
}