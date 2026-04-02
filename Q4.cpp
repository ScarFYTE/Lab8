#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>

using namespace std;

class FileHandler {
    fstream file;
    
    public:

    void openFile(const string& filename) {
        file.open(filename, ios::in | ios::out | ios::trunc);
        if (!file) {
            throw runtime_error("Could not open file: " + filename);
        }
    }
    void writeToFile(const string& data) {
        if (!file.is_open()) {
            throw runtime_error("File is not open for writing.");
        }
        file << data << endl;
        file.flush();
    }
    void readFromFile() {
        if (!file.is_open()) {
            throw runtime_error("File is not open for reading.");
        }

        file.clear();
        file.seekg(0, ios::beg);

        string line;
        cout << "Contents of the file:" << endl;
        //print
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
    void closeFile() {
        if (file.is_open()) {
            file.close();
        }
    }
};

int main() {
    FileHandler fileHandler;
    string filename = "Q4test.txt";
    
    fileHandler.openFile(filename);
    fileHandler.writeToFile("Hello, this is a test.");
    fileHandler.writeToFile("This file is used for testing file handling in C++.");
    fileHandler.readFromFile();
    fileHandler.closeFile();
    
    return 0;
}