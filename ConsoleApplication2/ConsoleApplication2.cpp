#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <string>
#include "FileHandlerIO.cpp"

using namespace std;



int main() {

greetings:


    cout << "Hello dear User!" << endl;

enter_dir:

    cout << "Please enter the directory that you'll working with: " << endl;
    string dir;
    cin >> dir;
    filesystem::path directory(dir);

check_dir:

    if (!filesystem::exists(dir)) {
        cout << "that directory does not exist" << endl;
        goto enter_dir;
    }

enter_file:
    cout << "Enter the name of txt file you want to work with or create" << endl;
    string filename;
    cin >> filename;
    string path = dir + "\\" + filename + ".txt";
    if (!filesystem::exists(path)) {
        ofstream outfile(path);
        outfile.close();
    }

    FileHandlerIO handler(path);

operationsIO:

    while (true) {

        cout << "Enter the number what you want to do: " << endl;
        cout << "1 write a line" << endl;
        cout << "2 read a single first line" << endl;
        cout << "3 read all lines from the file" << endl;
        cout << "4 clear the properties of file" << endl;
        cout << "5 chose/create an other file in existing dir" << endl;
        cout << "6 chose another dir" << endl;
        cout << "7 stop the programm" << endl;




        int x;
        cin >> x;


        switch (x) {
        case 1: {
            string line;
            cin >> line;
            handler.writeLine(line);
            break;
        }

        case 2:
            cout << handler.readLine() << endl;
            break;
        case 3:
            cout << handler.readAllLines() << endl;
            break;
        case 4:
            handler.clearFile();
            break;
        case 5:
            goto enter_file;
            break;
        case 6:
            goto enter_dir;
        case 7:
            abort();

        default:
            abort();
        }
    }

    return 0;
}