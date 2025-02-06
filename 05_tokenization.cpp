#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> tokenize(const string& source) {
    vector<string> tokens;
    string token;
    for (char ch : source) {
        if (ch == ' ' || ch == '@' || ch == '!' || ch == '_') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    cout << "Input source: ";
    string source;
    getline(cin, source);

    vector<string> tokens = tokenize(source);

    cout << "Tokens:\n";
    for (const string& token : tokens) {
        cout << "'" << token << "'" << endl;
    }

    return 0;
}
