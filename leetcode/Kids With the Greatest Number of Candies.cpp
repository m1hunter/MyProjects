#include "iostream"
#include "vector"
#include "algorithm"


using namespace std;

int findMax(vector<int>& candies)
{
    int maxx = *max_element(candies.begin(), candies.end());
    return maxx;
}

int main()
{
    int n = 0;
    int extraCandies = 0;
    cin >> n;
    cin >> extraCandies;

    vector<int>candies(n);
    vector<bool>result(n);

    for (int i = 0; i < n; i++)
        cin >> candies[i];
    
    int maxxx = findMax(candies);
    
    for (int i = 0; i < n; ++i)
    {
        if (candies[i] + extraCandies < maxxx)
        {
            result[i] = false;
        }
        else
            result[i] = true;
    }
    for (int i = 0; i < n; ++i)
        cout << result[i];    
}