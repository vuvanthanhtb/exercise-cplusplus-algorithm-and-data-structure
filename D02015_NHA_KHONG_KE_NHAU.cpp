/*
NHÀ KHÔNG KỀ NHAU
	Có N ngôi nhà trên một dãy phố, mỗi ngôi nhà chứa đựng một số lượng tài sản khác nhau. Một tên trộm muốn ăp cắp được nhiều nhất tài sản của dãy phố nhưng không muốn lấy tài sản của hai nhà kề nhau. Hãy cho biết, bằng cách đó tên trộm có thể đánh cắp được nhiều nhất bao nhiêu tài sản.

Input:
	Dòng đầu tiên đưa vào số lượng bộ test T.
	Những dòng kế tiếp đưa vào các bộ test.
	Mỗi bộ test gồm hai dòng:
	- dòng thứ nhất là một số N là số lượng ngôi nhà;
	- dòng tiếp theo đưa vào N số là tài sản tương ứng trong mỗi ngôi nhà;
	các số được viết cách nhau một vài khoảng trống.
	T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤106; 1≤A[i] ≤107.

Output:
	Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int giaTriCaoNhatNhaKhongKeNhau(int n) {
	if (n == 0) return 0;
	if (n == 1) return a[0];

	long long truoc1 = a[0];
	long long truoc2 = max(a[0], a[1]);

	for (int i = 2; i < n; ++i) {
		long long hienTai = max(truoc2, truoc1 + a[i]);
		truoc1 = truoc2;
		truoc2 = hienTai;
	}

	return truoc2;
}

int main() {
	int soBoTest;
	cin >> soBoTest;

	while (soBoTest--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		cout << giaTriCaoNhatNhaKhongKeNhau(n) << endl;
	}

	return 0;
}
