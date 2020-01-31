#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) 
    {
        int length = str.size();
        for(int i = 0; i < length; i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + 32;
            }
        }
        return str;
    }
};

int main()
{
    Solution A;
    string str = "HELLO";
    cout << A.toLowerCase(str) << endl;
    return 0;
}
