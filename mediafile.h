#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <vector>
class Mediafile
{
protected:
    std::string title;
    int length;
    std::vector<int> ratings;
    double avgrating;
    std::string genre;
    int totalratings;

public:
    //Mediafile(std::string _title, int _length, std::string _genre);
    Mediafile();
    virtual void showMeta();
    void addRating(int _rating);
    virtual void playback();
    std::string getTitle();
    double getAvgRating();
    int getLength();
    void showRatings();
    std::string getRatingsString();
    std::string getGenre();

    virtual ~Mediafile();
};

#endif // MOVIE_H
