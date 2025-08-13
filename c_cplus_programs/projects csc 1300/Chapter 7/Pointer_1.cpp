

#include <iostream>
using namespace std;



int main()
{
    const int SIZE = 10;
    string favoriteFood[SIZE];
    string *topFood;
    int i;
    
    topFood = new favoriteFood[SIZE];

    for(i = 0; i < SIZE; ++i)
    {
        cout << "Enter your fav. food #" << i + 1 << endl;
        getline(cin, *(topFood + i));
    }
    
    cout << "\nTop ten Favorite Foods\n";

    for(i = 0; i < SIZE; ++i)
        cout << favoriteFood[i] << endl;

    delete [] topFood;

    return 0;
}

