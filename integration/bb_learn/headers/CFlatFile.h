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

/** @brief Describes the feed file type of this particular derived class. */
#define THIS_FEED_TYPE "Snapshot Flat File"

/**
 * @brief Snapshot Flat File object.
 */
class CFlatFile : public FeedFile {
public:
    /* Receives validated file paths when
        reaper determines to build this object. */
    CFlatFile(const std::vector<std::string> &_paths,
              const options_t &_options);
    ~CFlatFile();

    /**
     * @brief Build a Snapshot Flat File object from specified file.
     * @retval bool True if object is built.
     */
    bool read();

private:

} typedef FlatFile;

#endif // _CFLATFILE_H_
