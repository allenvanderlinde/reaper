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

#include "../../CFeedFile.h"

#define THIS_FEED_TYPE "Snapshot Flat File"

class CFlatFile : public FeedFile {
public:
    /* Receives validated file paths when
        reaper determines to build this object. */
    CFlatFile(std::vector<std::string> _paths,
              const bool &_details);
    ~CFlatFile();

    /**
     * @brief Build a Snapshot Flat File from specified filed.
     * @param[in] _file_path Path to feed file.
     * @param[in] _details Should details be printed about this build?
     * @retval bool True if object is built.
     */
    bool build();

private:
    /** @brief Integer that keeps track of how many lines are processed. */
    unsigned int m_num_lines = 0;

    /** @brief Vector of remaining arguments after delimiter and details option chosen. */
    std::vector<std::string> m_files;

    /** @brief Vector of entries read from file line-by-line. */
    std::vector<std::wstring> m_entries;

} typedef FlatFile;

#endif // _CFLATFILE_H_
