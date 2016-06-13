#pragma once
#include "../Cpp/Course.hpp"
namespace project
{
	struct ITimeTable
	{
		virtual int sum() const abstract;   // ���� ����
		virtual
			std::vector <project::ICourse>& courses() const abstract;
	};
	bool write_table(std::ofstream& _out, const ITimeTable& _table)
		noexcept(false);
	struct ITableList
	{
		virtual int max() const abstract;   // �ð�ǥ �ִ�
		virtual 
			std::vector<ITimeTable>& tables() const abstract;
	};
	bool write_tList(std::ofstream& _out, const ITableList& _tList)
		noexcept(false);
}