#pragma once


#include "NameCard.h"

// ���� ������ ������ �μ��� ���� �ְ� �ϱ� ���� ������� '������' ���� Ŭ�����Դϴ�.
// ���� ������ ����� ���� �μ��� �����ϴ� �� �ܿ��� ��� �ϵ� ���� �ʽ��ϴ�.
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