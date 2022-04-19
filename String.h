//
// Created by joelr on 19.04.2022.
//

#ifndef CATGREP_STRING_H
#define CATGREP_STRING_H

namespace String {

    /**
     * @brief Concat a char to a const char*
     * @param s The string to concat to
     * @param c The char to add
     * @returns A pointer to the new created string
     * */
    inline char* concat(const char* s, const char c) {
        if (s == nullptr) {
            auto ns = new char[1];
            ns[0] = '\0';
            return ns;
        }

        if (c == '\0') return nullptr;

        auto len = std::strlen(s);

        auto ns = new char[len+2];
        if (len >= 1) {
            std::strncpy(ns, s, len);
        }
        ns[len] = c;
        ns[len+1] = '\0';
        return ns;
    }

    /**
     * @brief Creates an empty char array
     * @returns An empty char array
     * */
    inline const char * empty_string() {
        auto s = new char[1];
        s[0] = '\0';
        return s;
    }
}

#endif //CATGREP_STRING_H
