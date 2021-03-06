// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<fstream>


/*

Функционал программы:

В текстовом файле содержится таблица вида:

|Номер зачетки|Фамилия|Имя|Отчество|Дата рождения|Оценки 1 - 4|

Есть возможность добавить в конец файла, либо удалить конкретного студента. При удалении студента используется динамический массив объектов. Далее 
содержимое текстового файла переводится в бинарный файл, содержимое которого может быть обработано следующими функциями:

- Вывести содержимое текстового файла на экран.

- Получить список студентов, имеющих хотя бы 1 оценку 4.

- Получить список студентов, у которых все оценки 9 или 10.

- Самый длинный список студентов, у которых одинаковая дата рождения.

- Самый длинный список студентов, у которых одинаковые оценки.

- Замена мест в файле студентов с наибольшим и наименьшим  средним баллом.

- Сортировка по среднему баллу.

Итоговый результат записывается в новый бинарный файл, содержимое которого выводится на экран.
  */

class Student;

void createBinary(int&,char*, char*);

inline void displayStudent(Student& x);

inline void systemFunction();

inline void displayTitle();

bool checkFor4(Student x);

void listWith4(int stAmm, int& res, char* binarylist, char* binaryresult);

bool checkForAHighAchiever(Student x);

void highAchieverList(int stAmm, int& res, char* binarylist, char* binaryresult);

void showResult(int& res, char* binaryresult);

void FindMostDuplicateMarks(int& m1, int& m2, int& m3, int& m4, int stAmm, char* binarylist);

double bestAvarageMark(int stAmm, char* binarylist);

void swap(double& a, double& b);

void recopy(char*, char*, int);

void sortingFile(int stAmm, char* binarylist, char* binaryresult);

void recopy(char* binarylist, char* binaryresult, int stAmm);

void deleteStudents(int stAmm, int& res, char* binarylist, char* binaryresult);

void findMax(char* binarylist, int stAmm, Student& x);

void swapMaxAndMin(char* binarylist, char* binaryresult, int stAmm);

Student addStudent();

void findMin(char* binarylist, int stAmm, Student& x);

void addToEnd(char* textname);

void fullStudentsArray(char* textname, Student* arr, int amm);

int studentsAmmount(char* textname);

void deleteFromText(char* textname);

void bestStudentList(int stAmm, int& res, char* binarylist, char* binaryresult);

void equalMarksList(char* binarylist, char* binaryresult, int stAmm, int& res);

void createMenu(int stAmm, char* textfile, char* binaryfile, char* binaryresult);

inline int menu();

void textfileMenu(char* textfile, char* binary, char* result);

void displayTextFile(char* textname);



class Student
{
public:

	Student() {}
	Student(char*, char*, char*, char*, int, int, int, int, int);
	Student(const char*, const char*, const char*, const char*, int, int, int, int, int);
	~Student() {}
	inline void SetId(int);
	inline void SetFirstName(char*);
	inline void SetFirstName(const char*);
	inline void SetLastName(char*);
	inline void SetLastName(const char*);
	inline void SetPatronymic(char*);
	inline void SetPatronymic(const char*);
	inline void SetDate(char*);
	inline void SetDate(const char*);
	inline void SetMarks(int, int, int, int);
	inline void SetAvarageMark();

	inline char* GetFirstName();
	inline char* GetLastName();
	inline char* GetPatronymic();
	inline char* GetDate();
	inline int GetMark1() const;
	inline int GetMark2() const;
	inline int GetMark3() const;
	inline int GetMark4() const;
	inline int GetId() const;
	inline double GetAvMark() const;

	inline void Display();

	friend std::istream& operator >>(std::istream&, Student&);
	friend std::ostream& operator <<(std::ostream&, Student&);
	friend std::ifstream& operator >>(std::ifstream&, Student&);
	friend std::ofstream& operator <<(std::ofstream&, Student&);

	Student& operator = (const Student&);
	bool operator == (Student&);

private:
	char firstName[50];
	char lastName[50];
	char patronymic[50];
	char date[15];
	int mark1, mark3, mark4, mark2, id;

