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

class CFeedFile {
public:
    CFeedFile(const bool &_details);
    ~CFeedFile();

protected:
    /** @brief Display detailed actions of this object during runtime.
     *  CReaperSession passes its value of details to this object.
     */
    bool m_details;

    /**
     * @brief Virtual function for derived classes' build operation.
     * @retval bool True if build successful.
     */
    virtual bool build() = 0;

} typedef FeedFile;

#endif // _CFEEDFILE_H_
