#include <iostream> //temporary

#include <fstream>

#include "..\api\CCUBDeserializator.hpp"

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
	std::string str = "���������:\n";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"���������� ������� ���������:\" �����������");
	}

	pos += str.length();
	
	bool first  = false;
	bool second = false;
	bool third  = false;

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

	mMainInfo.mBaseCoord.coordX.reserve(mMainInfo.mBaseCoord.countX);
	mMainInfo.mBaseCoord.coordY.reserve(mMainInfo.mBaseCoord.countY);
	mMainInfo.mBaseCoord.coordZ.reserve(mMainInfo.mBaseCoord.countZ);

	str = "X:\n";
	pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"������� ���������� �� ��� X:\" �����������");
	}

	pos += str.length();

	for (int i = 0 ; i <  mMainInfo.mBaseCoord.countX; ++pos, ++i)
	{
		mMainInfo.mBaseCoord.coordX.push_back(writeNumber(pos));
	}

	str = "Y:\n";
	pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"������� ���������� �� ��� Y:\" �����������");
	}

	pos += str.length();

	for (int i = 0; i < mMainInfo.mBaseCoord.countZ; ++pos, ++i)
	{
		mMainInfo.mBaseCoord.coordY.push_back(writeNumber(pos));
	}

	str = "Z:\n";
	pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"������� ���������� �� ��� Z:\" �����������");
	}

	pos += str.length();

	for (int i = 0; i < mMainInfo.mBaseCoord.countZ; ++pos, ++i)
	{
		mMainInfo.mBaseCoord.coordZ.push_back(writeNumber(pos));
	}
	emptyBlocks();
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
	std::cout << "���������� ������� ���������:\n";
	std::cout << "  " << mMainInfo.mBaseCoord.countX << " "
		<< mMainInfo.mBaseCoord.countY << " "
		<< mMainInfo.mBaseCoord.countZ << "\n";

	std::cout.setf(std::ios::showpoint);
	std::cout.precision(3);
	std::cout << "������� ���������� �� ��� X:\n";
	for (int i = 0; i < mMainInfo.mBaseCoord.countX; ++i)
	{
		std::cout << mMainInfo.mBaseCoord.coordX[i] << "\n";
	}

	std::cout << "������� ���������� �� ��� Y:\n";
	for (int i = 0; i < mMainInfo.mBaseCoord.countY; ++i)
	{
		std::cout << mMainInfo.mBaseCoord.coordY[i] << "\n";
	}

	std::cout << "������� ���������� �� ��� Z:\n";
	for (int i = 0; i < mMainInfo.mBaseCoord.countZ; ++i)
	{
		std::cout << mMainInfo.mBaseCoord.coordZ[i] << "\n";
	}

	std::cout << "����� ������ ������ npust:\n";
	std::cout << " " << mMainInfo.mBlocksInfo.countEmptyBlocks;


	std::cout << "\n���������� i-�� ������� �����:\n\n";

	for (int i = 0; i < mMainInfo.mBlocksInfo.countEmptyBlocks; ++i)
	{
		std::cout << "i = " << i << "x1 x2; y1 y2; z1 z2;\n";
		std::cout << " " << mMainInfo.mBlocksInfo.coordEmptyBlocks[i].startCoord.X << " " << mMainInfo.mBlocksInfo.coordEmptyBlocks[i].endCoord.X << " "
			<< mMainInfo.mBlocksInfo.coordEmptyBlocks[i].startCoord.Y << " " << mMainInfo.mBlocksInfo.coordEmptyBlocks[i].endCoord.Y << " "
			<< mMainInfo.mBlocksInfo.coordEmptyBlocks[i].startCoord.Z << " " << mMainInfo.mBlocksInfo.coordEmptyBlocks[i].endCoord.Z << "\n";
	}

	std::cout << "������������� ���������������� E0:\n";
	std::cout << " " << mMainInfo.mMainTranscalancy;

	std::cout << "\n����� ������ � ������ �����������������:\n";
	std::cout << " " << mMainInfo.mBlocksInfo.countAnotherTrancalancy;


	std::cout << "\n���������� i-�� �����:\n\n";

	for (int i = 0; i < mMainInfo.mBlocksInfo.countAnotherTrancalancy; ++i)
	{
		std::cout << "i = " << i << "x1 x2; y1 y2; z1 z2;\n";
		std::cout << " " << mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].startCoord.X << " " << mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].endCoord.X << " "
			<< mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].startCoord.Y << " " << mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].endCoord.Y << " "
			<< mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].startCoord.Z << " " << mMainInfo.mBlocksInfo.coordAnotherTrancalancy[i].endCoord.Z << " "
			<< mMainInfo.mBlocksInfo.valueAnotherTrancalancy[i] << "\n";
	}

	std::cout << "������������ �����������:\n";

	for (int i = 0; i < mMainInfo.mHeatCoefficient.size(); ++i)
	{
		std::cout << mMainInfo.mHeatCoefficient[i] << " ";
	}
	std::cout << "\n";

	std::cout << "������������ ����������� � ����������� ������:\n";

	for (int i = 0; i < mMainInfo.mHoleHeatCollection.size(); ++i)
	{
		std::cout << mMainInfo.mHoleHeatCollection[i] << " ";
	}
	std::cout << "\n";

	std::cout << "����� ������ � ����������� NQ:\n";
	std::cout << mMainInfo.mBlocksInfo.countNQ;


	std::cout << "\n���������� i-�� ������� ��������� � �������� Qv*10E-6:\n\n";

	for (int i = 0; i <  mMainInfo.mBlocksInfo.countNQ; ++i)
	{
		std::cout << "i = " << i << "x1 x2; y1 y2; z1 z2;\n";
		std::cout << " " << mMainInfo.mBlocksInfo.coordNQ[i].startCoord.X << " " << mMainInfo.mBlocksInfo.coordNQ[i].endCoord.X << " "
			<< mMainInfo.mBlocksInfo.coordNQ[i].startCoord.Y << " " << mMainInfo.mBlocksInfo.coordNQ[i].endCoord.Y << " "
			<< mMainInfo.mBlocksInfo.coordNQ[i].startCoord.Z << " " << mMainInfo.mBlocksInfo.coordNQ[i].endCoord.Z << " "
			<< mMainInfo.mBlocksInfo.valueNQ[i] << "\n";
	}

	std::cout << "����� ������� ���������� Np1:\n";
	std::cout << mMainInfo.mCountFlatNp;

	std::cout << "\n����������� �����:\n";
	std::cout << mMainInfo.mTemperatureEnvironment;
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
	std::string str = "npust:\n";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"����� ������ ������ npust:\" �����������");
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

	str = "�����:\n";
	pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"���������� i-�� ������� �����:\" �����������");
	}

	pos += str.length();

	toNextString(pos);
	toNextString(pos);
	++pos;

	for (int i = 0; i < mMainInfo.mBlocksInfo.countEmptyBlocks; ++pos, ++i)
	{
		fillEmptyBlocks(mMainInfo.mBlocksInfo.coordEmptyBlocks, pos);
		toNextString(pos);
	}
}