	double avarMark;
};


int main()
{
	char textfile[13] = "Student.txt";
	char binaryfile[13] = "Binary.bin";
	char binaryresult[13] = "Result.bin";
	textfileMenu(textfile, binaryfile, binaryresult);


	system("pause");
    return 0;
}


#pragma region Student

inline void Student::SetId(int id)
{
	this->id = id;
}
inline void Student::SetFirstName(char* name)
{
	strcpy(this->firstName, name);
}
inline void Student::SetFirstName(const char* name)
{
	strcpy(this->firstName, name);
}
inline void Student::SetLastName(char* lname)
{
	strcpy(this->lastName, lname);
}
inline void Student::SetLastName(const char* lname)
{
	strcpy(this->lastName, lname);
}
inline void Student::SetPatronymic(char* patronymic)
{
	strcpy(this->patronymic, patronymic);
}
inline void Student::SetPatronymic(const char* patronymic)
{
	strcpy(this->patronymic, patronymic);
}
inline void Student::SetDate(char* date)
{
	strcpy(this->date, date);
}
inline void Student::SetDate(const char* date)
{
	strcpy(this->date, date);
}
inline void Student::SetMarks(int mark1, int mark2, int mark3, int mark4)
{
	this->mark1 = mark1;
	this->mark2 = mark2;
	this->mark3 = mark3;
	this->mark4 = mark4;

}
inline void Student::SetAvarageMark()
{
	int x = this->GetMark1() + this->GetMark2() + this->GetMark3() + this->GetMark4();
	this->avarMark = (double)x / 4;
}

inline char* Student::GetFirstName()
{
	return this->firstName;
}
inline char* Student::GetLastName()
{
	return this->lastName;
}
inline char* Student::GetPatronymic()
{
	return this->patronymic;
}
inline char* Student::GetDate()
{
	return this->date;
}
inline int Student::GetId() const
{
	return this->id;
}
inline int Student::GetMark1() const
{
	return this->mark1;
}
inline int Student::GetMark2() const
{
	return this->mark2;
}
inline int Student::GetMark3() const
{
	return this->mark3;
}
inline int Student::GetMark4() const
{
	return this->mark4;
}
inline double Student::GetAvMark() const
{
	int x = this->GetMark1() + this->GetMark2() + this->GetMark3() + this->GetMark4();
	return (double)x / 4;

}
void Student::Display()
{
	std::cout << this->GetId() << std::setw(10) << this->GetLastName() <<
		std::setw(12) << this->GetFirstName() << std::setw(12) << this->GetPatronymic() <<
		std::setw(11) << this->GetDate() << std::setw(7) << this->GetMark1() <<
		std::setw(7) << this->GetMark2() << std::setw(7) << this->GetMark3() <<
		std::setw(7) << this->GetMark4() << std::endl;

}

Student::Student(char* name, char* lastName, char* patr, char* date, int m1, int m2, int m3, int m4, int id)
{
	this->SetFirstName(name);
	this->SetLastName(lastName);
	this->SetPatronymic(patr);
	this->SetDate(date);
	this->SetMarks(m1, m2, m3, m4);
	this->SetId(id);
	this->SetAvarageMark();
}
Student::Student(const char* name, const char* lastName, const char* patr, const char* date, int m1, int m2, int m3, int m4, int id)
{
	this->SetFirstName(name);
	this->SetLastName(lastName);
	this->SetPatronymic(patr);
	this->SetDate(date);
	this->SetMarks(m1, m2, m3, m4);
	this->SetId(id);
	this->SetAvarageMark();
}

