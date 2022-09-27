#include "Parser.h"

Parser::Parser() {}

void Parser::initialize() {
    std::cout << PROGRAM_MESSAGE[PROGRAM_MESSAGE_INDEX::WELCOMING];
    
    std::string answer = AGREEMENT;

    while (answer == AGREEMENT) {
        if (!loadFile()) {
            return;
        }
        closeInFileStream();

        processData();

        if (!saveFile()) {
            return;
        }
        closeOutFileStream();

        answer = proposition();
    }

    std::cout << PROGRAM_MESSAGE[PROGRAM_MESSAGE_INDEX::FAREWELL];
}

std::string Parser::getFileName(const std::string message) {
    std::string input;

    std::cout << message;
    std::cin >> input;

    return input;
}

bool Parser::loadFile() {
    std::string fileName = getFileName(PROGRAM_MESSAGE[PROGRAM_MESSAGE_INDEX::LOADING_FILE]);

    if (fileName.rfind(FILE_EXTENSION) != (fileName.size() - FILE_EXTENSION.size())) {
        std::cout << PROGRAM_MESSAGE[PROGRAM_MESSAGE_INDEX::INVALID_FILE_TYPE];
        return false;
    }

    pInFileStream = new std::ifstream(fileName.c_str());
    if (!pInFileStream->good()) {
        std::cout << PROGRAM_MESSAGE[PROGRAM_MESSAGE_INDEX::FILE_DONT_EXIST];
        return false;
    }

    pInFileStream->seekg(0);

    try {
        while (!pInFileStream->eof()) {
            std::string inputFromFile;

            std::getline(*pInFileStream, inputFromFile);

            if (inputFromFile.size() != 0) {
                infoBlockVector.push_back(InfoBlock(inputFromFile));
            }
        }
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }

    return true;
}

bool Parser::saveFile() {
    std::string fileName = getFileName(PROGRAM_MESSAGE[PROGRAM_MESSAGE_INDEX::SAVING_FILE]);
    if (fileName.rfind(FILE_EXTENSION) != fileName.size() - FILE_EXTENSION.size()) {
        fileName.append(FILE_EXTENSION);
    }

    pOutFileStream = new std::ofstream(fileName);

    while (!processedInfoCleanVector.empty()) {
        InfoClean output = processedInfoCleanVector.back();
        *pOutFileStream << output.getFullInfo();
        processedInfoCleanVector.pop_back();
    }

    return true;
}

void Parser::processData() {
    while (!infoBlockVector.empty()) {
        infoCleanVector.push_back(InfoClean(infoBlockVector.back()));
        infoBlockVector.pop_back();
    }

    processedInfoCleanVector.push_back(infoCleanVector.back());
    infoCleanVector.pop_back();

    while (true) {
        bool successFlag = false;

        for (int processedIndex = 0; processedIndex < processedInfoCleanVector.size() && !infoCleanVector.empty(); processedIndex++) {
            if (processedInfoCleanVector[processedIndex].appendInfo(&infoCleanVector.back())) {
                infoCleanVector.pop_back();
                successFlag = true;
                break;
            }
        }

        if (infoCleanVector.empty()) {
            break;
        }

        if (successFlag == false) {
            processedInfoCleanVector.push_back(infoCleanVector.back());
            infoCleanVector.pop_back();
        }
    }
}

std::string Parser::proposition() {
    std::string input;

    std::cout << PROGRAM_MESSAGE[PROGRAM_MESSAGE_INDEX::PROPOSITION];
    std::cin >> input;

    return input;
}

void Parser::closeInFileStream() {
    delete pInFileStream;
}

void Parser::closeOutFileStream() {
    delete pOutFileStream;
}
