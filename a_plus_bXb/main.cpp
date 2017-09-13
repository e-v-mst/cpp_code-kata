#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

template <typename Stream>
bool read_num(Stream &stream, long int &number)
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
                number = atoi (buf.c_str());
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

    long long int sol=0;
    int a=0, i=0;

    while (!ifile.eof())
    {
        int num;

        if (read_num(ifile, num) && i == 0)
            a = num;
        else
            sol = a + pow(num, 2);
        ++i;
    }

    ofstream ofile ("output.txt");
    ofile << sol << endl;


    return EXIT_SUCCESS;
}
