#include <iostream>

using namespace std;

int SimpleFunc(int a = 10)
{
	return a + 1;
}

int SimpleFunc(void)
{
	return 10;
}

void main()
{
	// 함수를 인자없이 호출했을 때 디폴트 값 사용인지 인자없는 함수 사용인지 구분 불가능
}