/*
LIỆT KÊ TẬP CON - 2
	Cho một xâu ký tự S có N từ chỉ bao gồm các chữ cái viết hoa.
	Hãy liệt kê tất cả các từ khác nhau tạo được bằng cách ghép đúng K từ trong xâu S lại với nhau,
	vẫn giữ nguyên thứ tự trước sau như trong xâu ban đầu.

Input
	Dòng đầu ghi số N và số K (1 < K < N < 16).
	Dòng thứ 2 ghi lần lượt N từ, mỗi từ có độ dài lớn hơn 1 nhưng không quá 20, các từ có thể trùng nhau.

Output
	Ghi ra các từ khác nhau tạo được theo thứ tự từ điển.
*/

#include <bits/stdc++.h>
using namespace std;

int N, K;
string danhSachTu[20];
set<string> ketQua;

void quaylui(int viTri, int soTuDaChon, string tuHienTai) {
	if (soTuDaChon == K) {
		ketQua.insert(tuHienTai);
		return;
	}
	
	if (viTri >= N || (N - viTri) < (K - soTuDaChon)) {
		return;
	}
	
	quaylui(viTri + 1, soTuDaChon + 1, tuHienTai + danhSachTu[viTri]);
	quaylui(viTri + 1, soTuDaChon, tuHienTai);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> danhSachTu[i];
	}
	
	quaylui(0, 0, "");
	
	for (const string& tu : ketQua) {
		cout << tu << endl;
	}
	return 0;
}