#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Station {
    int id;
    string name;
    string pch;
    string shch;
    string ech;
    string rcs;
    int km;
    Station* prevStation;
    Station* nextStation;

};

class Section {
public:
    Section(Station* startStation, Station* endStation, int length)
            : startStation_(startStation), endStation_(endStation), length_(length) {}

    Station* getStartStation() const { return startStation_; }
    Station* getEndStation() const { return endStation_; }
    int getLength() const { return length_; }

private:
    Station* startStation_;
    Station* endStation_;
    int length_;
};

class StationDatabase {
public:
    StationDatabase() {}

    void addStation(const Station &station);

    void editStation(int &id, const string &name, const string &pch, const string &shch, const string &ech,
                     const string &rcs, int &km);

    void deleteStation(int &id);

    void createArea();

    void printPchStations(const string &pch) const;

    void printShchStations(const string &shch) const;

    void printEchStations(const string &ech) const;

    void printRcsStations(const string &rcs) const;

    void exportDatabase() const;

    void importDatabase();

    void printDatabase() const;

    void printArea();

private:
    vector<Station> stations;
    vector<Section> sections;
};