std::istream& operator >>(std::istream& input, Student& student)
{
	char name[25], lastName[25], patr[25], date[11];
	int mark1, mark2, mark3, mark4, id;

	input >> id >> lastName >> name >> patr >> date >> mark1 >> mark2 >> mark3 >> mark4;

	student.SetId(id);
	student.SetFirstName(name);
	student.SetPatronymic(patr);
	student.SetDate(date);
	student.SetMarks(mark1, mark2, mark3, mark4);

	return input;
}
std::ifstream& operator >>(std::ifstream& input, Student& student)
{
	char name[25], lastName[25], patr[25], date[11];
	int mark1, mark2, mark3, mark4, id;

	input >> id >> lastName >> name >> patr >> date >> mark1 >> mark2 >> mark3 >> mark4;

	student.SetId(id);
	student.SetFirstName(name);
	student.SetLastName(lastName);
	student.SetPatronymic(patr);
	student.SetDate(date);
	student.SetMarks(mark1, mark2, mark3, mark4);

	return input;
}
std::ostream& operator <<(std::ostream& output, Student& student)
{
	output << student.GetId() << ' ' << student.GetLastName() << ' ' << student.GetFirstName() << ' ' << student.GetPatronymic() << ' ' << student.GetDate() << ' ' <<
		student.GetMark1() << ' ' << student.GetMark2() << ' ' << student.GetMark3() << ' ' << student.GetMark4() << '\n';

	return output;
}
std::ofstream& operator <<(std::ofstream& output, Student& student)
{
	output << student.GetId() << ' ' << student.GetLastName() << ' ' << student.GetFirstName() << ' ' << student.GetPatronymic() << ' '
		<< student.GetDate() << ' ' << student.GetMark1() << ' ' << student.GetMark2() << ' ' << student.GetMark3() << ' '
		<< student.GetMark4() << '\n';

	return output;
}
Student& Student::operator=(const Student& x)
{
	strcpy(this->firstName, x.firstName);
	strcpy(this->lastName, x.lastName);
	strcpy(this->patronymic, x.patronymic);
	strcpy(this->date, x.date);
	this->id = x.id;
	this->mark1 = x.mark1;
	this->mark2 = x.mark2;
	this->mark3 = x.mark3;
	this->mark4 = x.mark4;

	return (*this);
}
bool Student::operator==(Student& x)
{
	if (!strcmp(this->GetFirstName(), x.GetFirstName()) && !strcmp(this->GetLastName(), x.GetLastName()) && !strcmp(this->GetPatronymic(),
		x.GetPatronymic()) && !strcmp(this->GetDate(), x.GetDate()) && this->GetId() == x.GetId() && this->GetMark1() == x.GetMark1() &&
		this->GetMark2() == x.GetMark2() && this->GetMark3() == x.GetMark3() && this->GetMark4() == x.GetMark4())
		return true;
	else return false;
}

#pragma endregion

void createBinary(int& stAmm, char* textlist, char* binarylist)
{
	std::ifstream fin(textlist);
	std::ofstream fout(binarylist, std::ios::binary | std::ios::out | std::ios::trunc);
	if (!fin.is_open() || !fout.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl;
	}
	for (int i = 0; i < stAmm; ++i)
	{
		Student x;

		fin >> x;
		fout.write((char*)&x, sizeof(Student));
	}
	fout.close();
	fin.close();
}

inline void displayStudent(Student& x)
{
	std::cout << x.GetId() << std::setw(10) << x.GetLastName() <<
		std::setw(12) << x.GetFirstName() << std::setw(12) << x.GetPatronymic() <<
		std::setw(11) << x.GetDate() << std::setw(7) << x.GetMark1() <<
		std::setw(7) << x.GetMark2() << std::setw(7) << x.GetMark3() <<
		std::setw(7) << x.GetMark4() << std::endl;
}

inline void systemFunction()
{
	std::cout << std::endl;
	system("cls");
}

inline void DisplayContent(int stAmm, char* binarylist)
{
	Student st;

	std::fstream fin(binarylist, std::ios::binary | std::ios::in | std::ios::out);

	if (!fin.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl; exit(1);
	}

	displayTitle();
	fin.seekg(0, std::ios::beg);
	for (int i = 0; i< stAmm; ++i)
	{
		fin.read((char*)&st, sizeof(Student));

		displayStudent(st);
	}

	fin.close();
}

inline void displayTitle()
{
	std::cout << "Id" << std::setw(15) << "LastName" << std::setw(10) << "Name" << std::setw(15) << "Patronymic" <<
		std::setw(7) << "Date" << std::setw(10) << "Mark 1" << std::setw(7) << "Mark 2" << std::setw(7) << "Mark 3" <<
		std::setw(7) << "Mark 4" << std::endl;
}

