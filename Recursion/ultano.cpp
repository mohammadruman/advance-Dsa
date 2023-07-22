#include <iostream>
using namespace std;
void printfromback(int i, int n)
{
    if (i < 1)
    {
        return;
    }
    cout << i << endl;
    printfromback(i - 1, n);
}
int main()
{
    int n;
    cin >> n;
    printfromback(n, n);
    return 0;
}