// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
//
//  File     : SubTable.h
//  Updated  : 16/06/10
//  Author
//      �� ���� ( ehdrnr333@naver.com )
//  Note
//      Subject ���
//
//  Task
//
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
#ifndef SUBTABLE_H
#define SUBTABLE_H

#include "Subject.h"

namespace project
{

	// - Note
	//      Subject Table class
	//
	class SubTable
	{
	private: // ---- ---- Variable ---- ----
	public: // ---- ---- Default ---- ----
		int          crs_sum;
		std::vector<Subject> sub_list;

		SubTable();
		void addCrs(Course _c);
	};
} // namespace project
#endif 