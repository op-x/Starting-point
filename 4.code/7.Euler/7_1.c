/*************************************************************************
	> File Name: 7_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 18时00分25秒
 ************************************************************************/

#include<stdio.h>

#define MAX_RANGE 10000

int prime[MAX_RANGE + 5] = {0};

int main() {
    for (int i = 2; i * i <= MAX_RANGE; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_RANGE; j += i) {
            if (!prime[j]) prime[j] = i;
        }
    }
    int n;
    while (scanf("%d", &n) != EOF && n >= 0) {
        //输出n的最小质因子
        printf("%d\n", prime[n]);
    }
    return 0;
}
