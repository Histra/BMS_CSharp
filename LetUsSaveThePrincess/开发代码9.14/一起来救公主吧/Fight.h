#pragma once
#include "Protagonist.h"
#include "Packsack.h"
#include "freshVillage.h"
using namespace std;
//Protagonist protagonist;
Packsack packsack;
int map_digit_choose = 0;
template <class T>
class Fight{
public :
    void fighting(T monster, int &judge_live){
        int roundsNumber = 1;
        while(true){
            cout << "���ں�" << monster.name << "ս��..." << endl;
            cout << "\t������ǰ����ֵ��" << protagonist.show_current_hitPoints();
            cout << " , �������ֵ��" << protagonist.show_max_hitPoints() << "��" << endl;
            cout << "\t��" << monster.name << "��ǰ����ֵ��";
            cout << monster.current_hitPoints << "��" << endl;
            cout << "�������𹥻���" << endl;
            cout << "\t[1.һ����]\t[2.������]\t[3.������]\t";
            cout << "��ѡ��____";
            int tempChoose;
            cin >> tempChoose;
            if (tempChoose == 1){
                cout << "����ʹ��һ���ܡ�" << protagonist.getskill_1() << "��";
                cout << "��" << monster.name << "���";
                int tempDamage;
                tempDamage = protagonist.usingskill_1() - monster.armor;
                if (tempDamage < 0)
                    tempDamage = 0;
                cout << tempDamage << "���˺�" << endl;
                monster.hitPoints_decline(tempDamage);
                getchar();getchar();
            }
            if (tempChoose == 2){
                cout << "����ʹ�ö����ܡ�" << protagonist.getskill_2() << "��";
                cout << "��" << monster.name << "���";
                int tempDamage;
                tempDamage = protagonist.usingskill_2() - monster.armor;
                if (tempDamage < 0)
                    tempDamage = 0;
                cout << tempDamage << "���˺�" << endl;
                monster.hitPoints_decline(tempDamage);
                getchar();getchar();

            }
            if (tempChoose == 3){
                cout << "����ʹ�������ܡ�" << protagonist.getskill_3() << "��";
                cout << "��" << monster.name << "���";
                int tempDamage;
                tempDamage = protagonist.usingskill_3() - monster.armor;
                if (tempDamage < 0)
                    tempDamage = 0;
                cout << tempDamage << "���˺�" << endl;
                monster.hitPoints_decline(tempDamage);
                getchar();getchar();

            }
            if (tempChoose == 4){
                cout << "����ʹ���ļ��ܣ����ؼ��ܣ���" << protagonist.getskill_4() << "��";
                cout << "��" << monster.name << "���";
                int tempDamage;
                tempDamage = protagonist.usingskill_4() - monster.armor;
                if (tempDamage < 0)
                    tempDamage = 0;
                cout << tempDamage << "���˺�" << endl;
                monster.hitPoints_decline(tempDamage);
                getchar();getchar();

            }
            //monster attack goudan
            cout << monster.name << "���𹥻�:" << endl;
            cout << "\t" << monster.name << "�Թ��������";
            int tempDamage;
            tempDamage = monster.strong - protagonist.showArmor();
            if (tempDamage < 0)
                    tempDamage = 0;
            cout << tempDamage << "���˺�" << endl;
            protagonist.hitPoints_decline(tempDamage);
            getchar();
            cout << "[ϵͳ��Ϣ]��" << roundsNumber ++ << "�غϽ���." << endl;
            if (protagonist.show_current_hitPoints() <= 0){
                if (judge_live == 10){
                    cout << "[ϵͳ��Ϣ]�㱻��������i~~" << endl;
                    cout << "\t�����Ѫ�������˹������е��ƣ�������ħŮ�ϳ�������" << endl;
                    cout << "\tħ��ʧȥ��������Դ�����һָ��˰������" << endl;
                    cout << "\tΪ�˼�������������������㣬�ѽ��춨��ɡ������ڡ�" << endl;
                    cout << "\t\t��The end��" << endl;
                    exit(0);
                }
                else{
                    cout << "[ϵͳ��Ϣ]����ս����������" << endl;
                    cout << "\n\n\t\t���ػ����ִ壬������...��" << endl;
                    protagonist.getMessage();
                    monster.getMessage();
                    getchar();
                    judge_live = 0;
                    system("CLS");
                }

                //����һ����־���ص����ִ塣
                break;
            }
            if (monster.current_hitPoints <= 0){
                cout << "[ϵͳ��Ϣ]����ս���л�ʤ��" << endl;
                cout << "\t�˴�ս�����õ�ս��Ʒ��:" << endl;
                cout << "\t\t1.����\t" << monster.exp << endl;
                cout << "\t\t2.���\t" << monster.gold << endl;
                protagonist.experienceAmount_plus(monster.exp);
                packsack.possession_plus(monster.gold);
                getchar();
                //����һ����־�ص�print_menu() ���� �������ء�
                break;
            }

            cout << "\t[1.����ս��]\t[2.����]\t��ѡ��____";
            int tempChoose_number;
            cin >> tempChoose_number;
            if (tempChoose_number == 1){
                cout << "**************************************************************************" << endl;
                continue;
            }
            if (tempChoose_number == 2){
                //���ñ�־����print_menu()��
                if (judge_live == 10){
                    cout << "����ʧ�ܣ�" << endl;
                    getchar();
                }
                else
                    break;
            }
        }


    }
private:



};
