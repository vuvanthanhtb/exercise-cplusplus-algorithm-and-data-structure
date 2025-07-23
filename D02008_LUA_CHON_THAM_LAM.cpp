/*
LỰA CHỌN THAM LAM
	Cho hai số nguyên dương N và S.
	Hãy lựa chọn các chữ số phù hợp để tạo ra số nhỏ nhất và số lớn nhất có N chữ số sao cho tổng chữ số đúng bằng S.

Input
	Chỉ có một dòng ghi hai số N và S. (0 < N <= 100; 0 <= S <= 900)

Output
	Ghi ra hai số nhỏ nhất và lớn nhất tìm được, cách nhau một khoảng trống.
	Nếu không thể tìm được thì ghi ra “-1 -1”
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, S;
	cin >> N >> S;

	if (S == 0) {
		if (N == 1) cout << "0 0\n";
		else cout << "-1 -1\n";
		return 0;
	}

	if (S > 9 * N) {
		cout << "-1 -1\n";
		return 0;
	}

	int sum = S;
	string soNhoNhat = "";
	for (int i = 0; i < N; ++i) {
		for (int d = (i == 0 ? 1 : 0); d <= 9; ++d) {
			int maxSumConLai = 9 * (N - i - 1);
			if (sum - d <= maxSumConLai && sum - d >= 0) {
				soNhoNhat += char(d + '0');
				sum -= d;
				break;
			}
		}
	}

	sum = S;
	string soLonNhat = "";
	for (int i = 0; i < N; ++i) {
		for (int d = 9; d >= 0; --d) {
			if (sum - d >= 0) {
				soLonNhat += char(d + '0');
				sum -= d;
				break;
			}
		}
	}

	cout << soNhoNhat << " " << soLonNhat << "\n";

	return 0;
}
