#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	int n;	// n*n 배열을 설정하기 위해 입력받을 n값을 변수로 설정
	int r = -1, c = 0;	// 달팽이 모양 배열을 나타낼 행 변수 r, 열 변수 c 설정
	int dir = 1; // 방향을 나타내는 변수 
	cout << "2차원 배열 n*n의 원소 : ";
	cin >> n;
	int S = n;
	int a = n * n;	// n*n을 표현하는 변수 a

	int** arr;
	arr = new int* [n];
	
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	// 2차원 배열에 값을 넣는 알고리즘
	while (a > 0) {
		for (int i = 0; i < S; i++) {
			r += dir;
			arr[r][c] = a;
			a -= 1;
		}

		S -= 1;
		for (int i = 0; i < S; i++) {
			c += dir;
			arr[r][c] = a;
			a -= 1;
		}
		dir = dir * (-1);
	}

	// 2차원 배열 결과 출력 부분
	for (int i = 0; i < n * n; i++) {
		int x = i / n;	// 행
		int y = i % n;	// 열
		cout << arr[x][y] << " ";
		if ((i % n) == n - 1) cout << endl;
	}
	
	return 0;
}
