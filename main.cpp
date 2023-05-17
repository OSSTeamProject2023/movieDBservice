#include <iostream>
#include "movie.h"

using namespace std;

int main(){
    DB_list list[700];

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