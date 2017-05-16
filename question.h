#ifndef QUESTION_H
#define QUESTION_H

#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<iterator>
#include<random>
#include<ctime>
#include<windows.h>
#include<cstdlib>

using namespace std;

enum DISP_MODE{mark,check};
class question
{
private:
    string content;
    vector<string> answers;
    string correct;
    int correct_nr;

public:
    question();
    question(string,string,string,string,string);
    void edit(string,string,string,string,string);
    void shuffle_answers(void);
    bool check_answer(char);
    char correct_answer(string&);
    void display_question(DISP_MODE, char);

    void fifty_fifty(void);
    char ask_friend(int);
    void ask_audience(int*,int);

    friend ostream& operator<<(ostream&,const question&);
};
#endif // QUESTION_H
