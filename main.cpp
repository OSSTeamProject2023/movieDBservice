#include <iostream>
#include <string>
#include <cstring>

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
    void leftSeats();
};


void DB_list::addInfo(DB_list* list, int index){
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
    cin >> list[index].room;
    cout << "�����!";
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
    cout << "������!";
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
            readInfo(list, index);
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
            readInfo(list, index);
            scnt++;
        }
    }

    if(scnt==0) cout << "\n=> �˻��� ������ ����!" << endl;
    else cout << "\n=> �� ���� "<< scnt << "��" << endl;
}

void DB_list::leftSeats(){

}

void saveData(){

}

void loadData(){

}

int show_menu(){
    int num;
    cout << "\n*********** MENU ****************" << endl;
    cout << "1 : Add new data" << endl;
    cout << "2 : Delete data" << endl;
    cout << "3 : Read data" << endl;
    cout << "4 : Update data" << endl;
    cout << "5 : Save data" << endl;
    cout << "6 : Search by name" << endl;
    cout << "7 : Search by movie name" << endl;
    cout << "8 : Show left seats by movie room" << endl;
    cout << "0 : Quit" << endl;
    cout << "Choose menu : ";
    cin >> num;

    return num;
}

int main(){
    DB_list list[100];

    int index = 0;
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
                saveData();
                break;
            case 6:
                list->search_by_name(list, index);
                break;
            case 7:
                list->search_by_moviename(list, index);
                break;
            case 8:
                list->leftSeats();
                break;
        }  
    }
    cout << "bye!" << endl;
}