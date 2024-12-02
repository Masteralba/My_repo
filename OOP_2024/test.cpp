#include <bits/stdc++.h>
using namespace std;

// A quick way to split strings separated via any character
// delimiter.
void adv_tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        cout << word << endl;
    }
}

int main(int argc, char const* argv[])
{
    string b = "10|12|3|1|2|3|h|h|v|0,0|1,2|5,6";
    adv_tokenizer(b, '|');
    cout << endl;
    return 0;
}