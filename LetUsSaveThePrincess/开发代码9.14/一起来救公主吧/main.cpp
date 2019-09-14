#include <bits/stdc++.h>
#include <Windows.h>
//#include "Protagonist.h"
#include "freshVillage.h"
#include "Place.h"
#include "forgivableVillage.h"
#include "madeInHeaven.h"
#include "depthOfFlowers.h"
#include "secondBuilding.h"
#include "kingCanyon.h"
#include "Camelot.h"
#include "blackTown.h"
#include "highMath.h"
#include "devilAbyss.h"
#include "BOSShome.h"
#include "Monster.h"
#include "Monster_1.h"
#include "Monster_2.h"
#include "Monster_3.h"
#include "Monster_4.h"
#include "Monster_5.h"
#include "Monster_6.h"
#include "Monster_7.h"
#include "Monster_8.h"
#include "Monster_9.h"
#include "Monster_10.h"
#include "Fight.h"

#include "Packsack.h"
#include "Store.h"


using namespace std;

//������ɫ
HANDLE  hConsole;
int current_point = 1;

//Protagonist protagonist;
//freshVillage fresh_village;
forgivableVillage forgivable_village;
madeInHeaven made_in_heaven;
depthOfFlowers depth_of_flowers;
secondBuilding second_building;
kingCanyon king_canyon;
Camelot camelot;
blackTown black_town;
highMath high_math;
devilAbyss devil_abyss;
BOSShome  BOSS_home;

//Packsack packsack;
Store store;

Monster_1 monster_1;
Monster_2 monster_2;
Monster_3 monster_3;
Monster_4 monster_4;
Monster_5 monster_5;
Monster_6 monster_6;
Monster_7 monster_7;
Monster_8 monster_8;
Monster_9 monster_9;
Monster_10 monster_10;

//Fight fight;

string map_digitization[20][20];
string name_digitization[20];
bool is_get_handbook = false;
void map_digitized(){
    ifstream file;
    file.open("map_name_digitization.txt", ios_base :: in);
    if (file){
        for (int i = 1; i <= 12; i ++){
            file >> name_digitization[i];
        }
    }
    file.close();
    map_digitization[1][1] = name_digitization[2];
    map_digitization[1][2] = name_digitization[5];
    map_digitization[2][1] = name_digitization[3];
    map_digitization[2][2] = name_digitization[6];
    map_digitization[2][3] = name_digitization[1];
    map_digitization[3][1] = name_digitization[2];
    map_digitization[3][2] = name_digitization[4];
    map_digitization[4][1] = name_digitization[3];
    map_digitization[4][2] = name_digitization[6];
    map_digitization[4][3] = name_digitization[8];
    map_digitization[5][1] = name_digitization[1];
    map_digitization[5][2] = name_digitization[10];
    map_digitization[5][3] = name_digitization[9];
    map_digitization[6][1] = name_digitization[2];
    map_digitization[6][2] = name_digitization[4];
    map_digitization[6][3] = name_digitization[7];
    map_digitization[7][1] = name_digitization[6];
    map_digitization[7][2] = name_digitization[8];
    map_digitization[7][3] = name_digitization[11];
    map_digitization[8][1] = name_digitization[4];
    map_digitization[8][2] = name_digitization[7];
    map_digitization[8][3] = name_digitization[11];
    map_digitization[9][1] = name_digitization[5];
    map_digitization[9][2] = name_digitization[10];
    map_digitization[10][1] = name_digitization[5];
    map_digitization[10][2] = name_digitization[9];
    map_digitization[10][3] = name_digitization[11];
    map_digitization[11][1] = name_digitization[7];
    map_digitization[11][2] = name_digitization[8];
    map_digitization[11][3] = name_digitization[10];
    //?
    map_digitization[12][1] = name_digitization[9];
    map_digitization[9][3] = name_digitization[12];
}
void emigrate(int current_point){
    if (current_point == 1){
        system("CLS");
        fresh_village.conversation_with_npc1_npc2();
    }
    if (current_point == 2){
        system("CLS");
        forgivable_village.conversation_with_npc();
    }
    if (current_point == 3){
        system("CLS");
        made_in_heaven.conversation_with_npc();
    }
    if (current_point == 4){
        system("CLS");
        depth_of_flowers.conversation_with_npc();
    }
    if (current_point == 5){
        system("CLS");
        second_building.conversation_with_npc();

    }
    if (current_point == 6){
        system("CLS");
        king_canyon.conversation_with_npc();
    }
    if (current_point == 7){
        system("CLS");
        camelot.conversation_with_npc();
    }
    if (current_point == 8){
        system("CLS");
        black_town.conversation_with_npc();
    }
    if (current_point == 9){
        system("CLS");
        high_math.conversation_with_npc();
    }
    if (current_point == 10){
        system("CLS");
        devil_abyss.conversation_with_npc();
    }
    if (current_point == 11){
        system("CLS");
        BOSS_home.conversation_with_npc();
    }
    if (current_point == 12){
        cout << "[ϵͳ��Ϣ]��ϲ�㣬������������������磡" << endl;
        cout << "\t����ʱ��Ť��������������˺����ԭ�ӣ�so��you die!" << endl;
        cout << "[ϵͳ��Ϣ]��óɾͣ������ĺ���������" << endl;
        cout << "\t�������е�������㣬���������˸���ά���������Ʒ������ͼ��\n" << endl;
        is_get_handbook = true;
        cout << "\t\t���ػ����ִ�...��" << endl;
        getchar();getchar();
        system("CLS");
        fresh_village.conversation_with_npc1_npc2();
    }
}

