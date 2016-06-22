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

int main(int argc, char* argv[]) {
    //util_ClearConsole();
    /* Build new reaper
        object. */
    grim* reaper = new grim(argc, argv);
    /* Attempt to parse and extract
        information from feed. */
    if(reaper->is_ready()) {
        if(!reaper->read_args(argv)) {
            std::cout << std::endl << " EXITING Reaper..." << std::endl;

            return 0;
        } else {
            std::cout << std::endl << " Reaper is RUNNING..." << std::endl << std::endl;
            reaper->reap(BB_FLAT_FILE);   // Final version should only need feed type specified
        }

        reaper->build_html();   // Write details and metadata of feed to HTML page
    }
    reaper->quit();

    return 0;
}
