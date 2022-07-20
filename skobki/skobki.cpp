#include <iostream>
#include <string>
#include <set>
using namespace std;

string to_lower(string word) {
    for (auto& c : word) {
        c = tolower(c);
    }
    return word;
}

bool check_next(int letter_i, string word) {
    for (int i = letter_i + 1; i <= word.length(); i++) {
        if (word[letter_i] == word[i]) {
            return 1;
        }
    }
    return 0;
}

string convert(string word) {
    set<char> exist{};
    string new_word = "";
    word = to_lower(word);
    for (int i = 0; i < word.length(); i++) {
        if (exist.find(word[i]) != exist.end()) {
            new_word += ")";
        } else {
            exist.insert(word[i]);
            if (check_next(i, word)) {
                new_word += ")";
            } else {
                new_word += "(";
            }
        }
    }
    return new_word;
}

int main() {
    string word;
    getline(cin, word);
    cout << convert(word);

    return 0;
}