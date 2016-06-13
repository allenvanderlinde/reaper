/**
 * @file    CReaperSession.cpp
 * @author  Allen Vanderlinde
 * @date    June 8, 2016
 * @brief   Class implementation.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "headers/reaper.h"
#include "headers/CReaperSession.h"
#include "version.h"

CReaperSession::CReaperSession(const int &_argc,
                               char* _argv[]) {
    /* Does the user just want to see
        supported LMSs and feed types? */
    std::string s;
    for(int i = 0; i < (_argc - 1); i++) {
        s.assign(_argv[i + 1]);
        std::use_facet<std::ctype<char>>(std::locale()).toupper(&s[0], &s[0] + s.length());    // This is explained in detail in read_args()
        if(s.compare(ARG_SUPPORTS) == MATCH) {
            supported_types();
            return;
        }
    }
    /* Ensure arguments are entered
        correctly. */
    if(!ready(_argc, _argv)) {
        m_ready = false;
        return;
    }

    // Command line welcome message
    std::cout << std::endl << "---------------------------=====[ reaper.exe ]=====---------------------------" << std::endl << std::endl;
    std::cout << "\t" << "_____________________   _____ _______________________________ " << std::endl;
    std::cout << "\t" << "\\______   \\_   _____/  /  _  \\\\______   \\_   _____/\\______   \\" << std::endl;
    std::cout << "\t" << " |       _/|    __)_  /  /_\\  \\|     ___/|    __)_  |       _/" << std::endl;
    std::cout << "\t" << " |    |   \\|        \\/    |    \\    |    |        \\ |    |   \\" << std::endl;
    std::cout << "\t" << " " << "|____|_  /_______  /\\____|__  /____|   /_______  / |____|_  /" << std::endl;
    std::cout << "\t" << "        \\/        \\/         \\/                 \\/         \\/" << std::endl << std::endl;
    std::cout << "\t" << " Build useful HTML pages which describe, organize, and provide\n\t    various metadata about feed files for SIS integrations." << std::endl << std::endl;
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    std::cout << " reaper.exe Version: " << AutoVersion::STATUS_SHORT << AutoVersion::FULLVERSION_STRING << "\tCopyleft (C) 2016 by Allen Vanderlinde" << std::endl << std::endl;
    std::cout << " Currently supports:\n Blackboard Learn Snapshot Flat Files" << std::endl << std::endl;
    std::cout << " Default delimiter is " << '|' << std::endl;
    std::cout << "------------------------------------------------------------------------------" << std::endl << std::endl;

    m_ready = true;
}

CReaperSession::~CReaperSession() {
}

bool CReaperSession::ready(const int &_argc,
                           char* _argv[]) {
    m_argc = (_argc - 1); // Minus 1 because the first index of _argv[] will always be the name of the command
    if(m_argc < MIN_ARGS) {
        std::cout << std::endl << " reaper.exe: Too few arguments. Minimum is " << MIN_ARGS << ".\n Usage -> -f *[FEED_FILE] -h [OUTPUT_FILE] {DELIMITER:-c,-p} {-details}" << std::endl;
        return false;;
    } else if(m_argc > MAX_ARGS) {
        std::cout << std::endl << " reaper.exe: Too many arguments. Maximum is " << MAX_ARGS << ".\n Usage -> -f *[FEED_FILE] -h [OUTPUT_FILE] {DELIMITER:-c,-p} {-details}" << std::endl;
        return false;
    }
    return true;
}

bool CReaperSession::read_args(char* _argv[]) {
    std::string current_argument;    // Argument pulled from _argv[] for comparison
    bool delim_found = false;

    /* Access strings of _argv[] by adding 1 to the actual
        index location. We don't want our vector filled with the
        name of the program which is always at _argv[0].
        Traverse the argument array and see if any strings
        match a reaper option. */
    for(int i = 0; i < m_argc; i++) {
        current_argument.assign(_argv[i + 1]);  // Assign string from _argv[] to a std::string we'll manipulate with STL

        /* To guarantee case-insensitivity we'll be using
            a special reference of a default std::locale
            known as a facet. The facet of the locale we're
            interested in is the 'character type' (std::ctype),
            because std::ctype has a nice function for
            capitalizing characters independent of language
            (based on the locale) using a range between a string's
            specified starting index to a specified ending index.
            This is far more efficient than using a nested loop to
            scan each character of the argument strings, capitalize
            them one-at-a-time, and then test if they match pre-
            defined reaper arguments. */
        std::use_facet<std::ctype<char>>(std::locale()).toupper(&current_argument[0], &current_argument[0] + current_argument.length());

        if(current_argument.compare(DISP_DETAILS) == MATCH) {   /* Do any arguments match reaper's options? */
            options.use_details = true;
        } else if(current_argument.compare(ARG_PIPE) == MATCH) {
            if(!delim_found) {
                delim_found = true;
                m_delim = PIPE;
            }
        } else if(current_argument.compare(ARG_COMMA) == MATCH) {
            if(!delim_found) {
                delim_found = true;
                m_delim = COMMA;
            }
        } else if(current_argument.compare(ARG_FEED_FILE) == MATCH) {   // The next argument in the array should be the path of the feed file
            m_paths[PATH_FEED_FILE] = _argv[i + 2];
        } else if(current_argument.compare(ARG_OUTPUT_FILE) == MATCH) { // The next argument in the array should be the path of the feed file
            m_paths[PATH_OUTPUT_FILE] = _argv[i + 2];
        } else if(current_argument.compare(ARG_DUMP) == MATCH) {    // Dump stored entries to file for testing after reading source
            options.dump_entries = true;
        }
        // NOTE: IF AN OUTPUT FILE IS NOT SPECIFIED THE OUTPUT FILE WILL BY DEFAULT BE {FEED FILE}.html //
    }

    std::cout << " Using delimiter: " << m_delim << std::endl << std::endl;   // Default is |
    if(options.use_details) {
        std::cout << " Displaying details" << std::endl;
    }
    std::cout << std::endl << " Starting..." << std::endl;
    std::cout << " Storing arguments..." << std::endl;
    /* Check if reaper can even process the arguments passed to it.
        This in case someone's trying to be funny. */
    if(!store_args(_argv)) {
        std::cout << std::endl << " reaper.exe: Reaper was unable to process your arguments." << std::endl;
        return false;
    }
    if(options.use_details) std::cout << std::endl << " SUCCESS: " << m_argc << " arguments stored" << std::endl << std::endl;
    else std::cout << " SUCCESS: " << m_argc << " arguments stored" << std::endl;

    return true;
}

bool CReaperSession::store_args(char* _argv[]) {
    if(options.use_details) {
        std::cout << std::endl << "\tARGUMENT DETAILS:" << std::endl << std::endl;
    }
    for(int i = 0; i < m_argc; i++) {
        m_args.push_back(_argv[i + 1]);
        if(options.use_details) std::cout << "\t\targ[" << i << "]: \"" << m_args[i] << "\"" << std::endl;
    }
    return true;
}

void CReaperSession::reap(const std::string &_file_path,
                          const int &feed_type) {
    std::cout << " Opening \"" << m_paths[PATH_FEED_FILE] << "\"..." << std::endl;

    switch(feed_type) {
    case BB_FLAT_FILE:
        ff = new FlatFile(m_paths, options);
        if(!ff->build()) {
            std::cout << " reaper.exe: FATAL: Unable to build integration feed file object." << std::endl;
            return;
        }

        break;
    default:

        break;
    };
}
