/*
LIỆT KÊ TẬP CON - 1
	Cho một xâu ký tự S có N từ chỉ bao gồm các chữ cái viết hoa.
	Hãy liệt kê tất cả các từ khác nhau tạo được bằng cách ghép các từ trong xâu S lại với nhau,
	có thể ghép với bất cứ số lượng từ 1 đến đủ N từ nhưng vẫn giữ nguyên thứ tự trước sau như trong xâu ban đầu.

Input
	Dòng đầu ghi số N (1 < N < 16).
	Dòng thứ 2 ghi lần lượt N từ, mỗi từ có độ dài lớn hơn 1 nhưng không quá 20, các từ có thể trùng nhau.

Output
	Ghi ra các từ khác nhau tạo được theo thứ tự từ điển.
*/

#include <bits/stdc++.h>
using namespace std;

char tu[16][21];
char ketQua[100000][321];
int soLuongKetQua = 0;
int N;

void sinhTu(char tuHienTai[], int viTri, int tuThu) {
	if (tuThu == N) {
		strcpy(ketQua[soLuongKetQua], tuHienTai);
		soLuongKetQua++;
		return;
	}
	
	sinhTu(tuHienTai, viTri, tuThu + 1);
	
	char tuMoi[321];
	strcpy(tuMoi, tuHienTai);
	strcat(tuMoi, tu[tuThu]);
	sinhTu(tuMoi, viTri + strlen(tu[tuThu]), tuThu + 1);
}

int soSanh(const void* a, const void* b) {
	return strcmp((char*)a, (char*)b);
}

void loaiBoTrungLap() {
	qsort(ketQua, soLuongKetQua, sizeof(ketQua[0]), soSanh);
	
	int viTriMoi = 0;
	for (int i = 0; i < soLuongKetQua; i++) {
		if (i == 0 || strcmp(ketQua[i], ketQua[viTriMoi - 1]) != 0) {
			if (i != viTriMoi) {
				strcpy(ketQua[viTriMoi], ketQua[i]);
			}
			viTriMoi++;
		}
	}
	soLuongKetQua = viTriMoi;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tu[i];
	}
	
	soLuongKetQua = 0;
	char tuBanDau[321] = "";
	sinhTu(tuBanDau, 0, 0);
	
	loaiBoTrungLap();
	
	int batDau = 0;
	if (soLuongKetQua > 0 && strlen(ketQua[0]) == 0) {
		batDau = 1;
	}
	
	for (int i = batDau; i < soLuongKetQua; i++) {
		cout << ketQua[i] << '\n';
	}
	
	return 0;
}