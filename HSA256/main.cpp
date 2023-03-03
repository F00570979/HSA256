#include <iostream> // For standard C++ Console Input & Output
#include <string> // For standard C++ String manipulation
#include <sstream>
#include <algorithm>
#include <fstream>
using namespace std;

// Our hash function:
unsigned int SHF(string input) // SHF = simple hash function
{
    unsigned int Init = 124564352;
    unsigned int Magic = 5674356;
    unsigned int Hash;
    for (int i = 0; i < input.length(); i++)
    {
        Hash = Hash ^ (input[i]); // XOR each byte of input;
        Hash = Hash * Magic; // Multiply by the magic number
        return Hash;
    }
}

//put it to hex format:

string ToHex(unsigned int input)
{
    string HexHash;
    stringstream hexstream;
    hexstream << hex << input;
    HexHash = hexstream.str();
    transform(HexHash.begin(), HexHash.end(), HexHash.begin(), :: toupper);
    return HexHash;
}
int main()
{
    fstream newfile;
    
    newfile.open("tpoint.txt", ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {   //checking whether the file is open
        string tp;
        while (getline(newfile, tp)) {  //read data from file object and put it into string.
            cout << ToHex(SHF(tp)) << "\n";   //print the data of the string
        }
        newfile.close();   //close the file object.
    }
    getchar();
}