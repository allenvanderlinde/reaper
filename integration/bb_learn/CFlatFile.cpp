/**
 * @file    CFlatFile.cpp
 * @author  Allen Vanderlinde
 * @date    June 10, 2016
 * @brief   Class implementation.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "headers/CFlatFile.h"

CFlatFile::CFlatFile(std::vector<std::string> _paths,
                     const options_t &_options)
    : CFeedFile(_options) {
    m_files = _paths;
}

CFlatFile::~CFlatFile() {
};

bool CFlatFile::build() {
    /* These are the input stream objects for reading
        the specified feed file (UTF-8). */
    std::wstringstream u16_sstream;
    std::wstring line;  /* Temporary string for each line which is
                            placed in the entries vector. */
    std::wifstream u16_ifs(m_files[PATH_FEED_FILE], std::ios::in);    // Open the stream to the file immediately

    /* Read the specified feed file and push each
        line into the entries vector. */
    if((u16_ifs.rdstate() & std::fstream::failbit) != 0) {  // != 0 is failure meaning the failbit is present
        std::cout << " reaper: Unable to open file at: \"" << m_files[PATH_FEED_FILE] << "\"" << std::endl;
        return false;
    } else {
        std::cout << " SUCCESS: Opened \"" << m_files[PATH_FEED_FILE] << "\"" << std::endl;
        /* Calculate physical size
            of file. */
        u16_ifs.seekg(0, u16_ifs.end);
        feed_bytes = u16_ifs.tellg();
        u16_ifs.seekg(0, u16_ifs.beg);
        std::cout << std::endl << " Reading..." << std::endl;
        if(m_options.use_details) {
            std::cout << std::endl << " \ttype:\t\t" << THIS_FEED_TYPE << std::endl;
            std::cout << "\tfile size: \t" << feed_bytes << " bytes: " << ((double)feed_bytes / 1024) << "k: " << std::fixed << std::setprecision(5) << ((double)((double)feed_bytes / 1024) / 1024) << "mb" << std::endl;
        }
        if(u16_ifs.is_open()) {
            /* Build the entries vector from each line
                in the feed file via a loop. */
            std::cout << std::endl;
            u16_ifs.clear();
            u16_ifs.seekg(0, u16_ifs.beg);
            while(std::getline(u16_ifs, line)) {
                m_entries.push_back(line);
                m_num_lines++;

                show_progress(line.length());
            }
            print_meter_done();
            if(m_options.use_details) std::cout << "\tlength:\t\t" << m_num_lines << " entries" << std::endl << std::endl;

            /* This ensures if the process is successful
                the user will know with a 100% regardless
                of the float interval in progress_pcent(). */
            //std::cout << " READING: 100%" << std::endl;

            if(m_options.dump_entries) dump_entries();
            std::cout << std::endl;

            /* Print out flat file's lines (Note: The cmd console isn't set to display Unicode chars correctly). */
            //if(m_options.use_details) std::for_each(m_entries.begin(), m_entries.end(), [](std::wstring s){ std::wcout << "\t" << s << std::endl; });
            u16_ifs.close();
        } else {
            std::cout << " reaper: Feed file is not open." << std::endl;
            return false;
        }
    }

    return true;
}
