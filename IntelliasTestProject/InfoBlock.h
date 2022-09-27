#include "Includes.h"
#include "Date.h"
#ifndef INFO_BLOCK_DEFINED
#define INFO_BLOCK_DEFINED

enum INFO_INDEX {
    NAME,
    EMAIL,
    DEPARTMENT,
    POSITION,
    PROJECT,
    TASK,
    DATE_TIME,
    LOGGED_HOURS
};

class InfoBlock {
    const int INFO_STRING_COUNT = 8;
    const int INFO_DELIMITER_COUNT = 7;
    const std::string INFO_STRING_DELIMITER = ";";
    const char EXCEPTION_MESSAGE[62] = " ERROR: Data taken from this file is invalid to be processed.";
    
    Date *pDate;
    std::string *pInfo;

public:
    InfoBlock(std::string rawInfo);

    std::string returnInfo(int infoIndex);
    bool validation(const std::string target, const std::string delimiterChar, const int delimiterEstimatedCount);
    Date *returnDate();
};

#endif