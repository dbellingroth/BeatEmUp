





class Tools {

	//returns the biggest size
	template <class T>
	static T getMajor( const T first, const T second ) { return first > second ? first : second; }

	//returns the biggest size
	template <class T>
	static T getMinor( const T first, const T second ) { return first < second ? first : second; }

	//returns the next power of two
	static int nextPowerOfTwo( const float basis );


	static Vec2 convertVectorPhys2Pix(Vec2 vector) {

		return new Vec2(vector.x * PhysicsWorld.pixelsPerMeter, vector.y
				* PhysicsWorld.pixelsPerMeter);
	}

	static Vec2 convertVectorPix2Phys(Vec2 vector) {

		return new Vec2(vector.x / PhysicsWorld.pixelsPerMeter, vector.y
				/ PhysicsWorld.pixelsPerMeter);
	}
	


};