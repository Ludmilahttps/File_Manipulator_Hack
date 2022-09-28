#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

size_t menu();
size_t open_file(string filename, vector<string> &liststrings);
size_t search();
size_t remove();
size_t remove_duplicates();
size_t statistics();

int main()
{
    size_t option = 0;
    vector<string> liststrings;                       // ve tor que concatena cada file add
    vector<pair<string, vector<string>>> listoffiles; // vetor com o nome dos arquivos e seu vetor de palavras

    do
    {
        option = menu();
        if (option == 1)
        {
            string filename;
            cout << "1. Open a File" << endl
                 << "Digite o nome do arquivo que deseja abrir: " << endl;
            cin >> filename;
            open_file(filename, liststrings);
            continue;
        }
        if (option == 2)
        {
            cout << "2. Search for Substrings" << endl;
            // search();
            continue;
        }
        if (option == 3)
        {
            cout << "3. Remove Words Containing a Substring" << endl;
            remove();
            continue;
        }
        if (option == 4)
        {
            cout << "4. Remove all Repeated Words" << endl;
            remove_duplicates();
            continue;
        }
        if (option == 5)
        {
            cout << "5. Show Statistics" << endl;

            cout << "list:" << endl;
            for (size_t i = 0; i < liststrings.size(); i++)
            {
                cout << "string " << i << " - " << liststrings.at(i) << endl;
            }

            statistics();
            continue;
        }
        if (option == 6)
        {
            cout << "6. Exit" << endl;
            break;
        }
        if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6)
        {
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
         << "1. Open a File" << endl
         << "2. Search for Substrings" << endl
         << "3. Remove Words Containing a Substring" << endl
         << "4. Remove all Repeated Words" << endl
         << "5. Show Statistics" << endl
         << "6. Exit" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}

size_t open_file(string filename, vector<string> &liststrings)
{
    ifstream infile(filename); // abre o arquivo em questão para pegar as strings
    infile.open(filename);

    vector<string> newfile;

    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            istringstream ss_line(line);
            while (ss_line)
            {
                string element;
                ss_line >> element;
                if (element == " ")
                {
                    cin.ignore();
                }
                else
                {
                    liststrings.push_back(element);
                }
            }
        }

        infile.close(); // fecha o arquivo
    }
    return 0;
}

size_t search()
{
    return 0;
}
size_t remove()
{
    return 0;
}
size_t remove_duplicates()
{
    return 0;
}
size_t statistics()
{
    return 0;
}