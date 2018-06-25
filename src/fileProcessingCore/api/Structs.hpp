#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <vector>

struct sXYZ
{
	int X;
	int Y;
	int Z;
};

struct sBlockCoord
{
	sXYZ startCoord;
	sXYZ endCoord;
};

struct sBoxInfo
{
   sBoxInfo() {}
   sBlockCoord coord;
   double value;
};
struct sBlocksInfo
{
   int countEmptyBlocks;
   std::vector<sBlockCoord> coordEmptyBlocks;

   int countAnotherTrancalancy;
   std::vector<sBoxInfo> AnotherTrancalancyBoxes;

   int countNQ;
   std::vector<sBoxInfo> NQBoxes;
};

struct sBaseCoord
{
	int countX;
	int countY;
	int countZ;

	std::vector<double> coordX;
	std::vector<double> coordY;
	std::vector<double> coordZ;
};

struct sMainInfo
{
	sBaseCoord          mBaseCoord;
	sBlocksInfo         mBlocksInfo;
	double              mMainTranscalancy;
	std::vector<double> mHeatCoefficient;
	std::vector<double> mHoleHeatCollection;
	int                 mCountFlatNp;
	double              mTemperatureEnvironment;
};

#endif //STRUCTS_HPP
