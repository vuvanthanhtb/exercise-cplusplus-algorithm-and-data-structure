/*
LIỆT KÊ HOÁN VỊ
	Cho hai số N và M với 0 < M ≤ N < 10;
	Hãy liệt kê các hoán vị của N số nguyên dương đầu tiên mà số M luôn đứng cuối
	Các hoán vị thỏa mãn cần liệt kê theo thứ tự từ điển.

Input
	Chỉ có một dòng ghi hai số N và M

Output
	Liệt kê lần lượt các hoán vị thỏa mãn. Mỗi hoán vị trên một dòng.
*/

#include <bits/stdc++.h>
using namespace std;

int hoanVi[10][10];
int soLuongHoanVi = 0;

void sinhHoanVi(int n, int m, int arr[], bool daSuDung[], int viTri) {
	if (viTri == n) {
		if (arr[n - 1] == m) {
			for (int i = 0; i < n; i++) {
				hoanVi[soLuongHoanVi][i] = arr[i];
			}
			soLuongHoanVi++;
		}
		return;
	}
	
	for (int so = 1; so <= n; so++) {
		if (!daSuDung[so]) {
			arr[viTri] = so;
			daSuDung[so] = true;
			sinhHoanVi(n, m, arr, daSuDung, viTri + 1);
			daSuDung[so] = false;
		}
	}
}

void sinhHoanViConLai(int n, int arr[], bool daSuDung[], int viTri) {
	if (viTri == n - 1) {
		for (int i = 0; i < n; i++) {
			hoanVi[soLuongHoanVi][i] = arr[i];
		}
		soLuongHoanVi++;
		return;
	}
	
	for (int so = 1; so <= n; so++) {
		if (!daSuDung[so]) {
			arr[viTri] = so;
			daSuDung[so] = true;
			sinhHoanViConLai(n, arr, daSuDung, viTri + 1);
			daSuDung[so] = false;
		}
	}
}

void sinhHoanViToiUu(int n, int m) {
	int arr[10];
	bool daSuDung[11] = {false};
	
	arr[n - 1] = m;
	daSuDung[m] = true;
	
	sinhHoanViConLai(n, arr, daSuDung, 0);
}

void sapXepHoanVi(int n) {
	for (int i = 0; i < soLuongHoanVi - 1; i++) {
		for (int j = 0; j < soLuongHoanVi - 1 - i; j++) {
			bool canDoiCho = false;
			for (int k = 0; k < n; k++) {
				if (hoanVi[j][k] < hoanVi[j + 1][k]) {
					break;
				} else if (hoanVi[j][k] > hoanVi[j + 1][k]) {
					canDoiCho = true;
					break;
				}
			}
			if (canDoiCho) {
				for (int k = 0; k < n; k++) {
					int temp = hoanVi[j][k];
					hoanVi[j][k] = hoanVi[j + 1][k];
					hoanVi[j + 1][k] = temp;
				}
			}
		}
	}
}

void timHoanViTheoYeuCau(int n, int m) {
	soLuongHoanVi = 0;
	sinhHoanViToiUu(n, m);
	sapXepHoanVi(n);
}

int main() {
	int N, M;
	cin >> N >> M;
	
	timHoanViTheoYeuCau(N, M);
	
	for (int i = 0; i < soLuongHoanVi; i++) {
		for (int j = 0; j < N; j++) {
			cout << hoanVi[i][j];
			if (j < N - 1) cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}