#pragma once
#include <bits/stdc++.h>
#include "Protagonist.h"
#include "Monster.h"
#include "Monster_1.h"
#include "Fight.h"
using namespace std;
//Fight fight;
void gotoxy(int x, int y){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(hOut, c);
}
void getxy(int &x, int &y){
    HANDLE gh_std_out;
    gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    GetConsoleScreenBufferInfo(gh_std_out,&bInfo);
    x = bInfo.dwCursorPosition.X;
    y = bInfo.dwCursorPosition.Y;
}
void clear_the_conversation(int tempX, int tempY){
    gotoxy(tempX, tempY);
    for (int i = 1; i <= 16; i ++){
        for (int j = 1; j <= 100; j ++)
            cout << "   ";
        cout << endl;
    }
    gotoxy(tempX, tempY);
}
HANDLE  hConsole_freshVillage;
//Protagonist protagonist;
class freshVillage{
public:
    void conversation_with_npc1_npc2(){
        hConsole_freshVillage = GetStdHandle(STD_OUTPUT_HANDLE);//������ɫ
        SetConsoleTextAttribute(hConsole_freshVillage,2);
        cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~����\t��\t�塿~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        int tempX, tempY;
        char tempChar;
        cout << "���������ִ�Ĵ�·�ϣ�������⣬�о��Լ�һ���ܹ��ȳ����������������۷�!" << endl;
        tempChar = getchar();
        SetConsoleTextAttribute(hConsole_freshVillage,3);
        getxy(tempX, tempY);
        cout << "ͻȻ��һλ����Ů�ӳ����ڴ�·�ϣ�����毺ã�����ݰף�����ˮ�ַ���" << endl;
        SetConsoleTextAttribute(hConsole_freshVillage,11);
        //Sleep(1000);
        cout << "\tNPC(Lv." << npc1Lv << "):" << endl;
        cout << "\t\t���ã�����������ӭ����<<һ�����ȹ�����>>~~" << endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << ")[����һ�ڿ�ˮ]:\t������λ����ķ�����" << endl;
        tempChar = getchar();
        //
        clear_the_conversation(tempX, tempY);
        //
        cout << "\tNPC(Lv." << npc1Lv << "):" << endl;
        cout << "\t\tСŮ������" << npc1Name << endl;
        tempChar = getchar();
        cout << "\tNPC(Lv." << npc1Lv << "):" << endl;
        cout << "\t\t���������ִ壬Ϊ��ά��ȫ����ƽ�����Ǹ������޵������һ˧�Ŀ������ص�����������������ܸ߼���ҵ��۸���" << endl;
        tempChar = getchar();

        clear_the_conversation(tempX, tempY);

        cout << "\t������(Lv." << protagonist.showLevel() << "): �Ǻ�" << endl;
        tempChar = getchar();

        clear_the_conversation(tempX, tempY);

        cout << "��ͻȻһ�ѷɽ�������" << npc1Name << "," << npc1Name << "˲��ҵ������Ŵ���һ���Ц��.....��"  << endl;
        tempChar = getchar();
        cout << "\t" << npc2Name << "(Lv." << npc2Lv << "):" << endl;
        cout << "\t\t��������~������ң���ƾ����С���ӣ�" << endl;
        tempChar = getchar();

        clear_the_conversation(tempX, tempY);

        cout << "��ֻ��һ�źڷ�ҹ���һֻ�޴��ޱȵĹ�����֡�" << endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t.....��ô��ʹ�boss����ʲô������Ȼ��������������һ������һ��ս���ɣ���������ΪʲôҪ˵������ˣ���" ;
        tempChar = getchar();

        //clear_the_conversation(tempX, tempY);
        SetConsoleTextAttribute(hConsole_freshVillage,10);
        cout << "[1.����]\t[2.����]\t[3.Ͷ��]\t[4.��������]\n";
        cout << "��ѡ��______";
        int tempChoose;
        cin >> tempChoose;
        if (tempChoose == 1){
            int judge_live = 1;
            Monster_1 monster_1;
            monster_1.getMessage();
            Fight <Monster_1> fight;
            fight.fighting(monster_1, judge_live);
            if (judge_live == 0){
                conversation_with_npc1_npc2();
            }
        }
        if (tempChoose == 2){
            cout << "[ϵͳ��Ϣ]��ϲ�㹷�����ɹ����ܣ��������ܵñ����ӻ��찡��" << endl;
            cout << "[ϵͳ��Ϣ]������������ѡ�������ܣ�" << npc2Name << "ռ�������ִ壬���ӳ���������ӡ�" << endl;
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
        if (tempChoose == 4){
            cout << "[ϵͳ��Ϣ]�����������롰�ְ֡���ȷ������" << npc2Name << "�ĸ��ӹ�ϵ." << endl;
            string name_baba;
            while (true){
                cin >> name_baba;
                if (name_baba == "�ְ�"){
                    cout << "��" << "��ϲ�㣬�������ɹ���Ϊ" << npc2Name <<"�Ķ��ӣ�ʵ�������������Ը,����" << npc2Name << "������ֹ,��ˮ��������" << endl;
                    Sleep(500);
                    cout << "[ϵͳ��Ϣ]��ϲ��ͨ���˿��飡" << endl;
                    break;
                }
                else{
                    cout << "[ϵͳ��Ϣ]�Ҿ�������Ĳ���,���������룺" << endl;
                }
            }

        }


    }
    void printInfo(){
      //  cout << npc1Name << endl;
      //  cout << npc1Lv << endl;
    }
    void getMessage(){
        //freshVillage_state = 1;
        ifstream file;
        file.open("npc1.txt", ios_base :: in);
        if (file){
            file >> npc1Name;
            file >> npc1Lv;
        }
        file.close();
        file.open("npc2.txt", ios_base :: in);
        if (file){
            file >> npc2Name;
            file >> npc2Lv;
        }
        file.close();
    }
private:
    string npc1Name;
    int npc1Lv;
    string npc2Name;
    int npc2Lv;

    //int freshVillage_state;//1.���ţ�2.��ռ��
};


