
#ifndef _TOOLS_
#define _TOOLS_

class Tools {

public:
	//returns the biggest size
	template<class T>
	static T getMajor(const T first, const T second) {
		return first > second ? first : second;
	}

	//returns the biggest size
	template<class T>
	static T getMinor(const T first, const T second) {
		return first < second ? first : second;
	}

	//returns the next power of two
	static int nextPowerOfTwo(const float basis);

};

#endif
