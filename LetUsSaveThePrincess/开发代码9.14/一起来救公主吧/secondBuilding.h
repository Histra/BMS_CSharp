#pragma once
#include <bits/stdc++.h>
#include "Monster.h"
#include "Monster_5.h"
using namespace std;

HANDLE  hConsole_secondBuilding;

class secondBuilding : public Place {
public:
    void topicWords(){
        SetConsoleTextAttribute(hConsole_secondBuilding,2);
        cout << "~~~~~~~~~~~~~~~~~~~~����\t��\t��\t��\t��\t¥��~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        cout << "�������겻�����⣬���ص�����ʼ�������Ÿ��ʵĳ�ǽ������ѹ�ֵ���Ϣʹ���˴�����������" << endl;
        cout << "������������Ҫ�ľ���Ҫ������������ڴ�פ���ı�����������������뵽���ʿ������������е����" << endl;
        getchar();
        cout << "\t����ȥ�ģ�" << endl;
        cout << "��1.����������2.ҩ�꡿��3.����䡿" << endl;
        int choose;
        cin >> choose;
        cout << "��ϵͳ��Ϣ����ϲ�㣬��·�ˣ�" << endl;
        getchar();
        cout << "����·��һ�죬�������ȣ���ʱ���������˽�̸,��..." << endl;
        cout << "��1.����ȥ����2.����ȥ����3.����ȥ����4.�������ˡ�" << endl;
        int choose2;
        cin >> choose2;
        cout << "�õģ��������ȥ��" << endl;
        getchar();
        cout << "\t???(Lv.??):" << endl;
        cout << "\t\t������ʱ����������������������ħ�塭������������" << endl;
        getchar();
        cout << "\t\t��ߴߴ����ߴߴ����������" << endl;
        getchar();
        cout << "Ȼ��������ȥ���Ǽ���������.�����ŵ�ͼ��" << endl;
    }
    bool is_first_come = true;
    void conversation_with_npc(){
        topicWords();
        if(is_first_come == true){
                getchar();
            cout << "���գ����в�û��ͨ�����ֵ���Ϣ���֡���" << endl;
            getchar();
            //cout << "\t����ȥ�ģ�" << endl;
            //cout << "��1.����䡿��2.��Ӫ����3.��������" << endl;
            int option1;
            while (true){
                bool jump = true;
                cout << "\t����ȥ�ģ�" << endl;
                cout << "��1.����䡿��2.��Ӫ����3.��������" << endl;
                cin >> option1;
                if(option1 != 1 && option1 != 2 && option1 != 3){
                    cout << "����ºú���" << endl;
                }
                if(option1 == 1){
                    cout << "��������͸¶���ڲز�ס������" << endl;
                }
                if(option1 == 2){
                    cout << "���ڴ�����ҵ�ʿ���Ƕ�����죬����ʿ��¶����ԥ�����顭��" << endl;
                    getchar();
                    cout << "\tʿ��(Lv.?):" << endl;
                    cout << "\t\t������˵�������������ǻ��ض��ǡ���" << endl;
                }
                if(option1 == 3){

                    cout << "�������������⡭��" << endl;
                    cout << "��1.��̸����2.������3.��ȡ����" << endl;
                    while(true){
                        int option2;
                        cin >> option2;
                        if(option2 != 1 && option2 != 2 && option2 != 3){
                            cout << "����ºú���" << endl;
                        }
                        if(option2 == 1){
                            cout << "\t����(Lv.???):" << endl;
                            cout << "\t\t��ϧ������Υ�������Ҷ�Ҫ��˳ǹ�������" << endl;
                        }
                        if(option2 == 2){
                            cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
                            cout << "\t\t��������𼦶����ˣ�˭�����ߵ�������û��B����.��" << endl;
                            getchar();
                            cout << "\t����(Lv.???):" << endl;
                            cout << "\t\t��С�Ѵ��Ժ��⣬���ѵ���α���������ɣ���" << endl;
                            getchar();
                            bool is_first_come3 = true;
                            while(true){
                                cout << "��1.Ѱ��֤�ݡ���2.ɱ������" << endl;
                                int option3;
                                cin >> option3;
                                if(option3 != 1 && option3 != 2)
                                {
                                    cout << "����ºú���" << endl;
                                }
                                if(option3 == 1 && is_first_come3 == true){
                                    cout << "��ת�����ߣ�ͻȻ���һ�󺮷�Ϯ������ƾ�����ϵļ������ݶ���˳�����ֱ��һ����" << endl;
                                    is_first_come3 = false;
                                }
                                if(option3 == 1 && is_first_come3 == false){
                                    cout << "��ϵͳ��Ϣ����ѡ���û������С���ӣ�" << endl;
                                }
                                if(option3 == 2 && is_first_come3 == true){
                                    cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
                                    cout << "\t\t����������BB�ðɣ�������һ��ter��" << endl;
                                    getchar();
                                    cout << "��ϵͳ��Ϣ����ɱ�˳���(Lv.???),��þ���+50��" << endl;//���Ͼ���
                                    protagonist.experienceAmount_plus(50);
                                    cout << "��ϵͳ��Ϣ����óɾͣ�����ɱ����Ī��" << endl;
                                    cout << "��ϵͳ��Ϣ������û��֤�ݣ���δ�ܻ�ý�Ǯ���������Ҳֻ��ӳ����С�" << endl;//�����ص�ǰ������
                                    break;
                                }
                                if(option3 == 2 && is_first_come3 == false){
                                    cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
                                    cout << "\t\t�����ٿ����ȵ�һ��������ŵ�һ�ʣ�����һ��ter��" << endl;
                                    cout << "��ϵͳ��Ϣ����ɱ�˳���(Lv.???),��þ���+50,���+200��" << endl;//���ϻ�õĶ���
                                    packsack.possession_plus(200);
                                    protagonist.experienceAmount_plus(50);
                                    cout << "��ϵͳ��Ϣ����óɾͣ�����ج��" << endl;//���ϻ�õĶ���
                                    break;
                                }
                            }
                            break;
                        }
                        if(option2 == 3){
                            cout << "\t����(Lv.???):" << endl;
                            cout << "\t\t�����Ӽ������ض��ǣ������ߺ����ش˵ص�ʿ�����µֵ���ס����ħ�����Ϯ������С�ѳ�������������������" << endl;
                            getchar();
                            cout << "��ϵͳ��Ϣ����ȡ���񣺴�ɨ������" << endl;
                            cout << "��ϵͳ��Ϣ��������������X50�����X200." << endl;
                            int judge_live = 1;
                            Monster_5 monster_5;
                            monster_5.getMessage();
                            Fight <Monster_5> fight;
                            fight.fighting(monster_5, judge_live);
                            if (judge_live == 0){
                                fresh_village.conversation_with_npc1_npc2();
                            }
                            getchar();
                            cout << "����ħ���ս�������˵��棬¶����һֻ��ʼ���õĽš�" << endl;
                            int option4;
                            while(true){
                                cout << "��1.�ڳ�������2.������á�" << endl;
                                cin >> option4;
                                if(option4 != 1 && option4 != 2){
                                    cout << "����ºú���" << endl;
                                }
                                if(option4 == 1){
                                    cout << "�����ʬ������������ƺ��ǻʼҵ���ʹ�������ϵĵ����൱��Ŀ��" << endl;
                                    cout << "ʬ��������յ���Ƥ��д�ţ����ڳ��ڣ��ǻ�����" << endl;
                                    getchar();
                                    cout << "�����°���������" << endl;
                                    getchar();
                                    break;
                                }
                                if(option4 == 2){
                                    cout << "��ϵͳ��Ϣ����ôû��������С���ӣ�" << endl;
                                }
                            }
                            cout << "��ص���������" << endl;
                            cout << "\t����(Lv.???):" << endl;
                            cout << "\t\t����л�㣬С�ѡ����Ǹ���Ľ�������" << endl;
                            cout << "��ϵͳ��Ϣ����ý���������+50�����+200." << endl;//���ϻ�õĶ���
                            protagonist.experienceAmount_plus(50);
                            packsack.possession_plus(200);
                            getchar();
                            cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
                            cout << "\t\t����˵����������ض��ǣ�˭�����ߵ�������û��B���𣿡�" << endl;
                            getchar();
                            cout << "\t����(Lv.???):" << endl;
                            cout << "\t\t��С�Ѵ��Ժ��⣬���ѵ���α���������ɣ���" << endl;
                            getchar();
                            bool is_first_come4 = true;
                            while(true){
                                cout << "��1.��ɱ������2.ɱ������" << endl;
                                int option5;
                                cin >> option5;
                                if(option5 != 1 && option5 != 2){
                                    cout << "����ºú���" << endl;
                                }
                                if(option5 == 1 && is_first_come4 == true){
                                    cout << "��ת�����ߣ�ͻȻ���һ�󺮷�Ϯ������ƾ�����ϵļ������ݶ���˳�����ֱ��һ����" << endl;
                                    is_first_come4 = false;
                                }
                                if(option5 == 1 && is_first_come4 == false){
                                    cout << "������û��ɱ��������һ�����Ϊ֮���뿪�˳��С�" << endl;//f����������
                                    cout << "��ϵͳ��Ϣ���������ɴ������ӣ�Ͷ��ħ���������伣��ħ��ʵ������׳�������᧿�Σ��" << endl;
                                    getchar();
                                    cout << "��ϵͳ��Ϣ����óɾͣ��²��ؼ��߸߹���" << endl;//���ϻ�õĶ���
                                    break;
                                }
                                if(option5 == 2){
                                    cout << "�������֣�ͻȻ����һ�󺮷�Ϯ������ƾ�����ϵļ������ݶ���˳������յ�һ����" << endl;
                                    getchar();
                                    cout << "\t������(Lv." << protagonist.showLevel() << "):" << endl;
                                    cout << "\t\t�����٣�����һȭ��" << endl;
                                    getchar();
                                    cout << "��ϵͳ��Ϣ����ɱ�˳���(Lv.???),��þ���X50,���X200��" << endl;//���ϻ�õĶ���
                                    protagonist.experienceAmount_plus(50);
                                    packsack.possession_plus(200);
                                    cout << "��ϵͳ��Ϣ����óɾͣ�����ج��" << endl;//���ϻ�õĶ���
                                    getchar();
                                    break;
                                }
                            }
                            break;
                        }

                    }
                    jump = false;
                }
                if(jump == false)
                    break;
            }
            is_first_come = false;
            //����������
        }
        if(is_first_come == false){
            int option6;
            while(true){
                cout << "\t����ȥ�ģ�" << endl;
                cout << "��1.����䡿��2.��Ӫ����3.����������4.�����ˡ�" << endl;
                cin >> option6;
                int tempX3, tempY3;
                getxy(tempX3, tempY3);
                if(option6 != 1 && option6 != 2 && option6 != 3 && option6 != 4){
                    cout << "����ºú���" << endl;
                    clear_the_conversation(tempX3, tempY3);
                }
                if(option6 == 1){
                    cout << "�������ϳ��ݸ�����" << endl;
                    clear_the_conversation(tempX3, tempY3);
                }
                if(option6 == 2){
                    cout << "��Ը���ص�սʿ��ɢ���żᶨ�Ĺ�ԡ�" << endl;
                    clear_the_conversation(tempX3, tempY3);

                }
                if(option6 == 3){
                    cout << "����������һ��" << endl;
                    clear_the_conversation(tempX3, tempY3);
                }
                if(option6 == 4)
                    break;
            }
            //����������

        }
    }
};







