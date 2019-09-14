#pragma once
#include <bits/stdc++.h>
#include "Protagonist.h"
#include "Monster.h"
#include "Monster_7.h"
#include "Monster_9.h"
#include "Monster_10.h"
using namespace std;

HANDLE  hConsole_BOSShome;
class BOSShome : public Place{
public:
    BOSShome (){
        getMessage();
        is_first_come1 = true;
    }
    void topicWords(){
        cout << "~~~~~~~~~~~~~~~~~~~~��BOSS��~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t����������������������BOSS�ļ��ſ�" << endl;
        getchar();
    }
    void conversation_with_npc(){
        topicWords();

        int tempX, tempY;
        int tempX1, tempY1;
        if(is_first_come1){
            getxy(tempX, tempY);
            cout << "\t" << npc1Name << "(LV." << npc1Lv << "):" << endl;
            cout << "\t\tû�뵽���ܻ����ߵ������Ҳ�޷���ɱ�������˵�����ø����һ����" << endl;
            getchar();
            cout << "\t����(LV." << protagonist.showLevel() << "):"<<endl;
            cout << "\t\t���㿪�Ű�����" << endl;
            getchar();
            clear_the_conversation(tempX, tempY);
            cout << "\t" << npc1Name << "(LV." << npc1Lv << "):" << endl;
            cout << "\t\t����������ȵ������ҵ�С������" << endl;
            getchar();
            clear_the_conversation(tempX, tempY);
            cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
            cout << "[ϵͳ��Ϣ]ս���ɣ�" << endl;
            int judge_live_1 = 1;
            Monster_7 monster_7;
            monster_7.getMessage();
            Fight <Monster_7> fight_7;
            fight_7.fighting(monster_7, judge_live_1);
            if (judge_live_1 == 0){
                fresh_village.conversation_with_npc1_npc2();
            }
            //getchar();
            system("CLS");
            topicWords();
            //clear_the_conversation(tempX, tempY);
            cout << "\t" << npc1Name << "(LV." << npc1Lv << "):" << endl;
            cout << "\t\tС���Ӹ�������ٵ���������һ��С����" << endl;
            getchar();
            cout << "\t����(LV." << protagonist.showLevel() << "):" <<endl;
            cout << "\t\t��Ҳ������ҽ��Ŵ��������֮�����˴������������" << endl;
            getchar();
            clear_the_conversation(tempX, tempY);
            cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
            cout << "[ϵͳ��Ϣ]ս���ɣ�" << endl;
            int judge_live_2 = 1;
           // Fight <Monster_7> fight_7;
            fight_7.fighting(monster_7, judge_live_2);
            if (judge_live_2 == 0){
                fresh_village.conversation_with_npc1_npc2();
            }
            //getchar();
            system("CLS");
            topicWords();
            //clear_the_conversation(tempX, tempY);
            cout << "\t" << npc1Name << "(LV." << npc1Lv << "):" << endl;
            cout << "\t\t������С���ӣ������������֮ǰ���Ҹ��㽲��������Σ�" << endl;
            getchar();
            cout << "\t����(LV." << protagonist.showLevel() << "):"<<endl;
            cout << "\t\t����G2��������Ҵ�����ѹ����ȳ������������۷��³�֮������ֳ��㿴���" << endl;
            getchar();
            cout << "\t" << npc1Name << "(LV." << npc1Lv << "):" << endl;
            cout << "\t\t���������ɧ���������治�������л�����������ʱ�䣬�ҵ���ʽ����ˡ����������С�а�������" << endl;
            getchar();
            cout << "\t����(LV." << protagonist.showLevel() << "):"<<endl;
            cout << "\t\t໣��������ǣ�" << endl;
            getchar();
            clear_the_conversation(tempX, tempY);
            getxy(tempX, tempY);
            cout << "�Ǳ����ŷ��������֨ѽ����Ƭ�̺��ſ���" << endl;
            cout << "\t[1.��ȥ]\t[2.������]\t[3.Ͷ��]" << endl;
            cout << "��ѡ��___";
            getxy(tempX1,tempY1);
            int option1;
            int chooseNum = 0;
            int chooseNum2 = 0;
            while(true){
                cin >> option1;
                if(option1 == 1){
                    cout << "\t" << npc1Name << "(LV." << npc1Lv << "):" << endl;
                    cout << "\t\t��������ҵ�Ĥ�������˺����Ƭ��" << endl;
                    getchar();
                    cout << "\t����(LV." << protagonist.showLevel() << "):"<<endl;
                    cout << "\t\t������ͫ�׶���ɢ�ˣ�������������֮��������ĸ��㽲" << endl;
                    getchar();
                    clear_the_conversation(tempX1, tempY1);
                    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
                    cout << "[ϵͳ��Ϣ]ս���ɣ�" << endl;
                    int judge_live_3 = 1;
                    Monster_9 monster_9;
                    monster_9.getMessage();
                    Fight <Monster_9> fight_9;
                    fight_9.fighting(monster_9, judge_live_3);
                    if (judge_live_3 == 0){
                        fresh_village.conversation_with_npc1_npc2();
                    }
                    getchar();
                    system("CLS");
                    topicWords();
                    //clear_the_conversation(tempX1, tempY1);
                    break;
                }
                if(option1 == 2){
                    cout << "�����һ���˻�ѡ���ѡ���벻�������" << endl;
                    getchar();getchar();

                    clear_the_conversation(tempX1, tempY1);
                    chooseNum += 1;
                    if(chooseNum >= 2){
                        clear_the_conversation(tempX, tempY);
                        break;

                    }

                }
                if(option1 == 3){
                    cout << "���棬��Ҫ������ڶ��Σ����һ�����൱Σ�յ�" << endl;
                    getchar();
                    clear_the_conversation(tempX1, tempY1);
                    chooseNum2 += 1;
                    if(chooseNum >= 2){
                        clear_the_conversation(tempX, tempY);
                        break;
                    }

                }
            }
            cout << "\t" << npc1Name << "(LV." << npc1Lv << "):" << endl;
            cout << "\t\t�㡭�����ҡ������������Ҳ�ա���ȥ�ȡ��������ɡ���������������" << endl;
            getchar();
            cout << "\t����(LV." << protagonist.showLevel() << "):" <<endl;
            cout << "\t\t��ô����ƤƤ��������ͷƤ������Ŀ���" << endl;
            cout << "\t\t��˵����������" << endl;
            is_first_come1 = false;
            getchar();
        }
        else{
            cout << "����û�ˡ���" << endl;
        }

        system("CLS");
        topicWords();
        int tempX2, tempY2;
        getxy(tempX2, tempY2);
        cout << "[��ɭ�ĺ������������ţ���ʴ�ţ��ù���������������]" << endl;
        getchar();
        cout << "\t������(LV." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t�����Ĺ�����������������۾��ɣ�" << endl;
        getchar();
        clear_the_conversation(tempX2, tempY2);

        cout << "[�����ŵĺ������������Ϻ�ɫ�Ĺ�â����Ѹ�ٴܽ�����������]" << endl;
        getchar();
        cout << "\t" << princess_name << "(LV." << princess_lv << "):" << endl;
        cout << "\t\t��ã����ʿ����������Ѿ��ѽ��ˣ�����һ�������������������Ҿ���Ϊ�˾����������ģ�" << endl;
        getchar();
        clear_the_conversation(tempX2, tempY2);

        cout << "\t������(LV." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t�����������ˣ�������..." << endl;
        getchar();
        cout << "\t" << princess_name << "(LV." << princess_lv << "):" << endl;
        cout << "\t\t������������ħ�����������ദ����������ȷʵ�����ˡ�" << endl;
        getchar();
        clear_the_conversation(tempX2, tempY2);

        cout << "\t" << princess_name << "(LV." << princess_lv << "):" << endl;
        cout << "\t\t������һ�ֵͼ��Ĵ��ڣ�����Զʼ֮ս�����µ�ʥ�ﹶ�Ӳд�����" << endl;
        getchar();
        cout << "\t" << princess_name << "(LV." << princess_lv << "):" << endl;
        cout << "\t\t��ħ��Ӧ����Ϊ��������Ϊ���ŵ����֡�����������һֱռ��������½���ƻ��Ż�����Ҳ�������ˣ�" << endl;
        getchar();
        clear_the_conversation(tempX2, tempY2);

        cout << "\t������(LV." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t�㲻�ǹ���������˭��ħŮӦ���Ѿ��������ѽ��������ô���£�" << endl;
        getchar();
        cout << "\t" << princess_name << "(LV." << princess_lv << "):" << endl;
        cout << "\t\t��֪�����డ����������ʥ�����Ĺ�����������Ҫ�������࣡" << endl;
        getchar();
        clear_the_conversation(tempX2, tempY2);

        cout << "\t" << princess_name << "(LV." << princess_lv << "):" << endl;
        cout << "\t\t�ɱ���ħŮ��Ŀ���ǳ���������������ȴ�����ű��˵���ò���������������ѱ�����ȡ��" << endl;
        getchar();
        cout << "\t" << princess_name << "(LV." << princess_lv << "):" << endl;
        cout << "\t\t��Ҫ�ñ�����Զʼ֮ս����һֱ�����������硣���������ڸ�Ϊ��λ��ħ��ģ�" << endl;
        getchar();
        clear_the_conversation(tempX2, tempY2);

        cout << "\t������(LV." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t������Ϊ����һ��ᱻ���֣���Ȼ�������е���������������" << endl;
        getchar();
        cout << "\t������(LV." << protagonist.showLevel() << "): " << endl;
        cout << "\t\t��ʱ��ѡ��Ҳ��ı�������ġ�" << endl;
        getchar();
        clear_the_conversation(tempX2, tempY2);

        cout << "1.��ѡ������   2.��ѡ���ӱ�   3.��ѡ��ս��" << endl;
        cout << "��ѡ��_______";
        getxy(tempX2, tempY2);
        int choose;
        cin >> choose;
        while (true){
             if (choose == 3){
                    system("CLS");
                    cout << "��ϵͳ��Ϣ��warnning warnning!" << endl;
                    cout << "\t����BOSS�������뵽��ս����" << endl;
                    Sleep(2500);
                    cout << "\tBOSS����2.5����Ȳ����������г�����..." << endl;
                    cout << "\t" << princess_name << "(Lv." << princess_lv << "):" << endl;
                    cout << "\t\t" << "enmmmm, ���Ǻ������ļ���~" << endl;
                    getchar();
                    cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
                    cout << "\t\t���������ڶ���~~(����������Ȼ��˵���ӳ�������磬��ֻ���������ˣ���" << endl;
                    getchar();
                    cout << "��ϵͳ��Ϣ�������������ؼ��ʣ�������Ȼ���������ֵ�ӳ�999999" << endl;
                    protagonist.max_hitPoints_plus(999999);
                    protagonist.current_hitPoints_plus(999999);
                    int judge_live_1 = 10;
                    Monster_10 monster_10;
                    monster_10.getMessage();
                    Fight <Monster_10> fight_10;
                    fight_10.fighting(monster_10, judge_live_1);

                    break;

             }
             if (choose == 2){
                    cout << "[ϵͳ��Ϣ]�ӱ��и�ë�ã�" << endl;
                    cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ��˵�һB" << endl;
                    getchar();
                    getchar();
                    clear_the_conversation(tempX2, tempY2);
                    //ûbreak��䣬������ѭ��

             }
             if (choose == 1){
                    cout << "\t" << princess_name << "(LV." << princess_lv << "):" << endl;
                    cout << "\t\t�����ϣ�" << endl;
                    getchar();
                    cout << "\t����˵�꣬�Թ�������������һ�������99999999���˺�" << endl;
                    getchar();
                    cout << "\t��������Ϊ�Լ�gg��..." << endl;
                    if (protagonist.check_have()){
                        cout << "\t��������������ѿ�����������ҫ�۵Ĺ�â" << endl;
                        getchar();
                        cout << "�ѿ��������ħŮ����꣬�����ָ�������" << endl;
                        getchar();
                        cout << "�����͹������Ҹ�����������һ��~~" << endl;
                        cout << "��The end��" << endl;
                        getchar();
                        exit(0);
                    }
                    else{
                        cout << "\t��ʵ���������gg��" << endl;
                        getchar();
                        cout << "����һ�ܵ�ʱ�䣬�����㱻ħ�幥�ݣ����������˸����Σ��..." << endl;
                        getchar();
                        cout << "\t�������ڴ���һ�����ȹ�����2����" << endl;
                        cout << "\t\t��gg...��" << endl;
                        getchar();
                        exit(0);

                    }
                    clear_the_conversation(tempX2, tempY2);

             }
             if (choose >= 4){
                    cout << "[ϵͳ��Ϣ]�ǲ������������ѡ����" << endl;
                    cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ���������" << endl; //�ɾͿ������ı��ļ������
                    getchar();
                    getchar();
                    clear_the_conversation(tempX2, tempY2);
             }


        }
    }
    void getMessage(){
        ifstream file;
		file.open("BOSShome_npc.txt", ios_base::in);
		if (file) {
            file >> npc1Name;
            file >> npc1Lv;
			file >> princess_name;
			file >> princess_lv;
		}
		file.close();
    }
private:
    bool is_first_come1;
    string npc1Name;
    int npc1Lv;
    string princess_name;
    int princess_lv;
};
