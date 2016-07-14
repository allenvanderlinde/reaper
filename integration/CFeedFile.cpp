/**
 * @file    CFeedFile.cpp
 * @author  Allen Vanderlinde
 * @date    June 12, 2016
 * @brief   Base class initialization/implementation.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "CFeedFile.h"

CFeedFile::CFeedFile(const options_t &_options) {
    m_options = _options;
    /* Note: Need to call calc_size() in derived class
        as that's where file paths will be defined. This
        should follow for all derived feed file classes. */
}

CFeedFile::~CFeedFile() {
    m_files.clear();
    m_entries.clear();
}
