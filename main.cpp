#include <iostream>
#include "movie.h"

using namespace std;

int main(){
    DB_list list[700];

    int index = list -> loadData(list);
    int num = 1;    //�ʱⰪ(0�� �ƴϸ� ��)
    while(num != 0) {      //�Է¹��� ���� 0�϶����� �ݺ�
        num = show_menu();                   
        
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