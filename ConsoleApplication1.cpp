// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdexcept>//for runtime_error

#include "head.h"

#define appNum 11
#define schoolNum 6
#define choiceNum 3

using namespace std;

extern Applicant app0;
extern Applicant app1;
extern Applicant app2;
extern Applicant app3;
extern Applicant app4;
extern Applicant app5;
extern Applicant app6;
extern Applicant app7;
extern Applicant app8;
extern Applicant app9;
extern Applicant app10;

extern int Quota[6];

int fact(int val);
void changePtr(int* v1, int* v2);
void initSchool(vector<School> &school);
void initStu(vector<Applicant> &stu);
void adjRank(vector<Applicant>& stu);
void giveRank(vector<Applicant>& stu);
void sortOrder(vector<School>& school);
void printRes(vector<School>& school);

void findSchool(vector<School>& school, vector<Applicant>& stu);

bool compare1(Applicant app1, Applicant app2);
bool compare2(int val1, int val2);

int main()
{
#if 0
    int stopNum = 0;

    cout << "Enter a num: ";
    cin >> stopNum;
    cout << fact(stopNum) << endl;

    int v1 = 10, v2 = 100;
    changePtr(&v1, &v2);
    cout << v1 << " " << v2;
#endif


    //int appNum = 11;
    //int schoolNum, choiceNum;
#if 0
/*
    cout << "please input the total number of applicants: ";
    cin >> appNum;

    cout << "\nplease input the total number of graduate schools: ";
    cin >> schoolNum;

    cout << "\nplease input the number of choices an applicant may have: ";
    cin >> choiceNum;
*/
#endif
    vector<School> school(schoolNum);
    initSchool(school);

    vector<Applicant> stu;
    initStu(stu);
    sort(stu.begin(), stu.end(), compare1);
    giveRank(stu);
    adjRank(stu);

    findSchool(school, stu);
    sortOrder(school);
    
    printRes(school);

    return 0;
}

int fact(int val)
{
    int res = 1;
    for (int i = 1; i <= val; ++i)
    {
        res *= i;
    }

    return res;
}

void changePtr(int* v1, int* v2)
{
    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;
    
}

void initSchool(vector<School>& school)
{
    for (int i = 0; i != school.size(); ++i)
    {
        school[i].schoolId = i;
        school[i].quota = Quota[i];
    }
}

void initStu(vector<Applicant>& stu)
{
    app0.id = 0;
    app0.gradeE = 100;
    app0.gradeI = 100;
    app0.finalGrade = (app0.gradeE + app0.gradeI) / 2;
    app0.idealSchool = { 0,1,2 };
    
    app1.id = 1;
    app1.gradeE = 60;
    app1.gradeI = 60;
    app1.finalGrade = (app1.gradeE + app1.gradeI) / 2;
    app1.idealSchool = { 2,3,5 };

    app2.id = 2;
    app2.gradeE = 100;
    app2.gradeI = 90;
    app2.finalGrade = (app2.gradeE + app2.gradeI) / 2;
    app2.idealSchool = { 0,3,4 };

    app3.id = 3; 
    app3.gradeE = 90;
    app3.gradeI = 100;
    app3.finalGrade = (app3.gradeE + app3.gradeI) / 2;
    app3.idealSchool = { 1,0,2 };

    app4.id = 4;
    app4.gradeE = 90;
    app4.gradeI = 90;
    app4.finalGrade = (app4.gradeE + app4.gradeI) / 2;
    app4.idealSchool = { 5,1,3 };

    app5.id = 5;
    app5.gradeE = 80;
    app5.gradeI = 90;
    app5.finalGrade = (app5.gradeE + app5.gradeI) / 2;
    app5.idealSchool = { 1,0,2 };

    app6.id = 6;
    app6.gradeE = 80;
    app6.gradeI = 80;
    app6.finalGrade = (app6.gradeE + app6.gradeI) / 2;
    app6.idealSchool = { 1,0,2 };

    app7.id = 7;
    app7.gradeE = 80;
    app7.gradeI = 80;
    app7.finalGrade = (app7.gradeE + app7.gradeI) / 2;
    app7.idealSchool = { 0,1,2 };

    app8.id = 8;
    app8.gradeE = 80;
    app8.gradeI = 70;
    app8.finalGrade = (app8.gradeE + app8.gradeI) / 2;
    app8.idealSchool = { 1,3,2 };

    app9.id = 9;
    app9.gradeE = 70;
    app9.gradeI = 80;
    app9.finalGrade = (app9.gradeE + app9.gradeI) / 2;
    app9.idealSchool = { 1,2,3 };

    app10.id = 10;
    app10.gradeE = 100;
    app10.gradeI = 100;
    app10.finalGrade = (app10.gradeE + app10.gradeI) / 2;
    app10.idealSchool = { 0,2,4 };

    stu.push_back(app0);
    stu.push_back(app1);
    stu.push_back(app2);
    stu.push_back(app3);
    stu.push_back(app4);
    stu.push_back(app5);
    stu.push_back(app6);
    stu.push_back(app7);
    stu.push_back(app8);
    stu.push_back(app9);
    stu.push_back(app10);
}

bool compare1(Applicant app1, Applicant app2)
{
    return app1.finalGrade > app2.finalGrade;
}

bool compare2(int val1, int val2)
{
    return val1 < val2;
}

void giveRank(vector<Applicant>& stu)
{
    for (int i = 0; i != stu.size(); ++i)
    {
        stu[i].rank = i;
    }
}

void adjRank(vector<Applicant>& stu)
{
    for (auto it = stu.begin()+1; it != stu.end(); ++it)
    {
        if ((it->finalGrade == (it - 1)->finalGrade) && (it->gradeE == (it - 1)->gradeE))
        {
            it->rank = (it - 1)->rank;
        }
    }
}

void sortOrder(vector<School>& school)
{
    for (auto& i : school)
    {
        sort(i.acceptStu.begin(), i.acceptStu.end(), compare2);
    }
}

void printRes(vector<School>& school)
{
    for (auto i : school)
    {
        for (auto j : i.acceptStu)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void findSchool(vector<School>& school, vector<Applicant>& stu)
{
    for (auto it = stu.begin(); it != stu.end(); ++it)
    {
        for (int i = 0; i != choiceNum; ++i)
        {
            int tempSchoolNum = it->idealSchool[i];
            if (school[tempSchoolNum].stuCnt < school[tempSchoolNum].quota)
            {
                school[tempSchoolNum].acceptStu.push_back(it->id);
                ++school[tempSchoolNum].stuCnt;
                break;
            }
            else
            {
                int lastAcceptStu = school[tempSchoolNum].acceptStu.back();
                if (it->rank == stu[lastAcceptStu].rank)
                {
                    school[tempSchoolNum].acceptStu.push_back(it->id);
                    ++school[tempSchoolNum].stuCnt;
                    break;
                }
            }
        }
    }
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
