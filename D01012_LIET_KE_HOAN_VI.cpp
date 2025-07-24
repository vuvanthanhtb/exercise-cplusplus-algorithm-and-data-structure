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

int n, m;
int ketQua[10];
bool daSuDung[11];

void inKetQua() {
    for (int i = 0; i < n - 1; ++i) {
        cout << ketQua[i] << " ";
    }
    cout << m << endl;
}

void quaylui(int viTri) {
    if (viTri == n - 1) {
        inKetQua();
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (i != m && !daSuDung[i]) {
            ketQua[viTri] = i;
            daSuDung[i] = true;
            
            quaylui(viTri + 1);
            
            daSuDung[i] = false;
        }
    }
}

void lietKeHoanVi() {
    for (int i = 0; i <= n; ++i) {
        daSuDung[i] = false;
    }
    quaylui(0);
}

int main() {
    cin >> n >> m;
    lietKeHoanVi();

    return 0;
}