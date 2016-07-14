/**
 * @file    CHTMLOutputStruct.h
 * @author  Allen Vanderlinde
 * @date    June 22, 2016
 * @brief   Class which defines the actual HTML markup of the results page.
 */
/*
   Copyleft (C) 2016 by Allen Vanderlinde
   reaper and its source code are licensed under the GNU General Public License (GPL)
   and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CHTMLOUTPUTSTRUCT_H_
#define _CHTMLOUTPUTSTRUCT_H_

/** @brief Structure-like class of elements of the results HTML page. */
class CHTMLOutputStruct {
public:
    CHTMLOutputStruct(const std::string &_feed_file_path,
                      const std::string &_output_file_path) {
        m_path = _feed_file_path;
        m_output = _output_file_path;
    };
    ~CHTMLOutputStruct(){};

    /** @brief String with markup for the DOCTYPE (default is HTML5). */
    std::wstring m_doctype = L"<!DOCTYPE html>\n<html lang=\"en-US\">\n";
    /** @brief String with markup for the title. */
    std::wstring m_title = L"<title>Reaper Results</title>\n\t";
    /** @brief String with markup for any meta tags. */
    std::wstring m_meta = L"<meta charset=\"utf-8\">\n\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n\t";
    /** @brief String with markup for any link tags. */
    std::wstring m_link = L"<link rel=\"stylesheet\" href=\"http://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css\">\n\t";
    /** @brief String with markup for any script tags. */
    std::wstring m_script = L"<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.12.0/jquery.min.js\"></script>\n\t<script src=\"http://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js\"></script>\n";
    /** @brief String with markup for beginning of body of page.
        This is built within CHTMLOutputStruct::write(). */
    std::wstring m_body;

    /**
     @brief This function is what actually writes the HTML markup to file.
     @param[in] _entries A vector of feed file rows/records.
     */
    inline void write(const std::vector<std::wstring> &_entries) {
        std::wofstream u16_ofs;
        u16_ofs.open(m_output, std::ios::out);

        std::cout << " Writing markup..." << std::endl;
        if((u16_ofs.rdstate() & std::fstream::failbit) != 0) {
            std::cout << " reaper: FATAL: Unable to open output stream for writing at \"" << m_path << "\"." << std::endl;
            return;
        } else {
            std::wstring new_path;
            util_WString(new_path, m_path);
            m_body = L"<body>\n\t<div class=\"container\">\n\t\t<h1>Reaper Results<small>&nbsp;&nbsp;Metadata and Information</small></h1>\n\t\t<h4>Feed File: " + new_path +  + L"</h4>\n\t</div>\n";

            u16_ofs << m_doctype;
            u16_ofs << m_header;
            u16_ofs << m_body;
            u16_ofs << m_footer;
        }

        //util_SearchKeyword(HTML_TEMPLATE, L"<div");
        u16_ofs.close();
    };

    /** @brief String with markup for the header of the page. */
    std::wstring m_header = L"<head>\n\t" + m_title + m_meta + m_link + m_script + L"</head>\n";
    /** @brief String with markup for the footer of the page. */
    std::wstring m_footer = L"</body>\n</html>";

private:
    /** @brief Path to output file to write to. */
    std::string m_path;
    /** @brief Path to feed file which was processed. */
    std::string m_output;

    /** @brief Entries vector from which to build HTML results. */
    std::vector<std::wstring> m_entries;

} typedef html_t;

#endif // _CHTMLOUTPUTSTRUCT_H_
