#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    char attendance;
    int prefixSum = 0;
    int maxLength = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;

    for (int i = 0; i < N; i++) {
        cin >> attendance;
        if (attendance == 'P')
            prefixSum += 1;
        else if (attendance == 'A')
            prefixSum -= 1;
        if (mp.find(prefixSum) != mp.end()) {
            int length = i - mp[prefixSum];
            if (length > maxLength)
                maxLength = length;
        } 
        else {
            mp[prefixSum] = i;
        }
    }
    cout << maxLength << endl;
    return 0;
}
