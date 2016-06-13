﻿// ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ==== ====
//
//  File     : CrsTable.hpp
//  Updated  : 16/06/04
//  Author
//      Park Dong-Ha ( luncliff@gmail.com )
//  Note
//      Course Table template class
//
//  Task
//      Comment update, class extension
//
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
#ifndef CRSTABLE_H
#define CRSTABLE_H

#include "./Course.h"

namespace project
{

// - Note :
//      Table of `Course`.
//      the template class can support various Course types.
// - Example
//      CrsTable<NamedCourse> tbl;
template <class Course>
class CrsTable
{
    // Summation of courses' point
    // Course list
public:
    std::deque<Course> crs_list{};
    explicit CrsTable() = default;

    void append(const Course& crs) noexcept(false)
    {
        crs_list.push_back(crs);
    }

    size_t total_point() const noexcept
    {
		size_t sum{0};
		for (const auto& crs : crs_list) {
			sum += crs.point();
		}
        return sum;
    }

    size_t size() const noexcept {
        return crs_list.size();
    }

    auto begin() noexcept {
        return crs_list.begin();
    }

    const auto begin() const noexcept {
        return crs_list.begin();
    }

    auto end() noexcept {
        return crs_list.end();
    }

    const auto end() const noexcept {
        return crs_list.end();
    }

};

template <class Course>
std::ostream& operator <<(std::ostream& out,
                          const CrsTable<Course>& _tbl) noexcept(false)
{
    out << "{ "
        << "\"total_point\" : \"" << _tbl.total_point() << "\", "
        << "\"courses : \"[ \n";
    for(const auto& crs : _tbl){
        out << crs << '\n';
    }
    out << " ] } ";
    return out;
}


}   // namespace project
#endif // CRSTABLE_H