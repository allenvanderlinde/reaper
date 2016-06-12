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
Reaper is written in C++ using the C++11 ISO standard with the Code::Blocks IDE and GNU GCC compiler.

It is written to be as computationally efficient as possible in order to save time and consume less resources when parsing thousands of lines of data from feeds.

The following are bullet points in terms of design and style.

* The majority of code uses a mix of a personal underline/Standard C style and only sometimes reminiscent of the Hungarian Notation style. Variable names will often times describe themselves more in the context of a function or they'll describe their purpose. Class variables are always preceded with ```m_``` for clarity.
* OS-specific code and hacks (like those found in ```util.h```) use a more traditional style like Camel case or Hungarian (e.g., ```windowHandle```, ```pszSomeString```). Reaper is well-documented with traditional code commenting and comes with doxygen-powered documentation for interested learners and/or developers.

Future Plans
--------
Reaper's source code might be translated to best compile on a Linux OS if found necessary.
