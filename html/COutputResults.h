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

class COutputResults {
public:
    /* Receives validated file paths when
        feed object built and needs to build results
        page. */
    COutputResults(const std::vector<std::string> &_paths,
                   const options_t &_options);
    ~COutputResults();

private:
    /** @brief Structure of options passed from CReaperSession to specify special actions. */
    options_t m_options;

    /** @brief Vector of remaining arguments after delimiter and details option chosen. */
    std::vector<std::string> m_files;

    /**
     * @brief Writes HTML to file with parsed and
     * organized feed metadata and details.
     */
    void write_file();

} typedef HTML;

#endif // _COUTPUTRESULTS_H_
