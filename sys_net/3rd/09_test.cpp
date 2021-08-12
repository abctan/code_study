#include <iostream>

using namespace std;

struct cls{
	int age;
};

int main(void)
{
	cls cls = {10};

	cout << "age : " << cls.age << endl;
}
