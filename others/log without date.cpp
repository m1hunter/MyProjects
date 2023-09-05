#include <iostream>
#include <string>

using namespace std;

int main()
{
    int logcount = 0;
    int daycount = 0;
    string date;
    cin >> logcount;
    string refdate = "23:59:59";
    for (int i = 0; i < logcount; ++i)
    {
        cin >> date;
        if (date <= refdate || date == "00:00:00")
            daycount++;
        refdate = date;
    }
    cout << daycount;
    return 0;
}