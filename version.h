#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "22";
	static const char MONTH[] = "06";
	static const char YEAR[] = "2016";
	static const char UBUNTU_VERSION_STYLE[] =  "16.06";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 10;
	static const long BUILD  = 24;
	static const long REVISION  = 186;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 190;
	#define RC_FILEVERSION 1,10,24,186
	#define RC_FILEVERSION_STRING "1, 10, 24, 186\0"
	static const char FULLVERSION_STRING [] = "1.10.24.186";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 14;
	

}
#endif //VERSION_H
