#pragma once
#include <bits/stdc++.h>
#include "Protagonist.h"
#include "Monster.h"
#include "Monster_6.h"
using namespace std;



HANDLE  hConsole_depthOfFlowers;
Protagonist protagonist_depthOfFlowers;
class depthOfFlowers : public Place{
public:
    depthOfFlowers(){
        is_first_come = true;
    }
    void TopicWords(){
        SetConsoleTextAttribute(hConsole_depthOfFlowers,2);
        cout << "~~~~~~~~~~~~~~~~~~~~����\t��\t��\t��\t����~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        cout << "��������һ��ɽ�ȣ������־ջ���ؿ��ţ����µľջ���������Χ�ơ����е�С���￡���ȡ��ö�����Ȯ����Ȼ�����Ǹ�����Ҫ�ƻ������ĵط�" << endl;
        cout << "������󷨽�ɽ�Ȼ������У�������������ת���뵹������ڶ����ƺ����Եֵ�ħ���Ľ�����һ�����Ӵӹȵ����쵽Զ������" << endl;
    }
    void conversation_with_npc(){
        int tempX, tempY;
        int tempX1, tempY1;
        TopicWords();
        getxy(tempX, tempY);
        if(is_first_come){
            cout << "���߽����У����ֳ��б���������������졣�ƺ��ڰ�ʲô���¡�Χ����Ⱥ���ж���������һ���ٻ���" << endl;
            cout << "\t" << "???" << "(Lv." << "???" << "):" << endl;
            cout << "\t\t����ѽ�������������" << endl;
            getchar();
            cout << "���룺��1.ȥ������\t��2.��������Ȥ��" << endl;
            cout << "��ѡ��___";
            int option1;
            cin >> option1;
            if(option1 == 1){
                cout << "���뿪Χ�۵���Ⱥ������һ��С�����С�������һ����ª��С���д�������" << endl;
                getchar();
                clear_the_conversation(tempX, tempY);
                cout << "\t��1.���Ž�ȥ��\t��2.ת����ȥ��" << endl;
                cout << "��ѡ��___";
                int option2;
                cin >> option2;
                if(option2 == 1){
                    cout << "�Ų�û���������ڼҾ߱����ҳ������ˣ�������������м���û��ס���ˡ�" << endl;
                    getchar();
                    cout << "��������������ڴ�������" << endl;
                    getchar();
                    cout << "��������ǰ���Ż����Ŀ��ˣ��������ζ����һ�ɽ�Ȼ��ͬ��������ζ���������������˹�ȥ��" << endl;
                    getchar();getchar();
                    cout << "��Χһ��ҡ�Ρ������˹���������������" << endl;
                    getchar();
                    cout << "����һ����ɫ�ĳ�����ռ�������и���һƬ������ȴû���š���" << endl;
                    getchar();
                    cout << "�Ӵ�������ȥ�����ں�����С�Χ����Ⱥ��������֮ǰ���죬����ȴ�����˼�ʮ�ꡣ" << endl;
                    getchar();
                    cout << "Զ����һ����̳һ���Ľ��������漸�����ź�ɫ�·������ڽ���ʲô��ʽ�����ϵ�����ʢ���ż�����ͷ����" << endl;
                    getchar();
                    cout << "��֪���˶�ã�����ͣ�ˡ�һ��ѣ�κ���վ����ľ�ذ��ϣ���Χ��û��ʲô���ӵ���Ӱ����" << endl;
                    cout << "������Χ���㷢������һ��ǳ��ɫ�Ĵ��ϡ���" << endl;
                    getchar();
                    clear_the_conversation(tempX, tempY);
                    int option3;
                    while(true){
                        cout << "���롾1.����ԭ�ء�\t��2.�ڼװ��Ͽ�����\t��3.ȥ���²㿴����" << endl;
                        getxy(tempX1, tempY1);
                        cin >> option3;
                        if(option3 == 1){
                            cout << "���������ɪɪ������" << endl;
                            getchar();
                            clear_the_conversation(tempX1, tempY1);
                        }
                        if(option3 == 2){
                            cout << "�װ��Ͽ���һ�ˣ���ʹ���ϵĵƶ����ţ������ɸо�����һ˿�������Ϣ����" << endl;
                            getchar();
                            clear_the_conversation(tempX1, tempY1);
                        }
                        if(option3 == 3){
                            cout << "���ڲ�Զ���ҵ��������ߵ�¥�ݣ�Խ�����ߣ�¥�ݵ���ɫ������ǳ����" << endl;
                            cout << "��¥�󣬵ذ�ǽ�ڵ���ɫ��ȫ����˰���ɫ����Ѫ��ζ���ڶ���" << endl;
                            cout << "��ǿѹ�����еĿ־塭��" << endl;
                            getchar();
                            clear_the_conversation(tempX1, tempY1);
                            break;
                        }
                    }
                    cout << "�㿪ʼ̽��ÿһ���ţ�Ȼ���ź���˰߲���Ѫ��֮���������" << endl;
                    getchar();
                    clear_the_conversation(tempX, tempY);
                    cout << "���������һ����ǰ����1.�򿪡���2.�ص��װ��ϡ�" << endl;
                    cout << "����___";
                    int option4;
                    cin >> option4;
                    if(option4 == 1){
                        cout << "�������Ҫ�ɾ���࣬һ����ɫ����Ӱ�����������м䣬����������������ͷ������һ�ۡ�" << endl;
                        getchar();
                        cout << "\t�ֳ���(Lv.10):" << endl;
                        cout << "\t\t�ҵط����ɣ����Ҵ��ǲ���ͣ�ģ������������Ҳ�������š�" << endl;
                        getchar();
                        clear_the_conversation(tempX, tempY);
                        int option5;
                        while(true){
                            getxy(tempX1, tempY1);
                            cout << "\t��1.���ڳ��е��ˡ�\t��2.���ڷ������Ѫ����\t��3.�ص��װ塿" << endl;
                            cout << "��ѡ��___";

                            cin >> option5;
                            if(option5 == 1){
                                cout << "\t����(Lv."  << protagonist.showLevel() << "):" << endl;//����ȥ�ȼ�
                                cout << "\t\t������ô�ϵĽ��ӣ����е���Ϊʲô��ͻȻ���ϣ�����Ϊʲô���������Ҵ��ϣ����׷�����ʲô������" << endl;
                                cout << "\t�ֳ���(Lv.10):" << endl;
                                cout << "\t\t�ȵȣ���˵�������ܿ���������˱����ˣ��˻����棿" << endl;
                                getchar();

                                cout << "\t����(Lv."  << protagonist.showLevel() << "):" << endl;
                                cout << "\t\t�ϻ������ж�����������⣿�����㻹�������ң��⵽������ô���£�GNMD�������ں��� �������ᵽ��" << endl;
                                cout << "\t�ֳ���(Lv.10):" << endl;
                                cout << "\t\t�첻�������壬�ҵ���ʮ���꣬���ڵȵ��ˡ���" << endl;
                                getchar();
                                cout << "\t����(Lv."  << protagonist.showLevel() << "):" << endl;
                                cout << "\t\t�õĺõ�ͬϲͬϲ�鷳��TM�ϻش��������������" << endl;
                                cout << "\t�ֳ���(Lv.10):" << endl;
                                cout << "\t\t�������������㣬��������ʱ��һ��Ҫ��ϧһ�д���ɱ����������ĩ�ڵ������������ġ�" << endl;
                                getchar();
                                cout << "\t����(Lv."  << protagonist.showLevel() << "):" << endl;
                                cout << "\t\t����лл���������Щ����������������������������ڰ˱��ʺ�����" << endl;
                                getchar();
                                clear_the_conversation(tempX1, tempY1);
                            }
                            if(option5 == 2){
                                cout << "\t����(Lv."  << protagonist.showLevel() << "):" << endl;
                                cout << "\t\t��˵�ϴ������²�ȥҲ�����ˣ��Ǵ�����ôһ����Ҳû�У�Ѫ�����������ģ�����" << endl;
                                cout << "\t�ֳ���(Lv.10):" << endl;
                                cout << "\t\t��ֻ�����Ǹ��ط����´�����һ������������֮ǰ��ֻ������Щ�˲�Ҫ������" << endl;
                                getchar();
                                cout << "\t����(Lv."  << protagonist.showLevel() << "):" << endl;
                                cout << "\t\t�������͵���ش��˰ɡ�����ش�����ķ�ʽ����Ƿ�Ե��ӡ�" << endl;
                                getchar();
                                clear_the_conversation(tempX1, tempY1);
                            }
                            if(option5 == 3){
                                cout << "\t����(Lv."  << protagonist.showLevel() << "):" << endl;
                                cout << "\t\t�һ��ǻؼװ��ϵ������Ӱɰװ�������~���ط������һɤ��һ���Ӿ�����ȥ����" << endl;
                                cout << "\t�ֳ���(Lv.10):" << endl;
                                cout << "\t\t�ȵȡ���" << endl;
                                getchar();
                                cout << "\t����(Lv."  << protagonist.showLevel() << "):" << endl;
                                cout << "\t\t????" << endl;
                                getchar();
                                cout << "\t�ֳ���(Lv.10):" << endl;
                                cout << "\t\t���͡���" << endl;
                                getchar();
                                cout << "\t����(Lv."  << protagonist.showLevel() << "):" << endl;
                                cout << "\t\t�������ǹݵĵ绰��Ǻã����ҵ����ִ���ۻ��ͻ��᳡�������һ��������" << endl;
                                getchar();
                                clear_the_conversation(tempX1, tempY1);
                                break;
                            }
                            if (option5 != 1 && option5 != 2 && option5 != 3){
                                cout << "����¡���" << endl;
                                getchar();
                                clear_the_conversation(tempX1, tempY1);
                            }
                        }
                    }
                    if(option4 == 2){
                        cout << "������һ�֣��ص��˼װ��ϡ���" << endl;
                        getchar();
                        clear_the_conversation(tempX, tempY);
                    }
                    cout << "��֪���˶�ã�����ͻȻ����������һֻ��Ŀ������ˮ�����˳�����Х���쳹�������������������κ���������" << endl;
                    cout << "��������Զ��һ���ʺ�ɫ�Ĵ����˹�������" << endl;
                    cout << "[1.����ȥ][2.��������]" << endl;
                    cout << "��ѡ��___";
                    int option6;
                    cin >> option6;
                    cout << "���ǰɣ��õġ���������ȥ��" << endl;
                    cout << "��ͷˮ�޵ĺ󱳰̺����ۣ�ÿһ���̺۶���һ����λ����" << endl;
                    getchar();
                    clear_the_conversation(tempX, tempY);
                    cout << "�ֹ�����ã�������̤�������ء���" <<endl;
                    cout << "���Ͽ�������ɫ�Ļ��������һ����������С���" << endl;
                    getchar();
                    clear_the_conversation(tempX, tempY);
                    cout << "\t����֮��(Lv.10):" << endl;
                    cout << "\t\t�ߣ�����Ϊ��������������κβ�������ɱ������" << endl;
                    getchar();
                    clear_the_conversation(tempX, tempY);

                    int judge_live = 1;
                    Monster_6 monster_6;
                    monster_6.getMessage();
                    Fight <Monster_6> fight;
                    fight.fighting(monster_6, judge_live);
                    if (judge_live == 0){
                        fresh_village.conversation_with_npc1_npc2();
                    }
                    //ս�����̣�������С�� С����ͬ
                    getchar();
                    clear_the_conversation(tempX, tempY);
                    cout << "\t����֮��(Lv.10):" << endl;
                    cout << "\t\t��ô���ܣ���ɱ�ң��ҿ��԰�����ط����㣬����������Щ�ṩ�����������ڣ������ˣ������㣬������" << endl;
                    getchar();
                    cout << "����˵�꣬�������ʫ��������������ʥսħŮ�Ķ����֣����������߳ܵ��³�" << endl;
                    getchar();
                    clear_the_conversation(tempX, tempY);
                    cout << "[ϵͳ��Ϣ]��ý��������+200������+80" << endl;
                    cout << "[ϵͳ��Ϣ]�����Ʒ����ɫ����" << endl;
                    protagonist.experienceAmount_plus(80);
                    packsack.possession_plus(200);
                    getchar();
                    //�ȼ����û����ë�棬�еĻ�ִ����������
                    cout << "[ϵͳ��Ϣ]�����ë������������ܸ���Ȥ�����㲻��һ������" << endl;
                    cout << "[ϵͳ��Ϣ]�����ë������� �ѿ�������" << endl;

                    protagonist.set_have();
                    //����ȥ
                    cout << "[ϵͳ��Ϣ]��óɾͣ�Ե�������" << endl;
                    protagonist.add_achievement("Ե�������");
                    getchar();
                    clear_the_conversation(tempX, tempY);
                }

            }
            else{
                cout << "�㿴��һ�ᣬ���뿪����Ⱥ��һ�ɹ���ĸо������������ͷ����" << endl;
                getchar();
                clear_the_conversation(tempX, tempY);
                cout << "�㿴�����и�ʾ���������������ͣ�����˺�˸�ʾ�������⡭��" << endl;
                getchar();
                clear_the_conversation(tempX, tempY);
                cout << "׼��ս������" << endl;
                getchar();
                clear_the_conversation(tempX, tempY);

                int judge_live = 1;
                Monster_6 monster_6;
                monster_6.getMessage();
                Fight <Monster_6> fight;
                fight.fighting(monster_6, judge_live);
                if (judge_live == 0){
                    fresh_village.conversation_with_npc1_npc2();
                }
                //zս�����������������ͬ ��ֻ
                getchar();
                clear_the_conversation(tempX, tempY);
                cout << "[ϵͳ��Ϣ]�����������+100������+50" << endl;
                protagonist.experienceAmount_plus(50);
                packsack.possession_plus(100);
                getchar();
                cout << "���뿪��ɽ�ȡ���" << endl;
                cout << "[ϵͳ��Ϣ]���պ�����֮���Ӱٻ������������ս���������ǿһ��������Ƹ����᧿�Σ����" << endl;
                getchar();
                clear_the_conversation(tempX, tempY);
            }
            is_first_come = false;
        }
        else{
            cout << "һƬ��������" << endl;
        }
    }

private:
    bool is_first_come;
};




