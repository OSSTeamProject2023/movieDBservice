#include <iostream>

using namespace std;

class DB_list {
    private:
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

int show_menu();