void listWith4(int stAmm, int& res, char* binarylist, char* binaryresult)
{
	res = 0;

	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);
	std::ofstream fout(binaryresult, std::ios::binary | std::ios::out | std::ios::trunc);

	if (!fin.is_open() || !fout.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl; exit(1);
	}


	Student st;

	fin.seekg(0, std::ios::beg);

	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&st, sizeof(Student));
		if (checkFor4(st))
		{
			fout.write((char*)&st, sizeof(Student));
			res++;
		}
	}

	fin.close();
	fout.close();
}

bool checkFor4(Student x)
{
	if (x.GetMark1() == 4 || x.GetMark2() == 4 || x.GetMark3() == 4 || x.GetMark4() == 4)
		return true;
	else return false;
}

void highAchieverList(int stAmm, int& res, char* binarylist, char* binaryresult)
{
	res = 0;

	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);
	std::ofstream fout(binaryresult, std::ios::binary | std::ios::out | std::ios::trunc);

	if (!fin.is_open() || !fout.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl; exit(1);
	}

	Student st;

	fin.seekg(0, std::ios::beg);

	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&st, sizeof(Student));
		if (checkForAHighAchiever(st))
		{
			fout.write((char*)&st, sizeof(Student));
			res++;
		}
	}

	fin.close();
	fout.close();
}

bool checkForAHighAchiever(Student x)
{
	if ((x.GetMark1() == 9 || x.GetMark1() == 10) && (x.GetMark2() == 9 || x.GetMark2() == 10) && (x.GetMark3() == 9 || x.GetMark3() == 10) && (x.GetMark4() == 9 || x.GetMark4() == 10))
		return true;

	else return false;
}

void showResult(int& res, char* binaryresult)
{
	Student st;

	std::fstream fin(binaryresult, std::ios::binary | std::ios::in | std::ios::out);

	if (!fin.is_open())
		std::cout << "Error! The file is not opened!" << std::endl;

	displayTitle();
	fin.seekg(0, std::ios::beg);
	for (int i = 0; i< res; ++i)
	{
		fin.read((char*)&st, sizeof(Student));

		displayStudent(st);
	}

	fin.close();
	res = 0;

	system("pause");
}

void FindMostDuplicateMarks(int& m1, int& m2, int& m3, int& m4, int stAmm, char* binarylist)
{
	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);

	if (!fin.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl; exit(1);
	}
	Student st, xt;
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, length = 0, ml = 0;

	int buffSize = sizeof(Student);
	fin.seekg(0, std::ios::beg);
	for (int i = 0; i < stAmm; ++i)
	{
		fin.seekg(i*buffSize, std::ios::beg);
		fin.read((char*)&st, sizeof(Student));

		x1 = st.GetMark1(); x2 = st.GetMark2(); x3 = st.GetMark3(); x4 = st.GetMark4();

		for (int j = i + 1; j < stAmm; ++j)
		{
			fin.seekg(j*buffSize, std::ios::beg);
			fin.read((char*)&xt, sizeof(Student));

			if (x1 == xt.GetMark1() && x2 == xt.GetMark2() && x3 == xt.GetMark3() && x4 == xt.GetMark4())
				length++;
		}

		if (length > ml)
		{
			ml = length; m1 = x1; m2 = x2; m3 = x3; m4 = x4; length = 0;
		}

		else length = 0;
	}

	fin.close();
}

double bestAvarageMark(int stAmm, char* binarylist)
{
	double max = 0;

	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);

	if (!fin.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl; exit(1);
	}

	Student xt;

	fin.seekg(0, std::ios::beg);
	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&xt, sizeof(Student));
		if (xt.GetAvMark() > max)
			max = xt.GetAvMark();
	}

	fin.close();

	return max;
}

void swap(double& a, double& b)
{
	double t = a;
	a = b;
	b = t;
}

