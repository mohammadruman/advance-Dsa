#include <iostream>
using namespace std;
void print(int i)
{
    if (i == 10)
    {
        return;
    }
    cout << i << endl;
    print(i + 1);
}
int main()
{
    int i = 0;

    print(i);

    return 0;
}