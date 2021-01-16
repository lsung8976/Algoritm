#include <iostream>
#include <cstring>
using namespace std;

class AAA
{
private:
	char* ptr;
public:
	AAA(const char* text)
	{
		int len = strlen(text);
		ptr = new char[len];
		strcpy_s(ptr, len + 1, text);
	}


public:
	void ShowAAA() const
	{
		cout << ptr << endl;
	}

	friend ostream& operator<<(ostream& os, const AAA& ref);
	
};

ostream& operator<<(ostream& os, const AAA& ref)
{
	os << ref.ptr << endl;
	return os;
}

int main(void)
{
	AAA note("problem");
	cout << note << endl;

}