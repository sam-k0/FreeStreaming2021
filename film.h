#ifndef FILM_H
#define FILM_H
#include "mediafile.h"

class Film : public Mediafile
{
private:
    int releasedate;
public:
    Film(std::string _title, int _length, std::string _genre, int _releasedate);
    void playback();
    void showMeta();

    bool amIOlder(Film* _compareTo);
    int getReleasedate();
};

#endif // FILM_H
