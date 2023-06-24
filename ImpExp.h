#pragma once

#include "Station.h"
#include "ConsoleHelper.h"

void StationDatabase::exportDatabase() const {
    ofstream fout("station.txt");
    if (!fout.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return;
    }
    for (const auto &station: stations) {
        fout << station.id << ";" << station.name << ";" << station.pch << ";" << station.shch << ";" << station.ech
             << ";" << station.rcs << ";" << station.km << endl;
    }
    fout.close();
    cout << "База данных успешно экспортирована" << endl;
}

void StationDatabase::importDatabase() {
    ifstream fin("station.txt");
    if (!fin.is_open()) {
        cout << "Ошибка открытия файла." << endl;
        return;
    }
    stations.clear();
    string line;
    while (getline(fin, line)) {
        Station station;
        auto pos = line.find(";");
        station.id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        pos = line.find(";");
        station.name = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(";");
        station.pch = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(";");
        station.shch = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(";");
        station.ech = line.substr(0, pos);
        line.erase(0, pos + 1);
        pos = line.find(";");
        station.rcs = line.substr(0, pos);
        line.erase(0, pos + 1);
        station.km = stoi(line);
        stations.push_back(station);

    }
    fin.close();
    cout << "База данных успешно импортирована." << endl;
}