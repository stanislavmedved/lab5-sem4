#include <fstream>
#include <iostream>
#include <string>

int countOccurrences(const std::string& filename, const std::string& target) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Невозможно открыть файл: " << filename << std::endl;
        return -1;
    }

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(target, pos)) != std::string::npos) {
            ++count;
            pos += target.size();
        }
    }

    return count;
}

void testCountOccurences() {
    const std::string filename = "text.txt";
    const std::string target = "hello";

    int count = countOccurrences(filename, target);
    if (count == -1) {
        std::cerr << "Невозможно провести операцию." << std::endl;
        return;
    }

    std::cout << "Кол-во появлений \"" << target << "\" в \"" << filename << "\": "
        << count << std::endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    testCountOccurences();
    return 0;
}