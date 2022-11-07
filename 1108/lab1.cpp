#include <iostream>
#include <sys/utsname.h>
#include <fstream>
#include <string>

int main()
{
    std::string str1, str2;
    struct utsname buf;
    int flag = 0;
    flag = uname(&buf);
    str1 = buf.version;
    std::size_t pos1 = str1.find("~") + 1;
    std::size_t pos2 = str1.find(".");
    str1 = str1.substr(pos1, pos2 - pos1);


    //std::cout << str1 << std::endl;

    std::ifstream f("/etc/os-release");
    while(getline(f, str2))
    {
        //std::cout << str2 << std::endl;
        if(str2.find("VERSION") != std::string::npos)
        {
            pos1 = str2.find("\"") + 1;
            pos2 = str2.find(".");
            str2 = str2.substr(pos1, pos2 - pos1);
            //std::cout << str2;
            break;
        }
    }
    if(str1 == str2)
        std::cout << "not in container..." << std::endl;
    else
        std::cout << "FLAG{Y0U_RU1V_TH3_C0N7A1N3R!!!!}";
    return 0;
}
