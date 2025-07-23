/*
LIỆT KÊ TẬP CON - 4
	Cho dãy số A có N số nguyên dương không quá 9 chữ số.
	Hãy tạo ra các dãy ký tự số khác nhau bằng cách ghép đúng K số trong dãy A lại với nhau,
	các số được ghép theo đúng thứ tự trước sau như trong dãy ban đầu.  
	Liệt kê các dãy ký tự số khác nhau tạo được theo thứ tự từ điển.

Input
	Dòng đầu ghi số N và K (1 < K < N < 16).
	Dòng thứ 2 ghi lần lượt N số nguyên dương, các số đều không quá 9 chữ số và có thể trùng nhau.

Output
	Ghi ra các dãy chữ số khác nhau tạo được theo thứ tự từ điển.
*/

#include <bits/stdc++.h>
using namespace std;

int N, K;
string danhSachSo[20];
set<string> ketQua;

void quaylui(int viTri, int soSoDaChon, string dayHienTai) {
	if (soSoDaChon == K) {
		ketQua.insert(dayHienTai);
		return;
	}
	
	if (viTri >= N || (N - viTri) < (K - soSoDaChon)) {
		return;
	}
	
	quaylui(viTri + 1, soSoDaChon + 1, dayHienTai + danhSachSo[viTri]);
	quaylui(viTri + 1, soSoDaChon, dayHienTai);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int so;
		cin >> so;
		danhSachSo[i] = to_string(so);
	}
	
	quaylui(0, 0, "");
	
	for (const string& day : ketQua) {
		cout << day << endl;
	}
	return 0;
}