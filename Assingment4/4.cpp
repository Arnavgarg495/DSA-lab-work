#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cout << "Enter characters (with spaces): ";
    getline(cin, s);

    queue<char> q;
    int freq[256] = {0};

    cout << "Output: ";

    for (char c : s) {
        if (c == ' ') continue; 

        freq[c]++;
        q.push(c);

        
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        
        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    return 0;
}
