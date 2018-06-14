//#include <fstream>
#include <iostream>

#include "CCUBSErializator.hpp"
#include "CCUBDeserializator.hpp"
#include "CSerializer.hpp"

int main()
{
	CCUBSerializator serializator;
	CCUBDeserializator deserializator;
	sMainInfo info;
	sBlockCoord coord;
	CSerializator serializer;


	coord.startCoord.X = 0;
	coord.startCoord.Y = 0;
	coord.startCoord.Z = 0;
	coord.endCoord.X = 1;
	coord.endCoord.Y = 1;
	coord.endCoord.Z = 1;

	info.mBaseCoord.countX = 5;
	info.mBaseCoord.countY = 5;
	info.mBaseCoord.countZ = 5;

	for (int i = 0; i < 5; ++i)
	{
		info.mBaseCoord.coordX.push_back(5.0);
		info.mBaseCoord.coordY.push_back(i);
		info.mBaseCoord.coordZ.push_back(i);
	}

	info.mBlocksInfo.countEmptyBlocks = 2;
	info.mBlocksInfo.countAnotherTrancalancy = 2;
	info.mBlocksInfo.countNQ = 2;

	for (int i = 0; i < 2; ++i)
	{
		info.mBlocksInfo.coordEmptyBlocks.push_back(coord);
		info.mBlocksInfo.valueAnotherTrancalancy.push_back(25.6);
		info.mBlocksInfo.coordAnotherTrancalancy.push_back(coord);
		info.mBlocksInfo.coordNQ.push_back(coord);
		info.mBlocksInfo.valueNQ.push_back(221.5);
	}
	
	info.mMainTranscalancy = 3.5;

	for (int i = 0; i < 6; ++i)
	{
		info.mHeatCoefficient.push_back(0.5 + i);
		info.mHoleHeatCollection.push_back(0.5 + i);
	}

	info.mCountFlatNp = 4;

	info.mTemperatureEnvironment = 36.6;

	//serializator.setURL();
	//serializator.baseCoord(info.mBaseCoord);
	//serializator.emptyBlocks(info.mBlocksInfo.coordEmptyBlocks);
	//serializator.mainTranscalancy(info.mMainTranscalancy);
	//serializator.anotherTranscalancy(info.mBlocksInfo.coordAnotherTrancalancy, info.mBlocksInfo.valueAnotherTrancalancy);
	//serializator.heatCoefficient(info.mHeatCoefficient);
	//serializator.holeHeatCoefficient(info.mHoleHeatCollection);
	//serializator.coordNQ(info.mBlocksInfo.coordNQ, info.mBlocksInfo.valueNQ);
	//serializator.flatNp(info.mCountFlatNp);
	//serializator.temperature(info.mTemperatureEnvironment);

	//serializer.serialize(info, "file.txt");
	try
	{
		serializer.deserialize("file.txt");
	}
	catch(exceptions::InvalidPathOrFile& invalid)
	{
		std::cout << invalid.getException();
	}

	//deserializator.setURL();
	std::cout << "END";
	system("pause");
	return 0;
}