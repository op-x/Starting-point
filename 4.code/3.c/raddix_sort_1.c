/*************************************************************************
	> File Name: raddix_sort.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月21日 星期日 11时01分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void raddix_sort(int *num, int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    int cnt[65536] = {0};
    
    // 先排低位
    for (int i = 0; i < n; i++) cnt[num[i] & 0xffff]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    cnt[0] = 0;
    for (int i = 65536; i >= 1; i--) cnt[i] = cnt[i - 1];
    for (int i = 0; i < n; i++) temp[cnt[(num[i] & 0xffff)]++] = num[i];
    
    memset(cnt, 0, sizeof(cnt));
    
    // 排高位
    for (int i = 0; i < n; i++) cnt[(temp[i] >> 16) & 0xffff]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    cnt[0] = 0;
    for (int i = 65536; i >= 1; i--) cnt[i] = cnt[i - 1];
    for (int i = 0; i < n; i++) num[cnt[(temp[i] >> 16) & 0xffff]++] = temp[i];
    
    return ;
}

void output(int *num, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    return ;
}

int main() {
    srand(time(0));
    int arr[100];
    for (int i = 0; i < 80; i++) {
        arr[i] = rand() % 0x7fffffff; 
    }
    raddix_sort(arr, 60);
    output(arr, 60);
    return 0;
}
