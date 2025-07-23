/*
KÝ TỰ A – B – C
	Hãy liệt kê tất cả các xâu ký tự có độ dài không quá N,
	chỉ tạo bởi các ký tự A, B, C và thỏa mãn các điều kiện sau:
	- Chứa cả ba ký tự A, B, C
	- Số ký tự A không nhiều hơn số ký tự B, số ký tự B không nhiều hơn số ký tự C

Input
	Chỉ có một dòng ghi số N, không quá 12.

Output
	Ghi ra lần lượt các xâu thỏa mãn theo thứ tự độ dài từ ngắn nhất đến dài nhất.
	Nếu có cùng độ dài thì ghi theo thứ tự từ điển.
	Mỗi xâu ghi trên một dòng.
*/

#include <bits/stdc++.h>
using namespace std;

char ketQua[1000000][13];
int soLuongKetQua = 0;

void sinhXauKyTu(char xauHienTai[], int viTri, int doDai, int demA, int demB, int demC) {
	int soViTriConLai = doDai - viTri;
	
	if (demB + soViTriConLai < demA || demC + soViTriConLai < demB) {
		return;
	}
	
	if (viTri == doDai) {
		if (demA > 0 && demB > 0 && demC > 0 && demA <= demB && demB <= demC) {
			for (int i = 0; i < doDai; i++) {
				ketQua[soLuongKetQua][i] = xauHienTai[i];
			}
			ketQua[soLuongKetQua][doDai] = '\0';
			soLuongKetQua++;
		}
		return;
	}
	
	xauHienTai[viTri] = 'A';
	sinhXauKyTu(xauHienTai, viTri + 1, doDai, demA + 1, demB, demC);
	
	xauHienTai[viTri] = 'B';
	sinhXauKyTu(xauHienTai, viTri + 1, doDai, demA, demB + 1, demC);
	
	xauHienTai[viTri] = 'C';
	sinhXauKyTu(xauHienTai, viTri + 1, doDai, demA, demB, demC + 1);
}

bool soSanhXau(int idx1, int idx2) {
	int len1 = strlen(ketQua[idx1]);
	int len2 = strlen(ketQua[idx2]);
	
	if (len1 != len2) {
		return len1 < len2;
	}
	
	int i = 0;
	while (i < len1 && ketQua[idx1][i] == ketQua[idx2][i]) {
		i++;
	}
	
	if (i == len1) return false;
	return ketQua[idx1][i] < ketQua[idx2][i];
}

void sapXepKetQua() {
	for (int i = 1; i < soLuongKetQua; i++) {
		int j = i - 1;
		
		while (j >= 0 && !soSanhXau(j, j + 1)) {
			char temp[13];
			strcpy(temp, ketQua[j]);
			strcpy(ketQua[j], ketQua[j + 1]);
			strcpy(ketQua[j + 1], temp);
			j--;
		}
	}
}

void timTatCaXau(int N) {
	soLuongKetQua = 0;
	char xauTam[13];
	
	for (int doDai = 3; doDai <= N; doDai++) {
		sinhXauKyTu(xauTam, 0, doDai, 0, 0, 0);
	}
	
	sapXepKetQua();
}

int main() {
	int N;
	cin >> N;
	
	timTatCaXau(N);
	
	for (int i = 0; i < soLuongKetQua; i++) {
		cout << ketQua[i] << '\n';
	}
	
	return 0;
}