/*
TÍCH LỚN NHẤT
	Cho dãy số A gồm N phần tử là các số nguyên. Hãy tính tích lớn nhất của 2 hoặc 3 phần tử trong dãy.

Input
	Dòng đầu tiên ghi số N (3 ≤ N ≤ 10000)
	Dòng thứ 2 ghi N số của dãy A (|Ai| ≤ 1000)

Outpput
	Ghi ra kết quả trên một dòng
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[10005];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);

	long long tich2_1 = 1LL * a[0] * a[1];
	long long tich2_2 = 1LL * a[n - 1] * a[n - 2];

	long long tich3_1 = 1LL * a[n - 1] * a[n - 2] * a[n - 3];
	long long tich3_2 = 1LL * a[0] * a[1] * a[n - 1];

	long long ketQua = max({tich2_1, tich2_2, tich3_1, tich3_2});

	cout << ketQua << endl;

	return 0;
}
