#ifndef DATA_H
#define DATA_H
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<random>
#include"question.h"

using namespace std;

class data
{
private:
    vector<question> easy_questions;
    vector<question> medium_questions;
    vector<question> hard_questions;
    vector<question> ultra_questions;

public:
    void read_data(void);
    void shuffle_data(void);
    void copy_questions(vector<question>&);
};
#endif // DATA_H
