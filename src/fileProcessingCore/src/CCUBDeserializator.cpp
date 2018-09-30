#include <iostream> //temporary

#include <fstream>

#include "../api/CCUBDeserializator.hpp"

CCUBDeserializator::CCUBDeserializator()
{
}

CCUBDeserializator::~CCUBDeserializator()
{
}

sMainInfo CCUBDeserializator::execute()
{

	baseCoord();
	emptyBlocks();
	mainTranscalancy();
	anotherTranscalancy();
	heatCoefficient();
	holeHeatCoefficient();
	coordNQ();
	flatNp();
	temperature();


	return mMainInfo;
}

void CCUBDeserializator::setURL(const std::string & URL)
{
	mURL = URL;

	writeBuffer();
}


void CCUBDeserializator::writeBuffer()
{
	std::ifstream file(mURL);
	char c;

	while (false == file.eof())
	{
		file.get(c);
		mBuffer.push_back(c);
	}

	file.close();
}

void CCUBDeserializator::baseCoord()
{
	std::string str = "координат:\n";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Количество базовых координат:\" отсутствует");
	}

	pos += str.length();

	bool first = false;
	bool second = false;
	bool third = false;

	for (; mBuffer[pos] != nSymbols::END_LINE; ++pos)
	{
		if (false != isdigit(mBuffer[pos]))
		{
			if (false == first)
			{
				mMainInfo.mBaseCoord.countX = static_cast<int>(writeNumber(pos));
				first = true;
			}
			else if (false == second)
			{
				mMainInfo.mBaseCoord.countY = static_cast<int>(writeNumber(pos));
				second = true;
			}
			else if (false == third)
			{
				mMainInfo.mBaseCoord.countZ = static_cast<int>(writeNumber(pos));
				third = true;
				break;
			}
		}
	}

	mMainInfo.mBaseCoord.coordX.reserve(mMainInfo.mBaseCoord.countX + 1);
	mMainInfo.mBaseCoord.coordY.reserve(mMainInfo.mBaseCoord.countY + 1);
	mMainInfo.mBaseCoord.coordZ.reserve(mMainInfo.mBaseCoord.countZ + 1);

	str = "X:\n ";
	pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Базовые координаты по оси X:\" отсутствует");
	}

	pos += str.length();

	for (int i = 0; i <= mMainInfo.mBaseCoord.countX; ++pos, ++i)
	{
		if (false != isdigit(mBuffer[pos]))
		{
			std::cout << "pus_back for X\n";
			mMainInfo.mBaseCoord.coordX.push_back(writeNumber(pos));
			++pos;//отступ перед следующим числом
		}
	}

	str = "Y:\n ";
	pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Базовые координаты по оси Y:\" отсутствует");
	}

	pos += str.length();

	for (int i = 0; i <= mMainInfo.mBaseCoord.countY; ++pos, ++i)
	{
		if (false != isdigit(mBuffer[pos]))
		{
			mMainInfo.mBaseCoord.coordY.push_back(writeNumber(pos));
			++pos;
		}
	}

	str = "Z:\n ";
	pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Базовые координаты по оси Z:\" отсутствует");
	}

	pos += str.length();

	for (int i = 0; i <= mMainInfo.mBaseCoord.countZ; ++pos, ++i)
	{
		if (false != isdigit(mBuffer[pos]))
		{
			mMainInfo.mBaseCoord.coordZ.push_back(writeNumber(pos));
			++pos;
		}
	}
}

double CCUBDeserializator::writeNumber(int& index) const
{
	char number[25];

	for (int i = 0; (nSymbols::SPACE != mBuffer[index] && index < mBuffer.length()); ++index, ++i)
	{
		if (nSymbols::END_LINE == mBuffer[index])
		{
			break;
		}
		number[i] = mBuffer[index];
	}

	return atof(number);
}