void print_map(){
    SetConsoleTextAttribute(hConsole,30);
    cout << "|=========================================================================================================|" << endl;
    cout << "|.........................................................................................................|" << endl;
    cout << "|...��......................................******........................................................|" << endl;
    cout << "|....��...................................**......********................................................|" << endl;
    cout << "|.....��***********************301������**................*******************.............................|" << endl;
    cout << "|.....**........................����¥.......................................**...........................|" << endl;
    cout << "|.....**............................**........................................**..........................|" << endl;
    cout << "|.....**.............................*.........................................�����ִ�...................|" << endl;
    cout << "|.....**..............................***.......................................##.....**.................|" << endl;
    cout << "|...ԭ��.................................**......................................##......**...............|" << endl;
    cout << "|....��******.............................***....................................##........**.............|" << endl;
    cout << "|.......**....**.............................**...................................##.........**...........|" << endl;
    cout << "|........**.....**.............................**********.........................##...........**.........|" << endl;
    cout << "|........**.......*************ũҩϿ��***...............##......................##..............**.......|" << endl;
    cout << "|........**......................#........**...............##...................##.................*****->?" << endl;
    cout << "|........**......................#..........**................##...............##.........................|" << endl;
    cout << "|........**......................#...........**.................###########��ħ��Ԩ.......................|" << endl;
    cout << "|........**......................#............**.............................##...........................|" << endl;
    cout << "|.........**.....................#.............**...........................##............................|" << endl;
    cout << "|...�����˼�.....................#...............**.........................##............................|" << endl;
    cout << "|.........##.....................#.................*.........................##...........................|" << endl;
    cout << "|..........##...................##...........��ɪ��*.........................##...........................|" << endl;
    cout << "|...........##.................##..............����######....................##...........................|" << endl;
    cout << "|...........##................#.........................##.....................##.........................|" << endl;
    cout << "|.............##..............#..........................##......................##.......................|" << endl;
    cout << "|..............#####�ٻ��.#..........................#.##......................##......................|" << endl;
    cout << "|..........................##......................#####...###....................##......................|" << endl;
    cout << "|............................##...................##...........#..................##......................|" << endl;
    cout << "|.............................##................##..............####################......................|" << endl;
    cout << "|..............................##.............##...................................##.....................|" << endl;
    cout << "|...............................##############.........................************BOOS����...............|" << endl;
    cout << "|............................................��ɫ����*******************..................................|" << endl;
    cout << "|.........................................................................................................|" << endl;
    cout << "|=========================================================================================================|" << endl;
}
void print_menu(){
    while(true){
        system("CLS");
        SetConsoleTextAttribute(hConsole,10);
        char tempChar;
        while(true){
            cout << "����ʾ��ͼ\t��ǰ���ص�\t��ϵͳѡ��\t�ܱ�����Ʒ\t�ݷ���̵�\t�޸�������\t�߸��˳ɾ�\t�����ͼ��" << endl;
            cout << "��ѡ��_____";
            cin >> tempChar;
            if (tempChar >= 49 && tempChar <= 57){
                break;
            }
            else{
                system("CLS");
            }
        }
        int tempChoose;
        tempChoose = tempChar - 48;
        //cin >> tempChoose;
        if (tempChoose == 1){
            SetConsoleTextAttribute(hConsole,150);
            print_map();
            cout << "\n[1.����]\n";
            char tempChar;
            cin >> tempChar;
            SetConsoleTextAttribute(hConsole,9);
            system("CLS");
        }
        if (tempChoose == 2){
            int tempCount = 1;
            cout << "������Ҫȥ�ĵط���[";
            for (int i = 1; i <= 11; i ++){
                if (map_digitization[current_point][i] != "")
                    cout << tempCount++ << "." << map_digitization[current_point][i] << "\t";
            }
            cout << "]" << endl;
            cout << "��ѡ��____";
            int tempChoose_number;
            cin >> tempChoose_number;
            for (int i = 1; i <= 12; i ++){
                if (map_digitization[current_point][tempChoose_number] == name_digitization[i]){
                    current_point = i;
                    break;
                }
            }//cout << current_point << "&&&" << endl;
            //���õص����еĺ�����
            emigrate(current_point);

            /*char tempChar;
            tempChar = getchar();Sleep(2000);
            system("CLS");*/
        }
        if (tempChoose == 3){
            cout << "[1.������Ϸ]\t[2.�浵]\t[3.֧��һ�¿�����]\t[4.ȡ��]" << endl;
            int tempChoose_number;
            cin >> tempChoose_number;
            if (tempChoose_number == 1){
                cout << "[ϵͳ��Ϣ]�޷�������Ϸ������Ҫ������Ȩ�޲��ܽ�����Ϸ��" << endl;
                getchar();
                char tempChar;
                tempChar = getchar();
                system("CLS");
                //exit(0);
            }
            if (tempChoose_number == 2){
                //cout << "[ϵͳ��Ϣ]�޷��浵���޴��Ŀ����߻�û��ѧ�᡾�ٱǡ�" << endl;
                protagonist.archive();
                packsack.archive();
                cout << "�浵�ɹ���" << endl;
                getchar();
                char tempChar;
                tempChar = getchar();
                system("CLS");
            }
            if (tempChoose_number == 3){
                cout << "[ϵͳ��Ϣ]���QQ��3169858658���²�Ҳ������Ҳ�С�" << endl;
                getchar();
                char tempChar;
                tempChar = getchar();
                system("CLS");
            }
            if (tempChoose_number == 4){
                system("CLS");
                continue;
            }
        }
        if (tempChoose == 4){
            SetConsoleTextAttribute(hConsole,15);
            int tempX2, tempY2;
            getxy(tempX2, tempY2);
            while (true){
                packsack.display();
                cout << "[1.ʹ����Ʒ]\t[2.��ж��Ʒ]\t[3.ȡ��]\t��ѡ��__";
                int tempChoose_number;
                cin >> tempChoose_number;
                if (tempChoose_number == 1){
                    cout << "��ѡ�񱳰�����Ʒ___";
                    int tempChoose_1;
                    cin >> tempChoose_1;
                    cout << "��ѡ������___";
                    int tempChoose_amount1;
                    cin >> tempChoose_amount1;
                    packsack.invoking_use(tempChoose_1, tempChoose_amount1);
                }
                if (tempChoose_number == 2){
                    cout << "\t������װ����" << endl;
                    cout << "\t\t";
                    bool flag = false;
                    packsack.equip_display(flag);
                    getchar();getchar();
                    if (flag){
                        cout << "��ѡ����Ʒ___";
                        int tempChoose_2;
                        cin >> tempChoose_2;
                        cout << "��ѡ������___";
                        int tempChoose_amount2;
                        cin >> tempChoose_amount2;
                        packsack.invoking_unuse(tempChoose_2, tempChoose_amount2);
                    }
                    else{
                        cout << "[ϵͳ��Ϣ]û����Ʒ���Բ�ж��" << endl;
                    }
                    getchar();
                }
                if (tempChoose_number == 3){
                    cout << "\n[ϵͳ��Ϣ]�����������..." << endl;
                    getchar();
                    char tempChar;
                    tempChar = getchar();
                    break;
                }
                //SetConsoleTextAttribute(hConsole,15);
                clear_the_conversation(tempX2, tempY2);
            }
        }
        if (tempChoose == 5){
            store.display();
        }
        if (tempChoose == 6){
            protagonist.display();
            getchar();
            char tempChar;
            tempChar = getchar();

        }
        if (tempChoose == 7){
            protagonist.showAchievements();
            getchar();
            getchar();
        }
        if (tempChoose == 8){
            if (is_get_handbook){
                ifstream file;
                string name;
                int kind;
                int max_hitPoints;
                int current_hitPoints;
                int armor;
                int strong;
                int level;
                int gold;
                int exp;
                string state;
                file.open("Monster_all.txt", ios_base :: in);
                if (file){
                    for (int i = 1; i  <= 10; i ++){
                        //cout<<setw(15)<<setiosflags(ios::left)<<setfill('X')<<4000<<endl;
                        cout << "1.���֣�";
                        file >> name;
                        cout << setw(15) << setiosflags(ios::left) << setfill(' ') << name;
                        cout << "\t2.���ࣺ";
                        file >> kind;
                        cout << setw(5) << setiosflags(ios::left) << setfill(' ') << kind;
                        cout << "\t3.����ֵ";
                        file >> max_hitPoints;
                        cout << setw(5) << setiosflags(ios::left) << setfill(' ') << max_hitPoints ;
                        file >> current_hitPoints;
                        cout << "\t4.����ֵ��";
                        file >> armor;
                        cout << setw(5) << setiosflags(ios::left) << setfill(' ') << armor ;
                        cout << "\t5.��������";
                        file >> strong;
                        cout << setw(5) << setiosflags(ios::left) << setfill(' ') << strong ;
                        cout << "\t6.�ȼ���" ;
                        file >> level;
                        cout << setw(5) << setiosflags(ios::left) << setfill(' ') << level ;;
                        cout << "\t7.��ɱ��ҽ�����";
                        file >> gold;
                        cout << setw(5) << setiosflags(ios::left) << setfill(' ') << gold ;
                        cout << "\t8.��ɱ���齱����";
                        file >> exp;
                        cout << setw(5) << setiosflags(ios::left) << setfill(' ') << exp ;
                        cout << endl;
                    }
                }
                file.close();
                getchar();getchar();
            }
            else{
                cout << "[ϵͳ��Ϣ]����Ҫ����ԱȨ�޲��ܴ򿪴�ͼ������" << endl;
                getchar();getchar();
            }
        }

    }

}
void print_the_background(){
    SetConsoleTextAttribute(hConsole,15);
    cout << "���ϵİ��������Ǵ�½�ϣ���Զʼ֮ս������ǧ��֮�ã��ܱ���ħ��һֱ����������" << endl;
    cout << "�ںڰ��н�����������Ż��ú���ɫ�ٴ�������Ƭ��½��" << endl;
    cout << "���޵�ħ��֮Ů��̰������������Ƭ�����Ĵ�½����ʹ��ħ���������ļ�԰��" << endl;
    getchar();
    SetConsoleTextAttribute(hConsole,13);
    cout << "����ԭ���ҵ�����(�s������)�s��ߩ��ߡ�" << endl;
    SetConsoleTextAttribute(hConsole,15);
    getchar();
    cout << "��ʥ����1037��ħ��������ս������ʱ��㹥���������ǣ��������֮�ʣ�����ս����������ף�" << endl;
    cout << "һ���ڽ��ʺ�ĸ��У���һ��������ħŮ������塣" << endl;
    cout << "������ħŮ�ֻ��˱����ó�����һ�����ء�" << endl;
    cout << "�����������������������������֮ʱ����߽����˸��������������������ע�⵽����ڹ�����ͷһ����û��" << endl;
    getchar();
    cout << "��ʥ����1054��ħŮð��Ǳ��������������������һ�ˣ�������°��" << endl;
    getchar();
    SetConsoleTextAttribute(hConsole,13);
    cout << "���һ��ȡ����顭��emmmm�����壬�ҵ�Ĥ���������˺����Ƭ(�s������)�s��ߩ��ߡ� " << endl;
    getchar();
    SetConsoleTextAttribute(hConsole,15);
    cout << "Σ���ٴ�ϯ���������Ǵ�½��" << endl;
    cout << "�ٷϴ��˵���ʥ������Ҳ�����ɱ�Ӫ�ȹ������Ϲ����Ѹ�ȫ������������������Ԯ��֮��! " << endl;
    cout << "�㱳��������������98K����Ȼ��Ȼ��̤�Ͼ���֮·��������" << endl;
    cout << "" << endl;
    getchar();
    cout << "�߰ɣ������ɡ�" << endl;
    int tempChar;
    tempChar = getchar();
    SetConsoleTextAttribute(hConsole,13);
    cout << "[ϵͳ��Ϣ]������...";
    Sleep(2000);
    for (int i = 1; i <= 50; i ++)
        cout << "\b";
}

