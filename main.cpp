#include <iostream>
#include <vector>
#include <string>

using namespace std;

size_t menu();

int main()
{
    size_t option = 0;

    do
    {
        option = menu();
        switch (option)
        {
        case 1:

            continue;

        case 2:
            continue;

        case 3:

            continue;

        case 4:

            continue;

        case 5:

            continue;

        case 6:

            break;

        default:
            cout << "Please chose a valid number" << endl;
            continue;
        }
    } while (option != 6);
    return 0;
}

size_t menu()
{
    size_t option;

    cout << "-------------------------------------------------" << endl
         << "FILE MANIPULATOR HACK" << endl
         << "Select an option:" << endl
         << "1. Open a File..." << endl
         << "2. Search for Substrings..." << endl
         << "3. Remove Words Containing a Substring" << endl
         << "4. Remove all Repeated Words" << endl
         << "5. Show Statistics" << endl
         << "6. Exit" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}