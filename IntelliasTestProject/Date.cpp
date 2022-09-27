#include "Date.h"

Date::Date(std::string date) {
    int delimiterPos;

    year = std::stoi(date.substr(0, delimiterPos = date.find(DELIMITER)));
    date.erase(0, delimiterPos + DELIMITER.size());
    month = std::stoi(date.substr(0, delimiterPos = date.find(DELIMITER)));
    date.erase(0, delimiterPos + DELIMITER.size());
    day = std::stoi(date);
}

std::string Date::returnParsedDate() {
    std::string result;
    std::string yearString = std::to_string(year);

    result.append(MONTH_NAME[month - 1]);
    result.append(" ");
    result.append(yearString);

    return result;
}