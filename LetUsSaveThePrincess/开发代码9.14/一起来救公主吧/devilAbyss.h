#pragma once
#include <bits/stdc++.h>
#include "Protagonist.h"
#include "Store.h"  //Store.h�ﶨ����һ��packsack����
#include "freshVillage.h"
using namespace std;
HANDLE  hConsole_devilAbyss;
//Protagonist protagonist_devilAbyss;

class devilAbyss : public Place{
public:
    devilAbyss (){
        getMessage();
    }
    void conversation_with_npc(){
        hConsole_devilAbyss = GetStdHandle(STD_OUTPUT_HANDLE);//������ɫ
        SetConsoleTextAttribute(hConsole_devilAbyss, 4);
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~����ħ֮Ԩ��~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        int tempX, tempY;
        char tempChar;
        cout << "Զʼ֮ս������ ħ��һֱ�ھӴ˵ء���ľͻأ��������գ�ѻ���϶���������Ⱦ�Ÿ����벻�ꡣ" << endl;
        tempChar = getchar();
        tempChar = getchar();
        getxy(tempX, tempY);

        SetConsoleTextAttribute(hConsole_devilAbyss,5);
        cout << "\t������(LV." << protagonist.showLevel() << ")��" << endl;
        cout << "\t\t" << "��Ү���������ɭ��һ����Ҳû����" << endl;
        tempChar = getchar();
        cout << "\t" << devilAbyss_npc_name << "(Lv." << devilAbyss_npc_lv << "):" << endl;
        cout << "\t\t" << "�þ�û�ŵ����˵���Ϣ�ˣ�����Ҫ�Ӳ��!" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);

        SetConsoleTextAttribute(hConsole_devilAbyss, 6);
        cout << "\t������(LV." << protagonist.showLevel() << ")��" << endl;
        cout << "\t\t" << "˭��˭���ģ����ֳ�������" << endl;
        tempChar = getchar();
        cout << "[һ������ɫ������Ʈ��]" << endl;
        tempChar = getchar();
        cout << "\t" << devilAbyss_npc_name << "(Lv." << devilAbyss_npc_lv << "):" << endl;
        cout << "\t\t" << "����������Ԩ��ʱ����ԨҲ�������㡣����,��������Ԩ��" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);

        SetConsoleTextAttribute(hConsole_devilAbyss, 10);
        cout << "[������ͻȻ����һ����ͷ��������]" << endl;
        tempChar = getchar();
        cout << "\t" << devilAbyss_npc_name << "(Lv." << devilAbyss_npc_lv << "):" << endl;
        cout << "\t\t" << "��ȥ��˭�ӵ����㽶Ƥ��ˤ������!" << endl;
        tempChar = getchar();
        cout << "\t������(LV." << protagonist.showLevel() << ")��" << endl;
        cout << "\t\t" << "������Ц���Һü̳��ҵĲƲ����һ���Ϊ��ħ���أ�û�뵽�Ǹ����ȣ�" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);

        SetConsoleTextAttribute(hConsole_devilAbyss, 9);
        cout << "\t" << devilAbyss_npc_name << "(Lv." << devilAbyss_npc_lv << "):" << endl;
        cout << "\t\t" << "����㣡��·���ҿ������������ԣ�Ҫ���·����������·�ƣ�һ�ڼ�250��" << endl;
        tempChar = getchar();
        cout << "1.����������   2.���ɷ��������죬   3.��ʮ������Ϊ��" << endl;
        cout << "��ѡ��_______";
        int choose;
        getxy(tempX, tempY);
        while (true){
             cin >> choose;
             if (choose == 1){
                    SetConsoleTextAttribute(hConsole_devilAbyss, 14);
                    cout << "\t" << devilAbyss_npc_name << "(Lv." << devilAbyss_npc_lv << "):" << endl;
                    cout << "\t\t" << "�й����������������ӣ�" << endl;
                    tempChar = getchar();
                    packsack.possession_decline(packsack.getPossession()); //����ӵĺ������ڱ���ͷ�ļ���
                    protagonist.hitPoints_decline(protagonist.show_current_hitPoints() - 1);
                    cout << "[ϵͳ��Ϣ]���Ǯ���ѿգ���ǰ����ֵ��Ϊ1��" << endl;
                    tempChar = getchar();
                    cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ����һB" << endl;
                    protagonist.add_achievement("���һB");
                    tempChar= getchar();
                    clear_the_conversation(tempX, tempY);
                    break;
             }
             if (choose == 2){
                    SetConsoleTextAttribute(hConsole_devilAbyss, 10);
                    cout << "\t������(LV." << protagonist.showLevel() << ")������ұƸ磬�˺�ɧ���ࡣ�Ҹ���" << endl;
                    tempChar = getchar();
                    packsack.possession_decline(250);
                    cout << "\t" << devilAbyss_npc_name << "(Lv." << devilAbyss_npc_lv << "):" << endl;
                    cout << "\t\t" << "��Ͷ���������ӣ���Ҫ���ҳ��֣�" << endl;
                    tempChar = getchar();
                    cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ��˵�һB" << endl;
                    protagonist.add_achievement("�˵�һB");
                    tempChar= getchar();
                    clear_the_conversation(tempX, tempY);
                    break;
             }
             if (choose == 3){
                    SetConsoleTextAttribute(hConsole_devilAbyss, 7);
                    cout << "\t" << devilAbyss_npc_name << "(Lv." << devilAbyss_npc_lv << "):" << endl;
                    cout << "\t\t" << "MMP�����ܣ����Ȳ���Ҫ���ǰɣ�" << endl;
                    tempChar = getchar();
                    cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ������ȵĶ�����" << endl;
                    protagonist.add_achievement("�����ȵĶ�����");
                    tempChar = getchar();
                    clear_the_conversation(tempX, tempY);
             }
             if (choose >= 4){
                    SetConsoleTextAttribute(hConsole_devilAbyss, 13);
                    cout << "[ϵͳ��Ϣ]�ǲ������������ѡ����" << endl;
                    tempChar = getchar();
                    cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ�Ϲ�˹���" << endl;
                    tempChar = getchar();
                    clear_the_conversation(tempX, tempY);
             }
        }

    }
    void getMessage(){
        ifstream file;
        file.open("devilAbyss_npc.txt", ios_base :: in);
        if (file){
            file >> devilAbyss_npc_name;
            file >> devilAbyss_npc_lv;

        }
        file.close();
    }
private:
    string devilAbyss_npc_name;
    int devilAbyss_npc_lv;
};
