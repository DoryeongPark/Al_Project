#pragma once
#include "../Cpp/Course.hpp"

namespace project
{


	class TestLecture : public ILecTime
	{
		// ���� ����
		// ��, ��, ȭ, ��, ��, ��, ��
		virtual Day day() const override;
		// ���� �ð�:
		// ex) 9�� == 1����
		virtual int start() const override;
		// �� �ð� 
		// ex) 10�� 30�� == 2.5
		virtual int end() const override;

		// �����ð� �� ����.
		// 30�� ������ ���.
		// ex) 90�� ������ ��ȯ�� == 3
		virtual int length() const override;
	};


}