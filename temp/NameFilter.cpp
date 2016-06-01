#include "NameFilter.h"	


NameFilter::NameFilter(const vector<ICourse>& vec)
{
	indexes_choosed.resize(TABLES_COUNT);

	//�ð�ǥ ���� ����(first : index, second : priority)
	for (int i = 0; i < vec.size(); ++i)
		course_sets[vec[i].key()].push_back(
			pair<int, int>(i, vec[i].priority()));
	
	//Priority 20���� ����ȭ
	for (auto set : course_sets) {
		sort_courses(set.second);
		distribute_course_index(set.second);
	}

	//TABLES_COUNT ��ŭ Copy
	for (int i = 0; i < TABLES_COUNT; ++i)
		tables_copied.emplace_back(vec);
}

vector<vector<ICourse>>& NameFilter::get_result()
{
	return tables_filtered;
}

// Insertion sort for priority(Insertion sort)
void NameFilter::sort_courses(
	vector<pair<int, int>>& set)
{
	int j;

	for (int i = 1; i < set.size(); i++) {
		auto in = set[i];
		for (int j = i - 1; (j >= 0) && 
			(in.second >= set[j].second); j--) {
			set[j + 1] = set[j];
		}
		set[j + 1] = in;
	}
}

// Normalization priority is changed to count
void NameFilter::priority_normalization(
	vector<pair<int, int>>& set)
{
	int total = 0;

	for (auto p : set) 
		total =+ p.second;

	for (auto r : set) 
		r.second = round(static_cast<double>
			(TABLES_COUNT) * (static_cast<double>
				(r.second) / total)) ;
	
}

//�����ϴ� �� �ð�ǥ ������ ���Ͽ� 
//���� �ð�ǥ case�� ����ġ�� �°� �й����ش�.
void NameFilter::distribute_course_index(
	vector<pair<int, int>>& set)
{
	for (int i = 0; i < TABLES_COUNT; ++i)
		indexes_choosed[i].emplace_back(VACANT);

	for (auto p : set) {

		auto count = p.second;
		auto interval = TABLES_COUNT / count;
		auto input_index = start_index;

		while(count != 0){

			input_index += interval;
			input_index %= TABLES_COUNT;

			if (indexes_choosed[input_index].at
								(start_index) == VACANT) {
				indexes_choosed[input_index].at
								(start_index) = p.first;
				--count;
			}
			else {
				//�� ������ ã�� �� ���� �� ĭ�� �̵�
				while (!(indexes_choosed[input_index].at
								(start_index) == VACANT)) {
					input_index += 1;
					input_index %= TABLES_COUNT;
				}

				indexes_choosed[input_index].at
								(start_index) = p.first;

				--count;
			}
		}

	}

	++start_index;
}
