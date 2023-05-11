#include <iostream>
#include <string>
using namespace std;



class DB_list {
    string name;
    string movie_name;
    string seat;
    int price;
    string date;
    int room;
public:
    void addInfo(DB_list *list, int index);
    void deleteInfo();
    void readInfo(DB_list *list, int index);
    void updateInfo();
    void search_by_name();
    void search_by_moviename();
    void leftSeats();
};


void DB_list::addInfo(DB_list* list, int index){
    cout << "예약자 이름: ";
    cin >> list[index].name;
    cout << "영화 이름: ";
    cin >> list[index].movie_name;
    cout << "티켓 좌석: ";
    cin >> list[index].seat;
    cout << "영화 가격: ";
    cin >> list[index].price;
    cout << "상영 날짜: ";
    cin >> list[index].date;
    cout << "영화관: ";
    cin >> list[index].room;
    cout << "저장됨!";
}

void DB_list::deleteInfo(){

}
 
void DB_list::readInfo(DB_list *list, int index){
    for(int i = 0; i < index; i++) {
        cout << "name: " << list[i].name << "\tmovie name: " << list[i].movie_name << "\tseat: " << list[i].seat << "\tprice: " << list[i].price << "\tdate: " << list[i].date << "\tmovie room: " << list[i].room << endl;
    }

    // cout << "name: " << list[0].name << endl;
    // cout << "price: " << list[1].price << endl;
}

void DB_list::updateInfo(){

}

void DB_list::search_by_name(){

}

void DB_list::search_by_moviename(){

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
    int num = 1;    //초기값(0만 아니면 됨)
    while(num != 0) {      //입력받은 값이 Q일때까지 반복
        num = show_menu();                   //메뉴판을 실행시키고 입력받은 값을 str에 받아옴
        
        switch(num) {
            case 1:
                list->addInfo(list, index);
                index++;
                break;
            case 2:
                list->deleteInfo();
                break;
            case 3:
                list->readInfo(list, index);
                break;
            case 4:
                list->updateInfo();
                break;
            case 5:
                saveData();
                break;
            case 6:
                list->search_by_name();
                break;
            case 7:
                list->search_by_moviename();
                break;
            case 8:
                list->leftSeats();
                break;
        }  
    }
    cout << "bye!" << endl;
}