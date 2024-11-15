#include <stdio.h>
#include <stdbool.h>

int computeGCD(int x, int y);
long computeLCM(int x, int y);
void recursion(int depth); // 1 ~ 6 순열 방문

bool visited[6]; // result 방문 배열
int result[6]; // 후보 문자열
int max_result[6]; // 가장 큰 LCM 갖는 문자열
const int buffer[6] = {1,2,3,4,5,6}; // 1 ~6 숫자 배열
int index = 0; // result index(stack 처럼 사용하기)
int I, M, B,A,C,K;
int max = -1; // 가장 큰 LCM 값

int main() {

    recursion(0); // 전체탐색해서 조건 맞는 수 찾기

    printf("LCM(%d, %d) = %d", max_result[0]*10 + max_result[1], max_result[2]*1000 + max_result[3] *100 + max_result[4] * 10 + max_result[5], max);

    return 0;
}

void recursion(int depth) {

    // 탈출 조건
    if (depth == 6) {
        I = result[0];
        M = result[1];
        B = result[2];
        A = result[3];
        C = result[4];
        K = result[5];

        // 조건식 맞는지 check 
        if (A * I * K == B * M * K + A* M * C) {
            printf("%d.%d\n", I*10 + M, B*1000 + A *100 + C * 10 + K);
            int lcm = computeLCM(I*10 + M, B*1000 + A *100 + C * 10 + K);

            //LCM 최댓값 갱신
            if (max < lcm) {
                max = lcm;
                for (int i = 0; i <6; i++) {
                    max_result[i] = result[i];
                }
            }
        }

        return;
    }
    
    // 1 ~ 6 순열 
    for (int i = 0; i < 6; i++) {
        if (visited[i]) {
            continue;
        }
        result[index++] = buffer[i];
        visited[i] = true;
        recursion(depth + 1);
        visited[i] = false;
        index--;
    }
}

long computeLCM(int x, int y) {

    long gcd = computeGCD(x, y);

    return (x / gcd) * (y / gcd) * gcd;
}

int computeGCD(int x, int y) {
    if (y > x) {
        int tmp = x;
        x = y;
        y = tmp;
    }

    if (x % y == 0) return y;

    return computeGCD(y, x % y);
}