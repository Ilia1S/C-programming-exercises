// В двоичном файле input.bin записан массив двухбайтовых беззнаковых чисел и однобайтовое число k.
// Требуется циклически сдвинуть массив на k чисел влево и записать результат в двоичный файл с именем output.bin.
// Гарантируется, что число k не превосходит длинну массива. Размер входного файла не превышает 2МБ

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void cyclicShift(const char *, const char *);

int main(int argc, const char * argv[])
{
    const char *inputBinaryFile = "input.bin";
    const char *outputBinaryFile = "output.bin";
    cyclicShift(inputBinaryFile, outputBinaryFile);
    return 0;
}
void cyclicShift(const char *inputBinaryFile, const char *outputBinaryFile)
{
    FILE *inputFile = fopen(inputBinaryFile, "rb");
    if (inputFile == NULL)
    {
        perror("Error occured while opening the file");
        return;
    }
    uint16_t *inputArray = (uint16_t*)malloc(2097152);
    fseek(inputFile, 0, SEEK_END);
    uint8_t k; // k - shift value
    long int size = ftell(inputFile);
    long int n = (size / sizeof(uint16_t)); // number of all elements excluding k
    rewind(inputFile);
    fread(inputArray, 2, n+1, inputFile); // read data and write to array including k
    k = inputArray[n];
    fclose(inputFile);
    for (uint8_t i = 0; i < k; i++)
    {
        uint16_t temp = inputArray[0];
        for (long int j = 0; j < n - 1; j++)
        {
            inputArray[j] = inputArray[j + 1];
        }
        inputArray[n - 1] = temp;
    }
    FILE *outputFile = fopen(outputBinaryFile, "wb");
    if (outputFile == NULL)
    {
        perror("Error occured while opening the file");
        return;
    }
    fwrite(inputArray, n*2, 1, outputFile);
    fclose(outputFile);
    free(inputArray);
}
