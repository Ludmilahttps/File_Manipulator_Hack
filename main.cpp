#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

size_t menu();
size_t open_file(string filename, vector<string> &liststrings);
size_t search_substring(vector<pair<string, vector<string>>> &ListOfFiles, string search, size_t option);
void remove_duplicates_files(vector<pair<string, vector<string>>> &ListOfFiles);
void remove_duplicates_words(vector<pair<string, vector<string>>> &ListOfFiles);
size_t statistics(const vector<pair<string, vector<string>>> ListOfFiles);
size_t save_file(string Outfilename, vector<pair<string, vector<string>>> &ListOfFiles);

int main()
{
    size_t option = 0;
    vector<string> liststrings;                       // vetor auxiliar que armazena
    pair<string, vector<string>> file;                // pair com o nome do arquivo e vetor de palavras
    vector<pair<string, vector<string>>> ListOfFiles; // vetor contendo file por file

    do
    {
        option = menu();
        if (option == 1)
        {
            string filename;
            cout << "1. Open a File" << endl
                 << "Enter a file to open: " << endl;
            cin >> filename;

            open_file(filename, liststrings);

            file.first = filename;
            file.second = liststrings;

            ListOfFiles.push_back(file);
            liststrings.clear();

            continue;
        }
        if (option == 2)
        {
            cout << "2. Search for Substrings" << endl;
            cout << "Enter a Substring to Search: " << endl;
            string search;
            cin >> search;

            search_substring(ListOfFiles, search, option);

            continue;
        }
        if (option == 3)
        {
            cout << "3. Remove Words Containing a Substring" << endl;
            cout << "Enter a Substring to remove: " << endl;

            string remove;
            cin >> remove;

            search_substring(ListOfFiles, remove, option);
            continue;
        }
        if (option == 4)
        {
            cout << "4. Remove all Repeated Words" << endl;
            remove_duplicates_words(ListOfFiles);
            continue;
        }
        if (option == 5)
        {
            cout << "5. Remove all Repeated Files" << endl;
            remove_duplicates_files(ListOfFiles);
            continue;
        }
        if (option == 6)
        {
            cout << "5. Show Statistics" << endl;
            cout << "File Manipulator Hack Statistics:" << endl;
            statistics(ListOfFiles);
            continue;
        }
        if (option == 7)
        {
            cout << "6. Exit" << endl
                 << "Enter a name to save the file: " << endl;
            string filename;
            cin >> filename;
            save_file(filename, ListOfFiles);
            break;
        }
        if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6 || option != 7)
        {
            cout << "Please chose a valid number" << endl;
            continue;
        }
    } while (option != 7);
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
         << "5. Remove all Repeated Files" << endl
         << "6. Show Statistics" << endl
         << "7. Exit" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}

size_t open_file(string filename, vector<string> &liststrings)
{
    ifstream infile(filename); // abre o arquivo em questão para pegar as strings

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
                if (element.size() == 0)
                {
                    // retira os espaços vazios
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

size_t search_substring(vector<pair<string, vector<string>>> &ListOfFiles, string search, size_t option)
{
    bool find = false; // variável que avisa se alguma substring foi encontrada

    if (ListOfFiles.empty())
    {
        cout << "File Manipulator is empty" << endl;
    }
    else
    {
        for (size_t i = 0; i < ListOfFiles.size(); i++)
        {
            for (size_t j = 0; j < ListOfFiles.at(i).second.size(); j++)
            {
                if (ListOfFiles.at(i).second.at(j).find(search) != string::npos)
                {
                    find = true;
                    if (option == 2)
                    {
                        cout << ListOfFiles.at(i).first << " has substring '" << search << "': " << ListOfFiles.at(i).second.at(j) << endl;
                    }
                    if (option == 3)
                    {
                        cout << "Removing " << ListOfFiles.at(i).second.at(j) << " located in file " << ListOfFiles.at(i).first << endl;
                        ListOfFiles.at(i).second.at(j).erase();
                        ListOfFiles.at(i).second.erase((ListOfFiles.at(i).second.begin(), ListOfFiles.at(i).second.end() + i));
                    }
                }
            }
        }

        if (find == false)
        {
            cout << "Substring not found" << endl;
        }
    }
    return 0;
}

void remove_duplicates_files(vector<pair<string, vector<string>>> &ListOfFiles)
{
    if (ListOfFiles.empty())
    {
        cout << "File Manipulator is empty" << endl;
    }
    else
    {
        sort(ListOfFiles.begin(), ListOfFiles.end());
        ListOfFiles.erase(unique(ListOfFiles.begin(), ListOfFiles.end()), ListOfFiles.end());
    }
}

void remove_duplicates_words(vector<pair<string, vector<string>>> &ListOfFiles)
{
    if (ListOfFiles.empty())
    {
        cout << "File Manipulator is empty" << endl;
    }
    else
    {
        for (size_t i = 0; i < ListOfFiles.size(); i++)
        {
            sort(ListOfFiles.at(i).second.begin(), ListOfFiles.at(i).second.end());
            ListOfFiles.at(i).second.erase(unique(ListOfFiles.at(i).second.begin(), ListOfFiles.at(i).second.end()), ListOfFiles.at(i).second.end());
        }
    }
}

size_t statistics(const vector<pair<string, vector<string>>> ListOfFiles)
{
    if (ListOfFiles.empty())
    {
        cout << "File Manipulator is empty" << endl;
    }
    else
    {
        for (size_t i = 0; i < ListOfFiles.size(); i++)
        {
            cout << "File " << ListOfFiles.at(i).first << " has " << ListOfFiles.at(i).second.size() << " words." << endl;
        }
    }
    return 0;
}

size_t save_file(string OutFilename, vector<pair<string, vector<string>>> &ListOfFiles)
{
    ofstream OutFile(OutFilename);

    for (size_t i = 0; i < ListOfFiles.size(); i++)
    {
        for (size_t j = 0; j < ListOfFiles.at(i).second.size(); j++)
        {
            OutFile << ListOfFiles.at(i).first << "  " << ListOfFiles.at(i).second.at(j) << endl;
        }
    }

    return 0;
}