void CCUBDeserializator::debug()
{
	std::cout << "debug\n";
	setlocale(0, "");
	std::cout << "Количество базовых координат:\n";
	std::cout << "  " << mMainInfo.mBaseCoord.countX << " "
		<< mMainInfo.mBaseCoord.countY << " "
		<< mMainInfo.mBaseCoord.countZ << "\n";

	std::cout.setf(std::ios::showpoint);
	std::cout.precision(3);
	std::cout << "Базовые координаты по оси X:\n";
	for (int i = 0; i < mMainInfo.mBaseCoord.coordX.size(); ++i)
	{
		std::cout << mMainInfo.mBaseCoord.coordX[i] << "\n";
	}

	std::cout << "Базовые координаты по оси Y:\n";
	for (int i = 0; i < mMainInfo.mBaseCoord.coordY.size(); ++i)
	{
		std::cout << mMainInfo.mBaseCoord.coordY[i] << "\n";
	}

	std::cout << "Базовые координаты по оси Z:\n";
	for (int i = 0; i < mMainInfo.mBaseCoord.coordZ.size(); ++i)
	{
		std::cout << mMainInfo.mBaseCoord.coordZ[i] << "\n";
	}

//	std::cout << "Число пустых блоков npust:\n";
//	std::cout << " " << mMainInfo.mBlocksInfo.countEmptyBlocks;
//
//
//	std::cout << "\nКоординаты i-го пустого блока:\n\n";
//
//	for (int i = 0; i < mMainInfo.mBlocksInfo.countEmptyBlocks; ++i)
//	{
//		std::cout << "i = " << i << "x1 x2; y1 y2; z1 z2;\n";
//		std::cout << " " << mMainInfo.mBlocksInfo.coordEmptyBlocks[i].startCoord.X << " " << mMainInfo.mBlocksInfo.coordEmptyBlocks[i].endCoord.X << " "
//			<< mMainInfo.mBlocksInfo.coordEmptyBlocks[i].startCoord.Y << " " << mMainInfo.mBlocksInfo.coordEmptyBlocks[i].endCoord.Y << " "
//			<< mMainInfo.mBlocksInfo.coordEmptyBlocks[i].startCoord.Z << " " << mMainInfo.mBlocksInfo.coordEmptyBlocks[i].endCoord.Z << "\n";
//	}
//
//	std::cout << "Преобладающая теплопроводность E0:\n";
//	std::cout << " " << mMainInfo.mMainTranscalancy;
//
//	std::cout << "\nЧисло блоков с другой теплопроводностью:\n";
//	std::cout << " " << mMainInfo.mBlocksInfo.countAnotherTrancalancy;
//
//
//	std::cout << "\nКоординаты i-го блока:\n\n";
//	/*
//	for (int i = 0; i < mMainInfo.mBlocksInfo.countAnotherTrancalancy; ++i)
//	{
//	std::cout << "i = " << i << "x1 x2; y1 y2; z1 z2;\n";
//	std::cout << " " << mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].startCoord.X << " " << mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].endCoord.X << " "
//	<< mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].startCoord.Y << " " << mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].endCoord.Y << " "
//	<< mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].startCoord.Z << " " << mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].endCoord.Z << " "
//	<< mMainInfo.mBlocksInfo.valueAnotherTrancalancy[i] << "\n";
//	}
//	*/
//	std::cout << "Коэффицикеты теплоотдачи:\n";
//
//	for (int i = 0; i < mMainInfo.mHeatCoefficient.size(); ++i)
//	{
//		std::cout << mMainInfo.mHeatCoefficient[i] << " ";
//	}
//	std::cout << "\n";
//
//	std::cout << "Коэффицикеты теплоотдачи с поверхности выемок:\n";
//
//	for (int i = 0; i < mMainInfo.mHoleHeatCollection.size(); ++i)
//	{
//		std::cout << mMainInfo.mHoleHeatCollection[i] << " ";
//	}
//	std::cout << "\n";
//
//	std::cout << "Число блоков с источниками NQ:\n";
//	std::cout << mMainInfo.mBlocksInfo.countNQ;
//
//
//	std::cout << "\nКоординаты i-го пустого источника и велечина Qv*10E-6:\n\n";
//	/*
//	for (int i = 0; i <  mMainInfo.mBlocksInfo.countNQ; ++i)
//	{
//	std::cout << "i = " << i << "x1 x2; y1 y2; z1 z2;\n";
//	std::cout << " " << mMainInfo.mBlocksInfo.coordNQ[i].startCoord.X << " " << mMainInfo.mBlocksInfo.coordNQ[i].endCoord.X << " "
//	<< mMainInfo.mBlocksInfo.coordNQ[i].startCoord.Y << " " << mMainInfo.mBlocksInfo.coordNQ[i].endCoord.Y << " "
//	<< mMainInfo.mBlocksInfo.coordNQ[i].startCoord.Z << " " << mMainInfo.mBlocksInfo.coordNQ[i].endCoord.Z << " "
//	<< mMainInfo.mBlocksInfo.valueNQ[i] << "\n";
//	}
//	*/
//	std::cout << "Число плоских источников Np1:\n";
//	std::cout << mMainInfo.mCountFlatNp;
//
//	std::cout << "\nТемпература среды:\n";
//	std::cout << mMainInfo.mTemperatureEnvironment;
}

void CCUBDeserializator::toNextString(int& index)
{
	while (nSymbols::END_LINE != mBuffer[index])
	{
		++index;
	}
	++index;
}

void CCUBDeserializator::toNextDigit(int & index)
{
	while (false != isdigit(mBuffer[index]))
	{
		++index;
	}
}

void CCUBDeserializator::emptyBlocks()
{
	std::string str = "npust:\n ";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Число пустых блоков npust:\" отсутствует");
	}

	pos += str.length();

	for (; mBuffer[pos] != nSymbols::END_LINE; ++pos)
	{
		if (false != isdigit(mBuffer[pos]))
		{
			mMainInfo.mBlocksInfo.countEmptyBlocks = writeNumber(pos);
			break;
		}
	}
	mMainInfo.mBlocksInfo.coordEmptyBlocks.reserve(mMainInfo.mBlocksInfo.countEmptyBlocks);

	str = "блока:\n";
	pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Координаты i-го пустого блока:\" отсутствует");
	}

	pos += str.length();

	toNextString(pos);
	toNextString(pos);
	++pos;
	++pos;

	for (int i = 0; i < mMainInfo.mBlocksInfo.countEmptyBlocks; ++pos, ++i)
	{
		fillEmptyBlocks(mMainInfo.mBlocksInfo.coordEmptyBlocks, pos);
		toNextString(pos);
		++pos;
	}
}

