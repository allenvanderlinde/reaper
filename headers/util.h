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
 * @brief Display a simple progress percentage.
 * Currently only a model with contrived
 * percentage iterations.
 */
inline void util_ShowProgress(void) {
    std::cout << std::endl;   // New line if necessary

    float progress = 0.0f; /* We use a float for the model to control iteration speed.
                                A real progress int or float should iterate to 100% only
                                when an actual computational cycle is completed. The weight
                                of the computation naturally controls iteration speed. */
    while(progress <= 1.0f) {
        std::cout << " " << (int)(progress * 100.0f) << "%\r";   // Rudimentary formatting; easily modified
        std::cout.flush();

        progress += 0.001f; // Trivial iteration. This forces the loop to cycle 10,000 times
    }
    std::cout << " 100%" << std::endl;
}

#endif // _UTIL_H_
