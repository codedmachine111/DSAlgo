#include <iostream>
using namespace std;

class Course{
    private:
        int marks;
    public:
        static int n_courses;
        string s1, s2, s3;
        void setCourses(string s1,string s2,string s3){
            this->s1 = s1;
            this->s2 = s2;
            this->s3 = s3;
        }

        void setMarks(int marks){
            this->marks = marks;
        }

        int getMarks(){
            return this->marks;
        }
};

class Math: public Course{
   
};

class Science: public Course{

};

class Statistics: public Course{

};

int printAvg(int x, int y, int z){
    return (x+y+z)/3;
}

int main(){
    Math alg;
    Science bio;
    Statistics prob;

    alg.setMarks(100);
    bio.setMarks(200);
    prob.setMarks(300);

    int avg = printAvg(alg.getMarks(), bio.getMarks(), prob.getMarks());
    cout << "Average : " << avg << endl;
    
    return 0;
}