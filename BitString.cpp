#include <iostream>

using namespace std;
#define FOR(i, n) for (int i = 0; i < n; ++i)
int N, K;
int a[1000] = {0};
bool ok[1000] = {0};
int cnt = 0;

void Try(int i) {
    
    for (int j = 0; j <= 1; j++) {
            
            a[i] = j;

            if (i == N) {
                ++cnt;
                if (cnt % 2 == 0) {
                    FOR(k, N) cout << a[k] << " ";
                    cout << endl;
                }
            }
            else 
                 Try(i + 1);

    }


}

int main(void) {

    cin >> N;
    Try(0);
    return 0;
}
