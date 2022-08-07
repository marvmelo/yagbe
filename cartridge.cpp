#include <iostream>

using namespace std;

class Cartridge
{
private:
    unsigned char ROM[32768];
    unsigned char RAM[8192];
public:
    Cartridge(unsigned char *);
    unsigned char Read(unsigned short int);
    void Write(unsigned short int, unsigned char);
};

Cartridge::Cartridge(unsigned char ROM[])
{
    for (int i = 0; i < 32768; i++)
    {
        this->ROM[i] = ROM[i];
    }
}

unsigned char Cartridge::Read(unsigned short int address)
{
    if (0 <= address && address <= 0x7FF)
    {
        return ROM[address];
    }
    else if (0xA000 <= address && address <= 0xBFFF)
    {
        return RAM[address-0xA000];
    }
    else
    {
        cout << "Adress " << address << "is out of bounds for reading." << endl;
        return 0;
    }
}

void Cartridge::Write(unsigned short int address, unsigned char value)
{
    if (0xA000 <= address && address <= 0xBFFF)
    {
        RAM[address-0xA000] = value;
    }
    else
    {
        cout << "Adress " << address << "is out of bounds for writing." << endl;
    }
}
