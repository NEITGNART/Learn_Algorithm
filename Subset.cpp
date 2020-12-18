#include <iostream>

using namespace std;
#define FOR(i, n) for (int i = 1; i <= n; ++i)
int N, K;

int a[1000] = {0};

void print() {

   for (int i = 1; i <= K; ++i) cout << a[i];
    cout << endl;
}

int cnt = 0;

void Try(int i) {
    
    for (int j = a[i-1] + 1; j <= N; j++) {
        a[i] = j;
        if (i == K) {
            ++cnt;
        }
        else 
            Try(i + 1);
    }


}

int main(void) {

    cin >> N >> K;
    for (int i = 1; i <= K; ++i) a[i] = i;

    Try(1);
    cout << cnt << endl;
    return 0;
}
