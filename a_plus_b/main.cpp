#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename Stream>
bool read_num(Stream &stream, int &number)
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
    ifstream in_file;
    in_file.open("input.txt", ios::in | ios::binary);

    if (!in_file) {
        cout << "can't read file input.txt" << endl;
        return EXIT_FAILURE;
    }

    long int sum=0;
    while (!in_file.eof())
    {
        int num;
        if (read_num(in_file, num))
            sum+=num;

    }

    ofstream out_file ("output.txt");
    out_file << sum << endl;


    return EXIT_SUCCESS;
}
