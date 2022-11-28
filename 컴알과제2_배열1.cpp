#include <iostream>
using namespace std;

int main() {
    int arr[100][100];
    int n;
    //bool check = true;
    cout << "2차원 배열 n*n의 원소 : ";
    cin >> n;

    //자리수를 더하면 같은수가 나온다.
    for (int k = 0, cnt = 1; k <= n + n - 2; k++) {
        for (int i = 0; i < n; i++) {       // 열 반복 부분
            for (int j = 0; j < n; j++) {   // 행 반복 부분
                
                // 행과 열의 합이 k와 같다면 cnt 넣고 값을 증가시키기
                if (i + j == k) {
                    arr[j][i] = cnt++;
                    break;
                }
            }
        }
    }
    // 2차원 배열 결과 출력 부분
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
