#ifndef GAME_H
#define GAME_H
#include<vector>
#include<iostream>
#include"data.h"

using namespace std;

enum HELP{aud,fif,pho};
class game
{
private:
    vector<question> contest_questions;
    int money[13];
    int quest_number;
    int award;
    bool audience;
    bool fifty_fifty;
    bool phone;
public:
    int which_question(void) {return quest_number;}
    int get_award(void) {return award;}
    void init(data&);
    void next_question(ostream&);
    void shuffle_answers(void);
    bool check_answer(char,char&,string&);
    void lifelines(ostream&, HELP);
    void question_menu(ostream&);
    void start_menu(ostream&);
    void display_question(DISP_MODE mode, char ans);
};
#endif // GAME_H
