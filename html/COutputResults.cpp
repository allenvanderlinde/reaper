/**
 * @file    COutputResults.cpp
 * @author  Allen Vanderlinde
 * @date    June 17, 2016
 * @brief   Class implementation.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "COutputResults.h"

COutputResults::COutputResults(const std::vector<std::string> &_paths,
                               const options_t &_options) {
    m_files = _paths;
    m_options = _options;
    if(m_files[PATH_OUTPUT_FILE] == "") {   // Give results page default name if none given
        m_files[PATH_OUTPUT_FILE] = "results_" + m_files[PATH_FEED_FILE] + ".html";
    }
    std::cout << " Building HTML results: \"" << m_files[PATH_OUTPUT_FILE] << "\"..." << std::endl;

    write_file();
}

COutputResults::~COutputResults() {
}

void COutputResults::write_file() {
    std::wifstream u16_ifs(HTML_TEMPLATE, std::ios::in);
    std::wstring line;
    std::wstring keyword;

    std::wofstream u16_ofs;
    unsigned int byte = 0;

    keyword = L"<title>";

    unsigned line_num = 0;
    std::size_t col = 0;

    if((u16_ifs.rdstate() & std::fstream::failbit) != 0) {
        //std::cout << " reaper: Unable to open file at: \"" << m_files[PATH_OUTPUT_FILE] << "\"" << std::endl;
        return;
    }
    /* Search through output template and find
        keywords to modify for results. */
    while(std::getline(u16_ifs, line)) {
        line_num++;

        col = line.find(keyword);

        /* This prints each record in feed line-for-line.
            (Used for programmer testing only). */
        //std::wcout << " " << line_num << " | \t" << line << std::endl;

        if(col != std::string::npos) {
            std::wcout << std::endl << " tellg(): " << u16_ifs.tellg() << " |Found keyword \"" <<  keyword << "\" at line " << line_num << " and column " << (unsigned)(col + 1) << std::endl;
            byte = u16_ifs.tellg();
        }
    }
    u16_ifs.close();
}