//�� print_the_beginning �ģ�

static const unsigned char ASCII_TAB[][5]=  //5*7
{
    { 0x00, 0x00, 0x00, 0x00, 0x00 },   // sp
    { 0x00, 0x00, 0x2f, 0x00, 0x00 },   // !
    { 0x00, 0x07, 0x00, 0x07, 0x00 },   // "
    { 0x14, 0x7f, 0x14, 0x7f, 0x14 },   // #
    { 0x24, 0x2a, 0x7f, 0x2a, 0x12 },   // $
    { 0xc4, 0xc8, 0x10, 0x26, 0x46 },   // %
    { 0x36, 0x49, 0x55, 0x22, 0x50 },   // &
    { 0x00, 0x05, 0x03, 0x00, 0x00 },   // '
    { 0x00, 0x1c, 0x22, 0x41, 0x00 },   // (
    { 0x00, 0x41, 0x22, 0x1c, 0x00 },   // )
    { 0x14, 0x08, 0x3E, 0x08, 0x14 },   // *
    { 0x08, 0x08, 0x3E, 0x08, 0x08 },   // +
    { 0x00, 0x00, 0x50, 0x30, 0x00 },   // ,
    { 0x10, 0x10, 0x10, 0x10, 0x10 },   // -
    { 0x00, 0x60, 0x60, 0x00, 0x00 },   // .
    { 0x20, 0x10, 0x08, 0x04, 0x02 },   // /

    { 0x3E, 0x51, 0x49, 0x45, 0x3E },   // 0
    { 0x00, 0x42, 0x7F, 0x40, 0x00 },   // 1
    { 0x42, 0x61, 0x51, 0x49, 0x46 },   // 2
    { 0x21, 0x41, 0x45, 0x4B, 0x31 },   // 3
    { 0x18, 0x14, 0x12, 0x7F, 0x10 },   // 4
    { 0x27, 0x45, 0x45, 0x45, 0x39 },   // 5
    { 0x3C, 0x4A, 0x49, 0x49, 0x30 },   // 6
    { 0x01, 0x71, 0x09, 0x05, 0x03 },   // 7
    { 0x36, 0x49, 0x49, 0x49, 0x36 },   // 8
    { 0x06, 0x49, 0x49, 0x29, 0x1E },   // 9

    { 0x00, 0x36, 0x36, 0x00, 0x00 },   // :
    { 0x00, 0x56, 0x36, 0x00, 0x00 },   // ;
    { 0x08, 0x14, 0x22, 0x41, 0x00 },   // <
    { 0x14, 0x14, 0x14, 0x14, 0x14 },   // =
    { 0x00, 0x41, 0x22, 0x14, 0x08 },   // >
    { 0x02, 0x01, 0x51, 0x09, 0x06 },   // ?
    { 0x32, 0x49, 0x59, 0x51, 0x3E },   // @

    { 0x7E, 0x11, 0x11, 0x11, 0x7E },   // A
    { 0x7F, 0x49, 0x49, 0x49, 0x36 },   // B
    { 0x3E, 0x41, 0x41, 0x41, 0x22 },   // C
    { 0x7F, 0x41, 0x41, 0x22, 0x1C },   // D
    { 0x7F, 0x49, 0x49, 0x49, 0x41 },   // E
    { 0x7F, 0x09, 0x09, 0x09, 0x01 },   // F
    { 0x3E, 0x41, 0x49, 0x49, 0x7A },   // G
    { 0x7F, 0x08, 0x08, 0x08, 0x7F },   // H
    { 0x00, 0x41, 0x7F, 0x41, 0x00 },   // I
    { 0x20, 0x40, 0x41, 0x3F, 0x01 },   // J
    { 0x7F, 0x08, 0x14, 0x22, 0x41 },   // K
    { 0x7F, 0x40, 0x40, 0x40, 0x40 },   // L
    { 0x7F, 0x02, 0x0C, 0x02, 0x7F },   // M
    { 0x7F, 0x04, 0x08, 0x10, 0x7F },   // N
    { 0x3E, 0x41, 0x41, 0x41, 0x3E },   // O
    { 0x7F, 0x09, 0x09, 0x09, 0x06 },   // P
    { 0x3E, 0x41, 0x51, 0x21, 0x5E },   // Q
    { 0x7F, 0x09, 0x19, 0x29, 0x46 },   // R
    { 0x46, 0x49, 0x49, 0x49, 0x31 },   // S
    { 0x01, 0x01, 0x7F, 0x01, 0x01 },   // T
    { 0x3F, 0x40, 0x40, 0x40, 0x3F },   // U
    { 0x1F, 0x20, 0x40, 0x20, 0x1F },   // V
    { 0x3F, 0x40, 0x38, 0x40, 0x3F },   // W
    { 0x63, 0x14, 0x08, 0x14, 0x63 },   // X
    { 0x07, 0x08, 0x70, 0x08, 0x07 },   // Y
    { 0x61, 0x51, 0x49, 0x45, 0x43 },   // Z

    { 0x00, 0x7F, 0x41, 0x41, 0x00 },   // [
    { 0x55, 0x2A, 0x55, 0x2A, 0x55 },   // '\'
    { 0x00, 0x41, 0x41, 0x7F, 0x00 },   // ]
    { 0x04, 0x02, 0x01, 0x02, 0x04 },   // ^
    { 0x40, 0x40, 0x40, 0x40, 0x40 },   // _
    { 0x00, 0x01, 0x02, 0x04, 0x00 },   // '

    { 0x20, 0x54, 0x54, 0x54, 0x78 },   // a
    { 0x7F, 0x48, 0x44, 0x44, 0x38 },   // b
    { 0x38, 0x44, 0x44, 0x44, 0x20 },   // c
    { 0x38, 0x44, 0x44, 0x48, 0x7F },   // d
    { 0x38, 0x54, 0x54, 0x54, 0x18 },   // e
    { 0x08, 0x7E, 0x09, 0x01, 0x02 },   // f
    { 0x0C, 0x52, 0x52, 0x52, 0x3E },   // g
    { 0x7F, 0x08, 0x04, 0x04, 0x78 },   // h
    { 0x00, 0x44, 0x7D, 0x40, 0x00 },   // i
    { 0x20, 0x40, 0x44, 0x3D, 0x00 },   // j
    { 0x7F, 0x10, 0x28, 0x44, 0x00 },   // k
    { 0x00, 0x41, 0x7F, 0x40, 0x00 },   // l
    { 0x7C, 0x04, 0x18, 0x04, 0x78 },   // m
    { 0x7C, 0x08, 0x04, 0x04, 0x78 },   // n
    { 0x38, 0x44, 0x44, 0x44, 0x38 },   // o
    { 0x7C, 0x14, 0x14, 0x14, 0x08 },   // p
    { 0x08, 0x14, 0x14, 0x18, 0x7C },   // q
    { 0x7C, 0x08, 0x04, 0x04, 0x08 },   // r
    { 0x48, 0x54, 0x54, 0x54, 0x20 },   // s
    { 0x04, 0x3F, 0x44, 0x40, 0x20 },   // t
    { 0x3C, 0x40, 0x40, 0x20, 0x7C },   // u
    { 0x1C, 0x20, 0x40, 0x20, 0x1C },   // v
    { 0x3C, 0x40, 0x30, 0x40, 0x3C },   // w
    { 0x44, 0x28, 0x10, 0x28, 0x44 },   // x
    { 0x0C, 0x50, 0x50, 0x50, 0x3C },   // y
    { 0x44, 0x64, 0x54, 0x4C, 0x44 }    // z
};
const int SCREEN_COLS   =       170 ; /* how many columns does terminal have */
const int HORIZONTAL_DISTANCE = 4  ; /* horizontal distance between two characters (�о�) */
const int VERTICAL_DISTANCE   = 1  ; /* vertical distance  between two rows of characters (�о�) */
const char BRUSH_CHAR        =  '*';
const char BLANK_CHAR       =   ' ';

