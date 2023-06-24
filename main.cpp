#include <iostream>

#include "Station.h"
#include "ConsoleHelper.h"

int main() {
    system("chcp 65001");

    StationDatabase database;
    database.importDatabase();
    database.createArea();
    database.printDatabase();

    int choice = -1;
    while (choice != 0) {
        ShowMenu();
        cout << "Введите пункт меню: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Station station;
                cout << "Введите id станции: ";
                cin >> station.id;
                cout << "Введите имя станции: ";
                cin.ignore();
                getline(cin, station.name);
                cout << "Введите дистанцию пути ПЧ: ";
                cin >> station.pch;
                cout << "Введите дистанцию СЦБ: ";
                cin >> station.shch;
                cout << "Введите дистанцию ЭЧ: ";
                cin >> station.ech;
                cout << "Введите региональный центр связи РЦС: ";
                cin >> station.rcs;
                cout << "Введите километр: ";
                cin >> station.km;
                database.addStation(station);
                cout <<"Добавлена станция:" << endl;
                cout << station.id << ";" << station.name << ";" << station.pch << ";" << station.shch << ";" << station.ech
                     << ";" << station.rcs << ";" << station.km << endl;
                system("pause");
                break;
            }
            case 2: {
                string name, pch, shch, ech, rcs;
                int id, km;
                cout << "Введите id станции: ";
                cin >> id;
                cout << "Введите имя станции: ";
                cin.ignore();
                getline(cin, name);
                cout << "Введите дистанцию пути ПЧ: ";
                cin >> pch;
                cout << "Введите дистанцию СЦБ: ";
                cin >> shch;
                cout << "Введите дистанцию ЭЧ: ";
                cin >> ech;
                cout << "Введите региональный центр связи РЦС: ";
                cin >> rcs;
                cout << "Введите километр: ";
                cin >> km;
                database.editStation(id, name, pch, shch, ech, rcs, km);
                cout <<"Отредактирована станция:" << endl;
                cout << id << ";" << name << ";" << pch << ";" << shch << ";" << ech << ";" << rcs << ";" << km << endl;
                system("pause");
                break;
            }
            case 3: {
                int id;
                cout << "Введите имя станции: ";
                cin >> id;
                database.deleteStation(id);
                break;
            }
            case 4: {
                string pch;
                cout << "Введите дистанцию пути ПЧ: ";
                cin >> pch;
                database.printPchStations(pch);
                break;
            }
            case 5: {
                string shch;
                cout << "Введите дистанцию пути ШЧ: ";
                cin >> shch;
                database.printShchStations(shch);
                break;
            }
            case 6: {
                string ech;
                cout << "Введите дистанцию пути ЭЧ: ";
                cin >> ech;
                database.printEchStations(ech);
                break;
            }
            case 7: {
                string rcs;
                cout << "Введите региональный центр связи РЦС: ";
                cin >> rcs;
                database.printRcsStations(rcs);
                break;
            }
            case 8: {
                database.exportDatabase();
                break;
            }
            case 9: {
                database.importDatabase();
                break;
            }
            case 10: {
                database.printDatabase();
                break;
            }
            case 11: {
                database.createArea();
                database.printArea();
                break;
            }
            case 0: {
                cout << "Выход." << endl;
                break;
            }
            default: {
                cout << "Неверный пункт меню." << endl;
                break;
            }
        }
    }

    return 0;
}