#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

bool findSumPair(int sum, vector<int> &v) {
    unordered_set<int> hash; // create an empty hash table
    for (int i = 0; i < v.size(); i++) {
        int temp = sum - v[i];
        if (hash.count(temp)) {
            // if the sum minus the current number is in the hash table,
            // then we have found a pair of numbers that add up to the sum
            cout << "Pair found: " << temp << " and " << v[i] << endl;
            return true;
        }
        hash.insert(v[i]); // add the current number to the hash table
    }
    return false;
}

int main(){
vector <int> v = {1, 4, 45, 6, 10, 8};
int sum = 16;
if (!findSumPair(sum, v))
    cout << "No pair found" << endl;







    return 0;
}