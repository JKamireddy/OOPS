#include <fstream>
#include <vector>
typedef unsigned char BYTE;





std::vector<BYTE> readFile(const char* olympic)
{
    // open the file:
    std::ifstream file(olympic, std::ios::binary);

    // Stop eating new lines in binary mode!!!
    file.unsetf(std::ios::skipws);

    // get its size:
    std::streampos fileSize;

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // reserve capacity
    std::vector<BYTE> vec;
    vec.reserve(fileSize);

    // read the data:
    vec.insert(vec.begin(),
               std::istream_iterator<BYTE>(file);
               std::istream_iterator<BYTE>());

    return vec;
}
