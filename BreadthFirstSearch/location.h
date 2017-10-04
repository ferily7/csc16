#ifndef LOCATION_H
#define LOCATION_H
struct Location{
    int row, col;
public:
    Location(): row(0), col(0) {}
    Location(int prow, int pcol): row(prow), col(pcol){}
    bool operator==(Location & other) { return other.col == col && other.row == row; }
};

#endif // LOCATION_H
