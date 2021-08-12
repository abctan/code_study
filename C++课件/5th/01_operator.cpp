#include <iostream>
#include <string>

using namespace std;

class student
{
    string name;
    int age;
    double *score;
public:

    student(string name = "noname",int age = 0)
    {
        this->name = name;
        this->age = age;
        score = new double[4];
        for(int i = 0; i < 4; i++)
            score[i] = i + 60;
    }
    student(const student &data)
    {
       *this = data;
    }

    ~student(){
        delete[] score;
    }

    void showThis()const{
        cout << name << " " << age << endl;
        for(int i = 0; i < 4; i++)
            cout << score[i]<< " ";
        cout << endl;
    }

    //���������
    bool operator =(const student &data){
        this->name = data.name;
        this->age = data.age;
        this->score = new double[4];
        for(int i = 0; i < 4; i++)
            score[i] = data.score[i];

        return true;
    }

    // = ����������ر���������ʵ��
    bool operator =(const string name){
        this->name = name;
        return true;
    }

//    friend bool operator =(student &stu,const string name);

//    int operator +(const student& data){
//        return this->age + data.age;
//    }
    friend int operator +(const student& data1,const student &data2);
    friend int operator +(const int data,const student &stu);

    //��׺++ ��Ҫһ��Int�͵Ĳ����������ڸ�ǰ׺����
    //���n��ԶĬ����0���޷�ͨ������Ĭ��ֵ�޸�
    student operator ++(int)
//    student operator ++(int n = 1)
    {
//        cout << n <<endl;
        student temp = *this;
        this->age++;
        return temp;
    }

    //ǰ׺++
    student& operator ++(){
        this->age++;
        return *this;
    }

    bool operator <(const student &stu){
        return this->name < stu.name;
    }

//    bool operator <(const student &stu){
//        return this->age < stu.age;
//    }
};

bool cmpStuAge(student &stu1,student &stu2)
{
    return stu1.age < stu2.age;
}

//��һ����������ֵ���ڶ�����������ֵ
int operator +(const student& data1,const student &data2)
{
    return data1.age + data2.age;
}

int operator +(const int data,const student &stu){
    return data + stu.age;
}


// = ���������������ʵ��
//bool operator =(student &stu,const string name)
//{
//    stu.name = name;
//    return true;
//}


//�����֤
void test01(){
    student *stu = new student("jack",20);
    student stu1(*stu);

    stu->showThis();
    stu1.showThis();

    delete stu;
    stu1.showThis();
}

int main()
{
    student stu("jack",20);
    student stu1("mary",19);

    ++stu = stu1;
    stu.showThis();
}





