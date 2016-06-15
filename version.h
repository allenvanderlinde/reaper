#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "15";
	static const char MONTH[] = "06";
	static const char YEAR[] = "2016";
	static const char UBUNTU_VERSION_STYLE[] =  "16.06";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 10;
	static const long BUILD  = 14;
	static const long REVISION  = 126;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 37;
	#define RC_FILEVERSION 1,10,14,126
	#define RC_FILEVERSION_STRING "1, 10, 14, 126\0"
	static const char FULLVERSION_STRING [] = "1.10.14.126";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 4;
	

}
#endif //VERSION_H