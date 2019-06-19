#include <iostream>
#include <map>
#include <vector>

using namespace std;

int varCoef(std::string x){
    std::size_t foundMulti = x.find('*');
    std::size_t foundDiv = x.find('/');
    if (foundMulti != std::string::npos || foundDiv != std::string::npos){
        std::size_t found = foundMulti==std::string::npos ? foundMulti:foundDiv;
        string coefStr = "";

        if (x[found+1] == 'x'){
            for (int i = found-1; i>=0; ++i)
                coefStr+=x[i];
        }
        else {
            for (unsigned int i = found+1; i < x.size(); ++i)
                coefStr+=x[i];
        }
        return stoi(coefStr);
    }
    if (x.find('-')==0)
        return -1;
    return 1;
}

int varPower(std::string x){
    std::size_t found = x.find('^');
    if (found != std::string::npos){
        string powerStr = "";

        for (unsigned int i = found+1; i < x.size(); ++i){
            if (x[i] == '*' || x[i] == '/' )
                break;
            else
                powerStr+=x[i];
        }
        return  stoi(powerStr);
    }
    return 1;
}

std::string derivative(std::string polynomial)
{
    map <int, int> xMap;
    vector<string> x;
    unsigned int i = 0;
    string str = "";

    while(i<polynomial.size()){

        if(polynomial[i] == '+'){
            x.push_back(str);
            str = "";
        }
        else if (polynomial[i] == '-'){
            x.push_back(str);
            str = '-';
        }
        else  if (polynomial[i] != ' ')
            str+=polynomial[i];

        ++i;
    }
    if (str!="")
        x.push_back(str);

    for (auto i = x.begin(); i != x.end(); ++i){
        std::size_t found = i->find('x');
        if (found != std::string::npos) {
            int power = varPower(*i);
            int coefficient = varCoef(*i);

            map<int, int>::iterator it = xMap.find(power);

            if (power != 0 && coefficient !=0 ){
                if(it != xMap.end())
                    xMap[power] =  xMap[power] + coefficient;
                else
                    xMap[power] =  coefficient;
            }
        }
    }

    map <long int, long int> newMap;
    for (auto& i: xMap)
        newMap[i.first - 1] = i.first * i.second;

    string s = "";

    for (auto i = newMap.rbegin(); i != newMap.rend(); ++i) {
        int power = i->first;
        int coef = i->second;

        if (coef < 0 && !s.empty())
            s.pop_back();

        if (coef == 1 && power == 0)
            s += std::to_string(coef);
        else if (coef != 1 )
            s += std::to_string(coef);
        else
            s += "";

        if (power != 0) {
            s += "*x";
            if (power != 1)
                s += "^" + std::to_string(power);
        }

        s += "+";
    }
    s.pop_back();

    return s;
}

int main() {
    string task;
    cin >> task;
    cout << derivative(task) << endl;
    return 0;
}
