#pragma once
#include <bits/stdc++.h>
#include "Monster.h"
#include "Monster_5.h"
#include "Monster_6.h"
#include "Monster_7.h"

using namespace std;
freshVillage fresh_village;
HANDLE  hConsole_forgivableVillage;
int tempX, tempY;
int tempX1, tempY1;
class forgivableVillage : public Place{
public:
    forgivableVillage(){
        getMessage();
        is_first_come = true;
        is_first_come2 = true;
    }
    //bool judge = true;
    void topicWords(){
        SetConsoleTextAttribute(hConsole_forgivableVillage,2);
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~��ԭ\t��\t�塿~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        cout << "��������һ�����ⰻȻ�Ĵ��ӡ������̫����ɫ�Ĺ�Ը�����ͷ�ϵ�ʥ�⽻���ӳ��С��ñ�����洦�ɼ������Ǹ�������Դ...(?)" << endl;
        getchar();
    }
    void conversation_with_npc(){
        topicWords();
        conversation_with_npc1();
        //conversation_with_npc2();
    }
    void conversation_with_npc1(){//�峤
        //bool jump = true;
        getxy(tempX, tempY);
        if(is_first_come){
            cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
            cout << "\t\t��ӭ����ԭ�´壬���꣬������������£�" << endl;
            getchar();
            while(true){
                getxy(tempX1, tempY1);
                cout << "��1.ѯ����ʷ�� ��2.��ȡ���� ��3.�����ˡ�" << endl;
                cout << "��ѡ��___";
                int tempChoose;
                cin >> tempChoose;
                if(tempChoose == 1){
                    cout << "��ϵͳ��Ϣ���峤�ܾ����㡣" << endl;
                    getchar();getchar();
                    clear_the_conversation(tempX1, tempY1);
                    continue;
                }
                if(tempChoose == 2){//֮��Ҫ���ж��ǲ��ǵ�һ���������ǵ�һ�����Ļ�������û���������
                    cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
                    cout << "\t\t�����������ɣ�ǰҹ���������Ϯ�����ӣ���ȥ�˴���һ��Ĵ����������ǻ̻̲�����" << endl;
                    getchar();
                    cout << "\t\t����������������ͷ���󣬰����������ʮ�����С��ñ��������" << endl;
                    getchar();
                    cout << "��ϵͳ��Ϣ����ȡ���񣺶�ع��峤����ñ" << endl;
                    cout << "��ϵͳ��Ϣ��������������+50�����+150" << endl;
                    getchar();
                    cout << "��ϵͳ��Ϣ���峤�����ӵ��˴����⣬׼��ս����" << endl;
                    getchar();//������ս������
                    clear_the_conversation(tempX, tempY);
                    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
                    cout << "[ϵͳ��Ϣ]�͵�һֻ����ս���ɣ�" << endl;
                    int judge_live_1 = 1;
                    Monster_5 monster_5;
                    monster_5.getMessage();
                    Fight <Monster_5> fight_5;
                    fight_5.fighting(monster_5, judge_live_1);
                    if (judge_live_1 == 0){
                        fresh_village.conversation_with_npc1_npc2();
                    }
                    system("CLS");
                    topicWords();
                    //clear_the_conversation(tempX, tempY);
                    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
                    cout << "[ϵͳ��Ϣ]�͵ڶ�ֻ����ս���ɣ�" << endl;
                    int judge_live_2 = 1;
                    Monster_6 monster_6;
                    monster_6.getMessage();
                    Fight <Monster_6> fight_6;
                    fight_6.fighting(monster_6, judge_live_2);
                    if (judge_live_2 == 0){
                        fresh_village.conversation_with_npc1_npc2();
                    }
                    system("CLS");
                    topicWords();
                    //clear_the_conversation(tempX, tempY);
                    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
                    cout << "[ϵͳ��Ϣ]�͵���ֻ����ս���ɣ�" << endl;
                    int judge_live_3 = 1;
                    Monster_7 monster_7;
                    monster_7.getMessage();
                    Fight <Monster_7> fight_7;
                    fight_7.fighting(monster_7, judge_live_3);
                    if (judge_live_3 == 0){
                        fresh_village.conversation_with_npc1_npc2();
                    }
                    system("CLS");
                    topicWords();
                    //clear_the_conversation(tempX, tempY);
                    if (judge_live_1 & judge_live_2 & judge_live_3){
                        cout << "��ϵͳ��Ϣ�����������Ʒ���͹�γε���ñ." << endl;
                        getchar();
                        cout << "\t��ص����ӽ���ñ�����峤��" << endl;
                        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
                        cout << "\t\tNICEѽ ��ɡ���л�㣬���ꡣ" << endl;
                        getchar();
                        cout << "��ϵͳ��Ϣ��������������+50�����+150" << endl;//���ϻ�õĶ���
                        protagonist.experienceAmount_plus(50);
                        packsack.possession_plus(150);
                        getchar();
                       // jump = false;
                        clear_the_conversation(tempX, tempY);
                        conversation_with_npc2();
                        is_first_come = false;
                        break;
                    }
                    else{
                        break;
                    }
                }
                if(tempChoose == 3){
                    cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
                    cout << "\t\t�����У���ð��ҡ�" << endl;
                    getchar();getchar();
                    clear_the_conversation(tempX, tempY);

                }
                if(tempChoose != 1 && tempChoose != 2 && tempChoose != 3){
                    cout << "С���Ӹ����飿��" << endl;
                    clear_the_conversation(tempX, tempY);
                }
            }
        }
        else{
             while(true){
                cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
                cout << "\t\t��ӭ�ص�ԭ�´壬���꣬������������£�" << endl;
                getchar();
                while(true){
                cout << "��1.ѯ����ʷ�� ��2.��ȡ���� ��3.�����ˡ�" << endl;
                    int tempChoose;
                    cin >> tempChoose;
                    if(tempChoose == 1){
                        cout << "��ϵͳ��Ϣ���峤�ܾ����㡣" << endl;
                        getchar();
                        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
                        cout << "\t\t���İ����꣬���ǲ���˵�ġ�" << endl;

                        getchar();
                        clear_the_conversation(tempX, tempY);
                    }
                    if(tempChoose == 2){//֮��Ҫ���ж��ǲ��ǵ�һ���������ǵ�һ�����Ļ�������û���������
                        cout << "\t" << npc1Name << "(Lv." << npc1Lv << "):" << endl;
                        cout << "\t\t��л�����꣬�������ñ�����ˡ�" << endl;
                        getchar();
                        clear_the_conversation(tempX, tempY);
                    }
                    if(tempChoose == 3){
                        break;
                    }
                    if(tempChoose != 1 && tempChoose != 2 && tempChoose != 3){
                        cout << "С���Ӹ����飿��" << endl;
                        clear_the_conversation(tempX, tempY);
                    }
                }
                break;
            }
        }
    }

