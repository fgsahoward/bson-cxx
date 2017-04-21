#include <algorithm>
#include <string>
#include <sstream>

#include "base64.h"

#include <iostream>

using namespace std;

stringstream base64::encode(const string data) {
    stringstream ss;

    auto extraBytes = data.size() % bytesPerIteration;
    auto padding = (extraBytes) ? bytesPerIteration - extraBytes : 0;

    for (unsigned int index = 0; index < data.size(); index += bytesPerIteration) {
        auto bytes = data.substr(index, bytesPerIteration);
        auto intData = strtoint(bytes);
        ss << getEncodedString(intData);
    }

    ss << string(padding, '=');

    return ss;
}

stringstream base64::decode(string data) {
    stringstream ss;

    auto padIndex = data.find('=');
    auto paddingSize = data.size() - padIndex;
    auto unpaddedData = (padIndex != string::npos) ? data.replace(padIndex, paddingSize, string(paddingSize, 'A')) : data;

    for (unsigned int index = 0; index < unpaddedData.size() - paddingSize; index += bytesPerIteration + 1) {
        auto bytes = unpaddedData.substr(index, bytesPerIteration + 1);
        auto intData = getDecodedInt(bytes);
        ss << inttostr(intData);
    }

    return ss;
}

unsigned int base64::strtoint(string data) {
    unsigned int ret = 0;
    reverse(data.begin(), data.end());

    for (auto i = 0; i < bytesPerIteration; i++)
        ret += (unsigned char)(data[i]) << (i * 8);

    return ret;
}

string base64::inttostr(unsigned int data) {
    auto ret = string();

    for (auto i = bytesPerIteration; i > 0; i--)
        ret += (unsigned char)(data >> ((i-1) * 8));

    return ret;
}

string base64::getEncodedString(unsigned int bits) {
    auto ret = string();

    for (int i = sizeof(bits) - 1; i >=0; i--) {
        auto index = (bits >> (i*6)) & 0x3F;
        ret += base64chars[index];
    }

    return ret;
}

unsigned int base64::getDecodedInt(string data) {
    unsigned int ret = 0;

    for (int i = bytesPerIteration; i>=0; i--) {
        auto index = base64chars.find(data[bytesPerIteration - i]);
        ret += (index << (i*6));
    }

    return ret;
};
