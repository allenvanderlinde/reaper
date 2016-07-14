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
                               const options_t &_options,
                               const std::vector<std::wstring> &_entries) {
    m_files = _paths;
    m_options = _options;
    if(m_files[PATH_OUTPUT_FILE] == "") {   // Give results page default name if none given
        m_files[PATH_OUTPUT_FILE] = "results_" + m_files[PATH_FEED_FILE] + ".html";
    }
    std::cout << " Building HTML results: \"" << m_files[PATH_OUTPUT_FILE] << "\"..." << std::endl;

    m_html = new html_t(m_files[PATH_FEED_FILE], m_files[PATH_OUTPUT_FILE]);
    m_html->write(_entries);
}
