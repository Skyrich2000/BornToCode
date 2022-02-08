#include <fstream>
#include <iostream>
#include <string>

bool input(
    int argc,
    const char* const argv[],
    std::string& fileName,
    std::string& s1,
    std::string& s2) {
    if (argc != 4) {
        std::cout << "Invalid input. USAGE : ./replace FILENAME S1 S2" << std::endl;
        return (false);
    }
    fileName = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    return (true);
}

bool open(const std::string& fileName, std::fstream& inputFile, std::fstream& outputFile) {
    std::string outputFileName = fileName + ".replace";

    inputFile.open(fileName.c_str(), std::ios::in);
    if (inputFile.fail()) {
        std::cout << "File " << fileName << " is not exist!" << std::endl;
        return (false);
    }

    outputFile.open(outputFileName.c_str(), std::ios::out);
    if (outputFile.fail()) {
        std::cout << "File " << outputFileName << " is not created!" << std::endl;
        inputFile.close();
        return (false);
    }
    return (true);
}

std::string replace(const std::string& origin, const std::string& s1, const std::string& s2) {
    std::string str = origin;
    std::string ret("");
    size_t index;

    std::cout << str << std::endl;
    while ((index = str.find(s1)) != std::string::npos) {
        ret += str.substr(0, index) + s2;
        str = str.substr(index + s1.length());
    }
    ret += str;
    return ret;
}

int main(int argc, const char* const argv[]) {
    std::string fileName;
    std::string s1, s2;
    std::fstream inputFile;
    std::fstream outputFile;

    if (!input(argc, argv, fileName, s1, s2))
        return (1);

    if (!open(fileName, inputFile, outputFile))
        return (2);

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replace(line, s1, s2) << "\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}