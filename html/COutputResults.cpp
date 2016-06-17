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
    if(m_files[PATH_OUTPUT_FILE] == "") {
        m_files[PATH_OUTPUT_FILE] = "results_" + m_files[PATH_FEED_FILE] + ".html";
    }
    std::cout << " Building HTML results: \"" << m_files[PATH_OUTPUT_FILE] << "\"..." << std::endl;

    write_file();
}

COutputResults::~COutputResults() {
}

void COutputResults::write_file() {
    std::wofstream u16_ofs(m_files[PATH_OUTPUT_FILE], std::ios::out);

    if(u16_ofs.is_open()) {
        u16_ofs.close();
    }
}
