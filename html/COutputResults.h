/**
 * @file    COutputResults.h
 * @author  Allen Vanderlinde
 * @date    June 17, 2016
 * @brief   Class definition for writing results to a HTML file.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _COUTPUTRESULTS_H_
#define _COUTPUTRESULTS_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "../headers/reaper.h"
#include "../headers/util.h"
#include "CHTMLOutputStruct.h"

/**
 * @brief HTML object of organized results and metadata.
 */
class COutputResults {
public:
    /* Receives validated file paths when
        feed object built and needs to build results
        page. */
    COutputResults(const std::vector<std::string> &_paths,
                   const options_t &_options,
                   const std::vector<std::wstring> &_entries);
    ~COutputResults() {
        delete m_html;
    };

private:
    /** @brief Structure of options passed from CReaperSession to specify special actions. */
    options_t m_options;

    /** @brief Vector of remaining arguments after delimiter and details option chosen. */
    std::vector<std::string> m_files;

    /** @brief Structure of elements of the results HTML page. */
    html_t* m_html;

} typedef HTML;

#endif // _COUTPUTRESULTS_H_
