/*
LIỆT KÊ TẬP CON - 3
	Cho dãy số A có N số nguyên dương không quá 9 chữ số.
	Hãy tạo ra các dãy ký tự số khác nhau bằng cách ghép các số trong dãy A lại với nhau,
	có thể ghép với bất cứ số lượng từ 1 đến đủ N số nhưng vẫn giữ nguyên thứ tự trước sau như trong dãy ban đầu.  
	Liệt kê các dãy ký tự số khác nhau tạo được theo thứ tự từ điển.

Input
	Dòng đầu ghi số N (1 < N < 16).
	Dòng thứ 2 ghi lần lượt N số nguyên dương, các số đều không quá 9 chữ số và có thể trùng nhau.

Output
	Ghi ra các dãy chữ số khác nhau tạo được theo thứ tự từ điển.
*/

#include <bits/stdc++.h>
using namespace std;

int N;
string danhSachSo[20];
set<string> ketQua;

void quaylui(int viTri, string dayHienTai) {
	if (!dayHienTai.empty()) {
		ketQua.insert(dayHienTai);
	}
	
	if (viTri >= N) {
		return;
	}
	
	quaylui(viTri + 1, dayHienTai + danhSachSo[viTri]);
	
	quaylui(viTri + 1, dayHienTai);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int so;
		cin >> so;
		danhSachSo[i] = to_string(so);
	}
	
	quaylui(0, "");
	
	for (const string& day : ketQua) {
		cout << day << endl;
	}
	return 0;
}