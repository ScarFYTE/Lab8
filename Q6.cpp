#include<iostream>

class BaseLogger {
    public:

    virtual void log(const std::string& message) {
        std::cout << "BaseLogger: " << message << std::endl;
    }

};

class ConsoleLogger : public BaseLogger {
    public:

    void log(const std::string& message) override {
        std::cout << "ConsoleLogger: " << message << std::endl;
    }
};

class FileLogger : public BaseLogger {
    public:

    void log(const std::string& message) override {
        std::cout << "FileLogger: " << message << std::endl;
    }
};

class DatabaseLogger : public BaseLogger {
    public:

    void log(const std::string& message) override {
        std::cout << "DatabaseLogger: " << message << std::endl;
    }
};

int main() {
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
    DatabaseLogger databaseLogger;

    consoleLogger.log("This is a message for the console.");
    fileLogger.log("This is a message for the file.");
    databaseLogger.log("This is a message for the database.");

    return 0;
}