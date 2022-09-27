#include "InfoClean.h"

InfoClean::InfoClean(InfoBlock infoBlock) {
    name = infoBlock.returnInfo(INFO_INDEX::NAME);
    date = infoBlock.returnDate()->returnParsedDate();
    totalHours = std::stoi(infoBlock.returnInfo(INFO_INDEX::LOGGED_HOURS));
}

std::string InfoClean::getName() {
    return name;
}

std::string InfoClean::getDate() {
    return date;
}

int InfoClean::getTotalHours() {
    return totalHours;
}

bool InfoClean::appendInfo(InfoClean *otherInfo) {
    if (name != otherInfo->getName()) {
        return false;
    }

    if (date != otherInfo->getDate()) {
        return false;
    }

    totalHours += otherInfo->getTotalHours();
    return true;
}

std::string InfoClean::getFullInfo() {
    std::string result = name;

    result.append(INFO_STRING_DELIMITER);
    result.append(date);
    result.append(INFO_STRING_DELIMITER);
    result.append(std::to_string(totalHours));
    result.append("\n");

    return result;
}