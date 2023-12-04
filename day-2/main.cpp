#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
    // split the line into parts, each part is separated by a semicolon
    std::vector<std::string> sub_games;
    std::string sub_game = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ';') {
            sub_games.push_back(sub_game);
            sub_game = "";
        } else {
            sub_game += line[i];
        }
    }

    // split each sub game into parts, each part is separated by a comma
    std::vector<std::string> parts;
    for (const auto &sub_game : sub_games) {
        std::string part = "";
        for (int i = 0; i < sub_game.size(); i++) {
            if (sub_game[i] == ',') {
                parts.push_back(part);
                part = "";
            } else {
                part += sub_game[i];
            }
        }
        parts.push_back(part);
    }

    int red = 0;
    int green = 0;
    int blue = 0;

    for (const auto &part : parts) {
        if (part[part.size()] == 'r') {

        }

        red = 0;
        green = 0;
        blue = 0;
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