/* ASCII_TAB��ģ������ĸ߶ȺͿ�� */
const int FONT_ROWS       =     13;
const int FONT_COLS      =      5;

/* ��Ļÿ����������ʾ���ַ����� */
const int CHAR_PER_LINE    =       (SCREEN_COLS/(FONT_COLS + HORIZONTAL_DISTANCE));

static char get_char_xy(char ch, int x, int y)
{
    if (ch < ' ' || ch > 'z')
        ch = ' ';
    ch -= ' ';
    return (ASCII_TAB[ch][x] & (1<<y)) ? BRUSH_CHAR : BLANK_CHAR;
}
static void print_row(char ch, int row)
{
    int i;
    for (i = 0; i < FONT_COLS; i++) {
        printf("%c", get_char_xy(ch, i, row));
    }
}
void print_the_beginning(){
    char str[80] = " Come and save the     princess";
    int i, j, k, len, index = 0;
    //printf("Please input a string:\n");
    //gets(str);
    //scanf("%s", str);
    len = strlen(str);
    while (index < len) {
        for (i = 0; i < FONT_ROWS; i++) {
            for (j = 0; j < CHAR_PER_LINE && j + index < len; j++) {
                print_row(str[index + j], i);
                for (k = 0; k < HORIZONTAL_DISTANCE; k++) {
                    printf("%c", BLANK_CHAR);
                }
            }
            printf("\n");
        }
        index += CHAR_PER_LINE;
        for (k = 0; k < VERTICAL_DISTANCE; k++) {
            printf("\n");
        }
    }
    for (int i = 1; i <= 0; i ++)
        cout << endl;
    cout << "�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z" << endl;
    cout << "�� " << endl;
    cout << "��\t��Ϸ���֣���һ�����ȹ����ɣ���" << endl;
    cout << "��" << endl;
    cout << "��\t�汾8.0" << endl;
    cout << "��" << endl;
    cout << "��\t��Ϸ���ܣ� c++�γ����Сѧ�ڵĲ���" << endl;
    cout << "��" << endl;
    cout << "��\tMUD��Ϸ�����ߣ����ա���𩡢۬��ǿ�����裨һ�飩" << endl;
    cout << "��" << endl;
    cout << "��\tQQ��1497058369" << endl;
    cout << "��" << endl;
    cout << "�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z�z" << endl;
    getchar();
    system("CLS");
}
int main(){
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//������ɫ
    protagonist.getMessage();
    protagonist.totalExperence();
    map_digitized();

    //BOSS_home.conversation_with_npc();
    //depth_of_flowers.conversation_with_npc();
   // store.display();
  // print_menu();
   //BOSS_home.conversation_with_npc();

//��ʼ��
    print_the_beginning();
    print_the_background();
    SetConsoleTextAttribute(hConsole,3);
    cout<< "\nΪ���������Ϸ�������Ƚ��������밴������ϲ������һ���������� ";
    SetConsoleTextAttribute(hConsole,5);
    /*cout << "1.�۰���($1000)" << endl;
    cout << "2.������($900)" << endl;
    cout << "3.����($500)" << endl;
    cout << "4.������($100)" << endl;
    int temp1;
    cin >> temp1;*/
    string tempString;
    cin >> tempString;
    getchar();
    SetConsoleTextAttribute(hConsole,6);
    cout << "�õģ����������������Ǻ����ѧ�����������ֶ���ô���أ�" << endl;
    SetConsoleTextAttribute(hConsole,7);
    cout << "��ȥӪ�ȹ�����~~" << endl;
    getchar();
    system("CLS");
    //SetConsoleTextAttribute(hConsole,2);
    //cout << "<������(cai)��(ji)����....>\n" << endl;
    SetConsoleTextAttribute(hConsole,8);

    fresh_village.getMessage();
    fresh_village.conversation_with_npc1_npc2();
    SetConsoleTextAttribute(hConsole,10);

    print_menu();
    return 0;
}
