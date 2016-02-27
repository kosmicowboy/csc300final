#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;
//----------- Problem 1 ---------------
class randInt {
public:
    randInt(int low, int high) : low(low), high(high) { }
    int operator()(const int& low, const int& high) {
        return rand() % low + high;
    }
private:
    int low;
    int high;
};
//----------- Problem 2 ---------------
bool larger(int x, int y) {
    return x > y;
}
//----------- Problem 3 ---------------
class DivisibleByN {
public:
    DivisibleByN(int n) : n(n) { }
    bool operator()(int x) {
        return (x % n == 0);
    }
private:
    int n;
};

//----------- Problem 4 ---------------

template<typename T,typename S>
class FinalClass {
public:
    FinalClass() { }
    FinalClass( const vector<T> &vec, const list<S> &lis) : vec(vec), lis(lis) {  size = getSize(); }
    //----------- Problem 4a ---------------
    int getElement(int k) {

        //----------- Problem 5 ---------------
        if (k > size || k > vec.size())//bigger than list or vector
        {
            throw runtime_error ("bad index");
        }
        std::list<int>::iterator it = lis.begin();
        std::advance(it, k);
        cout << "Position " << k << " has the values " << *it << " and  " << vec[k] << endl ;
    }

    //----------- Problem 4b ---------------
    int sum(int k) {
        std::list<int>::iterator it = lis.begin();
        std::advance(it, k);
        cout << "total is: " <<  *it + vec[k];
    }
    int getSize() {
        list<int>::iterator litr;
        int s = 0;
        for (litr = lis.begin(); litr != lis.end(); litr++) {
            s++;
        }
        return s;
    }

private:
    vector <T> vec;
    list <S> lis;
    int size;
};

//----------- Problem 6 ---------------
class Student {
public:
    Student() { }
    Student(const string &name, int totalCredits, double pricePerCredit) : name(name), totalCredits(totalCredits),
                                                                           pricePerCredit(pricePerCredit) { }
    virtual double computeTuition() {
        return totalCredits * pricePerCredit;
    }

private:
    string name;
    int totalCredits;
    double pricePerCredit;
};

class MasterStudent :public Student {
public:

    MasterStudent() : Student() { }
    MasterStudent(const string &name, int totalCredits, double pricePerCredit, double graduateFee)
            : Student(name, totalCredits, pricePerCredit), graduateFee(graduateFee) { }

    virtual double computeTuition() {
        return (Student::computeTuition() + graduateFee);
    }

private:
    double graduateFee;
};

class PhdStudent :public MasterStudent {
public:

    PhdStudent(const string &name, int totalCredits, double pricePerCredit, double graduateFee, double researchFee)
            : MasterStudent(name, totalCredits, pricePerCredit, graduateFee), researchFee(researchFee) { }

    virtual double computeTuition() {
        return (MasterStudent::computeTuition() + researchFee);
    }
private:
    double researchFee;
};

int main() {

    cout << " ----------- Problem 1 ---------------" << endl;
//    cout << randInt(13, 2044);

    cout << " ----------- Problem 2 ---------------" << endl;
    cout << larger(19, 13) << endl; // 0 for false, 1 for true

    cout << " ----------- Problem 3 ---------------" << endl;
    DivisibleByN n(10);
    cout << n(100) << endl; // 0 for false, 1 for true
    cout << n(13) << endl; // 0 for false, 1 for true

    cout << " ----------- Problem 4 ---------------" << endl;
    vector<int> exampleVector { 34,23,99,1000,123,4,5,564,234,234,2,77,0 };
    list<int> exampleList;

    for (int i=1; i<=10; ++i) {
        exampleList.push_back(1 + rand() % 100);
    }

    FinalClass<int,int> exampleTemplate(exampleVector, exampleList);
    //----------- Problem 4c ---------------
    exampleTemplate.getElement(7);
    exampleTemplate.sum(7);
    cout << " \n----------- Problem 5 ---------------" << endl;

    try {
        exampleTemplate.getElement(30);
    } catch (runtime_error e) {
        cout << e.what() << endl;
    }
    cout << " \n----------- Problem 6 ---------------" << endl;
    Student undergrad("Joe Schmoe",15, 250.00);
    MasterStudent middleManagement("Bob Barker", 9, 500.00, 1500.00);
    PhdStudent theCEO("Elon Musk", 6, 1250.00, 1500.00, 5000.00);
    vector <Student> csc626{undergrad, middleManagement, theCEO};

    for (int i = 0; i < csc626.size(); ++i) {
        cout << "Tuition is: " << csc626[i]->computeTuition() << endl;
    }


    return 0;
}
