#include <iostream>

using namespace std;

int a[100] = {};
bool ok[100] = {};
int n;

void print() {
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

void Try(int i) {


    for (int j = 1; j <= n; ++j) {

        if (!ok[j]) {

            a[i] = j;
            ok[j] = true;
        
            if (i == n) 
                print();
            else 
                Try(i + 1);
            
            ok[j] = false;

        }
    }

}

int main(void) {

    cin >> n;
    Try(1);
    
}
