/**
 * @file    util.h
 * @author  Allen Vanderlinde
 * @date    June 10, 2016
 * @brief   Utility functions for reaper and OS-specific code and hacks.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _UTIL_H_
#define _UTIL_H_

#include <windows.h>
#include <iostream>

/**
 * @brief This function traverses each cell of the console
 * and replaces it with a space, effectively clearing
 * the console.
 */
inline void util_ClearConsole() {
    HANDLE hConsole;
    CONSOLE_SCREEN_BUFFER_INFO csbi_t;
    DWORD nCount;
    DWORD nNumCells;
    COORD zerozero = {0, 0};

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get a handle on the console for interaction
    if(hConsole == INVALID_HANDLE_VALUE) return;

    if(!GetConsoleScreenBufferInfo(hConsole, &csbi_t)) return;
    /* Calculate how many cells on the screen;
        this adjusts for user-defined console dimensions. */
    nNumCells = csbi_t.dwSize.X * csbi_t.dwSize.Y;

    if(!FillConsoleOutputCharacter(hConsole,
                                   (TCHAR) ' ',
                                   nNumCells,
                                   zerozero,
                                   &nCount)) return;
    SetConsoleCursorPosition(hConsole, zerozero);
}

/**
 * @brief This function opens and reads a plain text file
 * line-for-line to search for a specific keyword. Details
 * about the occurrence (e.g., line number, column number)
 * are printed to the console.
 */
inline void util_SearchKeyword(std::string path,
                               std::wstring keyword) {
    std::wifstream u16_ifs(path, std::ios::in);
    std::wstring line;
    unsigned int byte = 0;
    unsigned int line_num = 0;
    std::size_t col = 0;

    if((u16_ifs.rdstate() & std::fstream::failbit) != 0) {
        std::cout << " reaper: Unable to open file at: \"" << path << "\"" << std::endl;
        return;
    }
    std::cout << std::endl << " Searching in \"" << path << "\"...";

    /* Search through specified file and find
        keywords to store or modify. */
    while(std::getline(u16_ifs, line)) {
        line_num++;
        col = line.find(keyword);
        if(col != std::string::npos) {
            byte = u16_ifs.tellg();
            std::wcout << std::endl << "\ttellg(): " << byte << " | Found keyword \"" << keyword << "\" at line " << line_num << " and column " << (unsigned int)(col + 1);
        }
    }
    u16_ifs.close();
}

/**
 @brief Convert a std::string to a std::wstring.
 @param[in] ws Reference to the string to assign from std::string.
 @param[in] s String to change into std::wstring.
 */
inline void util_WString(std::wstring &ws,
                         const std::string &s) {
    std::wstring temp(s.begin(), s.end());
    ws = temp;
}

#endif // _UTIL_H_
