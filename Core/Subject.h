// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
//
//  File     : Subject.h
//  Updated  : 16/06/10
//  Author
//      �� ���� ( ehdrnr333@naver.com )
//  Note
//      �м���ȣ�� ���� Course�� ���
//
//  Task
//
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
#ifndef SUBJECT_H
#define SUBJECT_H

#include "./Model/Course.h"

namespace project
{

	// - Note
	//      Subject class
	//
	class Subject
	{
	private: // ---- ---- Variable ---- ----
	public: // ---- ---- Default ---- ----
		std::vector<Course> crs_list;
		string          code;

		Subject(Course _c);
	};
} // namespace project
#endif 