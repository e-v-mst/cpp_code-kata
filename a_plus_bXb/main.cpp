#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

template <typename Stream>
bool read_num(Stream &stream,   __int64 &number)
{
    char c = 0;
    std::string buf;
    while (true)
    {
        stream.read(&c, 1);
        if (c == ' ' || stream.eof())
        {
            if (!buf.empty())
            {
                number = _atoi64(buf.c_str());
                return true;
            }
        }
        else
            buf +=c ;
    }
    return false;
}

int main()
{
    fstream ifile("input.txt");

    if (!ifile)
    {
        cout << "can't read file input.txt" << endl;
        return EXIT_FAILURE;
    }

     __int64 sol=0;
     __int64 a=0;
     int i=0;

    while (!ifile.eof())
    {
         __int64 num;

        if (read_num(ifile, num) && i == 0)
            a = num;
        else
            sol = a + num * num;
        ++i;
    }

    ofstream ofile ("output.txt");
    ofile << sol << endl;


    return EXIT_SUCCESS;
}
