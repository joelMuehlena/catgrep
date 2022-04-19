//
// Created by joelr on 19.04.2022.
//

#include "Arguments.h"
#include <cstring>

Arguments::Arguments() : _is_case_sensitive(true), _fileName(nullptr), _pattern(nullptr), error(nullptr) {}

bool Arguments::parse(unsigned const int argc, char **argv) {
    if (argc < 3) {
        this->error = "Not enough arguments provided. Please use the CLI interface like this: \n catgrep [-i] <fileName> <pattern>";
        return false;
    }

    this->_fileName = argv[argc-2];
    this->_pattern = argv[argc-1];

    for(unsigned int i=1; i < argc-2; ++i) {
        if (std::strcmp(argv[i], "-i") == 0) this->_is_case_sensitive = false;
    }

    return true;
}

const char* Arguments::fileName() const {
    return this->_fileName;
}

const char* Arguments::pattern() const {
    return this->_pattern;
}

bool Arguments::is_case_sensitive() const {
    return this->_is_case_sensitive;
}

const char* Arguments::getLastError() const {
    return this->error;
}