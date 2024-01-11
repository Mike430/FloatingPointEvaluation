#pragma once
#include <stdio.h>
#include <iostream>

#define PRINT_BITS(type, data) {std::cout << "Type = " << #type  << ",\tdata = "<< data << "\t"; PrintBits((type)data);}

void PrintCharBits(char data)
{
    for(int i = 8 - 1; i >= 0; --i)
    {
        printf("%c", (1 << i) & data ? '1': '0');
    }
}

template <typename T>
void PrintBits(T data)
{
    constexpr int size = sizeof(T);
    char DataBuffer[size];
    void* DataBufferPtr = &DataBuffer;
    *(T*)DataBufferPtr = data;
    printf ("size = %d bytes, %d bits\n-\t\tdata = ", size, size * 8);
    for(int i = size - 1; i >= 0; --i)
    {
        PrintCharBits(DataBuffer[i]);
    }
    printf(" (binary)\n");
}

void FloatTestingMain()
{
    printf("\nTEST: Print some chars\n//==========================================================\n");
    PRINT_BITS(char, 0)
    PRINT_BITS(char, 1);
    PRINT_BITS(char, 2);
    PRINT_BITS(char, 3);
    PRINT_BITS(char, 4);
    PRINT_BITS(char, 5);

    printf("\nTEST: Print some floats\n//==========================================================\n");
    PRINT_BITS(double,50764211387.234567);
    PRINT_BITS(float,64211387.234567f);
    
    printf("\nTEST: Print some signed and unsigned numbers\n//==========================================================\n");
    PRINT_BITS(int, -5);
    PRINT_BITS(unsigned int, 5);
}