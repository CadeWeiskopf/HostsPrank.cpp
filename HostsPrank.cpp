
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string sFile = "C:\\Windows\\System32\\drivers\\etc\\hosts";//"C:\\test\\test.txt"; 
    std::string sWrite = "50.28.52.163 www.facebook.com";
    bool bWrite = true;
    
    std::ifstream ifs;
    ifs.open(sFile);
    if (ifs.is_open())
    {
        std::string s;
        while (std::getline(ifs, s))
        {
            std::cout << s << std::endl;
            if (s == sWrite)
            {
                bWrite = false;
                break;
            }

            s = "";
        }
    }
    ifs.close();


    if (bWrite)
    {
        std::ofstream ofs;
        ofs.open(sFile, std::ios_base::app);
        ofs << std::endl << sWrite << std::endl;
        if (ofs.bad())
        {
            std::cout << "bad " << ofs.flags();
        }
        ofs.close();
    } 

    return 0;
}

