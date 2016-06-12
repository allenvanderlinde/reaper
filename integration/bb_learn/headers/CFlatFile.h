/**
 * @file    CFlatFile.h
 * @author  Allen Vanderlinde
 * @date    June 8, 2016
 * @brief   Class definition for the representation of a Snapshot
 *          Flat File for Blackboard Learn SIS integrations.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CFLATFILE_H_
#define _CFLATFILE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class CFlatFile {
public:
    CFlatFile();
    ~CFlatFile();

    /**
     * @brief Build a Snapshot Flat File from specified filed.
     * @param[in] _file_path Path to feed file.
     * @param[in] _details Should details be printed about this build?
     * @retval bool True if object is built.
     */
    bool build(const std::string &_file_path,
               const bool &_details);

private:
    /** @brief Integer that keeps track of how many lines are processed. */
    unsigned int m_num_lines = 0;
    /** @brief Display detailed actions of this object during runtime.
     *  CReaperSession passes its value of details to this object.
     */
    bool m_details;
    /** @brief Vector of remaining arguments after delimiter and details option chosen. */
    std::vector<std::string> m_files;

    /** @brief Vector of entries read from file line-by-line. */
    std::vector<std::string> m_entries;

} typedef FlatFile;

#endif // _CFLATFILE_H_
