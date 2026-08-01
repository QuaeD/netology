#ifndef VEHICLE_TESTS_H
#define VEHICLE_TESTS_H

class VehicleTests
{
public:
	static void startAllTests();
private:
	static void testAllTerrainBootsCreate();
	static void testBroomCreate();
	static void testCamelCreate();
	static void testCentaurCreate();
	static void testEagleCreate();
	static void testFastCamelCreate();
	static void testMagicCarpetCreate();

	static void testAllTerrainBootsSetGetFinishTime();
	static void testBroomSetGetFinishTime();
	static void testCamelSetGetFinishTime();
	static void testCentaurSetGetFinishTime();
	static void testEagleSetGetFinishTime();
	static void testFastCamelSetGetFinishTime();
	static void testMagicCarpetSetGetFinishTime();
};

#endif // !VEHICLE_TESTS_H

