/*
TỔNG GIÁ TRỊ LỚN NHẤT
	Một tên trộm đột nhập vào một cửa hiệu tìm thấy n món hàng có trọng lượng và giá trị khác nhau, nhưng hắn chỉ mang theo một cái túi có sức chứa về trọng lượng tối đa là M. Vậy tên trộm nên bỏ vào túi những món nào để đạt giá trị cao nhất trong khả năng mà hắn có thể mang đi được.

Input
	Dòng đầu tiên chứa hai số nguyên dương n và M (1 ≤ n, M ≤ 5000).
	n dòng tiếp theo, mỗi dòng chứa hai số nguyên dương x và y mô tả một đồ vật có trọng lượng x và giá trị y (1 ≤ x ≤ M, 1 ≤ y ≤ 10000).

Output
	In ra tổng giá trị lớn nhất đạt được.
*/

#include <bits/stdc++.h>
using namespace std;

int weight[5005];
int value[5005];
int dp[5005];

int main() {
	int n, M;
	cin >> n >> M;

	for (int i = 0; i < n; ++i) {
		cin >> weight[i] >> value[i];
	}

	for (int i = 0; i <= M; ++i) {
		dp[i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = M; j >= weight[i]; --j) {
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	cout << dp[M] << endl;

	return 0;
}
