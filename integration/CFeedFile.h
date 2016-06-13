/**
 * @file    CFeedFile.h
 * @author  Allen Vanderlinde
 * @date    June 12, 2016
 * @brief   Class definition for the SIS integration
 *          feed file base class.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CFEEDFILE_H_
#define _CFEEDFILE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "../headers/reaper.h"

class CFeedFile {
public:
    /* Base class expects whether details
        should be displayed from primary
        thread (e.g., main()). */
    CFeedFile(const options_t &_options);
    ~CFeedFile();

    /**
     * @brief Dump contents of entries vector to a plain text file
     * essentially as a copy to test if UTF-8 characters or other
     * features of the source file remain intact from reaper's storage.
     */
    inline void dump_entries() {
        std::string dump_file_path;
        dump_file_path = m_files[PATH_FEED_FILE].substr(0, m_files[PATH_FEED_FILE].find_first_of('.', 0));
        dump_file_path += "_dumped.txt";

        std::wofstream out(dump_file_path, std::ios::out);
        if(out) {
            if(out.is_open()) {
                for_each(m_entries.begin(), m_entries.end(), [&out](std::wstring ws){ out << ws << std::endl; });
            }
            out.close();
            std::cout << std::endl << " reaper.exe: Successfully dumped entries into \"" << dump_file_path << "\"." << std::endl;
        } else {
            std::cout << " reaper.exe: Unable to dump entries into \"" << dump_file_path << "\"." << std::endl;
        }
    }

protected:
    /**
     * @brief Virtual function for derived classes' build operation.
     * @retval bool True if build successful.
     */
    virtual bool build() = 0;

    /** @brief Structure of options passed from CReaperSession to specify special actions. */
    options_t m_options;

    /** @brief Integer that keeps track of how many lines are processed. */
    unsigned int m_num_lines = 0;

    /** @brief Vector of remaining arguments after delimiter and details option chosen. */
    std::vector<std::string> m_files;

    /** @brief Vector of entries read from file line-by-line. */
    std::vector<std::wstring> m_entries;

} typedef FeedFile;

#endif // _CFEEDFILE_H_
