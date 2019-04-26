#pragma once


#include "NameCard.h"

// 명함 빌더는 명함의 인수를 쉽게 넣게 하기 위해 만들어진 '간단한' 보조 클래스입니다.
// 따라서 명함을 만들기 위해 인수를 종합하는 것 외에는 어떠한 일도 하지 않습니다.
class NameCardBuilder
{
public:
	NameCardBuilder() = default;
	~NameCardBuilder() = default;

	NameCard GetNameCard();

	void SetName(std::string);
	void SetPosition(std::string);

	void SetCompanyName(std::string );
	void SetCompanyAddress(std::string);
	
	void SetTelNumber(std::string);
	void SetFaxNumber(std::string);
	void SetEmailAddress(std::string);


private:
	std::string name;
	std::string position;

	std::string companyName;
	std::string companyAddress;

	std::string tel;
	std::string fax;
	std::string email;
};