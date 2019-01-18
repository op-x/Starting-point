/*************************************************************************
	> File Name: 47.HZOJ.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月16日 星期三 10时53分11秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, V;
    int v[10005] = {0}, w[10005] = {0}, dp[10005] = {0};
    cin >> n >> V;
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