double findMin(int stAmm, char* binarylist)
{
	double min = 10;

	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);

	if (!fin.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl; system("pause"); exit(1);
	}
	Student xt;

	fin.seekg(0, std::ios::beg);
	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&xt, sizeof(Student));
		if (xt.GetAvMark() < min)
			min = xt.GetAvMark();
	}

	fin.close();

	return min;
}

double* markArray(int stAmm, char* binarylist)
{
	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);
	if (!fin.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl;
	}
	Student xt;

	double* x = new double[stAmm];

	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&xt, sizeof(Student));
		x[i] = xt.GetAvMark();
	}
	fin.close();

	return x;
}

void sort(int stAmm, double* x)
{
	for (int i = 0; i < stAmm; ++i)
	{
		for (int j = 0; j < stAmm - i - 1; ++j)
		{
			if (x[j] < x[j + 1]) swap(x[j], x[j + 1]);
		}
	}
}

void deleteStudents(int stAmm, int& res, char* binarylist, char* binaryresult)
{
	char name[50];

	std::cin.ignore();
	std::cin.getline(name, 50);

	systemFunction();

	char* len = new char[strlen(name) + 1];
	strcpy(len, name);

	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);
	std::ofstream fout(binaryresult, std::ios::binary | std::ios::out | std::ios::trunc);

	if (!fin.is_open() || !fout.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl; system("pause"); exit(1);
	}

	Student st;

	fin.seekg(0, std::ios::beg);
	fout.seekp(0, std::ios::beg);
	res = 0;
	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&st, sizeof(Student));
		if (strcmp(st.GetFirstName(), len))
		{
			fout.write((char*)&st, sizeof(Student));
			res++;
		}
	}

	fin.close();
	fout.close();
	delete[] len;
}

void sortingFile(int stAmm, char* binarylist, char* binaryresult)
{
	recopy(binarylist, binaryresult, stAmm);

	int x = stAmm;

	system("pause");

	bool flag = true;
	while (flag)
	{
		std::fstream streamInOut(binaryresult, std::ios::in | std::ios::out | std::ios::binary);
		if (!streamInOut.is_open())
		{
			std::cout << "Can't open file to read and write!";
			systemFunction();
			return;
		}
		flag = false;
		Student manOne, manTwo;
		int bufSize = sizeof(Student);
		streamInOut.read((char*)&manOne, bufSize);
		while (streamInOut.read((char*)&manTwo, bufSize))
		{
			if (manTwo.GetAvMark() > manOne.GetAvMark())
			{
				streamInOut.seekp(-2 * bufSize, std::ios::cur);
				streamInOut.write((char*)&manTwo, bufSize);
				streamInOut.write((char*)&manOne, bufSize);
				flag = true;
			}
			streamInOut.seekp(-bufSize, std::ios::cur);
			streamInOut.read((char*)&manOne, bufSize);
		}
		streamInOut.close();
	}
}

void recopy(char* binarylist, char* binaryresult, int stAmm)
{
	std::fstream fin("Binary.bin", std::ios::binary | std::ios::in);


	std::cout << fin.is_open();
	if (!fin.is_open())
	{
		std::cout << "Error! the file is not opened!" << std::endl; system("pause"); exit(1);
	}


	std::fstream fout("Result.bin", std::ios::binary | std::ios::out | std::ios::trunc);

	if (!fout.is_open())
	{
		std::cout << "Error! the file is not opened!" << std::endl; system("pause"); exit(1);
	}

	Student st;

	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&st, sizeof(Student));  fout.write((char*)&st, sizeof(Student));
	}

	fin.close();
	fout.close();
}

void swapMaxAndMin(char* binarylist, char* binaryresult, int stAmm)
{

	Student max, min;

	findMax(binarylist, stAmm, max);

	findMin(binarylist, stAmm, min);

	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);
	std::ofstream fout(binaryresult, std::ios::binary | std::ios::out | std::ios::trunc);


	fin.seekg(0, std::ios::beg);

	if (!fin.is_open() || !fout.is_open()) { std::cout << "Error!" << std::endl; system("pause"); exit(1); }

	Student st;
	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&st, sizeof(Student));

		if (st == min)
			fout.write((char*)&max, sizeof(Student));
		else if (st == max)
			fout.write((char*)&min, sizeof(Student));
		else
			fout.write((char*)&st, sizeof(Student));
	}

	fin.close();
	fout.close();
}

