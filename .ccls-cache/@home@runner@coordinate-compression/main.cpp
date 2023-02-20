#include <algorithm>
#include <iostream>
#include <unordered_map>
typedef long long ll;
using namespace std;
int main() {
  int n;
  cin >> n;
  ll arr[n];
  unordered_map<ll, int> mp;
  int current = -1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);
  for (int x : arr) {
    if (x > current) {
      current++;
    }
    mp[x] = current;
  }
}