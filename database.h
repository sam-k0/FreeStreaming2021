#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include "mediafile.h"
#include <string>
class Database
{
private:

    Database();

    static std::vector <Mediafile*> movieVec;

public:
    static void showAll();
    static bool addVideo(Mediafile* _toAdd); // returns successful or not
    static bool removeVideo( int _pos);
    static void sortByRank();
    static void showDuration();
    static bool playVideo(const int _pos); //uwu
    static bool init();
    static bool initFromFile(std::string _defaultpath);
    static bool saveDatabase();
    static bool saveDatabaseTo(std::string _defaultpath);
    static Mediafile* getMovie(const int _pos);

    static void simulateReviews(const int numberOfReviews);
    static int getMovieCount();
    static void addRatingToVideoDB(int _rating, int _index);
    ~Database();
};

#endif // DATABASE_H
