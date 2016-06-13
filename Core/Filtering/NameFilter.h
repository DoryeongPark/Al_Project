#ifndef NAME_FILTER_H 
#define NAME_FILTER_H

#include "../Base.h"
#include "../Model/Course.h"


namespace project
{
	class NameFilter {
	private:
		std::vector<Course> original_table; //���� �ð�ǥ
		std::vector<std::vector<Course>> tables_copied; //���� �ð�ǥ�� ������ ��
		std::map<std::string, std::vector<std::pair<int, int>>> course_sets; //������ �̸� ���� ���� ������(string : ���� �̸�, key : �й� ����, value : �ش� ���� �ε���)

		std::vector<std::vector<int>> indexes_choosed; //���� ���� ���� : ���õ� �ε��� ��ȣ�� 
		std::vector<std::vector<Course>> tables_filtered; //���͸� �� �ð�ǥ��

		int start_index = 0;

		const int TABLES_COUNT = 130;
		const int VACANT = -1;

	public:
		NameFilter(const std::vector<Course>& vec);
		std::vector<std::vector<Course>>& get_result();
	private:
		void sort_courses(std::vector<std::pair<int, int>>& set);
		void priority_normalization(std::vector<std::pair<int, int>>& set);
		void distribute_course_index(std::vector<std::pair<int, int>>& set);
	};

}
#endif