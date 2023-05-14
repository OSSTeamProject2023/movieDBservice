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
    cin >> room;
    while((room == 0) || (room > 7)){
        cout << "올바르지 않은 상영관 정보입니다!" << endl;
        cout << "영화관: ";
        cin >> room;
    }
    list[index].room = room;

    cout << "저장됨!" << endl;
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
    cout << "수정됨!" << endl;
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

    cout << "1관: " << room1 << "/100" << endl;
    cout << "2관: " << room2 << "/100" << endl;
    cout << "3관: " << room3 << "/100" << endl;
    cout << "4관: " << room4 << "/100" << endl;
    cout << "5관: " << room5 << "/100" << endl;
    cout << "6관: " << room6 << "/100" << endl;
    cout << "7관: " << room7 << "/100" << endl;
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
    cout << "\n FILE 저장됨!" << endl;
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
    cout<< "\n==> FILE 로딩 성공!" << endl;
    
    if(i == 0){
        cout << "\n ==> FILE 없음!" << endl;
        return 0;
    }

    return i;

}

int show_menu(){
    int num;
    cout << "\n*********** MENU ****************" << endl;
    cout << "1 : 정보 입력" << endl;
    cout << "2 : 정보 삭제" << endl;
    cout << "3 : 정보 불러오기" << endl;
    cout << "4 : 정보 수정" << endl;
    cout << "5 : 저장하기" << endl;
    cout << "6 : 예약자 명으로 검색" << endl;
    cout << "7 : 영화명으로 검색" << endl;
    cout << "8 : 상영관별 잔여 좌석 확인" << endl;
    cout << "0 : 서비스 종료" << endl;
    cout << "Choose menu : ";
    cin >> num;
    cout << endl;

    return num;
}

int main(){
    DB_list list[100];

    int index = list -> loadData(list);
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
    cout << "서비스가 종료되었습니다!" << endl;
}