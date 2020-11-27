#include <iostream>
#include <cstdlib>
using namespace std;

int a[10][10];
int x, y;

int pos_max(int j) //saddle points check
{
    int max = 0;
    for (int i = 1; i <= x - 1; i++) {
        if (a[i][j] > a[max][j]) {
            max = i;
        }
    }
    return max;
}

int main() {
    cout << "Enter the number of rows: ";
    cin >> x;
    cout << "Enter the number of columns: ";
    cin >> y;
    cout << "----------------------------" << endl;

    for (int i = 0; i <= x - 1; i++) //input of the matrix
        for (int j = 0; j <= y - 1; j++) {
            cout << "a[" << i + 1 << ", " << j + 1 << "] = ";
            cin >> a[i][j];
        }
    cout << "----------------------------\n";
    for (int i = 0; i <= x - 1; i++) //visualization of the matrix
    {
        for (int j = 0; j <= y - 1; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << "----------------------------\n";

    int r;
    int flag = 0;
    int i = y;

    for (int j = 0; j <= y - 1; j++) {
        r = pos_max(j);
        for (i = 0; i <= y - 1; i++) {
            if (a[r][i] < a[r][j]) {
                break;
            }
        }
        if (i == y) {
            cout << "Saddle points are: ";
            cout << "a[" << r + 1 << ", " << j + 1 << "] = " << a[r][j] << "\n";
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "No saddle points\n";
    }
    cout << "----------------------------\n";
    return 0;
}
