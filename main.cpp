#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;



class DB_list {
    string name;
    string movie_name;
    string seat;
    int price;
    string date;
    int room;
    int id;
public:
    void addInfo(DB_list *list, int index);
    void deleteInfo(DB_list *list, int index);
    void readInfo(DB_list *list, int index);
    void updateInfo(DB_list *list, int index);
    void search_by_name(DB_list *list, int index);
    void search_by_moviename(DB_list *list, int index);
    void leftSeats(DB_list *list, int index);
    void saveData(DB_list *list, int index);
    int loadData(DB_list *list);
};


void DB_list::addInfo(DB_list* list, int index){
    int room;
    
    cout << "������ �̸�: ";
    cin >> list[index].name;
    cout << "��ȭ �̸�: ";
    cin >> list[index].movie_name;
    cout << "Ƽ�� �¼�: ";
    cin >> list[index].seat;
    cout << "��ȭ ����: ";
    cin >> list[index].price;
    cout << "�� ��¥: ";
    cin >> list[index].date;
    cout << "��ȭ��: ";
    cin >> room;
    while((room == 0) || (room > 7)){
        cout << "�ùٸ��� ���� �󿵰� �����Դϴ�!" << endl;
        cout << "��ȭ��: ";
        cin >> room;
    }
    list[index].room = room;

    cout << "�����!" << endl;
    list[index].id = index + 1;
}
 
void DB_list::readInfo(DB_list *list, int index){

    for(int i = 0; i < index; i++) {
        if(list[i].price == -1) continue;
        else{
        cout << "\n���Ź�ȣ: " << list[i].id << "��" << endl;
        cout << "********************************************************" << endl;
        cout << "*                                                          *" << endl;
        cout << "*          ��ȭ ����: " << list[i].movie_name << "         \t*" << endl;
        cout << "*      ���Ͻ�: " << list[i].seat << "           ������: " << list[i].name << "      *" << endl;  
        cout << "*      �¼�: " << list[i].room << "�� "<< list[i].seat << "           ����: " << list[i].price << "  \t*" << endl;
        cout << "*                                                     *" << endl;
        cout << "*******************************************************" << endl;
        }
    }
}

void DB_list::updateInfo(DB_list *list, int index){
    int number;

    readInfo(list, index);

    cout << "������ �����ȣ��?: ";
    cin >> number;
    cout << "������ �̸�: ";
    cin >> list[number-1].name;
    cout << "��ȭ �̸�: ";
    cin >> list[number-1].movie_name;
    cout << "Ƽ�� �¼�: ";
    cin >> list[number-1].seat;
    cout << "��ȭ ����: ";
    cin >> list[number-1].price;
    cout << "�� ��¥: ";
    cin >> list[number-1].date;
    cout << "��ȭ��: ";
    cin >> list[number-1].room;
    cout << "������!" << endl;
}

void DB_list::deleteInfo(DB_list *list, int index){
    int number, confirm;

    readInfo(list, index);

    cout << "��ȣ��? (���: 0) " << endl;
    cin >> number;
    if(number == 0) return;

    cout << "������ �����Ͻðڽ��ϱ�? (����: 1) " << endl;
    cin >> confirm;

    if(confirm == 1){
        list[number-1].price = -1;
        cout << "������!!" << endl;
    }
}

void DB_list::search_by_name(DB_list *list, int index){
    string name;
    int scnt = 0;

    cout << "�˻��� ������ �̸���?: ";
    cin >> name;

    char char_name[name.length() + 1];
    name.copy(char_name, name.length() + 1);

    for(int i=0; i<index; i++) {
        if(list[i].price == -1) continue;

        char data_name[list[i].name.length() + 1];
        list[i].name.copy(data_name, list[i].name.length() + 1);
     
        if(strstr(data_name, char_name)) {
            cout << "\n���Ź�ȣ: " << list[i].id << "��" << endl;
            cout << "********************************************************" << endl;
            cout << "*                                                          *" << endl;
            cout << "*          ��ȭ ����: " << list[i].movie_name << "         \t*" << endl;
            cout << "*      ���Ͻ�: " << list[i].seat << "           ������: " << list[i].name << "      *" << endl;  
            cout << "*      �¼�: " << list[i].room << "�� "<< list[i].seat << "           ����: " << list[i].price << "  \t*" << endl;
            cout << "*                                                     *" << endl;
            cout << "*******************************************************" << endl;
            scnt++;
        }
    }

    if(scnt==0) cout << "\n=> �˻��� ������ ����!" << endl;
    else cout << "\n=> �� ���� "<< scnt << "��" << endl;

}

