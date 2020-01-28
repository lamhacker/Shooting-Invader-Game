#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <QColor>
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QString>

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/*This function reads all the lines in the config file
 * Checks the current line's key,
 * Then map the value to the appropriate title
 * Then check: while mapping if the values are not correct,
 * will make a dialog pop up that says "not correct value"
 * e.g., size == "L234098" instead of "large"
 * and replace this incorrect input with a large value.
 *
 * For non-existant config file, it makes a default config file first
 * Then saves this new config file
 *
 * If values are bad / key doesn't exist, then
 * displays a popup to alert user that a default value was used.
 *
 * CONFIG LAYOUT: [lines in any order]
 * color Col <- note capital first letter
 * size Size <- capital first letter
 * coord 200 <- some number
 * move LSR <- use L for left, R for right, S for shoot.
 *              - all upper case.
 *
 * Follow the above layout to make sure your values are
 * read succesfully, else they are replaced by defaults.
 *
 * ::FUTURE CHANGES::
 * If you wish to make future changes such as using std namespace
 * then okay.
 *
 * Another change would be; the config file will have Aliens.
 * Hence, we should have a MAP of maps.
 * I.e., configMap will be a map of maps e.g.,
 * configMap
 *  Ship 1 (map: color, size...)
 *  Alien 1 (map: x, y...)
 *
 * And you would read a header [SHIP] first
 * e.g., if [SHIP] then create a new map for ships
 * e.g., 2 if [ALIEN] then create a new map for alien1
 **/

class ConfigReader
{
public:

    /*************** CLASS AND SETUP ***********************/
    ConfigReader();
    ~ConfigReader();
    void setup(QString fileName, QString filePath);
    /************************** GETTERS ***********************/
    std::string getColor() const;
    std::string getSize() const;
    std::string getMove() const;
    int getCoord() const;

    /************************* SETTERS ***********************/
    void setColor(std::string newColor);
    void setSize(std::string newSize);

private:

    /****************** HELPER (CHECK) FUNCTIONS *********************/
    int goodKey(std::string key);
    bool goodValue(std::string key, std::string value);
    bool checkSize(std::string isize);
    //checks if it is a valid QColor
    bool checkColor(std::string cname);
    bool checkMove(std::string move);
    //check if parseable into an int for now, then save it.
    bool checkCoord(std::string coord);

    /************************ MESSAGE BOXES ********************/
    void alertUsingDefault(std::string key);

    /********************* MAPPING FUNCTIONS *******************/
    void fixName();
    void fixMap();
    void extractAndMap(std::string str);
    void writeFile();
    void createDefault();

    /********** VARIABLES *********/
    QString path;
    std::map<std::string, std::string> configMap;
    int coord;
    //this is the default possible keys, already init
    static const std::vector<std::string> defaultKeys;
    //this is the default values for such keys, listed in the same order.
    static const std::vector<std::string> defaultValues;
    static const std::vector<std::string> colors;

};


#endif // CONFIGREADER_H
