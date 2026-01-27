#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    char attendance;
    int prefixSum = 0;
    int maxLength = 0;

    // unordered_map declaration
    unordered_map<int, int> mp;

    // Base condition to handle subarray from index 0
    mp[0] = -1;

    for (int i = 0; i < N; i++) {
        cin >> attendance;

        // Convert P to +1 and A to -1
        if (attendance == 'P')
            prefixSum += 1;
        else if (attendance == 'A')
            prefixSum -= 1;

        // Check if prefixSum already exists
        if (mp.find(prefixSum) != mp.end()) {
            int length = i - mp[prefixSum];
            if (length > maxLength)
                maxLength = length;
        } 
        else {
            // Store first occurrence of prefixSum
            mp[prefixSum] = i;
        }
    }

    cout << maxLength << endl;
    return 0;
}
