#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
	void Print() const
	{
		cout << x << ", " << y << endl;
	}
	int GetX() const { return x; }
	int GetY()  const { return y; }
	int len(Point& tmp)
	{
		return abs(x - tmp.GetX()) + abs(y - tmp.GetY());
	}
};



int main()
{
	vector<Point> v;
	v.push_back(Point(1, 2));//a
	v.push_back(Point(5, 1));//b
	v.push_back(Point(3, 1));//c
	v.push_back(Point(3, 2));//d
	v.push_back(Point(3, 3));//e
	v.push_back(Point(4, 2));//f
	v.push_back(Point(5, 2));//g
	v.push_back(Point(6, 2));//h
	v.push_back(Point(8, 3));//i
	v.push_back(Point(7, 2));//j
	v.push_back(Point(8, 2));//k
	v.push_back(Point(9, 2));//l
	v.push_back(Point(7, 1));//m
	v.push_back(Point(6, 1));//n
	v.push_back(Point(9, 3));//o
	v.push_back(Point(10, 3));//p
	v.push_back(Point(1, 3));//q
	v.push_back(Point(4, 2));//r
	v.push_back(Point(2, 2));//s
	v.push_back(Point(5, 3));//t
	v.push_back(Point(7, 3));//u
	v.push_back(Point(4, 1));//v
	v.push_back(Point(2, 3));//w
	v.push_back(Point(2, 1));//x
	v.push_back(Point(6, 3));//y
	v.push_back(Point(1, 1));//z

	int total_time = 0;
	string s;
	Point left;
	Point right;
	vector<Point> bigyo(100);

	char char_temp;
	cin >> char_temp; // 왼손 초기화
	left = v[char_temp - 97];
	cin >> char_temp;	// 오른손 초기화
	right = v[char_temp - 97];

	cin >> s;	//문자열 입력
	
	for (int i = 0; i < s.length(); i++)
	{
		bigyo[i] = (v[s[i] - 97]);
	}
	cout << endl;
	
	for (int i = 0; i < s.length(); i++)
	{
		if (left.len(bigyo[i]) < right.len(bigyo[i]))	// 왼손에서 다음 문자까지 더 길이가 짧을때
		{
			total_time += left.len(bigyo[i]) + 1;
			left = bigyo[i];
		}
		else
		{
			total_time += right.len(bigyo[i]) + 1;
			right = bigyo[i];
		}

	}
	cout << endl;
	
	cout << total_time;

	return 0;
}