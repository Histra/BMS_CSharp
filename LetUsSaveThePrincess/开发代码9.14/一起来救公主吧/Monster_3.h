#pragma once
class Monster_3 : public Monster{
public:
    void getMessage(){
        ifstream file;
        file.open("Monster_3.txt",ios_base :: in);
        if(file){
            file >> name;
            file >> kind;
            file >> max_hitPoints;
            file >> current_hitPoints;
            file >> armor;
            file >> strong;
            file >> level;
            file >> gold;
            file >> exp;
        }
        file.close();
    }
};
