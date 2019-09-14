#pragma once
#include <bits/stdc++.h>
#include <windows.h>
#include "Object.h"
#include "Curative.h"
#include "Blade.h"
#include "Sword.h"
#include "Shoe.h"
#include "Crown.h"
#include "Clothes.h"
#include "Packsack.h"
using namespace std;
//Packsack packsack;
class Store {
public:
	Store(){}
	void display(){
	    while (true){
            cout << "��ӭ���٣������̵ꡣ������ʲô��Ҫ��" << endl;
            cout << "[1.����]\t[2.����]\t[3.ȡ��]" << endl;
            cout << "��ѡ��_____" ;
            int tempChoose;
            cin >> tempChoose;
            if (tempChoose == 1){
                system("CLS");
                cout << "[ϵͳ��Ϣ]��ӵ�н�Ǯ��" << packsack.getPossession() << "��" << endl;
                cout << "\n��ѡ��Ҫ����Ķ�����" << endl;
                cout << "1." << BOTTLE.getName() << "(�ָ�" <<BOTTLE.getAddHitPoint() << "������ֵ)";
                cout << setw(21) << BOTTLE.getPrice() << "��" << endl;
                cout << "2." << BLADE.getName() << "(����" << BLADE.getaddAttack() << "�㹥��)";
                cout << setw(20) << BLADE.getPrice() << "��" << endl;
                cout << "3." << SWORD.getName() << "(����" << SWORD.getaddAttack() << "�㹥��)";
                cout << setw(20) << SWORD.getPrice() << "��" << endl;
                cout << "4." << SHOE.getName() << "(����" << SHOE.getaddDefense() << "�㻤��)";
                cout << setw(16) << SHOE.getPrice() << "��" << endl;
                cout << "5." << CROWN.getName() << "(����" << CROWN.getaddDefense() << "�㻤��)";
                cout << setw(18) << CROWN.getPrice() << "��" << endl;
                cout << "6." << CLOTHES.getName() << "(����" << CLOTHES.getaddDefense() << "�㻤��)";
                cout << setw(16) << CLOTHES.getPrice() << "��" << endl;
                cout << "7.��������" << endl;
                cout << endl;
                buy(packsack);
            }
            if (tempChoose == 2){
                system("CLS");
                cout << "[ϵͳ��Ϣ]��ӵ�н�Ǯ��" << packsack.getPossession() << "��" << endl;
                packsack.display();
                sell(packsack);

            }
            if (tempChoose == 3){
                break;
            }
	    }
    }
	void buy(Packsack &packsack) {
        int buyChoose = 0;
        while (true) {
            cout << "��ѡ��___";
            cin >> buyChoose;
            int buyAmount;
            if (buyChoose != 7){
                cout << "��ѡ������___";
                cin >> buyAmount;
            }
            switch (buyChoose) {
            case 1:
                if (packsack.getPossession() >= packsack.getBottle().getPrice() * buyAmount) {
                    packsack.getBottle().number_plus(buyAmount);
                    packsack.buyPossession(packsack.getBottle().getPrice()* buyAmount);
                    cout << "[ϵͳ��Ϣ]����ɹ��������   " << packsack.getBottle().getName() << buyAmount <<"  ƿ!";
                    cout << "\t\t<ʣ��������  " << packsack.getPossession() << ">" << endl;
                }
                else
                    cout << "[ϵͳ��Ϣ]Ǯ����ѽ��" << endl;
                break;
            case 2:
                if (packsack.getPossession() >= packsack.getBlade().getPrice() * buyAmount) {
                    packsack.getBlade().number_plus(buyAmount);
                    packsack.buyPossession(packsack.getBlade().getPrice()* buyAmount);
                    cout << "[ϵͳ��Ϣ]����ɹ��������   " << packsack.getBlade().getName() << buyAmount <<"  ��!";
                    cout << "\t\t<ʣ��������  " << packsack.getPossession() << ">" << endl;
                }
                else
                    cout << "[ϵͳ��Ϣ]Ǯ����ѽ��" << endl;
                break;
            case 3:
                if (packsack.getPossession() >= packsack.getSword().getPrice() * buyAmount) {
                    packsack.getSword().number_plus(buyAmount);
                    packsack.buyPossession(packsack.getSword().getPrice()* buyAmount);
                    cout << "[ϵͳ��Ϣ]����ɹ��������   " << packsack.getSword().getName() << buyAmount <<"  ��!";
                    cout << "\t\t<ʣ��������  " << packsack.getPossession() << ">" << endl;
                }
                else
                    cout << "[ϵͳ��Ϣ]Ǯ����ѽ��" << endl;
                break;
            case 4:
                if (packsack.getPossession() >= packsack.getShoe().getPrice() * buyAmount) {
                    packsack.getShoe().number_plus(buyAmount);
                    packsack.buyPossession(packsack.getShoe().getPrice()* buyAmount);
                    cout << "[ϵͳ��Ϣ]����ɹ��������  " << packsack.getShoe().getName() << buyAmount <<"  ˫!";
                    cout << "\t\t<ʣ��������  " << packsack.getPossession() << ">" << endl;
                }
                else
                    cout << "[ϵͳ��Ϣ]Ǯ����ѽ��" << endl;
                break;
            case 5:
                if (packsack.getPossession() >= packsack.getCrown().getPrice() * buyAmount) {
                    packsack.getCrown().number_plus(buyAmount);
                    packsack.buyPossession(packsack.getCrown().getPrice()* buyAmount);
                    cout << "[ϵͳ��Ϣ]����ɹ��������  " << packsack.getCrown().getName() << buyAmount <<"  ��!";
                    cout << "\t\t<ʣ��������  " << packsack.getPossession() << ">" << endl;
                }
                else
                    cout << "[ϵͳ��Ϣ]Ǯ����ѽ��" << endl;
                break;
            case 6:
                if (packsack.getPossession() >= packsack.getClothes().getPrice() * buyAmount) {
                    packsack.getClothes().number_plus(buyAmount);
                    packsack.buyPossession(packsack.getClothes().getPrice()* buyAmount);
                    cout << "[ϵͳ��Ϣ]����ɹ��������  " << packsack.getClothes().getName() << buyAmount <<"  ��!";
                    cout << "\t\t<ʣ��������  " << packsack.getPossession() << ">" << endl;
                }
                else
                    cout << "[ϵͳ��Ϣ]Ǯ����ѽ��" << endl;
                break;
            case 7:
                cout << "[ϵͳ��Ϣ]���������" << endl;
                cout << "##############################################################" << endl;
                packsack.display();
                getchar();
                char tempChar;
                tempChar = getchar();
                system("CLS");
                //display();
            }
            if (buyChoose == 7)
                break;
        }
    }
	void sell(Packsack &packsack){
        int sellChoose = 0;
        while (true) {
            cout << "\n��ѡ��Ҫ���۵Ķ���<0.ȡ��>_____";
            cin >> sellChoose;
            int sellAmount;
            if(sellChoose != 0){
                cout << "��ѡ������___" ;
                cin >> sellAmount;
            }
            switch (sellChoose) {
            case 1:
                if (packsack.getBottle().getNumber() >= sellAmount) {
                    packsack.getBottle().number_decline(sellAmount);
                    packsack.sellPossession(packsack.getBottle().getPrice()* sellAmount);
                    cout << "[ϵͳ��Ϣ]���۳ɹ�������  " << packsack.getBottle().getName() << sellAmount << " ƿ";
                    cout << "\t<��ý�ң�" << packsack.getBottle().getPrice() / 2 * sellAmount << "��>" << endl;
                    cout << "******************************************************************" << endl;
                }
                else {
                    cout << "[ϵͳ��Ϣ]�������㣡" << endl;
                }

                break;
            case 2:
                if (packsack.getBlade().getNumber() >= sellAmount) {
                    packsack.getBlade().number_decline(sellAmount);
                    packsack.sellPossession(packsack.getBlade().getPrice() * sellAmount);
                    cout << "[ϵͳ��Ϣ]���۳ɹ�������  " << packsack.getBlade().getName() << sellAmount << " ��";
                    cout << "\t<��ý�ң�" << packsack.getBlade().getPrice() / 2 * sellAmount << "��>" << endl;
                    cout << "******************************************************************" << endl;
                }
                else {
                    cout << "[ϵͳ��Ϣ]�������㣡" << endl;
                }

                break;
            case 3:
                if (packsack.getSword().getNumber() >= sellAmount) {
                    packsack.getSword().number_decline(sellAmount);
                    packsack.sellPossession(packsack.getSword().getPrice() * sellAmount);
                    cout << "[ϵͳ��Ϣ]���۳ɹ�������  " << packsack.getSword().getName() << sellAmount << " ��";
                    cout << "\t<��ý�ң�" << packsack.getSword().getPrice() / 2 * sellAmount << "��>" << endl;
                    cout << "******************************************************************" << endl;
                }
                else {
                    cout << "[ϵͳ��Ϣ]�������㣡" << endl;
                }

                break;
            case 4:
                if (packsack.getShoe().getNumber() >= sellAmount) {
                    packsack.getShoe().number_decline(sellAmount);
                    packsack.sellPossession(packsack.getShoe().getPrice() * sellAmount);
                    cout << "[ϵͳ��Ϣ]���۳ɹ�������  " << packsack.getShoe().getName() << sellAmount << " ˫";
                    cout << "\t<��ý�ң�" << packsack.getShoe().getPrice() / 2 * sellAmount << "��>" << endl;
                    cout << "******************************************************************" << endl;
                }
                else {
                    cout << "[ϵͳ��Ϣ]�������㣡" << endl;
                }

                break;
            case 5:
                if (packsack.getCrown().getNumber() >= sellAmount) {
                    packsack.getCrown().number_decline(sellAmount);
                    packsack.sellPossession(packsack.getCrown().getPrice() * sellAmount);
                    cout << "[ϵͳ��Ϣ]���۳ɹ�������  " << packsack.getCrown().getName() << sellAmount << " ��";
                    cout << "\t<��ý�ң�" << packsack.getCrown().getPrice() / 2 * sellAmount << "��>" << endl;
                    cout << "******************************************************************" << endl;
                }
                else {
                    cout << "[ϵͳ��Ϣ]�������㣡" << endl;
                }

                break;
            case 6:
                if (packsack.getClothes().getNumber() >= sellAmount) {
                    packsack.getClothes().number_decline(sellAmount);
                    packsack.sellPossession(packsack.getClothes().getPrice() * sellAmount);
                    cout << "[ϵͳ��Ϣ]���۳ɹ�������  " << packsack.getClothes().getName() << sellAmount << " ��";
                    cout << "\t<��ý�ң�" << packsack.getClothes().getPrice() / 2 * sellAmount << "��>" << endl;
                    cout << "******************************************************************" << endl;
                }
                else {
                    cout << "[ϵͳ��Ϣ]�������㣡" << endl;
                }

                break;
            case 0 :
                cout << "[ϵͳ��Ϣ]���۽�����" << endl;
                char tempChar;
                getchar();
                tempChar = getchar();
                system("CLS");
                //display();
            }
            if (sellChoose != 0)
                packsack.display();
            else
                break;
        }
    }
private:
	Curative BOTTLE;
	Blade BLADE;
	Sword SWORD;
	Shoe SHOE;
	Crown CROWN;
	Clothes CLOTHES;
};