void findMax(char* binarylist, int stAmm, Student& x) 
{
	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);

	if (!fin.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl; system("pause"); exit(1);
	}

	fin.seekg(0, std::ios::beg);

	Student st;

	fin.read((char*)&x, sizeof(Student));

	for (int i = 0; i < stAmm-1; ++i)
	{
		fin.read((char*)&st, sizeof(st));

		if (st.GetAvMark() > x.GetAvMark()) x = st;
	}

	fin.close();
}

void findMin(char* binarylist, int stAmm, Student& x)
{
	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);

	if (!fin.is_open())
	{
		std::cout << "Error! The file is not opened!" << std::endl; system("pause"); exit(1);
	}

	fin.seekg(0, std::ios::beg);

	Student st;

	fin.read((char*)&x, sizeof(Student));

	for (int i = 0; i < stAmm - 1; ++i)
	{
		fin.read((char*)&st, sizeof(st));

		if (st.GetAvMark() < x.GetAvMark()) x = st;
	}

	fin.close();
}

Student addStudent()
{
	std::cout << "Enter the id of student:" << std::endl;
	int id; std::cin >> id;

	std::cout << "Enter the last name of the student : " << std::endl;
	std::cin.ignore();
	char lname[20]; std::cin.getline(lname, 20,'\n');

	std::cout << "Enter the first name of the student : " << std::endl;
	char fname[20]; std::cin.getline(fname, 20, '\n');

	std::cout << "Enter the patronymic of the student : " << std::endl;
	char patr[20]; std::cin.getline(patr, 20, '\n');

	std::cout << "Enter the date of the birth of the student : " << std::endl;
	char date[20]; std::cin.getline(date, 20, '\n');

	std::cout << "Enter the marks of the student:" << std::endl;
		int marks[4];
		for (int i = 0; i < 4; ++i)
			std::cin >> marks[i];

		Student y(fname, lname, patr, date, marks[0], marks[1], marks[2], marks[3], id);
		return y;
}

void deleteFromText(char* textname)
{
	Student del;
	std::cout << "Enter the student, you want to delete:" << std::endl;

	del = addStudent();
	int ammount = studentsAmmount(textname);

	Student* x = new Student[ammount];
	fullStudentsArray(textname, x, ammount);

	std::ofstream fout(textname, std::ios::trunc);

	if (!fout.is_open()) { std::cout << "Error! The file is not opened" << std::endl; system("pause"); exit(1); }

	for (int i = 0; i < ammount; ++i)
	{
		if (x[i] == del)
			continue;
		else
			fout << x[i];
	}

	delete[] x;
	fout.close();

	systemFunction();
}

int studentsAmmount(char* textname)
{
	std::ifstream fin(textname);

	if (!fin.is_open()) { std::cout << "Error! The file is not opened!" << std::endl; system("pause"); exit(1); }
	int k = 0;

	Student x;

	while (fin >> x)
	{

		++k;
	}

	fin.close();

	return k;

}

void fullStudentsArray(char* textname, Student* arr, int amm)
{
	std::ifstream fin(textname);

	if (!fin.is_open()) { std::cout << "Error! The file is not opened!" << std::endl; system("pause"); exit(1); }


	for (int i = 0; i < amm; ++i)
	{
		fin >> arr[i];
	}

	fin.close();
}

void addToEnd(char* textname)
{
	Student x = addStudent();

	std::ofstream fout(textname, std::ios::app);
	if (!fout.is_open()) { std::cout << "Error! The file is not opened!" << std::endl; exit(1); }

	fout << x;

	fout.close();
	
}

