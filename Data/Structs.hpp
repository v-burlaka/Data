#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <vector>

struct sXYZ
{
	int X;
	int Y;
	int Z;

	sXYZ(int x, int y, int z);
};

sXYZ::sXYZ(int x, int y, int z): X(x) , Y(y), Z(z)
{}

struct sBlockCoord
{
	sXYZ stratCoord;
	sXYZ endCoord;
};

struct sBlocksInfo
{
	int countEmptyBlocks;
	std::vector<sBlockCoord> coordEmptyBlocks;

	int countAnotherTrancalancy;
	std::vector<sBlockCoord> coordAnotherTrancalancy;

	int countNQ;
	double valueNQ;
	std::vector<sBlockCoord> coordNQ;
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