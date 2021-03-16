#include <iostream>
using namespace std;

void bigName (string name)
{
    const int alphabet = 26;
    const int numberOfLines = 5;
    string bigLetter[numberOfLines][alphabet];

    bigLetter[0][0]="  #  ";
    bigLetter[1][0]=" # # ";
    bigLetter[2][0]="#   #";
    bigLetter[3][0]="#####";
    bigLetter[4][0]="#   #";

    bigLetter[0][1]="#### ";
    bigLetter[1][1]="#   #";
    bigLetter[2][1]="#### ";
    bigLetter[3][1]="#   #";
    bigLetter[4][1]="#### ";

    bigLetter[0][2]=" ####";
    bigLetter[1][2]="#    ";
    bigLetter[2][2]="#    ";
    bigLetter[3][2]="#    ";
    bigLetter[4][2]=" ####";

    bigLetter[0][3]="#### ";
    bigLetter[1][3]="#   #";
    bigLetter[2][3]="#   #";
    bigLetter[3][3]="#   #";
    bigLetter[4][3]="#### ";

    bigLetter[0][4]="#####";
    bigLetter[1][4]="#    ";
    bigLetter[2][4]="#### ";
    bigLetter[3][4]="#    ";
    bigLetter[4][4]="#####";

    bigLetter[0][5]="#####";
    bigLetter[1][5]="#    ";
    bigLetter[2][5]="#### ";
    bigLetter[3][5]="#    ";
    bigLetter[4][5]="#    ";

    bigLetter[0][6]=" ### ";
    bigLetter[1][6]="#    ";
    bigLetter[2][6]="# ###";
    bigLetter[3][6]="#   #";
    bigLetter[4][6]=" ### ";

    bigLetter[0][7]="#   #";
    bigLetter[1][7]="#   #";
    bigLetter[2][7]="#####";
    bigLetter[3][7]="#   #";
    bigLetter[4][7]="#   #";

    bigLetter[0][8]="#####";
    bigLetter[1][8]="  #  ";
    bigLetter[2][8]="  #  ";
    bigLetter[3][8]="  #  ";
    bigLetter[4][8]="#####";

    bigLetter[0][9]="#####";
    bigLetter[1][9]="   # ";
    bigLetter[2][9]="   # ";
    bigLetter[3][9]="#  # ";
    bigLetter[4][9]=" ##  ";

    bigLetter[0][10]="#   #";
    bigLetter[1][10]="#  # ";
    bigLetter[2][10]="###  ";
    bigLetter[3][10]="#  # ";
    bigLetter[4][10]="#   #";

    bigLetter[0][11]="#    ";
    bigLetter[1][11]="#    ";
    bigLetter[2][11]="#    ";
    bigLetter[3][11]="#    ";
    bigLetter[4][11]="#####";

    bigLetter[0][12]="#   #";
    bigLetter[1][12]="## ##";
    bigLetter[2][12]="# # #";
    bigLetter[3][12]="#   #";
    bigLetter[4][12]="#   #";

    bigLetter[0][13]="#   #";
    bigLetter[1][13]="##  #";
    bigLetter[2][13]="# # #";
    bigLetter[3][13]="#  ##";
    bigLetter[4][13]="#   #";

    bigLetter[0][14]=" ### ";
    bigLetter[1][14]="#   #";
    bigLetter[2][14]="#   #";
    bigLetter[3][14]="#   #";
    bigLetter[4][14]=" ### ";

    bigLetter[0][15]="#### ";
    bigLetter[1][15]="#   #";
    bigLetter[2][15]="#### ";
    bigLetter[3][15]="#    ";
    bigLetter[4][15]="#    ";

    bigLetter[0][16]=" ### ";
    bigLetter[1][16]="#   #";
    bigLetter[2][16]="# # #";
    bigLetter[3][16]="#  ##";
    bigLetter[4][16]=" ####";

    bigLetter[0][17]="#### ";
    bigLetter[1][17]="#   #";
    bigLetter[2][17]="#### ";
    bigLetter[3][17]="#  # ";
    bigLetter[4][17]="#   #";

    bigLetter[0][18]=" ### ";
    bigLetter[1][18]="#    ";
    bigLetter[2][18]=" ### ";
    bigLetter[3][18]="    #";
    bigLetter[4][18]=" ### ";

    bigLetter[0][19]="#####";
    bigLetter[1][19]="  #  ";
    bigLetter[2][19]="  #  ";
    bigLetter[3][19]="  #  ";
    bigLetter[4][19]="  #  ";

    bigLetter[0][20]="#   #";
    bigLetter[1][20]="#   #";
    bigLetter[2][20]="#   #";
    bigLetter[3][20]="#   #";
    bigLetter[4][20]=" ### ";

    bigLetter[0][21]="#   #";
    bigLetter[1][21]="#   #";
    bigLetter[2][21]="#   #";
    bigLetter[3][21]=" # # ";
    bigLetter[4][21]="  #  ";

    bigLetter[0][22]="#   #";
    bigLetter[1][22]="#   #";
    bigLetter[2][22]="#   #";
    bigLetter[3][22]="# # #";
    bigLetter[4][22]=" # # ";

    bigLetter[0][23]="#   #";
    bigLetter[1][23]=" # # ";
    bigLetter[2][23]="  #  ";
    bigLetter[3][23]=" # # ";
    bigLetter[4][23]="#   #";

    bigLetter[0][24]="#   #";
    bigLetter[1][24]="#   #";
    bigLetter[2][24]=" # # ";
    bigLetter[3][24]="  #  ";
    bigLetter[4][24]="  #  ";

    bigLetter[0][25]="#####";
    bigLetter[1][25]="   # ";
    bigLetter[2][25]="  #  ";
    bigLetter[3][25]=" #   ";
    bigLetter[4][25]="#####";

    string bigLetterName[numberOfLines];
    for (int i = 0; i < name.length(); i++)
    {
        int letter = int(name[i]) - 97;
        bigLetterName[0] += bigLetter[0][letter] + ' ';
        bigLetterName[1] += bigLetter[1][letter] + ' ';
        bigLetterName[2] += bigLetter[2][letter] + ' ';
        bigLetterName[3] += bigLetter[3][letter] + ' ';
        bigLetterName[4] += bigLetter[4][letter] + ' ';
    }
    for (int i = 0; i < 5; i++) cout << bigLetterName[i] << endl;
}

int main()
{
    string name;
    cin >> name;
    bigName(name);
    return 0;
}
