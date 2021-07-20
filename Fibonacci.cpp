#include<iostream> 
#include<vector>

using namespace std;
void fibo(int n)
{
	vector <int> table{0,1};
	if (n == 0 || n == 1)
	{
		table.push_back(n);
		for (int i = 0; i < table.size(); i++)
			cout << table[i];
	}
	else for (int i = 2; i <= n; i++)
	{
		table.push_back(table[i - 1] + table[i - 2]);
		cout << table[i];
	}
}
int main()
{
	fibo(5);
}