void textfileMenu(char* textfile, char* binary, char* result)
{
	enum { Display = 1, AddStudent,  DeleteStudent, BinaryOperations, Exit};

	int k; int j = 0;
	while (j == 0)
	{
		systemFunction();

		std::cout << "  Enter the number to choose the operation with text file:" << std::endl;
		std::cout << " 1 - display the content of the text file" << std::endl;
		std::cout << " 2 - add a student to the end of a text file" << std::endl;
		std::cout << " 3 - delete a student from a text file" << std::endl;
		std::cout << " 4 - go over to the operations with binary files:" << std::endl;
		std::cout << " 5 - exit" << std::endl;

		int ammount = 0;

		std::cin >> k;
		systemFunction();
		switch (k)
		{
		case Display:
			systemFunction();
			displayTextFile(textfile);
			break;
		case AddStudent:
			systemFunction();
			addToEnd(textfile);
			displayTextFile(textfile);
			break;
		case DeleteStudent:
			systemFunction();
			deleteFromText(textfile);
			displayTextFile(textfile);
		case BinaryOperations:
			createMenu(ammount, textfile, binary, result);
			break;

		case Exit:
			++j;
		}
	}
}

void displayTextFile(char* textname)
{
	Student x;
	std::ifstream fin(textname);

	if (!fin.is_open()) { std::cout << "Error! The file is not opened!" << std::endl; }

	while (fin>>x)
	{

		displayStudent(x);
	}

	fin.close();

	system("pause");
}

inline int menu()
{
	int choice;

	std::cout << std::setw(30) << "\n Enter the number to choose the operation"
		"\n 1 - Display the contents of the file"
		"\n 2 - Display the list of students, that have marks 4"
		"\n 3 - Display the list of students, that have marks 9 and 10 "
		"\n 4 - Display the maximum list of students, that have equal dates"
		"\n 5 - Display the maximum list of students, that have equal marks"
		"\n 6 - Display the list of the best students(by an avarage mark)"
		"\n 7 - Swap students with maximum and minimum avarage marks"
		"\n 8 - Sort file by an avarage mark"
		"\n 9 - Delete selected student\n"
		"\n 10 - Exit \n";

	std::cin >> choice;
	return choice;
}

void theLongestData(char* binarylist, int stAmm, char* mdate)
{
	char data[15]; int length = 0, maxL = 0; char mdata[15];

	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);

	if (!fin.is_open()) { std::cout << "Error! The file is not opened!" << std::endl; system("pause"); exit(1); }
	Student st, xt;

	int buffSize = sizeof(Student);
	fin.seekg(0, std::ios::beg);
	for (int i = 0; i < stAmm; ++i)
	{
		fin.seekg(i*buffSize, std::ios::beg);
		fin.read((char*)&st, sizeof(Student));
		strcpy(data, st.GetDate());

		for (int j = i + 1; j < stAmm; ++j)
		{
			fin.seekg(j*buffSize, std::ios::beg);
			fin.read((char*)&xt, sizeof(Student));

			if (!strcmp(data, xt.GetDate()))
			{
				length++;
			}
		}

		if (length > maxL)
		{
			strcpy(mdata, data);
			maxL = length;
			length = 0;
		}
		else length = 0;
	}

	fin.close();

	strcpy(mdate, mdata);
}

void theLongestDataList(char* binarylist, char* binaryresult, int stAmm, int& res)
{
	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);
	std::ofstream fout(binaryresult, std::ios::binary | std::ios::out | std::ios::trunc);

	if (!fin.is_open() || !fout.is_open()) { std::cout << "Error!The file is not opened!" << std::endl; system("pause"); exit(1); }

	Student st;

	char date[15];
	theLongestData(binarylist, stAmm, date);
	fin.seekg(0, std::ios::beg);
	fout.seekp(0, std::ios::beg);
	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&st, sizeof(Student));
		if (!strcmp(date, st.GetDate()))
		{
			fout.write((char*)&st, sizeof(Student));
			++res;
		}
	}
	fin.close();
	fout.close();
}

