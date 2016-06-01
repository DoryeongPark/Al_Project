#ifndef NAME_FILTER_H 
#define NAME_FILTER_H

#include "../Cpp/Course.hpp"
#include <string>
#include <map>

using namespace std;
using namespace project;

class NameFilter {
private:
	
	vector<vector<ICourse>> tables_copied; //���� �ð�ǥ�� ������ ��
	map<string, vector<pair<int, int>>> course_sets; //������ �̸� ���� ���� ������(string : ���� �̸�, key : �й� ����, value : �ش� ���� �ε���)

	vector<vector<int>> indexes_choosed; //���� ���� ���� : ���õ� �ε��� ��ȣ�� 
	vector<vector<ICourse>> tables_filtered; //���͸� �� �ð�ǥ��

	int start_index = 0;

	const int TABLES_COUNT = 20;
	const int VACANT = -1;

public:
	NameFilter(const vector<ICourse>& vec);
	vector<vector<ICourse>>& get_result();
private:
	void sort_courses(vector<pair<int, int>>& set);
	void priority_normalization(vector<pair<int, int>>& set);
	void distribute_course_index(vector<pair<int, int>>& set);
};

#endif