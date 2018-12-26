/*4) Реализуйте вычисление значения полинома в точке посредством схемы Горнера */


#include <iostream>
using namespace std;
int main()
{
	unsigned long long int N, x;
	cin >> N >> x;
	long long int* a = new long long int[N + 1];
	for (unsigned long long int i = 0; i < N + 1; i++)
	{
		cin >> a[i];
	};

	long long int b = a[N];
	for (unsigned long long int i = N - 1; i >= 1; i--)
		b = a[i] + b * x;
	cout << a[0] + b * x;
	return 0;
}