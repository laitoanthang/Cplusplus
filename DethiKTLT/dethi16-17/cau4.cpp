#include <stdio.h>

// Duyệt đến phần tử current_pos, các phần tử i đã được chọn sẽ có fre[i] = false, remain là số phần tử cần phải chọn thêm
void attempt(int n, int a[], int current_pos, bool fre[], int remain) {
	// Đã chọn đủ, in ra kết quả
	if (remain == 0) {
		printf("{");
		for (int i = 0, d = 0; i < n; ++i) {
			if (fre[i] == false) {
				// Phần làm màu, không quan trọng xD
				if (d > 0) {
					printf(" ");
				}
				d = 1;
				printf("%d", a[i]);
			}
		}
		printf("} ");
		return;
	}
	// Thử phần tử được chọn tiếp theo trong đoạn [current_pos; n - 1]
	for (int i = current_pos; i < n; ++i) {
		fre[i] = false;
		attempt(n, a, i + 1, fre, remain - 1);
		fre[i] = true;
	}
}

int main() {
	int n, *a;
	printf("Nhap N: ");
	scanf("%d", &n);
	a = new int[n];
	for (int i = 0; i < n; ++i) {
		printf("A[%d] = ", i);
		scanf("%d", &a[i]);
	}

	for (int i = 0; i <= n; ++i) {
		bool* fre = new bool[n];
		for (int j = 0; j < n; ++j) {
			fre[j] = true;
		}
		attempt(n, a, 0, fre, i);
		printf("\n");
		
		delete[] fre;
	}

	delete[] a;
	return 0;
}