#pragma once

#include <string>
#include <sstream>

using namespace std;

class base64 {
    private:
        unsigned int bytesPerIteration = 3;
        string base64chars = string("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");

        unsigned int strtoint(string data);
        string inttostr(unsigned int data);
        string getEncodedString(unsigned int bits);
        unsigned int getDecodedInt(string data);

    public:
        stringstream encode(const string data);
        stringstream decode(string data);
};
