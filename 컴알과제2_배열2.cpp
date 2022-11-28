#include <iostream>
using namespace std;                         

// 변수 선언
enum Direction { LD, RU };

Direction dir{ Direction::LD };
int arr[101][101];
int r = 0, c = 0;
int num = 1;

// leftDown 함수 구현
void leftDown(int n) {
	if (c < n && r >= 0) {
		arr[c++][r--] = num++;
	}
	if (c >= n) {
		c--;
		r += 2;
		dir = Direction::RU;
	}
	else if (r < 0) {
		r++;
		dir = Direction::RU;
	}
}

// rightUp 함수 구현
void rightUp(int n) {
	if (r < n && c >= 0) {
		arr[r++][c--] = num++;
	}
	if (r >= n) {
		r--;
		c += 2;
		dir = Direction::LD;
	}
	else if (c < 0) {
		c++;
		dir = Direction::LD;
	}
}

// main 함수
int main(void) {
	int n;
	cout << "2차원 배열 n*n의 원소 : ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = -1;
		}
	}

	while (true) {
		if (dir == Direction::LD) {
			leftDown(n);
		}
		else {
			rightUp(n);
		}

		if (num > n * n)
			break;
	}

	// 2차원 배열 출력 부분
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
