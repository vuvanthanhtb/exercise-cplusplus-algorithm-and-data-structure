/*
LIỆT KÊ BỘ K SỐ TỪ N SỐ NGUYÊN DƯƠNG ĐẦU TIÊN
	Cho hai số nguyên dương n và k (k ≤ n). 
	Hãy liệt kê các bộ k số từ n số nguyên dương đầu tiên thoả mãn tính chất: các số từ trái sang phải có thể trùng nhau và có thứ tự không giảm. 
	Ví dụ với n = 3 và k = 2 thì các bộ thoả mãn là: {1,1} {1,2} {1,3} {2,2} {2,3} {3,3}
	Với n = 3 và k = 3 thì ta có kết quả như trong test ví dụ. 

Input
	Chỉ có 1 dòng ghi 2 số n và k (1 < k ≤ n ≤ 12).

Output
	Ghi ra màn hình lần lượt các bộ k số theo mô tả đề bài, mỗi kết quả trên một dòng, các số cách nhau một khoảng trống.
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
int boSo[15];

void quaylui(int viTri, int giaTriBatDau) {
	if (viTri == k) {
		for (int i = 0; i < k; i++) {
			cout << boSo[i];
			if (i < k - 1) cout << " ";
		}
		cout << endl;
		return;
	}
	
	for (int i = giaTriBatDau; i <= n; i++) {
		boSo[viTri] = i;
		quaylui(viTri + 1, i);
	}
}

int main() {
	cin >> n >> k;
	quaylui(0, 1);
	return 0;
}

