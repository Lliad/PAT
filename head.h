#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cstddef>//for size_t
#include <iterator>//for begin() and end()
#include <algorithm>

using namespace std;

int Quota[6] = { 2,1,2,2,2,3 };

#if 0
struct Sales_Data {
    std::string bookNo;
    double price = 0.0;
    unsigned int soldNum = 0;
    double reveneu = 0.0;
};

#endif

struct Applicant {
    int id;
    int gradeE = 0, gradeI = 0;
    double finalGrade = 0;

    int rank;

    vector<int> idealSchool;
};

Applicant app0, app1, app2, app3, app4, app5, app6, app7, app8, app9, app10;

struct School {
    int schoolId;
    int stuCnt = 0;
    int quota;//оч╤Н

    vector<int> acceptStu;
};