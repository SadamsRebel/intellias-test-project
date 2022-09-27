#include "InfoBlock.h"
#include "Date.h"

InfoBlock::InfoBlock(std::string rawInfo) {
    pInfo = new std::string[INFO_STRING_COUNT];

    if (!validation(rawInfo, INFO_STRING_DELIMITER, INFO_DELIMITER_COUNT)) {
        throw std::invalid_argument(EXCEPTION_MESSAGE);
    }

    int delimiterPos = 0;
    for (int infoNumber = 0; infoNumber < INFO_STRING_COUNT; infoNumber++) {
        delimiterPos = rawInfo.find(INFO_STRING_DELIMITER);

        if (delimiterPos == std::string::npos) {
            pInfo[infoNumber] = rawInfo;
            break;
        }

        pInfo[infoNumber] = rawInfo.substr(0, delimiterPos);
        rawInfo.erase(0, delimiterPos + INFO_STRING_DELIMITER.length());
    }

    pDate = new Date(this->returnInfo(INFO_INDEX::DATE_TIME));
}

std::string InfoBlock::returnInfo(int infoIndex) {
    if (infoIndex >= 0 && infoIndex < INFO_STRING_COUNT) {
        return pInfo[infoIndex];
    }
    return nullptr;
}

bool InfoBlock::validation(const std::string target, const std::string delimiterChar, const int delimiterEstimatedCount) {  
    int delimiterCount = 0;

    for (int charNumber = 0; charNumber < target.length(); charNumber++) {
        if (target.at(charNumber) == delimiterChar.at(0)) {
            delimiterCount++;
        }
    }

    if (delimiterCount != delimiterEstimatedCount) {
        return false;
    }

    return true;
}

Date *InfoBlock::returnDate() {
    return pDate;
}
