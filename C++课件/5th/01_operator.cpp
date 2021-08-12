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

    //运算符重载
    bool operator =(const student &data){
        this->name = data.name;
        this->age = data.age;
        this->score = new double[4];
        for(int i = 0; i < 4; i++)
            score[i] = data.score[i];

        return true;
    }

    // = 运算符的重载必须在类内实现
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

    //后缀++ 需要一个Int型的参数，仅用于跟前缀区分
    //这个n永远默认是0，无法通过函数默认值修改
    student operator ++(int)
//    student operator ++(int n = 1)
    {
//        cout << n <<endl;
        student temp = *this;
        this->age++;
        return temp;
    }

    //前缀++
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

//第一个参数是左值，第二个参数是右值
int operator +(const student& data1,const student &data2)
{
    return data1.age + data2.age;
}

int operator +(const int data,const student &stu){
    return data + stu.age;
}


// = 运算符不能在类外实现
//bool operator =(student &stu,const string name)
//{
//    stu.name = name;
//    return true;
//}


//深拷贝验证
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





