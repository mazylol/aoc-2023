#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int covert(char ch) {
    switch (ch) {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    default:
        return -1;
    }
}

std::vector<std::string> load_lines(std::string file) {
    std::ifstream f(file);

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(f, line)) {
        lines.push_back(line);
    }

    return lines;
}

int check(std::string line, int game_id) {
    line = line.erase(0, line.find(":") + 1);

    std::vector<std::string> parts;
    std::string part = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            parts.push_back(part);
            part = "";
        } else {
            part += line[i];
        }
    }

    return game_id;
}

int main() {
    auto lines = load_lines("input.txt");

    int valid = 0;

    int checked = 1;

    for (const auto &line : lines) {
        valid += check(line, checked);
        checked += 1;
    }

    std::cout << valid << std::endl;
}