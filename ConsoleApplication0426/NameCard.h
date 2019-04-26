#pragma once

#include "pch.h"

#include <string>
#include <vector>


// BSGJ: �� ������ ������������
//
// ���Ǽ����� ���Կ� �°� ����� ������ �ȵǰ�,
// �׸��� ������ ������ �� �ִ� ��ġ(����)�� �����,
// ��������� ��� �����Ϸ� �մϴ�.



class NameCard
{
public:
	// �⺻ �����ڴ� ������� ������, ���� �Ҵ��� �Ͼ�� �ʱ⿡ �Ҹ��ڴ� �⺻���� ����� �� �ֽ��ϴ�.
	NameCard() = delete;
	~NameCard() = default;

	// �����ÿ��� ��� ��� ������ �����Ǿ�� �մϴ�.
	// �׷��� ��� ����� ������ ���Ѿ� �ϴ� ���� ����ڿ��� ������ �� �ֽ��ϴ�. �̸� ������ �����մϴ�.
	NameCard(std::string name, std::string position, std::string companyName, std::string companyAddress,
		std::string tel, std::string fax, std::string email);

	// ����ִ� �������� ���� ���� std::cout ��ü�� �̿��� ���������� ����մϴ�.
	void Print() const;

	

	// Getter���Դϴ�. ���� ��� �̰��� �����Ű��, 
	// Setter�� �������� �ʴ� ������
	// �� �������� �б�����ó�� ����� �� �ֽ��ϴ�.
	std::string GetName() const;
	std::string GetPosition() const;

	std::string GetCompanyName() const;
	std::string GetCompanyAddress() const;

	std::string GetTelNumber() const;
	std::string GetFaxNumber() const;
	std::string GetEmail() const;




private:
	// �� ������ �̸�, ��ȭ��ȣ, �̸���, �ѽ���ȣ, �ּ�, ȸ���, ������ �������� �մϴ�.
	std::string name;
	std::string position;

	std::string companyName;
	std::string companyAddress;
	
	std::string tel;
	std::string fax;
	std::string email;
};