void DB_list::search_by_moviename(DB_list *list, int index){
    string movie_name;
    int scnt = 0;

    cout << "�˻��� ��ȭ �̸���?: ";
    cin >> movie_name;

    char char_movie_name[name.length() + 1];
    name.copy(char_movie_name, name.length() + 1);

    for(int i=0; i<index; i++) {
        if(list[i].price == -1) continue;

        char data_movie_name[list[i].name.length() + 1];
        list[i].name.copy(data_movie_name, list[i].name.length() + 1);

        if(strstr(data_movie_name, char_movie_name)) {
            cout << "\n���Ź�ȣ: " << list[i].id << "��" << endl;
            cout << "********************************************************" << endl;
            cout << "*                                                          *" << endl;
            cout << "*          ��ȭ ����: " << list[i].movie_name << "         \t*" << endl;
            cout << "*      ���Ͻ�: " << list[i].seat << "           ������: " << list[i].name << "      *" << endl;  
            cout << "*      �¼�: " << list[i].room << "�� "<< list[i].seat << "           ����: " << list[i].price << "  \t*" << endl;
            cout << "*                                                     *" << endl;
            cout << "*******************************************************" << endl;
            scnt++;
        }
    }

    if(scnt==0) cout << "\n=> �˻��� ������ ����!" << endl;
    else cout << "\n=> �� ���� "<< scnt << "��" << endl;
}

void DB_list::leftSeats(DB_list *list, int index){
    int room1 = 0, room2 = 0, room3 = 0, room4 = 0, room5 = 0, room6 = 0, room7 = 0;

    for(int i = 0; i < index; i ++){
        if(list[i].room == 1) room1 ++;
        else if(list[i].room == 2) room2 ++;
        else if(list[i].room == 3) room3 ++;
        else if(list[i].room == 4) room4 ++;
        else if(list[i].room == 5) room5 ++;
        else if(list[i].room == 6) room6 ++;
        else if(list[i].room == 7) room7 ++;
    }

    cout << "1��: " << room1 << "/100" << endl;
    cout << "2��: " << room2 << "/100" << endl;
    cout << "3��: " << room3 << "/100" << endl;
    cout << "4��: " << room4 << "/100" << endl;
    cout << "5��: " << room5 << "/100" << endl;
    cout << "6��: " << room6 << "/100" << endl;
    cout << "7��: " << room7 << "/100" << endl;
}

void DB_list::saveData(DB_list *list, int index){
    ofstream fout;
    fout.open("list.txt");

    for(int i = 0; i < index; i++){
        if(list[i].price == -1) continue;
        fout << list[i].name << " " << list[i].movie_name << " " <<  list[i].seat << " " << list[i].price << " " << list[i].date << " " << list[i].room << " " << list[i].id << endl;
    }

    fout << endl;
    fout.close();
    cout << "\n FILE �����!" << endl;
}

int DB_list::loadData(DB_list *list){
    ifstream fin("list.txt");

    string name;
    string movie_name;
    string seat;
    int price;
    string date;
    int room;
    int id;

    int i = 0;

    while(fin >> name >> movie_name >> seat >> price >> date >> room >> id){
        list[i].name = name;
        list[i].movie_name = movie_name;
        list[i].seat = seat;
        list[i].price = price;
        list[i].date = date;
        list[i].room = room;
        list[i].id = id;
        i++;
    }

    fin.close();
    cout<< "\n==> FILE �ε� ����!" << endl;
    
    if(i == 0){
        cout << "\n ==> FILE ����!" << endl;
        return 0;
    }

    return i;

}

int show_menu(){
    int num;
    cout << "\n*********** MENU ****************" << endl;
    cout << "1 : ���� �Է�" << endl;
    cout << "2 : ���� ����" << endl;
    cout << "3 : ���� �ҷ�����" << endl;
    cout << "4 : ���� ����" << endl;
    cout << "5 : �����ϱ�" << endl;
    cout << "6 : ������ ������ �˻�" << endl;
    cout << "7 : ��ȭ������ �˻�" << endl;
    cout << "8 : �󿵰��� �ܿ� �¼� Ȯ��" << endl;
    cout << "0 : ���� ����" << endl;
    cout << "Choose menu : ";
    cin >> num;
    cout << endl;

    return num;
}

int main(){
    DB_list list[100];

    int index = list -> loadData(list);
    int num = 1;    //�ʱⰪ(0�� �ƴϸ� ��)
    while(num != 0) {      //�Է¹��� ���� Q�϶����� �ݺ�
        num = show_menu();                   //�޴����� �����Ű�� �Է¹��� ���� str�� �޾ƿ�
        
        switch(num) {
            case 1:
                list->addInfo(list, index);
                index++;
                break;
            case 2:
                list->deleteInfo(list, index);
                break;
            case 3:
                list->readInfo(list, index);
                break;
            case 4:
                list->updateInfo(list, index);
                break;
            case 5:
                list->saveData(list, index);
                break;
            case 6:
                list->search_by_name(list, index);
                break;
            case 7:
                list->search_by_moviename(list, index);
                break;
            case 8:
                list->leftSeats(list, index);
                break;
        }  
    }
    cout << "���񽺰� ����Ǿ����ϴ�!" << endl;
}