#include <stdio.h>
#include <stdbool.h>

int computeGCD(int x, int y);
long computeLCM(int x, int y);
void recursion(int depth); // 1 ~ 6 ���� �湮

bool visited[6]; // result �湮 �迭
int result[6]; // �ĺ� ���ڿ�
int max_result[6]; // ���� ū LCM ���� ���ڿ�
const int buffer[6] = {1,2,3,4,5,6}; // 1 ~6 ���� �迭
int index = 0; // result index(stack ó�� ����ϱ�)
int I, M, B,A,C,K;
int max = -1; // ���� ū LCM ��

int main() {

    recursion(0); // ��üŽ���ؼ� ���� �´� �� ã��

    printf("LCM(%d, %d) = %d", max_result[0]*10 + max_result[1], max_result[2]*1000 + max_result[3] *100 + max_result[4] * 10 + max_result[5], max);

    return 0;
}

void recursion(int depth) {

    // Ż�� ����
    if (depth == 6) {
        I = result[0];
        M = result[1];
        B = result[2];
        A = result[3];
        C = result[4];
        K = result[5];

        // ���ǽ� �´��� check 
        if (A * I * K == B * M * K + A* M * C) {
            printf("%d.%d\n", I*10 + M, B*1000 + A *100 + C * 10 + K);
            int lcm = computeLCM(I*10 + M, B*1000 + A *100 + C * 10 + K);

            //LCM �ִ� ����
            if (max < lcm) {
                max = lcm;
                for (int i = 0; i <6; i++) {
                    max_result[i] = result[i];
                }
            }
        }

        return;
    }
    
    // 1 ~ 6 ���� 
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