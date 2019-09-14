#pragma once
#include <bits/stdc++.h>
#include "Monster.h"
#include "Monster_3.h"
using namespace std;
HANDLE  hConsole_Camelot;
class Camelot : public Place{
public:
    Camelot(){
        getMessage();
    }
    void conversation_with_npc(){
        hConsole_Camelot = GetStdHandle(STD_OUTPUT_HANDLE);//������ɫ
        SetConsoleTextAttribute(hConsole_Camelot,2);
        cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~����\tɪ\t��\t��\t�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        int tempX, tempY;
        getxy(tempX, tempY);
        char tempChar;
        SetConsoleTextAttribute(hConsole_Camelot,11);
        //Sleep(1000);
        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
        cout << "\t\t���ǡ�����������ԭ�´�������սʿ��" << endl;
        getchar();
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
        cout << "\t\t�ǣ����������ﵽ�׷�����ʲô��?" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);
        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
        cout << "\t\t�ұ����ػ�������ʮ���������˭֪����ǰ��Ȼ����һ��а�����ʦ," << endl;
        cout << "\t\t������ɢ���������ߣ������㿴���ģ�Ӣ�۵Ĺ����Ѿ������һƬ���ţ�" << endl;
        cout << "\t\t���Ѿ�˥�ϲ��Ҹ�Ⱦ�������ߣ���ɷ���Ϸ�һ��æ?"<<endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
        cout << "\t\t���˼ң�������Ǻ��������������...������ֻ��һ��С���" << endl;
        cout << "\t\t��ô�ܶ��ù��Ǹ�а�����ʦ�أ�û�кô���������㣩" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);
        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
        cout << "\t\t�����ˣ��ҿ���������㣬����һ�����ܣ�" << endl;
        cout << "\t\t��Ȼ�ܹ������һָ��⹬����������꣬" << endl;
        cout << "\t\t��ɺ�ؽ����Ϸ��ı��꣬��������ʦ°����һ���Ĺ�����" << endl;
        cout << "\t\t�������ò�Ż�����Ȼ�ܹ��������˹�ѽ���㿴���"<<endl;
        cout << "[ϵͳ��Ϣ]��������"<<endl;
        ///*******************************
        cout <<"\t\t��ң�300"<<endl;
        cout <<"\t\t���飺100"<<endl;
        ///**********************************
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t��......�ðɣ�����а���������壬��������Ӧ�������Ҵ�Ӧ��������" << endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t��˵�꣬������������������ɭ�Ĺ��" << endl ;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);
        SetConsoleTextAttribute(hConsole_Camelot,10);
        cout << "[1.����]\t[2.����]\t[3.Ͷ��]\n";
        cout << "��ѡ��______";
        int tempChoose;
        cin >> tempChoose;
        if (tempChoose == 1){
            int judge_live = 1;
            Monster_3 monster_3;
            monster_3.getMessage();
            Fight <Monster_3> fight;
            fight.fighting(monster_3,judge_live);
            if (judge_live == 0){
                fresh_village.conversation_with_npc1_npc2();
            }
        }
        if (tempChoose == 2){
            cout << "[ϵͳ��Ϣ]��ϲ�㹷�����ɹ����ܣ��������ܵñ����ӻ��찡��" << endl;
            getchar();
            char tempChar;
            tempChar= getchar();
            system("CLS");
            //print_menu();
        }
        if (tempChoose == 3){
            cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ��˵�һB" << endl;
            protagonist.add_achievement("�˵�һB");
            getchar();
            char tempChar;
            tempChar= getchar();
        }
    //ս������
        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
        cout << "\t\t������Ȼ�ھ����£��ɹ��ָ��˹����ƽ�����꣬��Щ����Ӧ�õĽ�����"<<endl;
        cout << "[ϵͳ��Ϣ]��ϲ����ã����+300������+100"<<endl;
        packsack.possession_plus(300);
        protagonist.experienceAmount_plus(100);

    }
    void getMessage(){
        //freshVillage_state = 1;
        ifstream file;
        file.open("Camelot_npc2.txt", ios_base :: in);
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
