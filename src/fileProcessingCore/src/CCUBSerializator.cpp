#include <fstream>

#include "../api/CCUBSerializator.hpp"

CCUBSerializator::CCUBSerializator()
{
}

CCUBSerializator::~CCUBSerializator()
{
}

void CCUBSerializator::setURL(const std::string & URL)
{
	mURL = URL;
}

void CCUBSerializator::baseCoord(const sBaseCoord & info) const
{
	std::ofstream file(mURL, std::ios_base::app);
	
	if (true == file.is_open())
	{
		file << "Количество базовых координат:\n";
		file << info.countX << " "
			<< info.countY << " "
			<< info.countZ << "\n";

		file << "Базовые координаты по оси X:\n";
		for (int i = 0; i < info.coordX.size(); ++i)
		{
			file << info.coordX[i] << "\n";
		}

		file << "Базовые координаты по оси Y:\n";
		for (int i = 0; i < info.coordX.size(); ++i)
		{
			file << info.coordY[i] << "\n";
		}

		file << "Базовые координаты по оси Z:\n";
		for (int i = 0; i < info.coordX.size(); ++i)
		{
			file << info.coordZ[i] << "\n";
		}
	}

	file.close();
}

void CCUBSerializator::emptyBlocks(const std::vector<sBlockCoord> info) const
{
	std::ofstream file(mURL, std::ios_base::app);
	
	if (true == file.is_open())
	{
		file << "Число пустых блоков npust:\n";
		file << info.size();


		file << "Координаты i-го пустого блока:\n\n";
		
		for (int i = 0; i < info.size(); ++i)
		{
			file << "i = " << i << "x1 x2; y1 y2; z1 z2;\n";
         file << " " << info[i].startCoord.X << " " << info[i].endCoord.X << " "
                     << info[i].startCoord.Y << " " << info[i].endCoord.Y << " "
                     << info[i].startCoord.Z << " " << info[i].endCoord.Z << "\n";
		}
	}

	file.close();
}

void CCUBSerializator::mainTranscalancy(const double & transcalancy) const
{
	std::ofstream file(mURL, std::ios_base::app);
	
	if (true == file.is_open())
	{
		file << "Преобладающая теплопроводность E0:\n";
		file << " " << transcalancy;
	}

	file.close();
}

void CCUBSerializator::anotherTranscalancy(const std::vector<sBlockCoord>& info) const
{
	std::ofstream file(mURL, std::ios_base::app);

	if (true == file.is_open())
	{
		file << "Число блоков с другой теплопроводностью:\n";
		file << info.size();


		file << "Координаты i-го блока:\n\n";

		for (int i = 0; i < info.size(); ++i)
		{
			file << "i = " << i << "x1 x2; y1 y2; z1 z2;\n";
         file << " " << info[i].startCoord.X << " " << info[i].endCoord.X << " "
              << info[i].startCoord.Y << " " << info[i].endCoord.Y << " "
              << info[i].startCoord.Z << " " << info[i].endCoord.Z << "\n";
		}
	}

	file.close();
}

void CCUBSerializator::heatCoefficient(const std::vector<double>& coefficients) const
{
	std::ofstream file(mURL, std::ios_base::app);

	if (true == file.is_open())
	{
		file << "Коэффицикеты теплоотдачи:\n";		
		
		for (int i = 0; i < coefficients.size(); ++i)
		{
			file << coefficients[i] << "\n";
		}
	}

	file.close();
}

void CCUBSerializator::holeHeatCoefficient(const std::vector<double>& coefficients) const
{
	std::ofstream file(mURL, std::ios_base::app);

	if (true == file.is_open())
	{
		file << "Коэффицикеты теплоотдачи с поверхности выемок:\n";

		for (int i = 0; i < coefficients.size(); ++i)
		{
			file << coefficients[i] << "\n";
		}
	}

	file.close();
}

void CCUBSerializator::coordNQ(const std::vector<sBlockCoord>& info, const std::vector<double>& NQ) const
{
	std::ofstream file(mURL, std::ios_base::app);

	if (true == file.is_open())
	{
		file << "Число блоков с источниками NQ:\n";
		file << info.size();


		file << "Координаты i-го пустого источника и велечина Qv*10E-6:\n\n";

		for (int i = 0; i < info.size(); ++i)
      {
         file << "i = " << i << "x1 x2; y1 y2; z1 z2;\n";
         file << " " << info[i].startCoord.X << " " << info[i].endCoord.X << " "
              << info[i].startCoord.Y << " " << info[i].endCoord.Y << " "
              << info[i].startCoord.Z << " " << info[i].endCoord.Z << " "
              << NQ[i] << "\n";
		}
	}

	file.close();
}

void CCUBSerializator::flatNp(const int count) const
{
	std::ofstream file(mURL, std::ios_base::app);

	if (true == file.is_open())
	{
		file << "Число плоских источников Np1:\n";
		file << count;
	}

	file.close();
}

void CCUBSerializator::temperature(const int temp) const
{
	std::ofstream file(mURL, std::ios_base::app);

	if (true == file.is_open())
	{
		file << "Температура среды:\n";
		file << temp;
	}

	file.close();
}
