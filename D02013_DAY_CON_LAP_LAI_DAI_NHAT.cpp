/*
DÃY CON LẶP LẠI DÀI NHẤT
	Cho xâu ký tự S.
	Nhiệm vụ của bạn là tìm độ dài dãy con lặp lại dài nhất trong S.
	Dãy con có thể chứa các phần tử không liên tiếp nhau.

Input:
	Dòng đầu tiên đưa vào số lượng bộ test T.
	Những dòng kế tiếp đưa vào các bộ test.
	Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào độ dài xâu str; dòng tiếp theo đưa vào xâu S.
	T, str thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ size(S) ≤ 100.

Output:
	Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

int doDaiDayConLapLaiDaiNhat(char S[], int n) {
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (S[i - 1] == S[j - 1] && i != j)
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[n][n];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int len;
		cin >> len;
		char S[105];
		cin >> S;

		int result = doDaiDayConLapLaiDaiNhat(S, len);
		cout << result << endl;
	}
	return 0;
}
