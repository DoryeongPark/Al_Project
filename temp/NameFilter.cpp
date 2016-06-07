#include "NameFilter.h"	
using namespace std;

NameFilter::NameFilter(const vector<Course>& vec)
{
	original_table = vec;

	//TABLES_COUNT ��ŭ Copy
	for (int i = 0; i < TABLES_COUNT; ++i)
		tables_copied.emplace_back(vec);

	indexes_choosed.resize(TABLES_COUNT);

	//�ð�ǥ ���� ����(first : index, second : priority)
	for (int i = 0; i < vec.size(); ++i)
		course_sets[vec[i].key()].push_back(
			pair<int, int>(i, vec[i].priority()));
	
	//Priority�� TABLES_COUNT��ŭ ����ȭ
	for (auto& set : course_sets) {
		sort_courses(set.second);
		priority_normalization(set.second);
		distribute_course_index(set.second);
	}
	
}

vector<vector<Course>>& NameFilter::get_result()
{

	//�ε��� ��¿�
	for (auto a : indexes_choosed) {
		for (auto b : a){
			cout << b << " ";
		}
		cout << endl;
	}
	
	
	//�ߺ��� ����
	for (int i = 0; i < indexes_choosed.size(); ++i) {

		for (auto iter = indexes_choosed.begin() + i + 1; 
					iter != indexes_choosed.end(); ++iter ) {
			if (indexes_choosed[i] == (*iter)) {
				indexes_choosed.erase(iter);
				iter = indexes_choosed.begin();
				advance(iter, i + 1);
			}
		}

	}

	tables_filtered.resize(indexes_choosed.size());

	for (int i = 0; i < indexes_choosed.size(); ++i) {

		for (auto a : indexes_choosed[i]) {
			auto&& current_crs = original_table[a];
			tables_filtered[i].emplace_back(current_crs);
		}

	}

	return tables_filtered;
}

// Insertion sort for priority(Insertion sort)
void NameFilter::sort_courses(
	vector<pair<int, int>>& set)
{
	auto j = 0;

	for (int i = 1; i < set.size(); i++) {
		auto in = set[i];
		for (j = i - 1; (j >= 0) && 
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
	int check = 0;

	for (auto& p : set) 
		total += p.second;

	for (auto& r : set) {
		r.second = round(static_cast<double>
			(TABLES_COUNT) * (static_cast<double>
				(r.second) / total));

		check += r.second;
	}

	//����ȭ �������� �� �������� �й谡 ���� �ʾ��� ���
	while (check != TABLES_COUNT) {

		if (check < TABLES_COUNT) {
			++set[0].second;
			++check;
		}
		else {
			--set[0].second;
			--check;
		}
	}
	
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
		auto interval = TABLES_COUNT / 
						count + pow(count, start_index);
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
