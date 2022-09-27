
#include "Includes.h"
#include "InfoBlock.h"
#include "InfoClean.h"
#ifndef PARSER_DEFINED
#define PARSER_DEFINED



enum PROGRAM_MESSAGE_INDEX {
    WELCOMING,
    LOADING_FILE,
    FILE_DONT_EXIST,
    INVALID_FILE_TYPE,
    SAVING_FILE,
    PROPOSITION,
    FAREWELL
};

class Parser {
    const std::string PROGRAM_MESSAGE[10] = {" Welcome to \"Time Tracking Report\" program. \n Made by Oleh Roshchyn. \n", 
                                             " Enter the path to target \".csv\" file: ", 
                                             " ERROR: The file with name you've entered does not exist. \n",
                                             " ERROR: Invalid file type. \n",
                                             " Enter name/path for output file: ",
                                             " Do you want to process another file?(y/n): ",
                                             " Well then, thanks for using this program! Hope you enjoyed it ;) \n"};
    const std::string AGREEMENT = "y";
    const std::string FILE_EXTENSION = ".csv";

    std::vector<InfoBlock> infoBlockVector;
    std::vector<InfoClean> infoCleanVector;
    std::vector<InfoClean> processedInfoCleanVector;

    std::ifstream *pInFileStream;
    std::ofstream *pOutFileStream;

    bool loadFile();
    bool saveFile();
    void processData();
    std::string getFileName(std::string message);
    std::string proposition();
    void closeInFileStream();
    void closeOutFileStream();
public:
    void initialize();
    Parser();
};

#endif