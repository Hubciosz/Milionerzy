#include "game.h"

void game::init(data& dat)
{
    contest_questions.erase(contest_questions.begin(),contest_questions.end());
    dat.copy_questions(contest_questions);
    for(int i=0; i!=13; ++i)
    {
        switch(i)
        {
        case 0:
            money[i]=0;
            break;
        case 1:
            money[i]=500;
            break;
        case 4:
            money[i]=5000;
            break;
        case 8:
            money[i]=75000;
            break;
        case 9:
            money[i]=125000;
            break;
        default:
            money[i]=2*money[i-1];
        }
    }
    quest_number=0;
    award=0;
    audience=true;
    fifty_fifty=true;
    phone=true;
}

void game::next_question(ostream& os)
{
    contest_questions[quest_number].shuffle_answers();
    os<<"Pytanie za "<<money[quest_number+1]<<"zˆ:\n";
    os<<contest_questions[quest_number];
}

bool game::check_answer(char ans, char& corr_ans, string& answer)
{
    bool result;
    corr_ans=(contest_questions[quest_number]).correct_answer(answer);
    result=(contest_questions[quest_number]).check_answer(ans);
    if(result)
    {
        if(quest_number==1 || quest_number==6 || quest_number==11)
            award=money[quest_number+1];
        ++quest_number;
    }
    return result;
}

void game::lifelines(ostream& os, HELP hp)
{
    int audience_prc[4]={0,0,0,0};
    char friend_ans;
    int prob;
    if(quest_number<=1)
    {
        prob=9;
    }
    else if(quest_number>=9)
    {
        prob=1;
    }
    else
    {
        prob=10-quest_number;
    }
    if(hp==aud)
    {
        (contest_questions[quest_number]).ask_audience(audience_prc,prob);
        os<<"Wyniki gˆosowania publiczno˜ci:\n";
        os<<"A: "<<audience_prc[0]<<"%\nB: "<<audience_prc[1]<<"%\nC: "<<audience_prc[2]<<"%\nD: "<<audience_prc[3]<<"%\n";
        audience=false;
    }
    else if(hp==fif)
    {
        (contest_questions[quest_number]).fifty_fifty();
        fifty_fifty=false;
        os<<contest_questions[quest_number];
    }
    else if(hp==pho)
    {
        friend_ans=(contest_questions[quest_number]).ask_friend(prob);
        os<<"Moim zdaniem prawidˆowa odpowied« to: "<<friend_ans<<"\n";
        phone=false;
    }
}

void game::question_menu(ostream& os)
{
    os<<"\nJaka jest Twoja decyzja?\n";
    os<<"0: Udzielam odpowiedzi\n";
    os<<"1: Rezygnuj© z dalszej gry\n";
    if(audience)
        os<<"2: Poprosz© publiczno˜† o pomoc\n";
    if(fifty_fifty)
        os<<"3: Wezm© p¢ˆ na p¢ˆ\n";
    if(phone)
        os<<"4: Chciaˆbym zadzwoni† do mojego przyjaciela\n";
}

void game::start_menu(ostream& os)
{
    os<<"MENU:\n";
    os<<"0: Rozpocznij gr©!\n";
    os<<"1: Wyj˜cie z programu.\n";
}

void game::display_question(DISP_MODE mode, char ans)
{
    (contest_questions[quest_number]).display_question(mode,ans);
}
