#ifndef MULTIMEDIACOLLECTION_H
#define MULTIMEDIACOLLECTION_H

#include "collectiontype.h"
#include "datatype.h"
#include "category.h"

using namespace std;

class MultimediaCollection
{
private:
    string collectionTypeID;
    string dataTypeID;
    string categoryID;
    string title;
    string version;
    static int currentID;
    string ID;
    string publisher;
    int recordedYear;
    int duration;

public:
    MultimediaCollection(string collectionTypeIDVal, string dataTypeIDVal, string categoryIDVal, string titleVal, string versionVal, string publisherVal,int recordedYearVal, int durationVal)
        : collectionTypeID(collectionTypeIDVal), dataTypeID(dataTypeIDVal), categoryID(categoryIDVal), title(titleVal), version(versionVal), publisher(publisherVal), recordedYear(recordedYearVal), duration(durationVal)
    {

    }

    void generateID();

    string getCollectionTypeID() {
        return collectionTypeID;
    }

    void setCollectionTypeID(string collectionTypeIDVal){
        collectionTypeID = collectionTypeIDVal;
    }

    string getDataTypeID(){
        return dataTypeID;
    }

    void setDataTypeID(string dataTypeIDVal){
        dataTypeID = dataTypeIDVal;
    }

    string getCategoryID(){
        return categoryID;
    }

    void setCategoryID(string categoryIDVal){
        categoryID = categoryIDVal;
    }

    string getTitle(){
        return title;
    }

    void setTitle(string titleVal){
        title = titleVal;
    }

    string getVersion(){
        return version;
    }

    void setVersion(string versionVal){
        version = versionVal;
    }

    static int getCurrentID(){
        return currentID;
    }

    static void setCurrentID(int currentIDVal){
        currentID = currentIDVal;
    }

    string getID(){
        return ID;
    }

    void setID(string IDVal){
        ID = IDVal;
    }

    string getPublisher(){
        return publisher;
    }

    void setPublisher(string publisherVal){
        publisher = publisherVal;
    }

    int getRecorededYear(){
        return recordedYear;
    }

    void setRecoredYear(int recordedYearVal){
        recordedYear = recordedYearVal;
    }

    int getDuration(){
        return duration;
    }

    void setDuration(int durationVal){
        duration = durationVal;
    }



};

#endif // MULTIMEDIACOLLECTION_H
