#include "film.h"
#include <iostream>
using namespace std;
Film::Film(std::string _title, int _length, std::string _genre, int _releasedate)
{
    title = _title;
    length = _length;
    genre = _genre;
    releasedate = _releasedate;
    avgrating = 0;
    totalratings = 0;
}

void Film::playback()
{
    cout << ">> INFO : MOVIE : Now playing: " << title <<" with average rating: "<< avgrating << endl;
}

void Film::showMeta()
{
    cout << ">> MOVIE : Information on movie"<<endl;
    cout << "|--Title: " << title << endl;
    cout << "|--Duration (min): " << length << endl;
    cout << "|--Rating: " << avgrating <<" (based off "<< ratings.size() << " ratings)"<< endl;
    cout << "|--Genre: " << genre << endl;
    cout << "|--Release Date: " << releasedate << endl;
}

bool Film::amIOlder(Film *_compareTo)
{
    if(releasedate > _compareTo->getReleasedate())
    {
        return true;
    }
    return false;
}

int Film::getReleasedate()
{
    return releasedate;
}
