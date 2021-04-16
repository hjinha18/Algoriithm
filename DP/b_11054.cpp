/*
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면,
그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,
{1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하시오.

입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다.
(1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.
*/

#include<iostream>
#define max(a, b) ((a>b)?a:b)
using namespace std;

int d[1001][2]; //0:증가 1:증가하다 감소 2:감소
int a[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[1][0] = 1; d[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i][0] = 1;
		d[i][1] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && d[i][0] < d[j][0] + 1) {
				d[i][0] = d[j][0] + 1; //증가
			}
			else if (a[i] < a[j] && ((d[i][1] < d[j][0] + 1) || (d[i][1] < d[j][1] + 1))) {
				d[i][1] = max(d[j][0], d[j][1]) + 1; //감소
			}
		}
	}
	int max2 = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i][0] > max2)
			max2 = d[i][0];
		if (d[i][1] > max2)
			max2 = d[i][1];
	}
	cout << max2;
}
