#ifndef CSERIALIZER_HPP
#define CSERIALIZER_HPP

#include <memory>

#include "CCUBDeserializator.hpp"
#include "CCUBSerializator.hpp"

class CSerializator
{
public:
	CSerializator();
	~CSerializator();

	void serialize(const sMainInfo& info, const std::string& URL) const;
	sMainInfo deserialize(const std::string URL) const;
private:
	std::unique_ptr<ISerializator>   mSerializator;
	std::unique_ptr<IDeserializator> mDeserializator;
};

#endif // !CSERIALIZER_HPP
