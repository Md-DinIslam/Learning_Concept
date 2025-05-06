#include <bits/stdc++.h>
using namespace std;
void PrintBinary(int nums) {
    for (int i = 8; i >= 0; --i) {
        cout << ((nums >> i) & 1);
    }
    cout << '\n';
}
int main()
{
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int nums;
    cin >> nums;
    int temp = nums;
    PrintBinary(nums);
    if (nums & 1) cout << "Odd" << endl;
    else cout << "Even" << endl;
    int cnt = 0;
    // Set Count;
    for (int i = 31; i >= 0; --i) {
        if ((nums & (1 << i)) != 0)
            cnt++;
    }
    int n = nums;
    cout << cnt << endl;
    // Bit Set 0 --> 1
    PrintBinary(nums | (1 << 1));
    // Bit Reverse
    PrintBinary(~nums);
    // Bit Unset 1 --> 0
    PrintBinary(nums & (~(1 << 2)));
    // Toggle Bit
    PrintBinary(nums ^ (1 << 2));
    // Divide by 2
    cout << (nums >> 1) << endl;
    // Multiply by 2
    cout << (nums << 1) << endl;
    PrintBinary('c');
    for (char ch = 'a'; ch < 'e'; ch++) {
        // LowerCase to UpperCase
        PrintBinary(int (ch & '_'));
    }
    // UpperCase to LowerCase
    for (char ch = 'A'; ch < 'E'; ch++) {
        PrintBinary(int (ch | ' '));
    }
    // LSB Unset
    int x = 2;
    int lsb = temp & (~((1 << x + 1) - 1));
    PrintBinary(lsb);
    // MSB Unset
    int msb = temp & ((1 << x) - 1);
    PrintBinary(msb);
    // Power of 2
    if (nums & (nums - 1)) cout << "Not power of two" << '\n';
    else cout << "Power of 2" << endl;
    return 0;
}