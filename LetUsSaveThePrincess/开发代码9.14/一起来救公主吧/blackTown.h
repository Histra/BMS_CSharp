#pragma once
#include <bits/stdc++.h>
#include "Protagonist.h"
#include "Monster.h"
#include "Monster_8.h"
#include "Fight.h"

HANDLE  hConsole_blackTown;
//Protagonist protagonist_blackTown;

class blackTown : public Place{
public:
    blackTown(){
        getMessage();
    }
    void conversation_with_npc(){

        hConsole_blackTown = GetStdHandle(STD_OUTPUT_HANDLE);//������ɫ
        SetConsoleTextAttribute(hConsole_blackTown,4);
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~����ɫ����~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        int tempX, tempY;
        char tempChar;
        cout << "����߽���ɫ����ֻ��һƬ��ڵķ��ݺͽֵ���ȴ��˸�Ż����͵���ɫ��" << endl;
        tempChar = getchar();
        tempChar = getchar();

        SetConsoleTextAttribute(hConsole_blackTown,5);
        getxy(tempX, tempY);
        cout << "\t" << blackTown_npc_name << "(Lv." << blackTown_npc_lv << "):" << endl;
        cout << "\t\tֻҪ998��Сñ���ؼ�! ǰ���ɧ�꣬��������ȱ�̣�����Сñ��!" << endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << ")��" << endl;
        cout << "\t\t��Ҫ������Ҫ�����ȹ��������ˣ�" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);

        SetConsoleTextAttribute(hConsole_blackTown,9);
        cout << "\t" << blackTown_npc_name << "(Lv." << blackTown_npc_lv << "):" << endl;
        cout << "\t\t����һ��æ���Ҿ͸����㹫�������䣡                           " << endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << ")��" << endl;
        cout << "\t\t����𣿱��۸���������١�" << endl;
        tempChar = getchar();
        cout << "\t" << blackTown_npc_name << "(Lv." << blackTown_npc_lv << "):" << endl;
        cout << "\t\t������һ�ԣ��ǿ���������׷��" << endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << ")��" << endl;
        cout << "\t\t�ɽ���" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);

        SetConsoleTextAttribute(hConsole_blackTown,6);
        cout << "\t" << blackTown_npc_name << "(Lv." << blackTown_npc_lv << "):" << endl;
        cout << "\t\t�����ɫ�����ﳤ��һ��������ñ�Ĳݣ�������ɫ֭Һ���ݹ���ñ��������ɫ������Ҳɼ��ꡣ" << endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << ")��" << endl;
        cout << "\t\t�Ե�Ƭ�̣��ҿ��¼��ܡ�" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);

        SetConsoleTextAttribute(hConsole_blackTown,7);
        cout << "\t" << blackTown_npc_name << "(Lv." << blackTown_npc_lv << "):" << endl;
        cout << "\t\t����ɧ�꣬������ħ�￴�صģ���������һ���ʻ������Ӵ!                               " << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);

        SetConsoleTextAttribute(hConsole_blackTown,14);
        cout << endl;
        cout << "��һ����ɫ����������Ʈ����������ԭ�µ���Ϣ��                                            "<< endl;
        tempChar = getchar();
        cout << "\t" << blackTown_monster_name << "(LV." << blackTown_monster_lv << "):" << endl;
        cout << "\t\t��Ҳ�������ҵ�ԭ�²ݵ��𣿺ǣ����ˣ�" << endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << ")��" << endl;
        cout << "\t\t�ף���ô����ħ����˰˱���Ѫù�ˣ�" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);

        SetConsoleTextAttribute(hConsole_blackTown,10);
        cout << "[1.����]\t[2.����]\n";
        cout << "��ѡ��______";
        getxy(tempX, tempY);
        int choose;
        cin >> choose;
        if (choose == 1){
            int judge_live = 1;
            Monster_8 monster_8;
            monster_8.getMessage();
            Fight <Monster_8> fight;
            fight.fighting(monster_8, judge_live);
            if (judge_live == 0){
                fresh_village.conversation_with_npc1_npc2();
            }
            else{
                SetConsoleTextAttribute(hConsole_blackTown,7);
                cout << "\t" << blackTown_npc_name << "(Lv." << blackTown_npc_lv << "):" << endl;
                cout << "\t\t" << "��Ү���㾹Ȼ���Ż����ˣ�Ҳ�գ�������ץ�����ߵ����֮���ˣ���������ǵ���һ���Ĵ��ڣ�" << endl;
                tempChar = getchar();
                cout << "[ϵͳ��Ϣ]�����������+250�𣬾���+100" << endl;
                packsack.possession_plus(250);
                protagonist.experienceAmount_plus(100);
                cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ�����������QQ����" << endl;
                protagonist.add_achievement("����������QQ����");
                tempChar = getchar();
                tempChar = getchar();
                clear_the_conversation(tempX, tempY);
            }
        }
        if (choose == 2){
                cout << "[ϵͳ��Ϣ]��ϲ�㹷�����ɹ����ܣ��������ܵñ����ӻ��찡��" << endl;
                tempChar = getchar();
                tempChar= getchar();
                system("CLS");
        }


        /* ֻҪսʤħ�����������񣬲��ṩ������Ϣ
        SetConsoleTextAttribute(hConsole_blackTown,7);
        cout << "\t" << blackTown_npc_name << "(Lv." << blackTown_npc_lv << "):" << endl;
        cout << "\t\t" << "��Ү���㾹Ȼ���Ż����ˣ�Ҳ�գ�������ץ�����ߵ����֮���ˣ���������ǵ���һ���Ĵ��ڣ�" << endl;*/




    }
    void getMessage(){
        ifstream file;
        file.open("blackTown_npc_monster.txt", ios_base :: in);
        if (file){
            file >> blackTown_npc_name;
            file >> blackTown_npc_lv;
            file >> blackTown_monster_name;
            file >> blackTown_monster_lv;
        }
        file.close();
    }
private:
    string blackTown_npc_name;
    int blackTown_npc_lv;
    string blackTown_monster_name;
    int blackTown_monster_lv;
};
