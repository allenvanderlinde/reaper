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
#define MAX_ARGS 6
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
/** @brief Option to display which SIS integration feed types reaper supports. */
#define ARG_SUPPORTS "-SUPPORTS"

/** @brief Comma character delimiter. */
#define COMMA ","
/** @brief Pipe character delimiter. */
#define PIPE "|"
/** @brief Human readable replacement for 0 when comparing strings. */
#define MATCH 0

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
