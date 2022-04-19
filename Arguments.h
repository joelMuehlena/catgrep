//
// Created by joelr on 19.04.2022.
//

#ifndef CATGREP_ARGUMENTS_H
#define CATGREP_ARGUMENTS_H


class Arguments {
    bool _is_case_sensitive;
    const char* _fileName;
    const char* _pattern;

    /// Holds the last occured error to fetch with getLastError()
    const char* error;

public:
    Arguments();

    /**
     * @brief Parses the command line arguments for easier use
     * @param argc The lenght of the command line arguments list
     * @param argv The command line argument list
     * */
    bool parse(unsigned const int argc, char **argv);

    [[nodiscard]] const char* fileName() const;
    [[nodiscard]] const char* pattern() const;
    [[nodiscard]] bool is_case_sensitive() const;
    [[nodiscard]] const char* getLastError() const;
};

#endif //CATGREP_ARGUMENTS_H
