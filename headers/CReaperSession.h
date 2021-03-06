/**
 * @file    CReaperSession.h
 * @author  Allen Vanderlinde
 * @date    June 8, 2016
 * @brief   Class definition for a reaper session
 *          object.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CREAPERSESSION_H_
#define _CREAPERSESSION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "reaper.h"
#include "../integration/bb_learn/headers/CFlatFile.h"
#include "../html/COutputResults.h"

/**
 * @brief Session object for reaper.
 */
class CReaperSession {
public:
    /* Constructor/destructor. */
    CReaperSession(const int &_argc,
                   char* _argv[]);
    ~CReaperSession();

    /**
     * @brief Check arguments and ability to process before running.
     * @param[in] _argc This is a copy of argc passed when object is instantiated.
     * @param[in] _argv[] This is a copy of *argv[] passed when object is instantiated.
     * @retval bool Yes or no.
     */
    bool ready(const int &_argc,
               char* _argv[]);

    /**
     * @brief Starts actual argument identification and determines user options.
     * @param[in] _argv Array of strings containing arguments to be stored (CReaperSession::store_args).
     */
    bool read_args(char* _argv[]);
    /**
     * @brief Store arguments passed into the command line.
     * @param[in] _argv Array of strings containing arguments.
     * @retval bool True if command line arguments successfully stored.
     */
    bool store_args(char* _argv[]);
    /**
     * @brief Tells whether the feed was read successfully.
     * @retval m_feed_ready True if feed read successfully.
     */
    bool feed_ready() { return m_feed_ready; }

    /**
     * @brief The beginning of primary processing. Open a file
     * and parse each line into the object's vector.
     * @param[in] feed_type A string representing the kind of feed
     * file being used based on the integration.
     */
    void reap(const int &feed_type);
    /**
     * @brief Parses feed information and builds a results
     * page in HTML which contains entry details and metadata
     */
    void build_html();

    /**
     * @brief Are details being displayed?
     * @retval bool Yes or no.
     */
    bool using_details() { return m_options.use_details; }
    /**
     * @brief Is reaper ready to run?
     * @retval bool Yes or no.
     */
    bool is_ready() { return m_ready; }

    /**
     * @brief Print a basic exit string to console.
     */
    inline void quit() { std::cout << std::endl << std::endl << " EXITING Reaper..." << std::endl; }

private:
    /** @brief Tells main thread if this object was instantiated successfully. */
    bool m_ready = false;
    /** @brief Structure of reaper options to use during runtime. */
    options_t m_options;
    /** @brief Tells if the feed file was loaded and read successfully. */
    bool m_feed_ready = false;

    /** @brief Number of arguments passed into the command line. */
    int m_argc;
    /** @brief The actual character identifying the delimiter when it's found. */
    std::string m_delim = "|";

    /** @brief Vector of arguments passed into the command line. */
    std::vector<std::string> m_args;

    /** @brief Vector of file paths to be passed to feed file object
     *  (e.g, "feed.txt", "output.html"). The vector is initialized
     *  immediately with arbitrary empty string literals. This
     *  is so these two indexes of the vector can later be referenced
     *  directly with paths[{index}], where {index} will equal either
     *  PATH_FEED_FILE or PATH_OUTPUT_FILE.
     */
    std::vector<std::string> m_paths{"", ""};

    /** @brief Object which represents a Snapshot Flat File and
     *  contains unique, useful information and functions.
     */
    FlatFile* ff;

    /** @brief Object which represents the HTML results page
     *  built from feed information.
     */
    HTML* results;

    /**
     * @brief Displays which SIS integration feeds are supported.
     */
    inline void supported_types() {
        std::cout << std::endl << "  REAPER.exe" << std::endl << std::endl;
        std::cout << "  LMS and integration feed type support:" << std::endl;
        std::cout << "  ---------------------------------------------------" << std::endl << std::endl;
        std::cout << "\t" << CURRENTLY_SUPPORTED << std::endl;
    }

} typedef grim;

#endif // _CREAPERSESSION_H_
