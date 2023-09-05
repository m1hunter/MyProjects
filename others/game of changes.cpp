#include <iostream>
#include <vector>

using namespace std;

vector<int> func2(string*);
bool func(string*, string*);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        if (a.size() == b.size() && func(&a, &b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

bool func(string* a, string* b)
{
    while (a->size() > 0)
    {
        if (func2(a) != func2(b))
            return false;
    }
    return true;
}

vector<int> func2(string* s)
{
    string t = *s;
    s->clear();
    vector<int> v(0);
    for (int i = 1; i < t.size(); ++i)
    {
        if (t[0] == t[i])
            v.push_back(i);
        else
            s->push_back(t[i]);
    }
    return v;
}