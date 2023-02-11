#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

int main()
{
    set<string> items;
    map<string, set<string>> mapple;
    string temp1;
    string temp2;
    char c;
    int i=0;
    while (cin >> temp1 >> c >> temp2) {
        if (temp2=="exit")||(temp1 == "exit")) {
            break;
        }
        temp1 = temp1.substr(0, temp1.find(";"));
        temp2 = temp2.substr(0, temp2.find(";"));
        if (mapple.count(temp1) == 1) {
            mapple[temp1].insert(temp2);
        } else {
            set<string> temp_set;
            temp_set.insert(temp2);
            mapple.emplace(temp1, temp_set);
        }
    }

    for (const auto &entry : mapple) {
        string key = entry.first;
        set<string> val = entry.second;

        cout << key << ": {";
        for (const auto &value : val) {
            cout << value << ", ";
        }
        cout << "}" << endl;
    }

    return 0;
}