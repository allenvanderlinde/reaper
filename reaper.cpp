/**
 * @file    reaper.cpp
 * @author  Allen Vanderlinde
 * @date    June 8, 2016
 * @brief   reaper is a lightweight utility that builds
            HTML files with nicely arranged and organized
            data from Snapshot Flat Files. Current
            delimiters accepted are , and |. Default is |.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "headers/reaper.h"
#include "headers/CReaperSession.h"
#include "headers/util.h"

/*
    NOTE:
    Can use struct to represent HTML elements that
    can be concatenated to other strings for writing to file.
*/

void test_output(std::string file) {
    std::ofstream output(file);
    if(output.is_open()) {
        output << "<!DOCTYPE html>" << std::endl << "<html>\n<body>\n</body>\n</html>" << std::endl;
    }
    output.close();
}

int main(int argc, char* argv[]) {
    //utilClearConsole();
    /* Build new reaper
        object. */
    grim* reaper = new grim(argc, argv);
    /* Attempt to parse and extract
        information from feed. */
    if(reaper->is_ready()) {
        reaper->read_args(argv);
    } else return 0;
    std::cout << std::endl << " Reaper is RUNNING..." << std::endl << std::endl;

    reaper->reap(std::string("input.txt"), BB_FLAT_FILE);   // Final version should only need feed type specified

    std::cout << std::endl << " EXITING Reaper..." << std::endl;

    return 0;
}