/*void linChangSheng_words(){
        cout << "�������ԭ����û�кӵġ���" << endl;
        cout << "��ʮ��ǰ��ʥս��ʱ��ħŮ���ż���ħ�徫���������������Ͻ��֣�" << endl;
        cout << "������ƴ�������������ɱ�������ֽ����񷣴���ħŮ֮���������ǿӮ���ⳡ��ս��" << endl;
        cout << "û�뵽������һ����������������ǿ�����������ѣ�Զ�����ˡ���" << endl;
        cout << "�ҵ�СŮ�����ٲ����£������ǿ��ѣ�˭��û�и��ߣ�����������������������" << endl;
        cout << "�����������꣬��������ˣ��ʱ��Ū����Ƥ����Ѫ�ε������ϣ����쿪ʼ�������ǣ������������˵���־忪ʼ�ˡ�" << endl;
        cout << "����ʳ������������ǿ���������ںϣ���ʼ��ʱ������������ȫѹ��ס�������һֱ���������������ܣ�" << endl;
        cout << "Ȼ���������ƿ������ʱ�����ĵ����ɻ����󷨵�������" << endl;
        cout << "��Ȼ�����Թ��˻����󷨣�����Ҳ׳����ѹ�����Ҳ���������ˡ�" << endl;
        cout << "���軤���󷨵������������ȡ�������Ĵ����ƿ��˳��е��ˣ��ֽ�����������Ϊ�����ӣ�" << endl;
    }*/
