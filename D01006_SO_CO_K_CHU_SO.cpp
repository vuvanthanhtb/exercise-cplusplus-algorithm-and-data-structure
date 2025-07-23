/*
SỐ CÓ K CHỮ SỐ
	Cho xâu ký tự S có N chữ số thập phân.
	Hãy liệt kê các số khác nhau có K chữ số lấy từ K vị trí khác nhau trong xâu S theo thứ tự từ nhỏ đến lớn.

Input
	Dòng đầu ghi số bộ test T (T < 10).
	Dòng thứ 2 ghi xâu S sau đó là một khoảng trống rồi đến số K (1 < K < N < 20).

Output
	Với mỗi bộ test, ghi ra lần lượt các số khác nhau tạo được theo thứ tự từ nhỏ đến lớn.
*/

#include <bits/stdc++.h>
using namespace std;

set<string> sinhSo(string &xau, int k) {
	set<string> tapKetQua;
	int n = xau.length();
	vector<int> chiSo(k);

	function<void(int, int)> quaylui = [&](int viTri, int batDau) {
		if (viTri == k) {
			string so = "";
			for (int i = 0; i < k; ++i)
				so += xau[chiSo[i]];
			tapKetQua.insert(so);
			return;
		}
		for (int i = batDau; i <= n - (k - viTri); ++i) {
			chiSo[viTri] = i;
			quaylui(viTri + 1, i + 1);
		}
	};

	quaylui(0, 0);
	return tapKetQua;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string xau;
		int k;
		cin >> xau >> k;

		set<string> ketQua = sinhSo(xau, k);
		for (const string &so : ketQua)
			cout << so << '\n';
	}

	return 0;
}