void CCUBDeserializator::fillEmptyBlocks(std::vector<sBlockCoord>& vector, int& index)
{
	sBlockCoord coord;
	coord.startCoord.X = static_cast<int>(writeNumber(index));
	++index;
	coord.endCoord.X = static_cast<int>(writeNumber(index));
	++index;
	coord.startCoord.Y = static_cast<int>(writeNumber(index));
	++index;
	coord.endCoord.Y = static_cast<int>(writeNumber(index));
	++index;
	coord.startCoord.Z = static_cast<int>(writeNumber(index));
	++index;
	coord.endCoord.Z = static_cast<int>(writeNumber(index));
	++index;

	vector.push_back(coord);
}

void CCUBDeserializator::fillEmptyBoxes(std::vector<sBoxInfo>& vector, int &index)
{
	sBoxInfo box;
	box.coord.startCoord.X = static_cast<int>(writeNumber(index));
	++index;
	box.coord.endCoord.X = static_cast<int>(writeNumber(index));
	++index;
	box.coord.startCoord.Y = static_cast<int>(writeNumber(index));
	++index;
	box.coord.endCoord.Y = static_cast<int>(writeNumber(index));
	++index;
	box.coord.startCoord.Z = static_cast<int>(writeNumber(index));
	++index;
	box.coord.endCoord.Z = static_cast<int>(writeNumber(index));
	++index;

	box.value = static_cast<int>(writeNumber(index));

	vector.push_back(box);
}

void CCUBDeserializator::mainTranscalancy()
{
	std::string str = "E0:\n ";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Преобладающая теплопроводность E0:\" отсутствует");
	}

	pos += str.length();
	++pos;

	mMainInfo.mMainTranscalancy = writeNumber(pos);
}

void CCUBDeserializator::anotherTranscalancy()
{
	std::string str = "теплопроводностью:\n ";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Число блоков с другой теплопроводностью:\" отсутствует");
	}

	pos += str.length();
	++pos;

	mMainInfo.mBlocksInfo.countAnotherTrancalancy = writeNumber(pos);

	toNextString(pos);
	toNextString(pos);
	toNextString(pos);
	toNextString(pos);
	++pos;
	++pos;

	for (int i = 0; i < mMainInfo.mBlocksInfo.countAnotherTrancalancy; ++pos, ++i)
	{
		fillEmptyBoxes(mMainInfo.mBlocksInfo.AnotherTrancalancyBoxes, pos);
		//mMainInfo.mBlocksInfo.valueAnotherTrancalancy.push_back(writeNumber(pos));
		toNextString(pos);
		toNextString(pos);
		++pos;
	}
}

void CCUBDeserializator::heatCoefficient()
{
	std::string str = "теплоотдачи:\n ";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Коэффицикеты теплоотдачи:\" отсутствует");
	}

	pos += str.length();

	for (int i = 0; i < nConstants::NUMBER_FACES; ++i)
	{
		mMainInfo.mHeatCoefficient.push_back(writeNumber(pos));
		++pos;
	}
}

void CCUBDeserializator::holeHeatCoefficient()
{
	std::string str = "выемок:\n ";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Коэффицикеты теплоотдачи с поверхности выемок:\" отсутствует");
	}

	pos += str.length();

	for (int i = 0; i < nConstants::NUMBER_FACES; ++i)
	{
		mMainInfo.mHoleHeatCollection.push_back(writeNumber(pos));
		++pos;
	}
}

void CCUBDeserializator::coordNQ()
{
	std::string str = "NQ:\n ";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Число блоков с источниками NQ:\" отсутствует");
	}

	pos += str.length();

	mMainInfo.mBlocksInfo.countNQ = writeNumber(pos);

	toNextString(pos);
	toNextString(pos);
	toNextString(pos);
	toNextString(pos);
	++pos;
	++pos;

	for (int i = 0; i < mMainInfo.mBlocksInfo.countNQ; ++pos, ++i)
	{
		fillEmptyBoxes(mMainInfo.mBlocksInfo.NQBoxes, pos);
		//mMainInfo.mBlocksInfo.valueNQ.push_back(writeNumber(pos));
		toNextString(pos);
		toNextString(pos);
		++pos;
	}

}

void CCUBDeserializator::flatNp()
{
	std::string str = "Np1:\n ";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Число плоских источников Np1:\" отсутствует");
	}

	pos += str.length();

	mMainInfo.mCountFlatNp = writeNumber(pos);

	temperature();
}

void CCUBDeserializator::temperature()
{
	std::string str = "среды:\n ";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("Строка \"Температура среды:\" отсутствует");
	}

	pos += str.length();

	mMainInfo.mTemperatureEnvironment = writeNumber(pos);

	//debug();
}
