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
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>

#include "../headers/reaper.h"

class CFeedFile {
public:
    /* Base class expects whether details
        should be displayed from primary
        thread (e.g., main()). */
    CFeedFile(const options_t &_options);
    virtual ~CFeedFile();

    /**
     * @brief Dump contents of entries vector to a plain text file
     * essentially as a copy to test if UTF-8 characters or other
     * features of the source file remain intact from reaper's storage.
     */
    inline void dump_entries() {
        std::string dump_file_path;
        dump_file_path = m_files[PATH_FEED_FILE].substr(0, m_files[PATH_FEED_FILE].find_first_of('.', 0));
        dump_file_path += "_dumped.txt";

        std::cout << std::endl << " Dumping feed..." << std::endl;

        std::wofstream out(dump_file_path, std::ios::out);
        if(out) {
            if(out.is_open()) {
                std::for_each(m_entries.begin(), m_entries.end(), [&out](std::wstring ws){ out << ws << std::endl; });
            }
            out.close();
            std::cout << std::endl << " reaper.exe: Successfully dumped entries into \"" << dump_file_path << "\"." << std::endl;
        } else {
            std::cout << " reaper.exe: Unable to dump entries into \"" << dump_file_path << "\"." << std::endl;
        }
    }

    /**
     * @brief Display a progress indicator (e.g., percentage) when
     * building the feed file object. ASCII characters are used here
     * to represent the "bar". Meter width is hard-coded.
     * @param[in] line_len The number of characters currently read to
     * divide by the size of the feed. That number * 100 equals the %.
     */
    inline void show_progress(const std::size_t &line_len) {
        static double chars = 0;
        static int meter_width = 70;
        static int digits = (int)log10(feed_bytes);

        chars += (double)line_len;
        if((int)chars % (int)(digits * 1000) == 0) { /* Modulus by the # of digits in size
                                                    of feed (divide by 2 for more percents). */
            std::cout << " [";
            double r = chars / feed_bytes;
            int n = (int)(r * meter_width);
            for(int j = 0; j < meter_width; j++) {
                if(j < n) std::cout << static_cast<char>(219);
                else if(j == n) std::cout << static_cast<char>(219);
                else std::cout << static_cast<char>(205);//" ";
            }
            std::cout << "] " << std::fixed << std::setprecision(0) << (r * 100.0) << "%\r";
            std::cout.flush();
        }
    }

    /**
     * @brief This just prints a finished 100% meter for the user after
     * reading.
     */
    inline void print_meter_done() {
        std::cout << " [";
        for(int i = 0; i < 69; i++) {
            std::cout << static_cast<char>(219);
        }
        std::cout << "] 100%";
        std::cout << std::endl << std::endl;
    }

    /**
     * @brief Calculate size of feed file which this object
     * is built from.
     * @retval unsigned int The number of bytes in the feed file.
     */
    inline void calc_size() {
        std::wifstream u16_ifs(m_files[PATH_FEED_FILE], std::ios::in);    // Open the stream to the file immediately
        /* Calculate physical size
            of file. */
        u16_ifs.seekg(0, u16_ifs.end);
        feed_bytes = (unsigned int)u16_ifs.tellg();
        u16_ifs.seekg(0, u16_ifs.beg);

        u16_ifs.close();
    }

    /**
     * @brief Return the size of the feed file in bytes.
     * @retval unsigned int The size of the feed in bytes.
     */
    inline unsigned int file_size() { return feed_bytes; }

protected:
    /**
     * @brief Virtual function for derived classes' build operation.
     * @retval bool True if build successful.
     */
    virtual bool build() = 0;

    /** @brief Structure of options passed from CReaperSession to specify special actions. */
    options_t m_options;

    /** @brief Size in bytes of feed file. */
    unsigned int feed_bytes = 0;
    /** @brief Integer that keeps track of how many lines are processed. */
    unsigned int m_num_lines = 0;

    /** @brief Timer/clock to measure duration of feed file read. */
    std::clock_t start;
    /** @brief Duration of a feed file read based on a std::clock_t timer. */
    double dur;

    /** @brief Vector of remaining arguments after delimiter and details option chosen. */
    std::vector<std::string> m_files;

    /** @brief Vector of entries read from file line-by-line. */
    std::vector<std::wstring> m_entries;

} typedef FeedFile;

#endif // _CFEEDFILE_H_
