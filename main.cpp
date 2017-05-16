#include <iostream>
#include "question.h"
#include "data.h"
#include "game.h"
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    srand(time(NULL));
    char answer;
    bool cor;
    bool bad_choice=false;
    bool bad_ans=false;
    bool help_used;
    char cor_ans;
    int decision;
    char again;
    HELP hp;
    string correct;
    game contest;
    data base;
    do
    {
        if(cin.fail())
        {
            cin.clear();
            cin.get();
            system("cls");
        }
        cout<<"Witaj w grze Milionerzy!\n";
        contest.start_menu(cout);
        cout<<"Wyb¢r: ";
        cin>>decision;
    }while(decision>1 || cin.fail());
    if(!decision)
    {
        base.read_data();
        do
        {
            base.shuffle_data();
            contest.init(base);
            do
            {
                system("cls");
                contest.next_question(cout);
                do
                {
                    help_used=false;
                    do
                    {
                        if(bad_choice || cin.fail())
                        {
                            cout<<"Obawiam si©, ¾e tego nie mo¾esz zrobi†\n";
                            if(cin.fail())
                            {
                                cin.clear();
                                cin.get();
                            }
                        }
                        contest.question_menu(cout);
                        cout<<"Decyzja: ";
                        if(cin>>decision)
                        {
                            bad_choice=false;
                            switch(decision)
                            {
                            case 0:
                                do
                                {
                                    if(cin.fail() || bad_ans)
                                    {
                                        if(cin.fail())
                                        {
                                            cin.clear();
                                            cin.get();
                                        }
                                        cout<<"Niestety, tej odpowiedzi nie ma dost©pnej.\n";
                                    }
                                    bad_ans=false;
                                    cout<<"Odpowied«: ";
                                    cin>>answer;
                                    if(!((answer>='A' && answer<='D')||(answer>='a' && answer<='d')))
                                        bad_ans=true;
                                }while(cin.fail()||bad_ans);
                                break;
                            case 1:
                                break;
                            case 2:
                                hp=aud;
                                break;
                            case 3:
                                hp=fif;
                                break;
                            case 4:
                                hp=pho;
                                break;
                            default:
                                bad_choice=true;
                            }
                        }
                    }while(bad_choice || cin.fail());
                    if(decision>=2 && decision<=4)
                    {
                        contest.lifelines(cout,hp);
                        help_used=true;
                    }
                }while(help_used);
                if(decision==0)
                {
                    if(answer>'D')
                        answer-=32;
                    system("cls");
                    cout<<"Zaznaczam odpowied« "<<answer<<"..."<<"\n";
                    contest.display_question(mark,answer);
                    cout<<"\n";
                    system("pause");
                    system("cls");
                    cout<<"\n";
                    contest.display_question(check,answer);
                    cor=contest.check_answer(answer,cor_ans,correct);
                    if(cor)
                    {
                        cout<<"\nTak, to jest poprawna odpowied«! Gratulacje!\n\n";
                        system("pause");
                    }
                    else
                        cout<<"\nNiestety, przykro mi...\n";
                }
                else
                {
                    answer='E';
                    cor=contest.check_answer(answer,cor_ans,correct);
                    cor=0;
                }
            }while(cor && contest.which_question()!=12);
            if(!cor)
            {
                cout<<"Poprawn¥ odpowiedzi¥ jest "<<cor_ans<<": "<<correct<<".\n";
            }
            cout<<"\nTwoja wygrana to: "<<contest.get_award()<<"zˆ\n";
            do
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.get();
                    system("cls");
                }
                cout<<"Czy chcesz zagra† jeszcze raz (T/N)?: ";
                cin>>again;
            }while(cin.fail());
        }while(again=='T' || again=='t');
    }
    cout<<"Dzi©ki za wsp¢ln¥ zabaw©!\n\n";
    system("pause");
    return 0;
}
