#include "configreader.h"


ConfigReader::ConfigReader() {}

ConfigReader::~ConfigReader() {
    //NOTE: We must save the new map first!
    writeFile();

}

//constructor, loads file / makes default file
void ConfigReader::setup(QString fileName, QString filePath) {

    path = (filePath + fileName);
    QFile config(path);

    //test if it actually exists, if not make a default config.
    if(!config.exists()) {
        createDefault();
        return;
    }
    config.open(QIODevice::ReadOnly | QIODevice::Text);

    //until EOF, read the next lines, put in Map.
    while (!config.atEnd()) {
        QByteArray line = config.readLine();
        std::string str(line.constData());
        extractAndMap(str);
    }
    config.close();
    //fill in anything missed out
    fixMap();
}

/************************** GETTERS ***********************/
std::string ConfigReader::getColor() const {
    return configMap.find("color")->second;
}

std::string ConfigReader::getSize() const {
    return configMap.find("size")->second;
}

std::string ConfigReader::getMove() const {
    return configMap.find("move")->second;
}

int ConfigReader::getCoord() const {
    return this->coord;
}

/************************ SETTERS *************************/
//reads the map value and then saves it
void ConfigReader::setColor (std::string newColor) {
    configMap["color"] = newColor;
}

void ConfigReader::setSize(std::string newSize) {
    configMap["size"] = newSize;
}

/****************** HELPER (CHECK) FUNCTIONS *************/
bool ConfigReader::checkSize(std::string isize) {
    return (isize == "Tiny" || isize == "Normal" || isize == "Large" || isize=="Giant");
}

//checks if it is one of the colours we offer
bool ConfigReader::checkColor(std::string cname) {
    return (std::find(colors.begin(), colors.end(), cname) != colors.end());
}

//Ships should move
bool ConfigReader::checkMove(std::string move) {
    if (move.empty()) {
        return false;
    }

    for (int i = 0; i < move.length(); i++) {
        char a = move.at(i);
        if (a != 'L' && a != 'S' && a != 'R') {
            return false;
        }
    }
    return true;
}

//checks the coord if it is a POSITIVE INT and sets int_coord variable.
// will cut off bad characters e.g., 900asdfasdf becomes 900.
// does not accept negative numbers, however.
bool ConfigReader::checkCoord(std::string coord) {
    //check if empty. coords need a letter.
    if (coord.empty()) {
        return false;
    }

    //check if it has a negative symbol
    if (coord.at(0) == '-') {
        return false;
    }

    std::istringstream stream(coord);
    int number = 0;
    if (stream >> number) {
        //now check if it failed or not, save it
        if (!stream.fail()) {
            this->coord = number;
            return true;
        }
    }
    return false;
}

//returns the number of the index in the default key array
int ConfigReader::goodKey(std::string key) {

    for (int i = 0; i < defaultKeys.size(); i++) {
        if (defaultKeys.at(i) == key)  {
            return i;
        }
    }
    return -1;
}

//returns if the value is a valid one... I think there's a nicer way to do this.
bool ConfigReader::goodValue(std::string key, std::string value) {

    //at this point we already know the key is valid
    if (key == "color") {
        value[0] = toupper(value[0]);
        return checkColor(value);
    } else if (key == "size") {
        return checkSize(value);
    } else if (key == "move") {
        return checkMove(value);
    } else if (key == "coord") {
        return checkCoord(value);
    }

    return false;
}

/********************* MAPPING FUNCTIONS *******************/
//This is a hotfix for the extensions >_>;;
void ConfigReader::fixName() {
    //get the actual value and change it
    std::string fixed = configMap["color"];
    fixed[0] = toupper(fixed[0]);
    configMap["color"] = fixed;

    fixed = configMap["size"];
    fixed[0] = toupper(fixed[0]);
    configMap["size"] = fixed;
}

//finds any missing items and fills a default value
void ConfigReader::fixMap() {
    // if the key does not exist, add default values :
    for (int i = 0; i < defaultKeys.size(); i++) {
        std::string key = defaultKeys.at(i);
        if (configMap.find(key) == configMap.end()) {
            std::string value = defaultValues.at(i);
            configMap.insert(std::pair<std::string, std::string>(key, value));
            alertUsingDefault(key);
        }
    }
    //init the 'coord' int variable
    checkCoord(configMap.find("coord")->second);

    //fixes color to be Capital ie., "Red" not "red"..
    fixName();
}

void ConfigReader::writeFile() {
    //save it to a new file.
    QFile file(path);

    file.open(QFile::WriteOnly);

    //loop through the created map; if we have different ships
    std::map<std::string, std::string>::iterator it;
    for (it = configMap.begin(); it != configMap.end(); it++) {
        //write to file
        QString key = QString::fromStdString(it->first);
        QString value = QString::fromStdString(it->second);
        QTextStream write(&file);
        write << key << " " << value << "\r\n";
    }
}

//it just runs 'fixMap()' and saves a folder.
void ConfigReader::createDefault() {
    fixMap();
    writeFile();
}

void ConfigReader::alertUsingDefault(std::string key) {
    QMessageBox badValue;
    badValue.setText("Appropriate " + QString::fromStdString(key) + " not found. Default value used.");
    badValue.exec();

}

//does what it says. Won't map anything that isn't an expected header or value.
void ConfigReader::extractAndMap(std::string str) {
    std::stringstream list(str);
    std::string key, value;
    list >> key >> value;

    //find the index of this key from the 'default keys' list
    int keyIndex = goodKey(key);
    if (goodKey(key) != -1) {
        //if the value is not good, then replace with default value.
        if (!goodValue(key, value)) {
            value = defaultValues.at(keyIndex);
            alertUsingDefault(key);
        }

        configMap.insert(std::pair<std::string, std::string>(key, value));
    } //ignore bad keys.


}

//there is an error with MSVC2013 apparently and I can't do it inline like in 2015.
const char *dkInit[] = {"color", "size", "move", "coord"};
 const std::vector<std::string> ConfigReader::defaultKeys(dkInit, dkInit + 4);

const char *dvInit[] = {"Red", "Large", "LSLSLSLSSRSRSRSRSRSRRLRS", "400"};
const std::vector<std::string> ConfigReader::defaultValues(dvInit, dvInit + 4);

const char *colInit[]  = {"Red", "Orange", "Yellow", "Green", "Blue"};
const std::vector<std::string> ConfigReader::colors(colInit, colInit + 4);


