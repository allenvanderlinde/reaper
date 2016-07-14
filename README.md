# UPDATE
**7/14/2016** - reaper's development, although ongoing, will no longer have live updates to my public GitHub repository. I'm writing a new proprietary thread API which reaper will heavily use. I'll be licensing the API to third-party developers once it's in a good enough shape and version 1.0 is released :]

Current plans for reaper's release are still to be determined. I fully plan on releasing a portable executable and accompanying documentation for non-commercial use by public institutions.

A non-free version will also be available with possible negotiable functionality on a tiered basis for for-profit higher educational, government, and professional institutions.

Any code and files currently published are available for educational purposes and will retain the current GNU General Public License.

The above stipulations will remain as they are until otherwise noted by me.

# Latest Code Base
**Commit:** Io2
**Desc:** Progress bar finalized and timer added. Option output organization
finalized. Feed file reading and vector storage optimized (at least for
now).

~Moving on to Ganymede1 (vector manipulation and processing/initial
algorithm/construction of HTML from real data).~

# reaper
Builds useful HTML pages which describe, organize, and provide various metadata about feed files for SIS integrations.

Introduction
--------
Reaper is a lightweight utility which produces well-formatted, human-readable, HTML-rich pages which describe various information about a SIS (Student Information System) integration feed file. A shining point of reaper is that it can produce specialized metadata of a feed file in a nicely organized way which can be used as a means to quickly "proofread" thousands of lines of integration entries preventing failed executions and suggesting incomplete or missing data.

Author
--------
I'm writing reaper as both a challenge to produce a powerful tool and to provide technical support and staff of educational institutions which utilize SIS integrations a meaningful, visual "draft" of their feed before committing changes in a live or production environment.

You can visit my personal online portfolio [here][ghostcat].

[ghostcat]: http://av.x10.bz/

Notes on Code
--------
Reaper is written in C++ using the C++11/C++0x ISO standard with the Code::Blocks IDE and GNU GCC compiler. 

It is written to be as computationally efficient as possible in order to save time and consume less resources when parsing thousands of lines of data from feeds.

The following are bullet points in terms of design and style.

* The majority of code uses a mix of a personal underline/Standard C style and only sometimes reminiscent of the Hungarian Notation style. Variable names will often times describe themselves more in the context of a function or they'll describe their purpose. Class variables are always preceded with ```m_``` for clarity.
* OS-specific code and hacks (like those found in ```util.h```) use a more traditional style like Camel case or Hungarian (e.g., ```windowHandle```, ```pszSomeString```). Reaper is well-documented with traditional code commenting and comes with doxygen-powered documentation for interested learners and/or developers.

### Limitations
* Reaper is currently limited to the use of using ```std::wstring```, ```std::wstringstream```, and ```std::wifstream``` in order to read and push Unicode 8-bit strings into its entries vector. A more portable and less compiler-dependent solution is included in the GCC 5.0+ compiler (C++14) which provides the programmer with the ```std::wstring_convert``` template object and the ```std::codecvt_utf8_utf16``` option which together allow for the same result as the ```std::w...``` method. Reaper will be updated with the improved method when possible. This limitation might not exist with the Visual C++ compiler.

Future Plans
--------
* Reaper's source code might be translated to best compile on a Linux OS
