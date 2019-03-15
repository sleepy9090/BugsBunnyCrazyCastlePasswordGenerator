/**
 ************************************************************************************************************************
 *
 *  @file                   bbccpassgen.cpp
 *  @brief                  Bugs Bunny Crazy Castle Password Generator
 *  @copyright              2019 Shawn M. Crawford
 *  @date                   March 15th, 2019
 *
 *  @remark Author:         Shawn M. Crawford
 *
 *  @note                   For use with the N.E.S. Version
 *
 ************************************************************************************************************************
 */

/* Includes */
#include <iostream>
#include <sstream>

using namespace std;

/**
 ************************************************************************************************************************
 *
 * @brief   Runs the program
 *
 * @param   N/A
 *
 * @return  N/A
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int main (int argc, char *argv[])
{
    int level = 0;
    int temp = 0;
    wchar_t tempArray[4];
    string input = "";

    cout << "Bugs Bunny Crazy Castle password generator v 1.0" << endl;
    cout << "For use with the N.E.S. game Bugs Bunny Crazy Castle" << endl;
    cout << "Coded by: sleepy9090" << endl;
    cout << "======================================" << endl;
    cout << endl;

    while (true) {
        cout << "Enter level number (0..80): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> level)
        {
            if (level >= 0 && level <= 80)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    if (level > 0)
    {
        level--;
    }

    temp = level;
    tempArray[0] = 0;
    tempArray[1] = 0;

    for (int i = 0; i < 4; i++)
    {
        tempArray[1] |= temp & 1 << i;
        temp >>= 1;
        tempArray[0] |= temp & 1 << i;
    }

    tempArray[2] = (level & 15) << 1;
    tempArray[3] = level >> 4;

    string password;
	for(int i = 0; i < 4; i++)
    {
        password += "SZWX2TPY31EH4U9IR5F6JBKGMLC7ANOD"[tempArray[i]];
    }

    cout << endl;
    cout << "Generated password: " << password << endl;

    return(0);
}