void createMenu(int stAmm, char* textfile, char* binaryfile, char* binaryresult)
{
	stAmm = studentsAmmount(textfile);
	createBinary(stAmm, textfile, binaryfile);

	enum { Create = 1, ListWith4, ListWith9and10, MaxEqualDateList, EqualMarksList, BestStudentsList, SwapMaxAndMin, SortByAvarageMark, DeleteStudent, Exit };
	int result = 0;
	while (true)
	{
		int key = menu();
		if (key == Exit)
			break;

		


		systemFunction();
		switch (key)
		{
		case Create:
			DisplayContent(stAmm, binaryfile);
			system("pause");
			systemFunction();
			break;

		case ListWith4:
			std::cout << "The list of students, that have at least 1 mark 4:" << std::endl;
			listWith4(stAmm, result, binaryfile, binaryresult);
			showResult(result, binaryresult);
			systemFunction();
			break;

		case ListWith9and10:
			std::cout << "The list of students, that have only 9 or 10 marks:" << std::endl;
			highAchieverList(stAmm, result, binaryfile, binaryresult);
			showResult(result, binaryresult);
			systemFunction();
			break;

		case MaxEqualDateList:
			std::cout << "The longest list of students with equal date:" << std::endl;
			theLongestDataList(binaryfile, binaryresult, stAmm, result);
			showResult(result, binaryresult);
			systemFunction();
			break;

		case EqualMarksList:
			std::cout << "The longest list of students with equal marks:" << std::endl;
			equalMarksList(binaryfile, binaryresult, stAmm, result);
			showResult(result, binaryresult);
			systemFunction();
			break;

		case BestStudentsList:
			std::cout << "The student with the best avarage mark!" << std::endl;
			bestStudentList(stAmm, result, binaryfile, binaryresult);
			showResult(result, binaryresult);
			systemFunction();
			break;

		case SwapMaxAndMin:
			std::cout << "New list of students with changed places of the best and the worst students" << std::endl;
			swapMaxAndMin(binaryfile, binaryresult, stAmm);
			result = stAmm;
			showResult(result, binaryresult);
			systemFunction();
			break;

		case SortByAvarageMark:
			std::cout << "New list of students, sorted by avarage mark" << std::endl;
			sortingFile(stAmm, binaryfile, binaryresult);
			result = stAmm;
			showResult(result, binaryresult);
			systemFunction();
			break;

		case DeleteStudent:
			std::cout << "Enter the name of the students" << std::endl;
			deleteStudents(stAmm, result,binaryfile, binaryresult);
		    showResult(result, binaryresult);
			systemFunction();
			break;
		}
	}

}

void equalMarksList(char* binarylist, char* binaryresult, int stAmm, int& res)
{
	int mark1 = 0, mark2 = 0, mark3 = 0, mark4 = 0;
	FindMostDuplicateMarks(mark1, mark2, mark3, mark4, stAmm, binarylist);

	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);
	std::ofstream fout(binaryresult, std::ios::binary | std::ios::out | std::ios::trunc);

	if (!fin.is_open() || !fout.is_open()) { std::cout << "Error! The file is not opened!" << std::endl; system("pause"); exit(1); }

	Student st;

	fin.seekg(0, std::ios::beg);
	fout.seekp(0, std::ios::beg);
	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&st, sizeof(Student));
		if (mark1 == st.GetMark1() && mark2 == st.GetMark2() && mark3 == st.GetMark3() && mark4 == st.GetMark4())
		{
			fout.write((char*)&st, sizeof(Student));
			++res;
		}
	}
	fin.close();
	fout.close();
}

void bestStudentList(int stAmm, int& res, char* binarylist, char* binaryresult)
{
	std::ifstream fin(binarylist, std::ios::binary | std::ios::in);
	std::ofstream fout(binaryresult, std::ios::binary | std::ios::out | std::ios::trunc);

	if (!fin.is_open() || !fout.is_open()) { std::cout << "Error! The file is not opened!" << std::endl; system("pause"); exit(1); }
	double max = bestAvarageMark(stAmm, binarylist);

	Student st;

	fin.seekg(0, std::ios::beg);
	fout.seekp(0, std::ios::beg);

	for (int i = 0; i < stAmm; ++i)
	{
		fin.read((char*)&st, sizeof(Student));
		if (st.GetAvMark() == max)
		{
			fout.write((char*)&st, sizeof(Student));
			res++;
		}
	}
	fin.close();
	fout.close();
}