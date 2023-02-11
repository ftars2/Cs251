#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void CompareSets(set<int> data_sequence_1, set<int> data_sequence_2) {
  set<int> difference_1, difference_2;
  set_difference(data_sequence_1.begin(), data_sequence_1.end(),
                 data_sequence_2.begin(), data_sequence_2.end(),
                 inserter(difference_1, difference_1.begin()));
  set_difference(data_sequence_2.begin(), data_sequence_2.end(),
                 data_sequence_1.begin(), data_sequence_1.end(),
                 inserter(difference_2, difference_2.begin()));
  
  cout << "Unique values in data sequence 1: ";
  for (auto i : difference_1) {
    cout << i << " ";
  }
  cout << endl;
  
  cout << "Unique values in data sequence 2: ";
  for (auto i : difference_2) {
    cout << i << " ";
  }
  cout << endl;
}


int main() {
  int n;
  cout << "Enter the number of data points: ";
  cin >> n;
  
  set<int> data_sequence_1;
  set<int> data_sequence_2;
  
  cout << "Enter the data points (integers):\n";
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i < n/2) {
      data_sequence_1.insert(x);
    } else {
      data_sequence_2.insert(x);
    }
  }
  
  CompareSets(data_sequence_1, data_sequence_2);
  return 0;
}
