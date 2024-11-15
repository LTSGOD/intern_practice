#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"

#define MAX 512

typedef struct BigNum {
    Node* numHead;
    int length;
} BigNum;

void convertStringToBigNumber(char string[], BigNum* bigNumber);
void printBigNumber(BigNum *bigNumber);
void addPositiveBigNumber(BigNum *first, BigNum *second, BigNum *result);
int chr_len(char string[]);

int main() {
    char first[MAX];
    char second[MAX];
    BigNum Bfirst = {NULL, 0};
    BigNum Bsecond = {NULL, 0};;
    BigNum result = {NULL, 0};

    printf("Enter the first big integer = ");
    scanf("%s", first);

    printf("Enter the second big integer = ");
    scanf("%s", second);

    convertStringToBigNumber(first, &Bfirst);
    convertStringToBigNumber(second, &Bsecond);

    addPositiveBigNumber(&Bfirst, &Bsecond, &result);

    printf("%s + %s = ", first, second);
    printBigNumber(&result);



    return 0;
}

void addPositiveBigNumber(BigNum *first, BigNum *second, BigNum *result) {
    int min = first->length > second->length ? second->length : first->length;
    int max = first->length > second->length ? first->length : second->length;

    Node* pfirst = first->numHead;
    Node* psecond = second->numHead;

    bool carry = false;
    int i = 0;

    // 뒷자리부터 계산
    while (pfirst != NULL || psecond != NULL) {

        // 2번째수가 더 긴경우
        if(pfirst == NULL) {
            int sum = psecond->data + carry;
            carry = false;

            if (sum > 9) {
                carry = true;
                sum -= 10;
            }

            push(&result->numHead, sum);
            
            psecond = psecond->next;
            continue;
        }

        // 1번째수가 더 긴경우
        if(psecond == NULL) {
            int sum = pfirst->data + carry;
            carry = false;

            if (sum > 9) {
                carry = true;
                sum -= 10;
            }

            push(&result->numHead, sum);
            
            pfirst = pfirst->next;
            continue;
        }

        int nfirst = pfirst->data;
        int nsecond = psecond->data;

        int sum = nfirst + nsecond + carry;

        carry = false;

        if (sum > 9) {
            carry = true;
            sum -= 10;
        }

        // result data 추가
        push(&result->numHead, sum);

        // 다음 자리
        pfirst = pfirst->next;
        psecond = psecond->next;
        
    }

    if (carry) {
        push(&result->numHead, 1);
    }
}

void convertStringToBigNumber(char string[], BigNum* bigNumber) {
    int len = chr_len(string);

    for(int i = 0; i < len; i++) {
        push(&bigNumber->numHead, string[i] - '0' );
    }

    bigNumber->length = len;
}

void printBigNumber(BigNum *bigNumber) {
    Node* p = bigNumber->numHead;
    while(p != NULL) {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}

int chr_len(char string[]) {
    char* p = string;
    int count = 0;
    while(*p) {
        count++;
        p++;
    }
    return count;
}