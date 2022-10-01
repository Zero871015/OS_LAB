#include <stdio.h>
#include <string.h>

unsigned long myHash(char*);
void genKey();
void showFlag(char*);

int main()
{
    // generate key in memory
    genKey();
    char key[20];

    // printf("%lu", myHash("OPEN"));
    
    printf("Enter the key:\n");
    scanf("%s", key);
    if(myHash(key) == 6384369399)
        showFlag(key);
    else
        printf("error:(\n");
    return 0;
}

unsigned long myHash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void genKey()
{
    const char* table[31] = {
    "5PFW",
    "Z9MO",
    "M4I7",
    "VIJX",
    "KULX",
    "X334",
    "MGVQ",
    "06QH",
    "6YZL",
    "VCZO",
    "9AVX",
    "DB7G",
    "OFEG",
    "9EXS",
    "XSDZ",
    "ASSV",
    "GQEB",
    "EZQM",
    "1QG4",
    "UACO",
    "ML39",
    "LJKZ",
    "Z6HM",
    "43PC",
    "VA8U",
    "X3CL",
    "Y4MS",
    "VXQP",
    "9E9N",
    "BY3J",
    "8670",
    "L0FK",
    "UQGL",
    "1KAG",
    "R431",
    "CYP7",
    "NH4S",
    "M2TI",
    "7XYA",
    "NP9J",
    "U6NM",
    "MXFY",
    "ENNC",
    "E7CJ",
    "PKZI",
    "8PRN",
    "ZO2B",
    "QZLW",
    "ZW6B",
    "ZMOI"};
    char key[4] = "\x54\x53\x43\x4f";
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 4; j++)
            key[j] ^= table[i][j];

    if(!strcmp(key, "<I compare with the key>"))
        printf("Hi :)\n");
    else
        printf("The key is in memory now...\n");
}

void showFlag(char* key)
{
    char* flag = "\x2c\x3f\x2a\x22";
    printf("FLAG{");
    for(int i = 0; i < 4; i++)
        printf("%c", flag[i] ^ key[i]);
    printf("}\n");
}
