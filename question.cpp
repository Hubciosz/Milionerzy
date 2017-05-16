#include"question.h"

question::question()
:content("To be or not to be?"), correct("A"), correct_nr(0)
{
    answers.push_back("A");
    answers.push_back("B");
    answers.push_back("C");
    answers.push_back("D");
}

question::question(string q,string a1,string a2,string a3,string a4)
:content(q), correct(a1), correct_nr(0)
{
    answers.push_back(a1);
    answers.push_back(a2);
    answers.push_back(a3);
    answers.push_back(a4);
}

void question::edit(string q,string a1,string a2,string a3,string a4)
{
    content=q;
    correct=a1;
    correct_nr=0;
    answers[0]=a1;
    answers[1]=a2;
    answers[2]=a3;
    answers[3]=a4;
}

void question::shuffle_answers(void)
{
    random_shuffle(answers.begin(),answers.end());
    for(int i=0; i!=4; ++i)
    {
        if(answers[i]==correct)
        {
            correct_nr=i;
            break;
        }
    }
}

bool question::check_answer(char a)
{
    string ans;
    switch(a)
    {
    case 'A':
        ans=answers[0];
        break;
    case 'B':
        ans=answers[1];
        break;
    case 'C':
        ans=answers[2];
        break;
    case 'D':
        ans=answers[3];
        break;
    }
    if(ans==correct)
        return true;
    else
        return false;
}

char question::correct_answer(string& ans)
{
    ans=correct;
    return (65+correct_nr);
}

void question::display_question(DISP_MODE mode, char ans)
{
    int max_wide=0;
    int wide;
    streamsize old_wide;
    for(int i=0;i!=4;++i)
    {
        max_wide=((wide=(answers[i]).length())>max_wide)?wide:max_wide;
    }
    cout<<content<<"\n";
    if (ans=='A')
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    if (mode==check && correct_nr==0)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
    cout<<"A:";
    old_wide=cout.width(max_wide);
    cout<<left<<answers[0]<<"\t";
    cout.width(old_wide);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    if (ans=='B')
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    if (mode==check && correct_nr==1)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
    cout<<"B:";
    old_wide=cout.width(max_wide);
    cout<<answers[1]<<"\t\n";
    cout.width(old_wide);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    if (ans=='C')
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    if (mode==check && correct_nr==2)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
    cout<<"C:";
    old_wide=cout.width(max_wide);
    cout<<answers[2]<<"\t";
    cout.width(old_wide);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    if (ans=='D')
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    if (mode==check && correct_nr==3)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
    cout<<"D:";
    old_wide=cout.width(max_wide);
    cout<<answers[3]<<"\t\n";
    cout.width(old_wide);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout.unsetf(ios_base::adjustfield);
}

void question::fifty_fifty(void)
{
    int bad;
    int used=4;
    bool good=false;
    //srand(time(NULL));
    while(!good)
    {
        bad=rand()%4;
        if(bad!=correct_nr && bad!=used)
        {
            answers[bad]="";
            if(used!=4)
                good=true;
            else
                used=bad;
        }
    }
}

char question::ask_friend(int prop)
{
    int bad[3]={0,0,0};
    int draw[10];
    int k=0;
    int tip;
    //srand(time(NULL));
    if(prop>10)
        prop=10;
    for(int i=0;i!=4;++i)
    {
        if(i!=correct_nr && !(answers[i]).empty())
        {
            bad[k++]=i;
        }
    }
    /*if(k==1)
    {
        bad[1]=bad[0];
        bad[2]=bad[0];
    }*/
    for(int i=0;i!=10;++i)
    {
        draw[i]=(i<prop)?correct_nr:bad[rand()%3];
    }
    tip=draw[rand()%10];
    return (65+tip);
}

void question::ask_audience(int* prc, int prop)
{
    int bad[3]={0,0,0};
    int draw[10];
    int k=0;
    //srand(time(NULL));
    if(prop>10)
        prop=10;
    for(int i=0;i!=4;++i)
    {
        if(i!=correct_nr && !(answers[i]).empty())
        {
            bad[k++]=i;
        }
        prc[i]=0;
    }
    /*if(k==1)
    {
        bad[1]=bad[0];
        bad[2]=bad[0];
    }*/
    for(int i=0;i!=10;++i)
    {
        draw[i]=(i<prop)?correct_nr:bad[rand()%3];
    }
    for(int i=0;i!=100;++i)
    {
        ++prc[draw[rand()%10]];
    }
}

ostream& operator<<(ostream& os,const question& q)
{
    int max_wide=0;
    int wide;
    streamsize old_wide;
    for(int i=0;i!=4;++i)
    {
        max_wide=((wide=(q.answers[i]).length())>max_wide)?wide:max_wide;
    }
    os<<q.content<<"\n";
    os<<"A:";
    old_wide=os.width(max_wide);
    os<<left<<q.answers[0];
    os.width(old_wide);
    os<<"\tB:";
    old_wide=os.width(max_wide);
    os<<q.answers[1]<<"\n";
    os.width(old_wide);
    os<<"C:";
    old_wide=os.width(max_wide);
    os<<q.answers[2];
    os.width(old_wide);
    os<<"\tD:";
    old_wide=os.width(max_wide);
    os<<q.answers[3]<<"\n";
    os.width(old_wide);
    os.unsetf(ios_base::adjustfield);
    return os;
}
