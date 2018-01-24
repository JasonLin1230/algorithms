#include <iostream>
#include <algorithm>
using namespace std;
const int N = 30;
int main(int argc, char* argv[])
{
	int origin[N];  
	int tail[N];
	int i, j, n, s = 1;
	while (EOF != scanf_s("%d", &n))
	{
		int temp = n;
		while (temp--)
		{
			scanf_s("%d", &origin[s++]);
		}
		for (i = 1; i <= n; i++)
		{
			int Max = 1;
			for (j = 1; j < i; j++)
			{
				if (origin[j] >= origin[i])
				{
					Max = max(Max, tail[j] + 1);
				}
			}
			tail[i] = Max;
		}
		int k = -9999;
		for (i = 1; i <= n; i++)
		{
			if (tail[i] > k)
			{
				k = tail[i];
			}
		}
		printf("%d\n", k);
	}
	system("pause");
	getchar();
	return 0;
}