void CCUBDeserializator::fillEmptyBlocks(std::vector<sBlockCoord>& vector, int& index)
{
	sBlockCoord coord;
	coord.startCoord.X = static_cast<int>(writeNumber(index));
	++index;
	coord.endCoord.X   = static_cast<int>(writeNumber(index));
	++index;
	coord.startCoord.Y = static_cast<int>(writeNumber(index));
	++index;
	coord.endCoord.Y   = static_cast<int>(writeNumber(index));
	++index;
	coord.startCoord.Z = static_cast<int>(writeNumber(index));
	++index;
	coord.endCoord.Z   = static_cast<int>(writeNumber(index));
	++index;

	vector.push_back(coord);
}

void CCUBDeserializator::mainTranscalancy()
{
	std::string str = "E0:\n";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"������������� ���������������� E0:\" �����������");
	}

	pos += str.length();
	++pos;

	mMainInfo.mMainTranscalancy = writeNumber(pos);
}

void CCUBDeserializator::anotherTranscalancy()
{
	std::string str = "�����������������:\n";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"����� ������ � ������ �����������������:\" �����������");
	}

	pos += str.length();
	++pos;

	mMainInfo.mBlocksInfo.countAnotherTrancalancy = writeNumber(pos);

	toNextString(pos);
	toNextString(pos);
	toNextString(pos);
	toNextString(pos);
	++pos;

	for (int i = 0; i < mMainInfo.mBlocksInfo.countAnotherTrancalancy; ++pos, ++i)
	{
		fillEmptyBlocks(mMainInfo.mBlocksInfo.coordAnotherTrancalancy, pos);
		mMainInfo.mBlocksInfo.valueAnotherTrancalancy.push_back(writeNumber(pos));
		toNextString(pos);
		toNextString(pos);
	}
}

void CCUBDeserializator::heatCoefficient()
{
	std::string str = "�����������:\n";
	int pos = mBuffer.find(str);	
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"������������ �����������:\" �����������");
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
	std::string str = "������:\n";
	int pos = mBuffer.find(str);	
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"������������ ����������� � ����������� ������:\" �����������");
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
	std::string str = "NQ:\n";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"����� ������ � ����������� NQ:\" �����������");
	}

	pos += str.length();

	mMainInfo.mBlocksInfo.countNQ = writeNumber(pos);

	toNextString(pos);
	toNextString(pos);
	toNextString(pos);
	toNextString(pos);
	++pos;

	for (int i = 0; i < mMainInfo.mBlocksInfo.countAnotherTrancalancy; ++pos, ++i)
	{
		fillEmptyBlocks(mMainInfo.mBlocksInfo.coordNQ, pos);
		mMainInfo.mBlocksInfo.valueNQ.push_back(writeNumber(pos));
		toNextString(pos);
		toNextString(pos);
	}

}

void CCUBDeserializator::flatNp()
{
	std::string str = "Np1:\n";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"����� ������� ���������� Np1:\" �����������");
	}
	
	pos += str.length();

	mMainInfo.mCountFlatNp = writeNumber(pos);

	temperature();
}

void CCUBDeserializator::temperature()
{
	std::string str = "�����:\n";
	int pos = mBuffer.find(str);
	if (nConstants::STRING_IS_ABSENT == pos)
	{
		throw exceptions::InvalidPathOrFile("������ \"����������� �����:\" �����������");
	}

	pos += str.length();

	mMainInfo.mTemperatureEnvironment = writeNumber(pos);

	//debug();
}
