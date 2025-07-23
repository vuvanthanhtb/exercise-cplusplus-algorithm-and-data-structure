/*
TĂNG - GIẢM
	Cho hai dãy số thực A[] và B[] đều có N phần tử, các giá trị là số thực và không quá 100.
	Hãy tính độ dài dài nhất của dãy các vị trí (không cần liên tiếp) thỏa mãn cả hai điều kiện:
	Nếu xét các vị trí đó trên dãy A[] thì dãy con thu được thỏa mãn tính chất tăng dần (giá trị bằng nhau không được tính vào dãy tăng).
	Nếu xét các vị trí đó trên dãy B[] thì dãy con thu được thỏa mãn tính chất giảm dần (giá trị bằng nhau không được tính vào dãy giảm).

Input
	Dòng đầu ghi số bộ test (không quá 100).
	Mỗi bộ test bắt đầu bởi số N (không quá 500).
	Tiếp theo là N dòng, mỗi dòng ghi 2 giá trị A[i] và B[i]

Output
	Với mỗi test, ghi ra độ dài tính được trên một dòng.
*/

#include <bits/stdc++.h>
using namespace std;

double A[505], B[505];
int dp[505];

int main() {
	int n;
	cin >> n;

	while (n--) {
		int N;
		cin >> N;

		for (int i = 0; i < N; ++i) {
			cin >> A[i] >> B[i];
		}

		int ketQua = 1;

		for (int i = 0; i < N; ++i) {
			dp[i] = 1;
			for (int j = 0; j < i; ++j) {
				if (A[j] < A[i] && B[j] > B[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ketQua = max(ketQua, dp[i]);
		}

		cout << ketQua << endl;
	}

	return 0;
}
