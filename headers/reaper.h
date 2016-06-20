/**
 * @file    reaper.h
 * @author  Allen Vanderlinde
 * @date    June 10, 2016
 * @brief   Constants, definitions, etc.,
 *          for the more general aspects of reaper.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _REAPER_H_
#define _REAPER_H_

/** @brief String of currently supported SIS integration feed types. */
#define CURRENTLY_SUPPORTED "-> Blackboard Learn (9.1+) Snapshot Flat File (plain text)"

/** @brief Maximum number of arguments allowed. */
#define MAX_ARGS 7
/** @brief Minimum number of arguments allowed. */
#define MIN_ARGS 2
/** @brief Specifies that the next argument is the feed file. */
#define ARG_FEED_FILE "-F"
/** @brief Specifies that the next argument is the output file (.html). */
#define ARG_OUTPUT_FILE "-H"
/** @brief Option to print out more details in the console. */
#define DISP_DETAILS "-DETAILS"
/** @brief Delimiter option specified to be a comma. */
#define ARG_COMMA "-C"
/** @brief Delimiter option specified to be a pipe. */
#define ARG_PIPE "-P"
/** @brief Option to dump contents stored in entries vector to file for testing. */
#define ARG_DUMP "-D"
/** @brief Option to display which SIS integration feed types reaper supports. */
#define ARG_SUPPORTS "-SUPPORTS"

/** @brief Comma character delimiter. */
#define COMMA ","
/** @brief Pipe character delimiter. */
#define PIPE "|"
/** @brief Human readable replacement for 0 when comparing strings. */
#define MATCH 0

/** @brief Path to HTML template file for results. */
#define HTML_TEMPLATE "template.html"

/** @brief Structure of options passed between objects. */
struct reaper_options {
    /** @brief Display details during execution. */
    bool use_details        = false;
    /** @brief Dump entries from feed's vector to new file. */
    bool dump_entries       = false;
} typedef options_t;

/** @brief Enumeration used to identify index of certain file paths in
 *  CReaperSession::paths vector.
 */
enum {
    PATH_FEED_FILE = 0,
    PATH_OUTPUT_FILE
};

/** @brief Blackboard Learn Snapshot Flat File for native SIS. */
#define BB_FLAT_FILE 1

#endif // _REAPER_H_
