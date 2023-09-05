#include <iostream>
#include <vector>

std::vector<int> func2(std::string*);
bool func(std::string*, std::string*);

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string a, b;
        std::cin >> a >> b;
        if (a.size() == b.size() && func(&a, &b))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}

bool func(std::string* a, std::string* b)
{
    while (a->size() > 0)
    {
        if (func2(a) != func2(b))
            return false;
    }
    return true;
}

std::vector<int> func2(std::string* s)
{
    std::string t = *s;
    s->clear();
    std::vector<int> v(0);
    for (int i = 1; i < t.size(); ++i)
    {
        if (t[0] == t[i])
            v.push_back(i);
        else
            s->push_back(t[i]);
    }
    return v;
}