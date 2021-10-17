#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getRes(vector<int>& values, int Q) {

	int count = values.size();
	vector<int> maxmoney;
	maxmoney.push_back(0);
	for (int i = 0; i < count; i++)
	{
		int maxmoney_size = maxmoney.size();
		for (int j = 0; j < maxmoney_size; j++)
		{
			int tmp = maxmoney[j] + values[i];
			if (tmp <= Q)
			{
				maxmoney.push_back(tmp);
			}
		}
	}
	int res = 0;
	for (auto i : maxmoney) res = max(res, i);

	return res;
}

int readInt() {
	int x = 0;
	char ch = getchar();
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

// 主要就是化为01背包
// 结果精度问题

int main() {
	int N ;
	double Q ;
	vector<int> values = vector<int>();
	// vector<int> resV = vector<int>();
	int A_Price, B_Price , C_Price ;
	int sumValue;
	bool isRight;
	string s;
	while (true)
	{
		scanf("%lf", &Q);
		getchar();
		N = readInt();
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
		{
			int m;
			m = readInt();
			isRight = true;
			sumValue = 0;
			A_Price = 0;
			B_Price = 0;
			C_Price = 0;
			for (int j = 0; j < m; j++)
			{

				char type;
				double temp;
				scanf("%c:%lf", &type, &temp);
				getchar();

                // 转为整数
                // 加0.5防止double 掉精度
                // 比如0.09存储可能为0.0899
                // int(8.9 + 0.5) = 9
				int value = (int)(temp * 100 + 0.5);

				if (type == 'A') {
					A_Price += value;
					if (A_Price > 60000) {
						isRight = false;
					}
				}
				if (type == 'B') {
					B_Price += value;
					if (B_Price > 60000) {
						isRight = false;
					}
				}
				if (type == 'C') {
					C_Price += value;
					if (C_Price > 60000) {
						isRight = false;
					}
				}
				
				if(type != 'A' && type != 'B'&& type != 'C')
				{
					isRight = false;
				}
			}
			sumValue = A_Price + B_Price + C_Price;
			if (isRight && sumValue <= 100000)
			{
				values.push_back(sumValue);
			}
			isRight = true;
		}

		int res = getRes(values,(int)(Q*100));
		printf("%.2lf\n", (double)(res) / 100);
		values.clear();
	}
	return 0;
}