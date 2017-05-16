#include"data.h"

void data::read_data(void)
{
    fstream file("dataE.dat",ios_base::in);
    string content, A, B, C, D;
    question q;
    int number_of_questions;
    file>>number_of_questions;
    file.get();
    for(int i=0;i!=number_of_questions;++i)
    {
        getline(file,content);
        getline(file,A);
        getline(file,B);
        getline(file,C);
        getline(file,D);
        q.edit(content,A,B,C,D);
        easy_questions.push_back(q);
        getline(file,content);  //pominiecie "---"
    }
    file.close();
    file.open("dataM.dat",ios_base::in);
    file>>number_of_questions;
    file.get();
    for(int i=0;i!=number_of_questions;++i)
    {
        getline(file,content);
        getline(file,A);
        getline(file,B);
        getline(file,C);
        getline(file,D);
        q.edit(content,A,B,C,D);
        medium_questions.push_back(q);
        getline(file,content);  //pominiecie "---"
    }
    file.close();
    file.open("dataH.dat",ios_base::in);
    file>>number_of_questions;
    file.get();
    for(int i=0;i!=number_of_questions;++i)
    {
        getline(file,content);
        getline(file,A);
        getline(file,B);
        getline(file,C);
        getline(file,D);
        q.edit(content,A,B,C,D);
        hard_questions.push_back(q);
        getline(file,content);  //pominiecie "---"
    }
    file.close();
    file.open("dataU.dat",ios_base::in);
    file>>number_of_questions;
    file.get();
    for(int i=0;i!=number_of_questions;++i)
    {
        getline(file,content);
        getline(file,A);
        getline(file,B);
        getline(file,C);
        getline(file,D);
        q.edit(content,A,B,C,D);
        ultra_questions.push_back(q);
        getline(file,content);  //pominiecie "---"
    }
    file.close();
}

void data::shuffle_data(void)
{
    //srand(time(NULL));
    int n=rand()%52;
    for(int i=0;i!=n;++i)
    {
        random_shuffle(easy_questions.begin(),easy_questions.end());
        random_shuffle(medium_questions.begin(),medium_questions.end());
        random_shuffle(hard_questions.begin(),hard_questions.end());
        random_shuffle(ultra_questions.begin(),ultra_questions.end());
    }
}

void data::copy_questions(vector<question>& conq)
{
    conq.push_back(easy_questions[0]);
    conq.push_back(easy_questions[1]);
    copy(medium_questions.begin(),medium_questions.begin()+4,back_insert_iterator<vector<question> >(conq));
    copy(hard_questions.begin(),hard_questions.begin()+4,back_insert_iterator<vector<question> >(conq));
    copy(ultra_questions.begin(),ultra_questions.begin()+2,back_insert_iterator<vector<question> >(conq));
}
