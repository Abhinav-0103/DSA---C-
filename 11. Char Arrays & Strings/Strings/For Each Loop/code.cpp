#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    for(char ch : str) {
        cout << ch << "-";
    }

    return 0;
}