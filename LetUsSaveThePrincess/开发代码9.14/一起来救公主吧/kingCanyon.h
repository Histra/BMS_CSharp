#pragma once
#include "Monster.h"
#include "Monster_2.h"
HANDLE  hConsole_kingCanyon;
class kingCanyon : public Place{
public:
    kingCanyon(){
        getMessage();
    }
    void conversation_with_npc(){
        hConsole_kingCanyon = GetStdHandle(STD_OUTPUT_HANDLE);//������ɫ
        SetConsoleTextAttribute(hConsole_kingCanyon,2);
        cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~��ũ\tҩ\tϿ\t�ȡ�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        int tempX, tempY;
        getxy(tempX, tempY);

        SetConsoleTextAttribute(hConsole_kingCanyon,11);
        //Sleep(1000);
        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
        cout << "\t\t���ʲô��˼��?�����������У�" << endl;
        char tempChar;
        getchar();
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
        cout << "\t\tС......С�� ���������ðɣ���������ֳ���ٵĹ�����" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);
        cout << "\t" << npc1Name << "(Lv." << npc1Lv  << "):" << endl;
        cout <<"\t\t�Ǻǣ�������Ц������Զ�������Ŀ��ˣ�Ҫ����槼���ˣô"<<endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
        cout << "\t\t ��һ����������ð��ð�" << endl;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);
        cout << "\t" << npc1Name << "(Lv." << npc1Lv  << "):" << endl;
        cout << "\t\t���Ǻ�����ˣ���˱����ǽ�̤�߲����Ƶĸ���Ӣ�ۣ���Ը�����槼��Ŀ���ô?" <<endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t��......�⣨�е���ԥ��" ;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);
        cout << "\t" << npc1Name << "(Lv." << npc1Lv  << "):" << endl;
        cout << "\t\t���ͨ����Ӣ�۵Ŀ��飬槼��������һ��������" <<endl;
        cout << "[ϵͳ��Ϣ]�����������ɻ�ã�"<<endl;
        cout << "\t����⾫��";
        cout << "\t�ƺţ���������"<<endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t��һ��������˷��Ľ�����������ԥ�Ĵ�Ӧ������no problem" ;
        tempChar = getchar();
        clear_the_conversation(tempX, tempY);
        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
        cout <<"\t\t���ˣ�ȥͨ��������Ӣ�۵������---ũҩϿ�Ȱ�" <<endl;
        tempChar = getchar();
        cout << "\t������(Lv." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t��С�����������Ͽ��֮�У���֪��ǰ���ж�Σ�գ�����槼���Ϊ���飩" ;
        tempChar = getchar();
        SetConsoleTextAttribute(hConsole_kingCanyon,10);
        cout << "[1.����]\n";
        cout << "��ѡ��______";
        int tempChoose;
        cin >> tempChoose;
        if (tempChoose == 1){
            int judge_live = 1;
            Monster_2 monster_2;
            monster_2.getMessage();
            Fight <Monster_2> fight;
            fight.fighting(monster_2, judge_live);
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
        cout << "\t" << npc1Name << "(Lv." << npc1Lv  << "):" << endl;
        cout <<"\t\t���ˣ��ҹ�Ȼû�п����㣬����槼���ˣ��"<<endl;
        cout <<"[ϵͳ��Ϣ]��ϲ�����:����buff �� ��ͨ���� + 1"<<endl;
        protagonist.strength_plus(1);
       // protagonist.add_achievement("��������");
        cout << "[ϵͳ��Ϣ]�������߾������е����������þ���+60�� ���+250" << endl;
        protagonist.experienceAmount_plus(60);
        packsack.possession_plus(250);
        getchar();
    }
    void getMessage(){
        //freshVillage_state = 1;
        ifstream file;
        file.open("kingCanyon_npc3.txt", ios_base :: in);
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
