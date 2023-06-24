#pragma once

#include <iostream>

#include "Station.h"
#include "ImpExp.h"

using namespace std;

void StationDatabase::addStation(const Station &station) {
    stations.push_back(station);
    sort(stations.begin(), stations.end(), [](const Station &a, const Station &b) {
        return a.id < b.id;
    });
}

void StationDatabase::editStation(int &id, const string &name, const string &pch, const string &shch, const string &ech,
                                  const string &rcs, int &km) {
    auto it = find_if(stations.begin(), stations.end(), [&id](const Station &station) {
        return station.id == id;
    });
    if (it != stations.end()) {
        it->name = name;
        it->pch = pch;
        it->shch = shch;
        it->ech = ech;
        it->rcs = rcs;
        it->km = km;
        sort(stations.begin(), stations.end(), [](const Station &a, const Station &b) {
            return a.id < b.id;
        });
    }
}

void StationDatabase::deleteStation(int &id) {
    stations.erase(remove_if(stations.begin(), stations.end(), [&id](const Station &station) {
        return station.id == id;
    }), stations.end());
}

void StationDatabase::createArea() {
    sort(stations.begin(), stations.end(), [](const Station& a, const Station& b) {
        return a.id < b.id;
    });
    for (int i = 0; i < stations.size(); i++) {
        if (i > 0) {
            stations[i].prevStation = &stations[i-1];
            Section section(&stations[i-1], &stations[i], stations[i].km - stations[i-1].km);
            sections.push_back(section);
        }
        if (i < stations.size() - 1) {
            stations[i].nextStation = &stations[i+1];
        }
    }
}

void StationDatabase::printPchStations(const string &pch) const {
    cout << "Дистанция пути со станциями " << pch << ":" << endl;
    for (const auto &station: stations) {
        if (station.pch == pch) {
            cout << station.name << endl;
        }
    }
}

void StationDatabase::printShchStations(const string &shch) const {
    cout << "Дистанция СЦБ со станциями " << shch << ":" << endl;
    for (const auto &station: stations) {
        if (station.shch == shch) {
            cout << station.name << endl;
        }
    }
}

void StationDatabase::printEchStations(const string &ech) const {
    cout << "Дистанция ЭЧ со станциями " << ech << ":" << endl;
    for (const auto &station: stations) {
        if (station.ech == ech) {
            cout << station.name << endl;
        }
    }
}

void StationDatabase::printRcsStations(const string &rcs) const {
    cout << "Регионалтный центр связи со станциями " << rcs << ":" << endl;
    for (const auto &station: stations) {
        if (station.rcs == rcs) {
            cout << station.name << endl;
        }
    }
}

void StationDatabase::printDatabase() const {
    cout << "База данный станций:" << endl;
    for (const auto &station: stations) {
        cout << "id: " << station.id;
        cout << " | " << station.name;
        cout << " | " << station.pch;
        cout << " | " << station.shch;
        cout << " | " << station.ech;
        cout << " | " << station.rcs;
        cout << " | " << station.km;
        cout << endl;
    }
}

void StationDatabase::printArea() {
    cout << "Список перегонов:" << endl;
    for (const auto& section : sections) {
        cout << section.getStartStation()->name << " - " << section.getEndStation()->name << " (" << section.getLength() << " km)" << endl;
    }
}


void ShowMenu() {
    cout << "1. Добавить ж.д. пункт\n"
         << "2. Редактировать ж.д. пункт\n"
         << "3. Удалить ж.д. пункт\n"
         << "4. Вывести на экран список станций по дистанции пути (ПЧ)\n"
         << "5. Вывести на экран список станций по дистанции СЦБ (ШЧ)\n"
         << "6. Вывести на экран список станций по дистанции энергоснабжения (ЭЧ)\n"
         << "7. Вывести на экран список станций по региональному центру связи (РЦС)\n"
         << "8. Экспортировать базу данных\n"
         << "9. Импортировать базу данных\n"
         << "10. Вывести базу данных на экран\n"
         << "11. Вывести списки перегонов на экран\n"
         << "0. Выход\n";
}
