#include "Includes.h"
#include "InfoBlock.h"
#ifndef INFO_CLEAN_DEFINED
#define INFO_CLEAN_DEFINED

class InfoClean {
    const std::string INFO_STRING_DELIMITER = ";";
    
    std::string name;
    std::string date;
    int totalHours;
public:

    InfoClean(InfoBlock infoBlock);
    std::string getName();
    std::string getDate();
    int getTotalHours();
    bool appendInfo(InfoClean *otherInfo);
    std::string getFullInfo();
};

#endif