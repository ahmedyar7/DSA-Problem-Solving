#include <iostream>
using namespace std;

void reverse_str(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    string ros = s.substr(1);
    reverse_str(ros);
    cout << s[0];
}

void replace_pi(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replace_pi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replace_pi(s.substr(1));
    }
}

string remove_duplicate(string s)
{
    if (s.length() == 0) // Base case: if the string is empty
    {
        return ""; // Return an empty string
    }
    char ch = s[0];                             // Store the first character
    string ans = remove_duplicate(s.substr(1)); // Recursive call with the rest of the string

    // If the first character of the remaining string matches 'ch', skip 'ch'
    if (ch == ans[0])
    {
        return ans;
    }
    else
    {
        return (ch + ans); // Otherwise, include 'ch' in the result
    }
}

string move_all_x(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = move_all_x(s.substr(1));
    if (ch == 'x')
    {
        return ans + ch;
    }
    return ch + ans;
}

void subseq(string s, string a)
{
    if (s.length() == 0)
    {
        cout << s << endl;
        return;
    }
    char ch = s[0];
    string ans = s.substr(1);

    subseq(ans, a);
    subseq(ans, ch);
}

int main()
{
    // reverse_str("Ahmed");
    // replace_pi("pippppiiiipi");

    // cout << remove_duplicate("gfg");
    // cout << move_all_x("ahxmexd");
}