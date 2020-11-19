#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cout << "Introducir el numero de cifras" << endl;
    cin >> n;

    int result;
    for(int i = 1; i <= n; i++)
    {
        for(int j =1; j <=n; j++)
        {

            result = i*j;
            cout << i << "x" << j << "=";
            cout << result << endl;
        }
    }



}