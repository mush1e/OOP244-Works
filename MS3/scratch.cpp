#include <iostream>

using namespace std;

int main()
{
    char name[5];
    cin >> name;
    cout << strlen(name);
    if(cin.fail())
        cout << "failed";

    return 0;
}
