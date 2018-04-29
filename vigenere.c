#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, string argv[])
{
    string s;      //Variable system key
    string pt;     //Plaintext String
    string ct;     //Ciphertext String
    string cmp1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";     //String reference to compare capitols letters
    string cmp2 = "abcdefghijklmnopqrstuvwxyz";     //String reference to compare lowes case letters
    int i = 0;     //index to select Capitol or lower case in plain text
    int j = 0;     //index to select Capitol or lower case in key
    int k = 0;     //index to stablish comparation between Capitol plaintext and cmp1 to get the caracter position
    int l = 0;     //index to stablish comparation between Capitol key and cmp1 to get the caracter position
    int m = 0;     //index to stablish comparation between lower case plaintext and cmp1 to get the caracter position
    int n = 0;     //number of Alphabetic method
    int p = 0;     //intex to restart key string for Capitol
    int q = 0;     //index to stablish comparation between lowe case key and cmp1 to get the caracter position

    if ((argv[1][0] != 65 && argv[1][0] != 66 && argv[1][0] != 67 && argv[1][0] != 68 && argv[1][0] != 69 && argv[1][0] != 70 &&
         argv[1][0] != 71 && argv[1][0] != 72 && argv[1][0] != 73 && argv[1][0] != 74 && argv[1][0] != 75 && argv[1][0] != 76 &&
         argv[1][0] != 77 && argv[1][0] != 78 && argv[1][0] != 79 && argv[1][0] != 80 && argv[1][0] != 81 && argv[1][0] != 82 &&
         argv[1][0] != 83 && argv[1][0] != 84 && argv[1][0] != 85 && argv[1][0] != 86 && argv[1][0] != 87 && argv[1][0] != 88 &&
         argv[1][0] != 89 && argv[1][0] != 90 && argv[1][0] != 97 && argv[1][0] != 98 && argv[1][0] != 99 && argv[1][0] != 100 &&
         argv[1][0] != 101 && argv[1][0] != 102 && argv[1][0] != 103 && argv[1][0] != 104 && argv[1][0] != 105 && argv[1][0] != 106 &&
         argv[1][0] != 107 && argv[1][0] != 108 && argv[1][0] != 109 && argv[1][0] != 110 && argv[1][0] != 111 && argv[1][0] != 112 &&
         argv[1][0] != 113 && argv[1][0] != 114 && argv[1][0] != 115 && argv[1][0] != 116 && argv[1][0] != 117 && argv[1][0] != 118 &&
         argv[1][0] != 119 && argv[1][0] != 120 && argv[1][0] != 121 && argv[1][0] != 122) || argc != 2)
    {
        printf("Usage: %s k\n", argv[0]);
    }
    else
    {
        pt = get_string("plaintext: ");
        ct = pt;
        s = argv[1];

        for (i = 0, j = p; pt [i] != '\0' || j < strlen(s); i++, j++)
        {
            //for (j = p; s [j] != '\0'; j++)
            {
                if (pt [i] >= 65 && pt [i] <= 90)
                {
                    for (k = 0; cmp1 [k] != pt [i]; k++) { }

                    if (s [j] >= 65 && s [j] <= 90)
                    {
                        for (l = 0; cmp1 [l] != s [j]; l++) { }
                    }

                    if (s [j] >= 97 && s [j] <= 122)
                    {
                        for (l = 0; cmp2 [l] != s [j]; l++) { }
                    }

                    n = ((k + l) % 26);
                    ct [i] = cmp1 [n];

                    if (j == (strlen(s) - 1))
                    {
                        j = -1;
                    }

                }

                if (pt [i] >= 97 && pt [i] <= 122)
                {
                    for (m = 0; cmp2 [m] != pt [i]; m++) { }

                    if (s [j] >= 65 && s [j] <= 90)
                    {
                        for (q = 0; cmp1 [q] != s [j]; q++) { }
                    }

                    if (s [j] >= 97 && s [j] <= 122)
                    {
                        for (q = 0; cmp2 [q] != s [j]; q++) { }
                    }

                    n = ((m + q) % 26);
                    ct [i] = cmp2 [n];

                    if (j == (strlen(s) - 1))
                    {
                        j = -1;
                    }
                }

            }
        }

        printf("ciphertext: %s\n", ct);
    }
}