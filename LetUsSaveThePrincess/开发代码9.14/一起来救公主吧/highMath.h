#pragma once
#include <bits/stdc++.h>
using namespace std;
HANDLE  hConsole_highMath;
class highMath {
public:
	highMath() {
		getMessage();
	}
	void conversation_with_npc() {

		hConsole_highMath = GetStdHandle(STD_OUTPUT_HANDLE);//������ɫ
		SetConsoleTextAttribute(hConsole_highMath, 4);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~�������ִ塿~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		int tempX, tempY;
		char tempChar;
		cout << "��ѧ���������߱����¶����¡������ִ延ӭ�㣡" << endl;
		tempChar = getchar();
		tempChar = getchar();
		getxy(tempX, tempY);
		cout << "\t������(LV." << protagonist.showLevel() << "): �е��˻��ţ����Ѿ�����... �е������ˣ��Ͳ����ñ��˻����ţ�٣���������..." << endl;
		tempChar = getchar();
		cout << "\t" << highMath_npc1_name << "(LV." << highMath_npc1_lv << "):" << endl;
		cout << "\t\t" << "���������ϣ�ѧ���ø����͹ֱ��ˣ�" << endl;
		tempChar = getchar();
		cout << "\t" << highMath_npc2_name << "(Lv." << highMath_npc2_lv << "):" << endl;
		cout << "\t\t" << "���Ǿ��ǣ��治Ҫ����" << endl;
		tempChar = getchar();
		clear_the_conversation(tempX, tempY);

		SetConsoleTextAttribute(hConsole_highMath, 6);
		cout << "\t������(LV." << protagonist.showLevel() << "): ˵˭�أ�����ͷ��! �Ҹ��������Ϲ�60�ֵģ�" << endl;
		tempChar = getchar();
		cout << "\t" << highMath_npc2_name << "(LV." << highMath_npc2_lv << "):" << endl;
		cout << "\t\t" << "ӴӴ���ɲ����ˣ�" << endl;
		tempChar = getchar();
		cout << "\t" << highMath_npc1_name << "(LV." << highMath_npc1_lv << "):" << endl;
		cout << "\t\t" << "tan90��!" << endl;
		tempChar = getchar();
		clear_the_conversation(tempX, tempY);

		SetConsoleTextAttribute(hConsole_highMath, 8);
		cout << "\t������(LV." << protagonist.showLevel() << "): ʮ���ڵļӼ��˳����ſھͳ���" << endl;
		tempChar = getchar();
		cout << "\t" << highMath_npc1_name << "(LV." << highMath_npc1_lv << "):" << endl;
		cout << "\t\t" << "������ɧ���β��������" << endl;
		tempChar = getchar();
		clear_the_conversation(tempX, tempY);

		SetConsoleTextAttribute(hConsole_highMath, 9);
		cout << "\t" << highMath_npc2_name << "(LV." << highMath_npc2_lv << "):" << endl;
		cout << "\t\t" << "��(-a,a)��(a * a - x * x)������������Ҿ͸����㹫������Ϣ��" << endl;
		cout << "\t\t" << "1. ��a * a,    2. 0.25��a * a,    3. 0.5��a * a,  " << endl;
		cout << "\t\t  4. ���ϴ𰸶�����ȷ,    5. �Ҳ�֪��" << endl;
		cout << "��ѡ��______";
		getxy(tempX, tempY);
		int choose;
		while (true){
            cin >> choose;
            if (choose == 1){
                SetConsoleTextAttribute(hConsole_highMath, 2);
                cout << "[ϵͳ��Ϣ]��Ү���𰸴��ˡ�" << endl;
                tempChar = getchar();
                cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ�����һB" << endl;
			    protagonist.add_achievement("����һB");
			    tempChar = getchar();
                cout << "\t" << highMath_npc1_name << "(LV." << highMath_npc1_lv << "):" << endl;
                cout << "\t\t" << "�������Ϲ�60�֣��������Ҷ����ţ�" << endl;
                tempChar = getchar();
			    clear_the_conversation(tempX, tempY);
		    }
		    if (choose == 2){
		        SetConsoleTextAttribute(hConsole_highMath, 3);
                cout << "[ϵͳ��Ϣ]����ѽ����ɳ����İɣ�" << endl;
                tempChar = getchar();
                cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ�����һB" << endl;
			    protagonist.add_achievement("����һB");
                cout << "\t" << highMath_npc1_name << "(LV." << highMath_npc1_lv << "):" << endl;
                cout << "\t\t" << "����ţ����������" << endl;
                tempChar = getchar();
			    clear_the_conversation(tempX, tempY);
		    }
		    if (choose == 3) {
		        SetConsoleTextAttribute(hConsole_highMath, 12);
                cout << "[ϵͳ��Ϣ]�����ˣ��ҵĹ���������ȷ����ý���������+100" << endl;
                protagonist.experienceAmount_plus(100);
                tempChar = getchar();
			    cout << "\t" << highMath_npc1_name << "(LV." << highMath_npc1_lv << "):" << endl;
                cout << "\t\t" << "�������ɵİɣ�" << endl;
			    tempChar = getchar();
			    cout << "\t" << highMath_npc2_name << "(LV." << highMath_npc2_lv << "):" << endl;
			    cout << "\t\t" << "������ץ���ϱߵ����֮�֣�����ǰ��Ķ�ħ֮Ԩ���ܵ������֮���ˣ�ǧ���ȥ��������" << endl;
			    tempChar = getchar();
			    clear_the_conversation(tempX, tempY);
                break;

		    }
            if (choose == 4){
                SetConsoleTextAttribute(hConsole_highMath, 13);
                cout << "[ϵͳ��Ϣ]���Ǻ��������Ķ�����" << endl;
                tempChar = getchar();
                cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ�����һB" << endl;
			    protagonist.add_achievement("����һB");
			    tempChar = getchar();
			    clear_the_conversation(tempX, tempY);
            }
		    if (choose == 5) {
		        SetConsoleTextAttribute(hConsole_highMath, 10);
                cout << "[ϵͳ��Ϣ]��ܳ�ʵ�����������֣�" << endl;
                tempChar = getchar();
			    cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ�����һB" << endl;
			    protagonist.add_achievement("����һB");
			    tempChar = getchar();
			    clear_the_conversation(tempX, tempY);
		    }
		    if (choose >= 6){
		        SetConsoleTextAttribute(hConsole_highMath, 14);
                cout << "[ϵͳ��Ϣ]û���ѡ���ɵ����" << endl;
                tempChar = getchar();
                cout << "[ϵͳ��Ϣ]��ϲ������óɾͣ�ɵ������" << endl;
                protagonist.add_achievement("ɵ������");
			    tempChar = getchar();
			    clear_the_conversation(tempX, tempY);
		    }
        }

	}
	void getMessage() {
		ifstream file;
		file.open("highMath_npc.txt", ios_base::in);
		if (file) {
			file >> highMath_npc1_name;
			file >> highMath_npc1_lv;
			file >> highMath_npc2_name;
			file >> highMath_npc2_lv;
		}
		file.close();
	}
private:
	string highMath_npc1_name;
	int highMath_npc1_lv;
	string highMath_npc2_name;
	int highMath_npc2_lv;

};
