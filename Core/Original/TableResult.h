// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
//
//  File     : TableResult.h
//  Updated  : 16/06/10
//  Author
//      �� ���� ( ehdrnr333@naver.com )
//  Note
//      �ð�ǥ�� �����ϴ� Ŭ����
//
//  Task
//
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
#ifndef TABLERESULT_H
#define TABLERESULT_H

#include "SubTable.h"
#include "Model\CrsTable.hpp"
static constexpr int PERIOD_MAX = 136;
//1~27 28~54 55~81 82~108 109~135
static constexpr int TABLE_MAX = 15;
namespace project
{

	// - Note
	//      �ð�ǥ�� ����� Ŭ����
	//
	class TableResult
	{
	private: // ---- ---- Variable ---- ----
	public: // ---- ---- Default ---- ----
		std::vector<int> execute;
		std::vector<bool> map;
		SubTable calList;
		std::vector<CrsTable<Course>> table_list;

		TableResult(CrsTable<Course> _ctb);
		int get_idx(const int& _i, const int& _w);
		void CreateTableList();
		void CreateTable();
		void ArrInit();
		bool TimeCal(const Course& _course);
		bool OverloadCheck(const CrsTable<Course>& _ctb);
		bool ExecuteMaxCheck();
		void NextExecute();

	};
} // namespace project
#endif 