    void conversation_with_npc2(){
        cout << "�������ȥ��������ͷ������������" << endl;
        getchar();
        if(is_first_come2){
            cout << "\t" << npc2Name << "(Lv." << npc2Lv << "):" << endl;
            cout << "\t\t���������������������������ء���" << endl;
            getchar();
            int tempChoose;
            while(true){
                cout << "��1.������ñ�� ��2.����һ�١� ��3.��οС���� ��4.�����ˡ�" << endl;
                cin >> tempChoose;
                if(tempChoose == 1){
                    cout << "��ϵͳ��Ϣ����û�����ֶ�����" << endl;
                    getchar();getchar();
                    clear_the_conversation(tempX, tempY);
                }
                if(tempChoose == 2){
                    cout << "\t" << npc2Name << "(Lv." << npc2Lv << "):" << endl;
                    cout << "\t\t�ߣ�����ꡣ" << endl;
                    getchar();
                    cout << "��ϵͳ��Ϣ���㱻С������һ�١�" << endl;
                    getchar();getchar();
                    clear_the_conversation(tempX, tempY);
                }
                if(tempChoose == 3){
                    int allnum = 4;
                    for(allnum = 4; allnum >= 0; allnum--){
                        for(int i = allnum; i >= 0; i--){
                            cout << "����" ;
                        }

                        getchar();
                    }
                    cout << "\t\t�㹶ƨ��ͨ�Ŀ��������¼���С������������飬��������ȫ��ȫ��Ͷ�뵽С��ñ������ҵ��ȥ��" << endl;
                    getchar();
                    cout << "\t" << npc2Name << "(Lv." << npc2Lv << "):" << endl;
                    cout << "\t\t******��" << endl;
                    getchar();
                    cout << "��ϵͳ��Ϣ����ý��������ë�棨�������ֵ+1%��" << endl;//���ϻ�õĶ���
                    //�������Լӳ�
                    protagonist.max_hitPoints_plus(protagonist.show_max_hitPoints() / 100);

                    getchar();
                    cout << "��ϵͳ��Ϣ����óɾͣ����޵Ŀ��ܣ�" << endl;//���ϻ�õĶ���
                    protagonist.add_achievement("���޵Ŀ��ܣ�");
                    getchar();
                    clear_the_conversation(tempX, tempY);
                    break;
                }
                if(tempChoose == 4){
                    break;
                }
            }
            is_first_come2 = false;
        }
        else{
            cout << "\t" << npc2Name << "(Lv." << npc2Lv << "):" << endl;
            cout << "\t\t�ٺٺٺٹ�������������" << endl;
            int tempChoose;
            while(true){
                cout << "��1.������ñ�� ��2.����һ�١� ��3.�����ˡ�" << endl;
                cin >> tempChoose;
                if(tempChoose == 1){
                    cout << "��ϵͳ��Ϣ����û�����ֶ�����" << endl;
                    getchar();
                    clear_the_conversation(tempX, tempY);
                }
                if(tempChoose == 2){
                    cout << "\t" << npc2Name << "(Lv." << npc2Lv << "):" << endl;
                    cout << "\t\t�ߣ�����ꡣ" << endl;
                    getchar();
                    cout << "��ϵͳ��Ϣ���㱻С������һ�١�" << endl;
                    getchar();
                    clear_the_conversation(tempX, tempY);
                }
                if(tempChoose == 3){
                    break;
                }
            }
        }

    }
    void getMessage(){
        ifstream file;
        file.open("forgivableVillage_npc1.txt", ios_base :: in);
        if (file){
            file >> npc1Name;
            file >> npc1Lv;
        }
        file.close();
        file.open("forgivableVillage_npc2.txt", ios_base :: in);
        if (file){
            file >> npc2Name;
            file >> npc2Lv;
        }
        file.close();
    }
private:
    bool is_first_come;
    bool is_first_come2;
    string npc1Name;
    int npc1Lv;
    string npc2Name;
    int npc2Lv;

};

