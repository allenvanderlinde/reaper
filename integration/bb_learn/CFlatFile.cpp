/**
 * @file    CFlatFile.cpp
 * @author  Allen Vanderlinde
 * @date    June 10, 2016
 * @brief   Class implementation.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../headers/reaper.h"
#include "headers/CFlatFile.h"

CFlatFile::CFlatFile() {    // Members are initialized by input from CReaperSession
}

CFlatFile::~CFlatFile() {
};

bool CFlatFile::build(const std::string &_file_path,
                      const bool &_details) {
    std::string line;    /* Temporary string for each line which is
                            placed in the entries vector. */
    m_details = _details;
    std::ifstream input(_file_path, std::ios::in);    // Open the stream to the file immediately
    if(input) {
        if(m_details) {
            std::cout << std::endl << " \t[Flat File metadata]: " << std::endl << std::endl;
            /* Calculate physical size
                of file. */
            input.seekg(0, input.end);
            int len = input.tellg();
            input.seekg(0, input.beg);
            std::cout << "\t\tfile size: \t" << len << " bytes: " << ((double)len / 1024) << "k: " << ((double)((double)len / 1024) / 1024) << "mb" << std::endl;
        }
        if(input.is_open()) {
            /* Build the entries vector from each line
                in the feed file. */
            while(getline(input, line)) {
                m_entries.push_back(line);
                m_num_lines++;
            }
            if(m_details) std::cout << "\t\tsize: \t\t" << m_num_lines << " entries" << std::endl;
            std::cout << std::endl;
            /* Print out flat file's lines. */
            if(m_details) for_each(m_entries.begin(), m_entries.end(), [](std::string s){ std::cout << "\t" << s << std::endl; });
        } else {
            std::cout << " reaper: Feed file is not open." << std::endl;
            return false;
        }
    } else {
        std::cout << " reaper: Unable to open file at: \"" << _file_path << "\"" << std::endl;
        return false;
    }

    return true;
}
