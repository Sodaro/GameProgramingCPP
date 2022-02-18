#include <iostream>
#include <bitset>
using namespace std;


int bitwiseAdd(int nr1, int nr2)
{
   //nr1 = 6 == 00001100
   //nr2 = 7 == 00001101
   
   //shifting value *= 2
   //given 6 and 7, they share 2 bits, the bits in common can be shifted and the uncommon xor:ed with the shifted value to do an add
   
   while (nr2 != 0)
   {
       unsigned carry = nr1 & nr2; //get the bits that are the same
       
       nr1 = nr1 ^ nr2; //get the unique bits
       nr2 = carry << 1;
   }
   
   
   return nr1;
}

int bitwiseSub(int nr1, int nr2)
{

   while(nr2 != 0)
   {
       int borrow = (~nr1) & nr2;
       nr1 = nr1 ^ nr2;
       nr2 = borrow << 1;
   }
   
   return nr1;
}

void bitwiseMathSwap(int& a, int& b)
{
    a = bitwiseAdd(a, b);
    b = bitwiseSub(a, b);
    a = bitwiseSub(a, b);
}

void bitwiseSwap(int& a, int& b)
{
    //a = 0011
    //b = 1100
    //c = 1111
    
    //b = c ^ b = 0011
    //a = c ^ a = 1100
    int c = a ^ b;
    b = c ^ b;
    a = c ^ a;
}

int main()
{
    int nr1 = 1;
    int nr2 = 2;
    
    cout << "Before math swap: " << nr1 << " " << nr2 << endl;
    
    bitwiseMathSwap(nr1, nr2);
    
    
    cout << "Before cipher swap: " << nr1 << " " << nr2 << endl;
    
    cout << endl;
    bitwiseSwap(nr1, nr2);
    
    return 0;
}