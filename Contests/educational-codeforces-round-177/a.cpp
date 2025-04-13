#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    
    int T, jamJar, jamKg, berryKg;
    cin >> T;
    while(T--) {
        cin >> jamJar;
        jamKg = jamJar * 3;
      
        // jamKg = 3/4(berryKg * 2 )
        // jamKg = 3/2 * berryKg
        // jamKg * 2/3 = berryKg
        berryKg = (jamKg * 2) / 3;

        cout << berryKg << endl;
    }
    

    return 0;
}
