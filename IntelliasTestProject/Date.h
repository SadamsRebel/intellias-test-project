#include "Includes.h"
#ifndef DATE
#define DATE

class Date {
    const std::string MONTH_NAME[12] = { "January", 
                                         "February", 
                                         "March", 
                                         "April", 
                                         "May", 
                                         "June", 
                                         "July", 
                                         "August", 
                                         "September", 
                                         "October", 
                                         "November", 
                                         "December" };
    const std::string DELIMITER = "-";

    int day;
    int month;
    int year;
public:
    Date(std::string date);

    std::string returnParsedDate();
};

#endif