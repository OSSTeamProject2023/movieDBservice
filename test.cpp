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
    list[index].id = index + 1;
}
 
void DB_list::readInfo(DB_list *list, int index){

    for(int i = 0; i < index; i++) {
        if(list[i].price == -1) continue;
        else{
        cout << "\n예매번호: " << list[i].id << "번" << endl;
        cout << "********************************************************" << endl;
        cout << "*                                                          *" << endl;
        cout << "*          영화 제목: " << list[i].movie_name << "         \t*" << endl;
        cout << "*      상영일시: " << list[i].seat << "           예매자: " << list[i].name << "      *" << endl;  
        cout << "*      좌석: " << list[i].room << "관 "<< list[i].seat << "           가격: " << list[i].price << "  \t*" << endl;
        cout << "*                                                     *" << endl;
        cout << "*******************************************************" << endl;
        }
    }
}

void DB_list::updateInfo(DB_list *list, int index){
    int number;

    readInfo(list, index);

    cout << "수정할 예약번호는?: ";
    cin >> number;
    cout << "예약자 이름: ";
    cin >> list[number-1].name;
    cout << "영화 이름: ";
    cin >> list[number-1].movie_name;
    cout << "티켓 좌석: ";
    cin >> list[number-1].seat;
    cout << "영화 가격: ";
    cin >> list[number-1].price;
    cout << "상영 날짜: ";
    cin >> list[number-1].date;
    cout << "영화관: ";
    cin >> list[number-1].room;
    cout << "수정됨!";
}

void DB_list::deleteInfo(DB_list *list, int index){
    int number, confirm;

    readInfo(list, index);

    cout << "번호는? (취소: 0) " << endl;
    cin >> number;
    if(number == 0) return;

    cout << "정말로 삭제하시겠습니까? (삭제: 1) " << endl;
    cin >> confirm;

    if(confirm == 1){
        list[number-1].price = -1;
        cout << "삭제됨!!" << endl;
    }
}

void DB_list::search_by_name(DB_list *list, int index){
    string name;
    int scnt = 0;

    cout << "검색할 예약자 이름은?: ";
    cin >> name;

    char char_name[name.length() + 1];
    name.copy(char_name, name.length() + 1);

    for(int i=0; i<index; i++) {
        if(list[i].price == -1) continue;

        char data_name[list[i].name.length() + 1];
        list[i].name.copy(data_name, list[i].name.length() + 1);
     
        if(strstr(data_name, char_name)) {
            cout << "\n예매번호: " << list[i].id << "번" << endl;
            cout << "********************************************************" << endl;
            cout << "*                                                          *" << endl;
            cout << "*          영화 제목: " << list[i].movie_name << "         \t*" << endl;
            cout << "*      상영일시: " << list[i].seat << "           예매자: " << list[i].name << "      *" << endl;  
            cout << "*      좌석: " << list[i].room << "관 "<< list[i].seat << "           가격: " << list[i].price << "  \t*" << endl;
            cout << "*                                                     *" << endl;
            cout << "*******************************************************" << endl;
            scnt++;
        }
    }

    if(scnt==0) cout << "\n=> 검색된 데이터 없음!" << endl;
    else cout << "\n=> 총 예약 "<< scnt << "건" << endl;

}

void DB_list::search_by_moviename(DB_list *list, int index){
    string movie_name;
    int scnt = 0;

    cout << "검색할 영화 이름은?: ";
    cin >> movie_name;

    char char_movie_name[name.length() + 1];
    name.copy(char_movie_name, name.length() + 1);

    for(int i=0; i<index; i++) {
        if(list[i].price == -1) continue;

        char data_movie_name[list[i].name.length() + 1];
        list[i].name.copy(data_movie_name, list[i].name.length() + 1);

        if(strstr(data_movie_name, char_movie_name)) {
            cout << "\n예매번호: " << list[i].id << "번" << endl;
            cout << "********************************************************" << endl;
            cout << "*                                                          *" << endl;
            cout << "*          영화 제목: " << list[i].movie_name << "         \t*" << endl;
            cout << "*      상영일시: " << list[i].seat << "           예매자: " << list[i].name << "      *" << endl;  
            cout << "*      좌석: " << list[i].room << "관 "<< list[i].seat << "           가격: " << list[i].price << "  \t*" << endl;
            cout << "*                                                     *" << endl;
            cout << "*******************************************************" << endl;
            scnt++;
        }
    }

    if(scnt==0) cout << "\n=> 검색된 데이터 없음!" << endl;
    else cout << "\n=> 총 예약 "<< scnt << "건" << endl;
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