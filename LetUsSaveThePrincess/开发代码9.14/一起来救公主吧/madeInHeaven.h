#pragma once
#include <bits/stdc++.h>
#include "Monster.h"
#include "Monster_4.h"
//freshVillage fresh_village;
using namespace std;
HANDLE  hConsole_madeTnHeaven;
class madeInHeaven : public Place{
public:
    madeInHeaven(){
        getMessage();
    }
    void conversation_with_npc(){
        hConsole_madeTnHeaven = GetStdHandle(STD_OUTPUT_HANDLE);//������ɫ
        SetConsoleTextAttribute(hConsole_madeTnHeaven,2);
        cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~����\t��\t��\t�䡿~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        char tempChar;
        int tempX, tempY;
        getxy(tempX, tempY);
        SetConsoleTextAttribute(hConsole_madeTnHeaven,11);
        //Sleep(1000);
        cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
        cout << "\t\t��ô���ľ�ɫѽ�������ѵ����ɾ�ô?����˵���ߣ�ͻȻǰ������һ��¥��" << endl;
        getchar();
        tempChar = getchar();
        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
        cout << "\t\t��λ����Ҫ������һ����!" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);
        cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
        cout << "\t\t��һ�����Σ���...�����������ɬ" << endl;
        tempChar = getchar();
        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
        cout << "\t\t�������Ц��������׬Ǯ�ĵط��кܶ࣬�ҽ���һ������� "<< endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);
        cout << "\t������(Lv." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t�Ǿ��ͷ����ˣ�ϲ�������Ա�" ;
        tempChar = getchar();
        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
        cout << "\t\t��ǰ��Ĳ�Զ��������׬�ô�����ҵĵط�����λ���˸Ͽ�ȥ�ɣ���Ҫ���ǻ�����"<< endl;
        cout << "[ϵͳ��Ϣ]����������ң�300" << endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t�����꣬�Ȳ������Ĵ����Լ��ĳ���ɱ���ȥ��" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);
        cout << "��ͻȻ�������һֻ�޴��ޱȵĹ������....(����ٸ�һ��,���ϱ�����Ⱦ)��" << endl;
        int judge_live = 1;
        Monster_4 monster_4;
        monster_4.getMessage();
        Fight <Monster_4> fight;
        fight.fighting(monster_4, judge_live);
        if (judge_live == 0){
            fresh_village.conversation_with_npc1_npc2();
        }
        else {
            cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
            cout <<"��ϲ�㣬������������񡾻��Ż�����"<<endl;
            cout <<"[1.�����ɾ�]\t2.[�뿪�ɾ�]\n";
            cout <<"��ѡ��_____";
            int tempChoose;
            cin >> tempChoose;
            if (tempChoose == 1){
                cout <<"[ϵͳ��Ϣ]��ɫ�Ĺ������۳�200���"<<endl;
                packsack.possession_decline(200);
            }

            if (tempChoose == 2){
                cout <<"[ϵͳ��Ϣ]��ֱ�Ĺ��������������300���"<<endl;
                packsack.possession_plus(300);
            }

            getchar();getchar();
        }

    }
    void getMessage(){
        //freshVillage_state = 1;
        ifstream file;
        file.open("madeInHeaven_npc1.txt", ios_base :: in);
        if (file){
            file >> npc1Name;
            file >> npc1Lv;
        }
        file.close();

    }
private:
    string npc1Name;
    int npc1Lv;
};
