#include <iostream>
#include <cstring>
#include <fstream>

#include "Arguments.h"
#include "String.h"


/**
 * @brief Reads the content of a file to a c style string
 * @param path The path to the file to read
 * @returns The file content
 * */
const char* read_file(const char* path) {
    auto file_content = String::empty_string();

    try {
        auto stream = std::ifstream(path, std::ios::in);
        stream.exceptions(std::ifstream::badbit);
        char c;
        while(stream.get(c)) {
            auto file_content_ptr = String::concat(file_content, c);
            delete file_content;
            file_content = file_content_ptr;
        }
    }catch (const std::ifstream::failure &e) {
        std::cerr << "Error reading file: " << e.what() << std::endl;
        return nullptr;
    }

    return file_content;
}

/**
 * @param text The text to search for a pattern
 * @param pattern The pattern to search for (no regex support just plain text)
 * @param case_sensitive Indicates if the search should be performed case sensitive or not
 * @returns The greped result
 * */
const char* grep(const char* text, const char* pattern, const bool case_sensitive) {
    const char* greped = String::empty_string();

    auto pattern_length = std::strlen(pattern);
    auto txt_length = std::strlen(text);


    auto ls = 0;

    for(int i = 0;i<txt_length;++i) {

        if(text[i] == '\n') {
            ls = i+1;
        }

        bool found = case_sensitive ? (std::strncmp(text + i, pattern, pattern_length) == 0) : (strncasecmp(text + i, pattern, pattern_length) == 0);

        if (found) {
            int le = 0;
            // Find the line ending for the string concat
            for(auto j = ls;j<txt_length;++j) {
                if(text[j] == '\n' || text[j] == '\0') {
                    le = j;
                    break;
                }
            }

            //Concat the line to the greped result
            for(int j=ls;j<=le;++j) {
                auto file_content_ptr = String::concat(greped, text[j]);
                delete greped;
                greped = file_content_ptr;
            }
        }
    }

    if (std::strlen(greped) == 0) return nullptr;

    return  greped;
}


int main(int argc, char **argv) {

    auto args = Arguments();
    if (!args.parse(argc, argv)) {
        std::cerr << args.getLastError() << std::endl;
        return 1;
    }

    std::cout << "CatGrep Tool called with file: " << args.fileName() << " and pattern: " << args.pattern() << ". Pattern is case sensitive: " << (args.is_case_sensitive() ? "yes" : "no") << std::endl;

    auto file_content = read_file(args.fileName());

    if (file_content == nullptr) return 1;

    auto greped = grep(file_content, args.pattern(), args.is_case_sensitive());

    if (greped == nullptr) std::cerr << "Nothing with pattern '" << args.pattern() << "' found in file at " << args.fileName() << std::endl;
    else std::cout << greped << std::endl;

    return 0;
}
